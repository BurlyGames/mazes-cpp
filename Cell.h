/*
The individual Cell object
*/

#pragma once
#include <string>
#include <vector>

// To make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

class Cell
{
public:

	// Constructors
	Cell();
	Cell(int32 Row, int32 Column, FString Name);

	// Members
	FString Name;
	Cell* North;
	Cell* South;
	Cell* East;
	Cell* West;
	std::vector<Cell*> Links;
	std::vector<Cell*> Neighbors;

	// Methods
	bool IsLinked(Cell* cell);
	void Link(Cell* cell);
	void Unlink(Cell* cell);
	std::vector<Cell*> GetNeighbors();

	// Distances GetDistances();

private:

	int32 _row, _column;
	FString _name;

	Cell* _north;
	Cell* _south;
	Cell* _east;
	Cell* _west;
};

