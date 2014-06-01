#ifndef ___BOARD___
#define ___BOARD___

#include "player.h"
#define border_count 60

struct board_t {
	struct card_t slot[2][5];
	struct player_t pl[2];	
};



void init_board(struct board_t *board);

void print_border(char ch);

void print_field(struct board_t board, int side);

void print_board(struct board_t board);

int open_slot(struct board_t board, int side, int corr);

int can_play_card(struct board_t board, int side);

int play_card(struct board_t *board, struct card_t card, int side);

void on_turn(struct board_t *board, int AI, int side);

void turn_end(struct board_t *board);

void improved_turn_end(struct board_t *board, int AI, int *side);

int winner(struct board_t board);

void print_winner(struct board_t board);

int load_deck_from_file(struct board_t *board, int side, char *filename);

void game_begin(struct board_t *board, int *side, int *AI);

int AI_bot(struct player_t player, int FULL);


#endif
