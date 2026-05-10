#pragma once

#include <string>
#include "Grid.h"

class Player {
public:
	Player(const std::string&, GridPiece);
	inline std::string getName() const { return name; }
	inline GridPiece getPieceColor() const { return piece; }

private:
	std::string name;
	GridPiece piece;
};