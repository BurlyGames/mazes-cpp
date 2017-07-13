/*
The individual Cell object implementation
*/

#include "Cell.h"
#include <vector>

Cell::Cell()
{
	return;
}

Cell::Cell(int32 Row, int32 Column, FString Name)
{
	Cell::_row = Row;
	Cell::_column = Column;
	Cell::_name = Name;
	Cell::Name = Name;

	Links.reserve(4);

	return;
}

bool Cell::IsLinked(Cell* cell)
{
	// Check through the local Links collection to see if the passed Cell is present
	std::vector<Cell*>::iterator it = std::find(Links.begin(), Links.end(), cell);

	// Cell was found before end
	return (it != Links.end());
}

void Cell::Link(Cell* cell)
{
	Links.push_back(cell);

	return;
}

void Cell::Unlink(Cell* cell)
{
	return;
}

std::vector<Cell*> Cell::GetNeighbors()
{
	Cell::Neighbors.clear();

	if (Cell::North != NULL) Cell::Neighbors.push_back(Cell::North);
	if (Cell::South != NULL) Cell::Neighbors.push_back(Cell::South);
	if (Cell::East != NULL) Cell::Neighbors.push_back(Cell::East);
	if (Cell::West != NULL) Cell::Neighbors.push_back(Cell::West);

	return Cell::Neighbors;
}
