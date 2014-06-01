#include<stdio.h>
#include "player.h"

void init_player(struct player_t *player) {
	player->name[0] = '\0';
	init_deck(&player->deck);
	init_deck(&player->hand);
	init_manapool(&player->pool);
	player->hp = 0;
	player->turn = 0;
}

void print_player(struct player_t pl) {
printf("PLAYER: %s(%dhp),MANA %d/%d,TURN:%d\n", pl.name, pl.hp, pl.pool.current_mp, pl.pool.max_mp,pl.turn);
}

void print_hand(struct player_t pl) {
	int i;
	printf("|");
	for(i = 0; i < pl.hand.top; i++) {
		printf(" ");
		print_card(pl.hand.card[i]);
		printf(" |");
		if(i == 5 || i == 10 || i == 15 || i == 20) {
			printf("\n");
			if(i + 1 < pl.hand.top) printf("|");
		}
	}
	printf("\n");
}

void change_hp(struct player_t *player, int hp) {
	if(hp > MAX_HP) {
		player->hp = MAX_HP;
	} else {
		player->hp += hp;
		if(player->hp < 0) player->hp = 0;
	}
}

int discard_card(struct player_t *player, int card, struct card_t *return_card) {
	if(player->hand.top == 0) return 0;
	*return_card = player->hand.card[card];
	player->hand.top--;
	return 1;
}

struct card_t play_card_from_hand(struct player_t *player, int card) {
	int i;	
	struct card_t played_card;
	struct card_t error=error_card;
	if(discard_card(player, card, &played_card)) {
		for(i = card + 1; i <= player->hand.top; i++) {
			player->hand.card[i - 1] = player->hand.card[i];
		}
		return played_card;
	} else {
		return error;
	}
}

void turn_begin(struct player_t *player) {
	struct card_t drawed_card;
	if(draw_card(&player->deck, &drawed_card)) player->hand.card[player->hand.top++] = drawed_card;		
	player->turn++;
	add_max_mana(&player->pool);
	fill_pool(&player->pool);
}
