#include "manapool.h"
#include "card.h"

void init_manapool(struct manapool_t *pool) {
	pool->current_mp = 0;
	pool->max_mp = 0;
}

int use_mana(struct manapool_t *pool, int amount) {
    if(amount > pool->current_mp) return 0;
    pool->current_mp -= amount;
    return 1;
}

void gain_mana(struct manapool_t *pool, int gain) {
    if(gain > pool->max_mp){
        pool->current_mp = pool->max_mp;
    } else {
        pool->current_mp += gain;
    }
}

void fill_pool(struct manapool_t *pool) {
	pool->current_mp = pool->max_mp;
}

void add_max_mana(struct manapool_t *pool) {
	pool->max_mp++;
}

int can_put_card(struct card_t card, struct manapool_t pool) {
    return card.mana_cost > pool.current_mp ? 0 : 1;
}
