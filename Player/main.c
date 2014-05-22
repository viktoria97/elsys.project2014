#include <stdio.h>
#include "player.h"

int main() {
struct card_t card1 = {"Card", 3, 3, 3};
struct card_t card2 = {"Card", 4, 4, 4};
struct card_t card3 = {"Card", 5, 5, 5};
struct player_t pl = {"Player", 30, {0}, {0}, {1, 1}};
int i, j = 0;
for(i = 0; i < 30; i++) {
	j++;
	switch(j) {
		case 1:
		pl.deck.card[i] = card1;
		break;
		case 2:
		pl.deck.card[i] = card2;
		case 3:
		pl.deck.card[i] = card3; 
	}
	if(j == 3) j = 0;
}
pl.deck.top = 30;
turn_begin(&pl);
turn_begin(&pl);
turn_begin(&pl);
print_player(pl);
printf("play: ");
print_card(play_card_from_hand(&pl, 0));
print_player(pl);
change_hp(&pl, -5);
print_player(pl);
return 0;
}
