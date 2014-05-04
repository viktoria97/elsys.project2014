#include<stdio.h>
#include "player.h"

void init_player(struct player_t *player) 
{
	player->name = NULL;
	init_deck(&player->deck);
	init_deck(&player->hand);
	init_manapool(&player->pool);
	player->hp = 0;
}

void print_player(struct player_t player) 
{
	int i;
	printf("%s (%d) (%d|%d)\n", player.name, player.hp, player.pool.max_mp, player.pool.current_mp);
	for(i = 0; i < player.hand.top; i++) 
	{
	print_card(player.hand.card[i]);
	}
}

void change_hp(struct player_t *player, int hp) 
{
	if(hp > MAX_HP) {
		player->hp = MAX_HP;
	} else {
		player->hp += hp;
		if(player->hp < 0) player->hp = 0;
	}
}

int discard_card(struct player_t *player, int card, struct card_t *return_card)
{
	if(player->hand.top == 0) return 0;
	*return_card = player->hand.card[card];
	player->hand.top--;
	return 1;
}

struct card_t play_card_from_hand(struct player_t *player, int card) 
{
	int i;	
	struct card_t played_card;
	struct card_t error=error_card;
	if(discard_card(player, card, &played_card)) {
		for(i = card + 1; i <= player->hand.top; i++) 
		{
		player->hand.card[i - 1] = player->hand.card[i];
		}
		return played_card;
	 
}

void turn_begin(struct player_t *player) {
	struct card_t drawed_card;
	if(draw_card(&player->deck, &drawed_card)) player->hand.card[player->hand.top++] = drawed_card;		
}
