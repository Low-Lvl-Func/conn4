#pragma once

#include <vector>
#include <unordered_map>
#include <functional>
#include <memory>

#include "Grid.h"
#include "Player.h"

class Game {
public:
	Game(Grid*, int connN, int targetScore, std::vector<std::unique_ptr<Player>>&);
	void printBoard();
	std::pair<int, int> playMove(const Player*);
	Player* playRound();
	void play();

private:
	Grid* grid;
	int connN, targetScore;
	std::vector<std::reference_wrapper<Player>> players;
	std::unordered_map<std::string, int> score;
};