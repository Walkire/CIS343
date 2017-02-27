#ifndef H_CONNECT4_ENGINE
#define H_CONNECT4_ENGINE

int place_token(int player, int column, int num_rows,
	int num_columns, int board[num_rows][num_columns]);

int winner(int num_rows, int num_columns, int length_to_win,
	int array[num_rows][num_columns]);

int verticalWin(int num_rows, int num_columns, int length_to_win,
	int array[num_rows][num_columns]);

int horizontalWin(int num_rows, int num_columns, int length_to_win,
        int array[num_rows][num_columns]);

int readColumn(int column, int num_rows, int num_columns,
	int board[num_rows][num_columns]);

int diag_leftWin (int num_rows, int num_columns, int length_to_win,
        int array[num_rows][num_columns]);

int diag_rightWin (int num_rows, int num_columns, int length_to_win,
        int array[num_rows][num_columns]);

void printBoard (int num_rows, int num_columns, int board[num_rows][num_columns]);

#endif
