#include "card.h"
int attack (struct card_t*attacker, struct card_t*defender)
{
if ((defender->hp) - (attacker->damage) <=0)
	&& ((attacker->hp) -(defender->damage) <=0)
		{
		(attacker->hp -=defender->damage);
		(defender->hp -=attacker->damage);
		return 0;
		}

if (attacker->damage >=defender->hp)
		{
		(attacker->hp -=defender->damage);
		(defender->hp -=attacker->damage);
		return 1;
		}

if (defender->damage >=attacker->hp)
		{
		(attacker->hp -=defender->damage);
		(defender->hp) -=attacker->damage);
		return 2;
		}

if (((defender->hp) - (attacker->damage)) >0 
	&& ((attacker->hp) - (defender->damage)) >0))
		{
		(attacker->hp -=defender->damage);
		(defender->hp -=attacker->damage);
		return 3;
		}
}

