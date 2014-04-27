#include <stdio.h>
#include  “deck.h”
int push_card(struct card_t card_to_push, struct deck_t *player_deck)
{
if (player_deck ->top <= 30)
	{ 
	player_deck->card[player_deck->top++] = card_to_push; 
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


int look_card(struct deck_t player_deck, struct card_t *card_return)
{
        if(player_deck.top > 0) 
	{
        *card_return = player_deck.card[--player_deck.top];
        return 1; 
	} 
else  printf ("Deck is empty!”);
}


