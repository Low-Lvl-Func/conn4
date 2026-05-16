#pragma once

#include <vector>

using Matrix = std::vector<std::vector<int>>;
enum GridPiece { EMPTY = '*', YELLOW = 'Y', RED = 'R' };

class Grid {
public:
	Grid(int, int);
	void initGrid();

	inline Matrix getGrid() { return grid; }
	inline int getColsCnt() { return cols; }

	int placePiece(int col, GridPiece);
	bool checkWin(int conN, int row, int col, GridPiece);
private:
	int rows, cols;
	Matrix grid;
};