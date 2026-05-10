#pragma once

#include <string>
#include "Grid.h"

class Player {
public:
	Player(const std::string&, GridPiece);
	inline std::string getName() { return name; }
	inline GridPiece getPieceColor() { return piece; }

private:
	std::string name;
	GridPiece piece;
};