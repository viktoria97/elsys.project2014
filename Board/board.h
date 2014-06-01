#ifndef ___BOARD___
#define ___BOARD___

#include "player.h"
#define border_count 60

struct board_t {
	struct card_t slot[2][5];
	struct player_t pl[2];	
};

//Waits for enter to be pressed
void press_key();
//Uses press_key(); in fixes conditions
void wait_for_key(int AI, int side);
//init board to 0
void init_board(struct board_t *board);
//prints fixed amount of chars
void print_border(char ch);
//prints cards on field[side]
void print_field(struct board_t board, int side);
//prints the board
void print_board(struct board_t board);
//returns 1 if can play card
//returns 0 if can't play card
int is_slot_empty(struct board_t board, int side, int corr);
//returns 1 if there is free slot on the board
//returns 0 if there is no free slot on the board
int can_play_card(struct board_t board, int side);
//returns 1 if successful
//returns 0 if failure
int play_card(struct board_t *board, struct card_t card, int side);
//allows the user / AI_BOT to play cards
void on_turn(struct board_t *board, int AI, int side);
//cards on board attacks 
//if there are no enemies pl[!side] takes the dmg
void turn_end(struct board_t *board);
//uses turn_end();
//print shits in fixed conditions
//uses press_key()
//changes side to !side
void improved_turn_end(struct board_t *board, int AI, int *side);
//returns 0 if there is no winner
//returns 1 if player1 is the winner
//returns 2 if player2 is the winner
int winner(struct board_t board);
//prints the winner's name
void print_winner(struct board_t board);
//returns 1 if successfully loaded
//returns 0 if loading failed
int load_deck_from_file(struct board_t *board, int side, char *filename);
//init player to starting stats
//reads names
//load decks
void game_begin(struct board_t *board, int *side, int *AI);
//plays cards sorted by mana_cost
//FULL flags the AI(bot) when the board has no empty slots
//returns the index of the card with the lowest mp_cost or -1 if there is no option to play
int AI_bot(struct player_t player, int FULL);
//atk:hp=1:balance_atk
//mp:(atk+hp)=1:balance_mp
//returns 1 if deck generation was successful
//returns 0 if failure
int card_generator(int cards_to_generate, float balance_atk, float balance_mp, char *filename);
//generate deck with parameters choosed by the user
void generate_deck();

#endif
