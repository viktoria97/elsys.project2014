#ifndef ___manapool___
#define ___manapool___
#include "card.h"
struct manapool_t
{
    int mana_now;
};

void manapool_create(struct manapool_t *pool);
int mana_get (struct manapool_t *pool, int get);
int mana_push (struct manapool_t *pool, int add);
int can_put_card(struct card_t card, struct manapool_t pool);

#endif
