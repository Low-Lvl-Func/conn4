#include "Game.h"

#include <iostream>
#include <cassert>

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

std::pair<int, int> Game::playMove(const Player& player) {
	using std::cout, std::endl, std::cin;
	this->printBoard();
	cout << player.getName() << "'s turn" << endl;
	const int colCnt = this->grid->getColsCnt();
	cout << "Column(0 - " << colCnt - 1 << "): ";
	int moveCol;
	cin >> moveCol;
	int moveRow = this->grid->placePiece(moveCol, player.getPieceColor());
	return std::make_pair(moveRow, moveCol);
}

Player* Game::playRound() {
	while (true) {
		for (const auto& p_wrapper : this->players) {

			// Unpack the actual Player reference from the wrapper
			Player& p = p_wrapper.get();

			const auto& [row, col] = this->playMove(p);
			GridPiece piece = p.getPieceColor();

			if (this->grid->checkWin(this->connN, row, col, piece)) {
				this->score[p.getName()]++;

				// 3. Return the address of the actual Player object
				return &p;
			}
		}
	}
	return nullptr;
}

void Game::play() {
	using std::cout, std::endl;
	int maxScore = 0;
	Player* winner = nullptr;
	while (maxScore < this->targetScore) {
		winner = playRound();
		cout << winner->getName() << " won the round" << endl;
		maxScore = std::max(this->score[winner->getName()], maxScore);
		this->grid->initGrid(); // reset grid
	}
	assert(winner != nullptr);
	cout << winner->getName() << " won the game" << endl;
}