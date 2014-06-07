#ifndef cardhead
#define cardhead

struct card_t
{
char *name;
int mana;
int damage;
int hp;
};

void print_card(struct card_t card);
int attack(struct card_t *attacker, struct card_t *defender);

#endif
