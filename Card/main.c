#include <stdio.h>
#include "card.h"

int main() {
struct card_t Card1 = {"CARD", 5, 3, 5};
struct card_t Card2 = {"CARD", 5, 6, 4};
struct card_t temp1, temp2;
temp1 = Card1;
temp2 = Card2;
printf("%d\n", attack(&temp1, &temp2));
print_card(temp1);
print_card(temp2);
temp1 = Card1;
temp2 = Card2;
printf("%d\n", attack(&temp2, &temp1));
print_card(temp2);
print_card(temp1);
temp1 = Card1;
temp2 = Card1;
printf("%d\n", attack(&temp1, &temp2));
print_card(temp1);
print_card(temp2);
temp1 = Card2;
temp2 = Card2;
printf("%d\n", attack(&temp1, &temp2));
print_card(temp2);
print_card(temp2);
return 0;
}
