#ifndef _CARD_
#define _CARD_
#define _GAME_

struct card_t
{
char name [10];
int mana;
int damage;
int hp;
};

int attack(struct card_t*attacker,struct cart_t*defender);
#endif
