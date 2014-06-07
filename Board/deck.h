#ifndef deckhead
#define deckhead

#include "card.h"

struct deck_t{
    int top;
    struct card_t card[30];
};

void print_deck(struct deck_t deck);
int push_card(struct card_t card_to_push, struct deck_t *deck); 
int draw_card(struct deck_t *deck, struct card_t *card); 
int look_card(struct deck_t deck, struct card_t *card_to_look); 

#endif
