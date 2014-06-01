#include <string.h>
#include "deck.h"

void init_deck(struct deck_t *deck) {
	memset(deck, 0, sizeof(*deck));
	deck->top = 0;
}

int push_card(struct card_t card_to_push, struct deck_t *player_deck){
    if(player_deck->top == deck_size) return 0;
    player_deck->card[player_deck->top++] = card_to_push;
    return 1;
}

int draw_card(struct deck_t *player_deck, struct card_t *card) {
     if(player_deck->top == 0) return 0;
     *card = player_deck->card[--player_deck->top];
     return 1;
}

int look_card(struct deck_t player_deck, struct card_t *card) {
    if(player_deck.top == 0) return 0;
     *card = player_deck.card[--player_deck.top];
     return 1;
}
