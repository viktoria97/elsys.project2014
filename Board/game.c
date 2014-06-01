#include <stdio.h>
#include "board.h"

int main() {
	struct board_t board;
	int side;
	int card;
	int AI, FULL; //FULL flags the AI bot when the board has no empty slots
	char ch;

	
	game_begin(&board, &side, &AI);
	while( !winner(board) ) {
		turn_begin(&board.pl[side]);
		do {
			system("clear");
			if(!(side && AI)) printf("%s is on turn!\n", board.pl[side].name);
			print_board(board);
			printf("%s is on turn (-1 to end the turn): ", board.pl[side].name);
			if(side && AI) {
				card = AI_bot(board.pl[1], FULL);
			} else {
				scanf("%d", &card);
			}
			if( card != -1) {			
				if( card > 0 && card <= board.pl[side].hand.top ) {
					card--;
					if( can_put_card(board.pl[side].hand.card[card], board.pl[side].pool) ) {
						if( can_play_card(board, side) ) {
							use_mana(&board.pl[side].pool, board.pl[side].hand.card[card].mana_cost);
							play_card(&board, play_card_from_hand(&board.pl[side], card), side);
							system("clear");
							print_board(board);
						} else {
							FULL = 1;
							printf("There no free slots on the board!\n");
							
						} 
					} else {
						printf("Not enough mana!\n");
	
					}
				} else {
					printf("Invalid card!\n");
					
				}
			}
		} while(card != -1);
		if(board.pl[0].turn == board.pl[1].turn) {
		if(side && AI) printf("\n");		
			
			turn_end(&board);
		}
	side = !side;
	
	}
	print_winner(board);
	return 0;
}
