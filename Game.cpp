#include "Game.h"

#include <iostream>

Game::Game(
	Grid* grid, 
	int connN, 
	int targetScore,
	std::vector<std::unique_ptr<Player>>& players
) : grid(grid), connN(connN), targetScore(targetScore) {
	for (const auto& player : players) {
		this->players.push_back(std::ref(*player));
	}
}

void Game::printBoard() {
	using std::cout, std::endl;
	const auto& grid = this->grid->getGrid();
	constexpr unsigned LINE_LEN = 30;
	cout << std::string(LINE_LEN, '-') << endl;
	for (size_t i = 0; i < grid.size(); i++) {
		std::string row;
		for (int piece : grid[i]) {
			row += static_cast<char>(piece);
		}
		cout << row << endl;
	}
	cout << std::string(LINE_LEN, '-') << endl;
}

std::pair<int, int> Game::playMove(const Player* player) {
	using std::cout, std::endl, std::cin;
	this->printBoard();
	cout << player->getName() << "'s turn" << endl;
	const int colCnt = this->grid->getColsCnt();
	cout << "Column(0 - " << colCnt - 1 << "): ";
	int moveCol;
	cin >> moveCol;
	int moveRow = this->grid->placePiece(moveCol, player->getPieceColor());
	return std::make_pair(moveRow, moveCol);
}

Player* Game::playRound() {
	return NULL;
}

void Game::play() {

}