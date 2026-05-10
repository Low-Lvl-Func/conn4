#include "Grid.h"

#include <ranges>

Grid::Grid(int rows, int cols) : rows(rows), cols(cols) {

}

void Grid::initGrid() {
	this->grid.assign(rows, std::vector<int>(cols, GridPiece::EMPTY));
}

int Grid::placePiece(int col, GridPiece piece) {
	if (col < 0 || col >= cols) {
		throw "Invalid column";
	}
	if (piece == GridPiece::EMPTY) {
		throw "Invalid piece";
	}
	for (int row : std::views::iota(0, rows) | std::views::reverse) {
		if (grid[row][col] == GridPiece::EMPTY) {
			grid[row][col] = piece;
			return row;
		}
	}
	return -1;
}

bool Grid::checkWin(int connN, int row, int col, GridPiece piece) {
	// Directions: Horizontal, Vertical, Diagonal (\), Anti-Diagonal (/)
	static const std::vector<std::pair<int, int>> DIRS = {
		{0, 1}, {1, 0}, {1, 1}, {1, -1}
	};
	for (const auto& [dirRow, dirCol] : DIRS) {
		int cnt = 1; // Start with the piece just placed
		for (int side : {-1, 1}) { // Check in both directions along the axis
			int newRow = row + dirRow * side;
			int newCol = col + dirCol * side;
			while (
				newRow >= 0 && newRow < rows &&
				newCol >= 0 && newCol < cols &&
				grid[newRow][newCol] == piece
			) {
				cnt++;
				newRow += (dirRow * side);
				newCol += (dirCol * side);
			}
		}
		if (cnt >= connN) {
			return true;
		}
	}
	return false;
}