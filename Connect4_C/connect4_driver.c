#include <stdio.h>
#include "connect4_engine.h"

int main() {
	
	int EMPTY = -1;

	int board_size = -1;
	int length_to_win = -1;
	int runningGame = 1;
	int currentPlayer = 0;
	int playerInput = -1;
	int placeHolder = -1;
	
	int num_rows = 0;
	int num_columns = 0;

	printf("Enter board size: ");
	scanf("%d", &board_size);

	while (board_size < 3) {
		printf("Board size is invalid!\n");
		printf("Enter borad size: ");
		scanf("%d",&board_size);				
	}

	num_rows = board_size;
	num_columns = board_size;
	int board[num_rows][num_columns];

	for (int row_index = num_rows-1; row_index > -1; --row_index) {
		for (int col_index = num_columns-1; col_index > -1; --col_index) {
			board[row_index][col_index] = EMPTY;
		}
	}

	printf("Enter win size: ");
	scanf("%d", &length_to_win);
 
	while (length_to_win < 3) {
		printf("Win size is invalid!\n");
		printf("Enter win size: ");
		scanf("%d",&length_to_win);				
	}

	while (runningGame == 1) {
		printBoard(num_rows, num_columns, board);
		printf("Player %d, choose a column: ", currentPlayer+1);
		scanf("%d", &playerInput);

		while(playerInput < 1 || playerInput > board_size) {
			printf("Invalid column!\n");
			printf("Player %d, choose a column: ", currentPlayer+1);
			scanf("%d", &playerInput);
                }

		placeHolder = place_token(currentPlayer, playerInput, num_rows, num_columns, board);
		while(placeHolder < 0){
			printf("Column is full!\n");
			printf("Player %d, choose a column: ",currentPlayer+1);
			scanf("%d", &playerInput);
			placeHolder = place_token(currentPlayer,playerInput,num_rows,num_columns,board);
		}

		placeHolder = winner(num_rows, num_columns, length_to_win, board);
		if(placeHolder > -1) {
			printBoard(num_rows,num_columns, board);
			printf("Player %d Wins!!\n", placeHolder+1);
			runningGame = 0;
		}

		if(currentPlayer == 0) {
			currentPlayer = 1;
		}
		else {
			currentPlayer = 0;
		}	

		placeHolder = -1;
	}
	return -1;
}


