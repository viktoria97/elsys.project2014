#include "manapool.h"
#include <stdio.h>

void manapool_create(struct manapool_t *pool)
{
pool -> mana_now = 1; 
pool -> max = 1;
}

int mana_get (struct manapool_t *pool, int get)
{
    	pool -> mana_now -=get;
    	return 0;
}

int mana_push (struct manapool_t *pool, int add)
{
    	pool -> mana_now += add;
	if(add > pool->max) pool -> mana_now = pool->max;
    	return 0;
}

int can_put_card(struct card_t card_to_put, struct manapool_t pool)
{
    	if (pool.mana_now>=card_to_put.mana)
        return 1;
    	else
        return 0;
}
