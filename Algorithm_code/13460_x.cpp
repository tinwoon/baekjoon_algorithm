#include <iostream>
#include <vector>


std::vector< std::vector<char> > board;
std::vector<char> initialize_row;

struct red_location {
	int row;
	int col;
}Red_location;

struct blue_location {
	int row;
	int col;
}Blue_location;

struct hole_location {
	int row;
	int col;
}Hole_location;

void take_board(int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%c", &board[i][j]);
			switch (board[i][j]) {
				case 'R':
					Red_location.row = i;
					Red_location.col = j;
					break;
				case 'B':
					Blue_location.row = i;
					Blue_location.col = j;
					break;
				case 'O':
					Hole_location.row = i;
					Hole_location.col = j;
					break;

			}
				
		}
	}
}

void calculate_min(std::vector< std::vector<char> >	&board) {

}

void left(std::vector< std::vector<char> > &board, int row, int col) {
	int how_much_loop = col;
	while (how_much_loop--) {
		if (Red_location.col < Blue_location.col) {

			if (board[Red_location.row][Red_location.col - 1] == '.') {
				board[Red_location.row][Red_location.col] = '.';
				Red_location.col--;
				board[Red_location.row][Red_location.col] = 'R';
			}
			if (board[Blue_location.row][Blue_location.col - 1] == '.') {
				board[Blue_location.row][Blue_location.col] = '.';
				Blue_location.col--;
				board[Blue_location.row][Blue_location.col] = 'B';
			}

		}
		else if (Red_location.col > Blue_location.col) {

			if (board[Blue_location.row][Blue_location.col - 1] == '.') {
				board[Blue_location.row][Blue_location.col] = '.';
				Blue_location.col--;
				board[Blue_location.row][Blue_location.col] = 'B';
			}
			if (board[Red_location.row][Red_location.col - 1] == '.') {
				board[Red_location.row][Red_location.col] = '.';
				Red_location.col--;
				board[Red_location.row][Red_location.col] = 'R';
			}

		}
	}
	
}

void right(std::vector< std::vector<char> >& board, int row, int col) {
	int how_much_loop = col;
	while (how_much_loop--) {
		if (Red_location.col > Blue_location.col) {
			if (board[Red_location.row][Red_location.col + 1] == '.') {
				board[Red_location.row][Red_location.col] = '.';
				Red_location.col++;
				board[Red_location.row][Red_location.col] = 'R';
			}
			if (board[Blue_location.row][Blue_location.col + 1] == '.') {
				board[Blue_location.row][Blue_location.col] = '.';
				Blue_location.col++;
				board[Blue_location.row][Blue_location.col] = 'B';
			}
		}
		else if (Red_location.col < Blue_location.col) {
			if (board[Blue_location.row][Blue_location.col + 1] == '.') {
				board[Blue_location.row][Blue_location.col] = '.';
				Blue_location.col++;
				board[Blue_location.row][Blue_location.col] = 'B';
			}
			if (board[Red_location.row][Red_location.col + 1] == '.') {
				board[Red_location.row][Red_location.col] = '.';
				Red_location.col++;
				board[Red_location.row][Red_location.col] = 'R';
			}
		}
	}

}

int main() {
	int row, col;
	scanf("%d %d",&row,&col);
	take_board(row,col);


	return 0;
}
