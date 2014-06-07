#ifndef playerhead
#define playerhead

#include "card.h"
#include "deck.h"
#include "manapool.h"

struct player_t { 
	char *name;
	int hp;
	struct deck_t deck;
	struct deck_t hand;
	struct manapool_t pool;
};


void print_player(struct player_t player);
void change_hp(struct player_t *player, int hp);
int throw_card(struct player_t *player, int card, struct card_t *return_card); 
struct card_t play_card_from_hand(struct player_t *player, int card);
void turn_begin(struct player_t *player);

#endif
