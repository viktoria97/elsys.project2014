#ifndef ___deck___
#define ___deck___

#include "card.h"
#define deck_size 30

struct deck_t {
    struct card_t card[deck_size];
    int top;
};

//init deck to 0
void init_deck(struct deck_t *deck);

//returns 1 if succsess
//returns 0 if deck is full
int push_card(struct card_t card_to_push, struct deck_t *player_deck);

//returns 1 if succsess
//returns 0 if deck is empty
int draw_card(struct deck_t *player_deck, struct card_t *card);

//returns 1 if succsess
//returns 0 if deck is empty
int look_card(struct deck_t player_deck, struct card_t *card);

#endif
