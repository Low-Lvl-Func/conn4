#include "Grid.h"
#include "Player.h"
#include "Game.h"

int main() {
	int CONN_N = 4, TARGET_SCORE = 3;
	Grid grid(6, 7);
	std::vector<std::unique_ptr<Player>> players;
	players.emplace_back(std::make_unique<Player>("Player1", GridPiece::RED));
	players.emplace_back(std::make_unique<Player>("Player2", GridPiece::YELLOW));
	Game game(&grid, CONN_N, TARGET_SCORE, players);
	game.play();
	return 0;
}