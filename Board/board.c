#include <stdio.h>
#include <string.h>
#include <time.h>
#include "board.h"
#include "board.h"


void init_board(struct board_t *board) {
	int corr;
	for(corr = 0; corr < 5; corr++) {
		board->slot[0][corr].hp = 0;
		board->slot[1][corr].hp = 0;
	}
	init_player(&board->pl[0]);
	init_player(&board->pl[1]);
}

void print_border(char ch) {
	int i;
	for(i = 0; i < border_count; i++) {
		printf("%c", ch);
	}
	printf("\n");
}

void print_field(struct board_t board, int side) {
	int corr;
	printf("#");
	for(corr = 0; corr < 5; corr++) {
		if( !is_slot_empty(board, side, corr) ) {
			printf("   %d|%d   #", board.slot[side][corr].atk, board.slot[side][corr].hp);
		} else {
			printf("         #");
		}
	}
	printf("\n");
}

void print_board(struct board_t board) {	
	print_player(board.pl[0]);
	print_border('_');
	printf("\n");
	print_hand(board.pl[0]);
	print_border('#');
	printf("\n");
	print_field(board, 0);
	printf("\n");
	print_field(board, 1);
	printf("\n");
	print_border('#');
	print_hand(board.pl[1]);
	print_border('_');
	printf("\n");
	print_player(board.pl[1]);	
}

int open_slot(struct board_t board, int side, int corr) {
	return board.slot[side][corr].hp > 0 ? 0 : 1;
}

int can_play_card(struct board_t board, int side) {
	int corr = 0;
	for(corr = 0; corr < 5; corr++) {
		if( open_slot(board, side, corr) ) return 1;
	}
	return 0;
}

int play_card(struct board_t *board, struct card_t card, int side) {
	int corr;
	for(corr = 0; corr < 5; corr++) {
		if( open_slot(*board, side, corr) ) {
			board->slot[side][corr] = card;
			return 1;
		}
	}
	return 0;
}

void on_turn(struct board_t *board, int AI, int side) {
	int card;
	int FULL = 0; //FULL flags the AI bot when the board has no empty slots
	char ch;
		do {
			system("clear");
			if(!(side && AI)) printf("%s is on turn!\n", board->pl[side].name);
			print_board(*board);
			printf("%s is on turn (-1 to end the turn): ", board->pl[side].name);
			if(side && AI) {
				card = AI_bot(board->pl[1], FULL);
			} else {
				scanf("%d", &card);
			}
			if( card != -1) {			
				if( card > 0 && card <= board->pl[side].hand.top ) {
					card--;
					if( can_put_card(board->pl[side].hand.card[card], board->pl[side].pool) ) {
						if( can_play_card(*board, side) ) {
							use_mana(&board->pl[side].pool, board->pl[side].hand.card[card].mana_cost);
							play_card(board, play_card_from_hand(&board->pl[side], card), side);
							system("clear");
							print_board(*board);
						} else {
							FULL = 1;
							printf("There no free slots on the board!\n");
							wait_for_key(AI, side);
						} 
					} else {
						printf("Not enough mana!\n");
						wait_for_key(AI, side);
					}
				} else {
					printf("Invalid card!\n");
					wait_for_key(AI, side);
				}
			}
		} while(card != -1);
}

void turn_end(struct board_t *board) {
	int corr;
	for(corr = 0; corr < 5; corr++) {
		if( !is_slot_empty(*board, 0, corr) && !is_slot_empty(*board, 1, corr) ) {
			attack(&board->slot[0][corr], &board->slot[1][corr]);
		} else if( !is_slot_empty(*board, 0, corr) ) {
			board->pl[1].hp -= board->slot[0][corr].atk;
		} else if( !is_slot_empty(*board, 1, corr) ) {
			board->pl[0].hp -= board->slot[1][corr].atk;
		}
	}
}

void improved_turn_end(struct board_t *board, int AI, int *side) {
	if(board->pl[0].turn == board->pl[1].turn) {
		if(*side && AI) printf("\n");		
			printf("Press enter to continue...\n");
			press_key();
			turn_end(board);
		}
	*side = !(*side);
}

