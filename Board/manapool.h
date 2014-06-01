#ifndef ___manapool___
#define ___manapool___

#include "card.h"

struct manapool_t {
    int current_mp;
    int max_mp;
};

//init max & current mp to 0
void init_manapool(struct manapool_t *pool);
//returns 1 if there is enough mana
//returns 0 if there is not enough mana
int use_mana(struct manapool_t *pool, int amount);
//gain fixed amount of mana (cannot be more than max_mp)
void gain_mana(struct manapool_t *pool, int gain);
//fills pool
void fill_pool(struct manapool_t *pool);
//increments max_mana by 1
void add_max_mana(struct manapool_t *pool);
//returns 1 if can put card
//returns 0 if can not put card
int can_put_card(struct card_t card, struct manapool_t pool);

#endif
