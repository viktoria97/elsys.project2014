#include <stdio.h>
#include  "deck.h"

void print_deck(struct deck_t deck) {
int j;
for(j = 0; j < deck.top; j++)
{
	print_card(deck.card[j]);
}
}

int push_card(struct card_t card_to_push, struct deck_t *deck)
{
if (deck->top <= 30)
{ 
	deck->card[deck->top++] = card_to_push; 
    	return 1;
}
	else printf("Deck is full!");
}

int draw_card(struct deck_t *player_deck, struct card_t *card)
{
if (player_deck->top >0 )
{
        *card = player_deck->card[--player_deck->top];
}
        else printf ("Deck is empty!");
}


int look_card(struct deck_t player_deck, struct card_t *card_to_look)
{
        if(player_deck.top > 0) 
{
        *card_to_look = player_deck.card[--player_deck.top];
        return 1; 
} 
else  printf ("Deck is empty!");
}


