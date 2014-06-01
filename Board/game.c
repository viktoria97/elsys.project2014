#include <stdio.h>
#include "board.h"

int main() {
	struct board_t board;
	int side;
	int card;
	int AI, FULL; //FULL flags the AI bot when the board has no empty slots
	char ch;

	
	game_begin(&board, &side, &AI);
	while( !winner(board) ) {
		turn_begin(&board.pl[side]);
		
	
	}
	print_winner(board);
	return 0;
}