int winner(struct board_t board) {
	if(board.pl[0].hp > 0 && board.pl[1].hp > 0) {
		return 0;
	} else if(board.pl[0].hp > 0) {
		return 1;
	} else {
		return 2;
	}
}

void print_winner(struct board_t board) {
	system("clear");
	if(winner(board) == 1) {
		printf("%s won the game!\n", board.pl[0].name);
	} else {
		printf("%s won the game!\n", board.pl[1].name);
	}
}

int load_deck_from_file(struct board_t *board, int side, char *filename) {
	FILE *fp;
	char str[1800];
	char *buff;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;
	while( fgets(str, 1800, fp) ) {
		buff = strtok(str, ",");
		sscanf(buff, "%s", board->pl[side].deck.card[board->pl[side].deck.top].name);
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->pl[side].deck.card[board->pl[side].deck.top].mana_cost);	
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->pl[side].deck.card[board->pl[side].deck.top].atk);
		buff = strtok(NULL, ",");
		sscanf(buff, "%d", &board->pl[side].deck.card[board->pl[side].deck.top].hp);
		board->pl[side].deck.top++;	
	} 	
	fclose(fp);
	return 1;
}

void game_begin(struct board_t *board, int *side, int *AI) {
	char filename[30];
	char ch = '0';	
	int dice1, dice2;
	int i;
	struct card_t drawed_card;
	srand(time(NULL));
	init_board(board);
	do {
		system("clear");
		printf("Do you want to play against AI BOT (1 - YES / 0 - NO)? ");
		scanf("%d", AI);
	} while(*AI != 0 && *AI != 1);
	printf("Enter player1's name: ");
	scanf("%s", board->pl[0].name);
	if( !(*AI) ) {
		printf("Enter player2's name: ");
		scanf("%s", board->pl[1].name);
	} else {
		strcpy(board->pl[1].name, "AI(BOT)");
	}
	board->pl[0].hp = MAX_HP;
	board->pl[1].hp = MAX_HP;
	printf("%s's is choosing deck: ", board->pl[0].name);
	scanf("%s", filename);
	while( !load_deck_from_file(board, 0, filename) ) {
		printf("(invalid file name) %s's is choosing deck: ", board->pl[0].name);
		scanf("%s", filename);
	}
	printf("%s's is choosing deck: ", board->pl[1].name);
	scanf("%s", filename);
	while( !load_deck_from_file(board, 1, filename) ) {
		printf("(invalid file name) %s's is choosing deck: ", board->pl[1].name);
		scanf("%s", filename);
	}
	system("clear");
	do {
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		printf("%s threw %d out of 6!\n", board->pl[0].name, dice1);
		printf("%s threw %d out of 6!\n\n", board->pl[1].name, dice2);
	} while(dice1 == dice2);
	if(dice1 > dice2) {
		printf("%s will begin first!\n", board->pl[0].name);
		*side = 0;
	} else {
		printf("%s will begin first!\n", board->pl[1].name);
		*side = 1;
	}
	for(i = 0; i < 5; i++) {
		if(draw_card(&board->pl[0].deck, &drawed_card)) board->pl[0].hand.card[board->pl[0].hand.top++] = drawed_card;
		if(draw_card(&board->pl[1].deck, &drawed_card)) board->pl[1].hand.card[board->pl[1].hand.top++] = drawed_card;	
	}
	printf("Press any key to continue...\n");
	ch = getchar();
	ch = getchar();
	system("clear");
}

int AI_bot(struct player_t player, int FULL) {
	if(FULL || player.hand.top == 0) return -1;
	int i;
	int min_cost = player.hand.card[0].mana_cost;
	int card_id = 0;
	for(i = 1; i < player.hand.top; i++) { 
		if(player.hand.card[i].mana_cost < min_cost) card_id = i;
	}
	if(player.hand.card[card_id].mana_cost > player.pool.current_mp) return -1;
	return card_id + 1;
}

