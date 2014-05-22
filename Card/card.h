#ifndef cardhead
#define cardhead


struct card_t
{
char *name;
int mana;
int damage;
int hp;
};

int attack(struct card_t *attacker,struct cart_t *defender);
#endif
