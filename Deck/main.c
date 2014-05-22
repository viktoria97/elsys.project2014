#include <stdio.h>
#include "deck.h"

int main() {
struct card_t card = {"card", 3, 3, 3};
struct deck_t deck;
push_card(card, &deck);
push_card(card, &deck);
push_card(card, &deck);
print_deck(deck);
draw_card(&deck, &card);
printf("draw: ");
print_card(card);
print_deck(deck);
look_card(deck, &card);
printf("look: ");
print_card(card);
print_deck(deck);
return 0;
}
