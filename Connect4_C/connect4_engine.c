#include <stdio.h>
#include "connect4_engine.h"

int place_token(int player, int column, int num_rows,
	int num_columns, int board[num_rows][num_columns]) {

	int row = -1;
	int isEmpty = readColumn(column, num_rows, num_columns, board);

	if (isEmpty < 0) {
		return -1;
	}
	
	else {
		row = readColumn(column, num_rows, num_columns, board);
		board[row][column-1] = player;
		return player;
	}
}

int winner(int num_rows, int num_columns, int length_to_win,
	int array[num_rows][num_columns]) {
        
        int wins[4] = {-1};

	wins[0] = verticalWin(num_rows, num_columns,
				length_to_win, array);
	
	wins[1] = horizontalWin(num_rows, num_columns,
                                length_to_win, array);
	
	wins[2] = diag_leftWin(num_rows, num_columns,
                                length_to_win, array);
	
	wins[3] = diag_rightWin(num_rows, num_columns,
                                length_to_win, array);

	for (int i = 0; i < 4; i++) {
        if (wins[i] == 0)
          return 0;
        if (wins[i] == 1)
          return 1;
        }

	return -1;
}

int verticalWin(int num_rows, int num_columns, int length_to_win,
	int array[num_rows][num_columns]) {

	int trackedPlayer = -1;
	int winCounter = 0;
	
	for (int col_index = 0; col_index < num_columns; col_index++) {
		for (int row_index = num_rows-1; row_index > -1; --row_index) {

			int contains = array[row_index][col_index];
		        
		       	if((winCounter == 0) && (contains != -1)) {
				++winCounter;
			}
			if ((contains == array[row_index - 1][col_index])&& (contains != -1)) {
			  ++winCounter;
			  trackedPlayer = array[row_index][col_index];
			} 
			else {
			  winCounter = 0;
			  trackedPlayer = -1;
			}
			if (winCounter == length_to_win) {
			  return trackedPlayer;
			}	
		}
	}

	return -1;
}

int horizontalWin(int num_rows, int num_columns, int length_to_win,
        int array[num_rows][num_columns]) {

       	int trackedPlayer = -1;
	int winCounter = 0;
	
	for (int row_index = 0; row_index < num_rows; row_index++) {
		for (int col_index = 0; col_index < num_columns-1; col_index++) {

			int contains = array[row_index][col_index];
		        
		       	if((winCounter == 0) && (contains != -1)) {
				++winCounter;
			}
			if ((contains == array[row_index][col_index+1])&& (contains != -1)) {
			  ++winCounter;
			  trackedPlayer = array[row_index][col_index];
			} 
			else {
			  winCounter = 0;
			  trackedPlayer = -1;
			}
			if (winCounter == length_to_win) {
			  return trackedPlayer;
			}	
		}
	}

	return -1;
}

int diag_leftWin (int num_rows, int num_columns, int length_to_win,
		  int array[num_rows][num_columns]) {

    int winCounter = -1;
    int counter = 0;

    for (int x = 2; x < num_rows * 2 - 3; x++) {
        counter = 0;
        if (x < num_rows) {
            counter = 0;
        } else {
            counter = x - num_rows + 1;
        }
        winCounter = -1;
        for (int y = counter; y <= x - counter; y++) {
            int row_index = y;
            int col_index = (num_rows - 1) - (x - y);
            if ((winCounter == 0) && (array[row_index][col_index] != -1)) {
                ++winCounter;
            }
            if ((array[row_index - 1][col_index - 1] == array[row_index][col_index]) &&
                (array[row_index][col_index] != -1)) {
                ++winCounter;
            } else {
                winCounter = 0;
            }
            if (winCounter >= length_to_win) {
                return array[row_index][col_index];
            }
        }
    }
    return -1;
}

int diag_rightWin (int num_rows, int num_columns, int length_to_win,
        int array[num_rows][num_columns]) {

    int winCounter = -1;
    int counter = 0;

    for (int x = 2; x < num_rows * 2 - 3; x++) {
        counter = 0;
        if (x < num_rows) {
            counter = 0;
        } else {
            counter = x - num_rows + 1;
        }
        winCounter = -1;
        for (int y = counter; y <= x - counter; y++) {

            int row_index = y;
            int col_index = x - y;

            if ((winCounter == 0) && (array[row_index][col_index] != -1)) {
                ++winCounter;
            }
            if ((array[row_index - 1][col_index + 1] == array[row_index][col_index]) &&
                (array[row_index][col_index] != -1)) {
                ++winCounter;
            } else {
                winCounter = 0;
            }
            if (winCounter >= length_to_win) {
                return array[row_index][col_index];
            }
        }
    }
    return -1; 
}

int readColumn(int column, int num_rows, int num_columns,
	 int board[num_rows][num_columns]) {
	
	int row_index = num_rows -1;
	int col_placedIndex = column -1;

	for (row_index; row_index > -1; --row_index) {
		if (board[row_index][col_placedIndex] == -1) {
			return row_index;
		}
	}

	return -1;
}

void printBoard(int num_rows, int num_columns, int board[num_rows][num_columns]) {
	
	int player = 0;

	for (int x= 1; x < num_columns+1 ; x++) {
		printf("*%d*", x);
	}

	printf("\n");

	for (int row_index = 0; row_index < num_rows; row_index++) {
		for (int col_index = 0; col_index < num_columns; col_index++) {
			if (board[row_index][col_index] == -1) {
				printf("[ ]");
			}
			else {
				player = board[row_index][col_index];
				printf("[%d]",player);
			}
		}
		printf("\n");
	}	
}
