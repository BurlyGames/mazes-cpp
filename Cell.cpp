/*
The individual Cellz object implementation
*/

#include "Cell.h"
#include <vector>

Cellz::Cellz()
{
	return;
}

Cellz::Cellz(int32 Row, int32 Column, FString Name)
{
	Cellz::_row = Row;
	Cellz::_column = Column;
	Cellz::_name = Name;
	Cellz::Name = Name;

	Links.reserve(4);

	return;
}

bool Cellz::IsLinked(Cellz* cell)
{
	// Check through the local Links collection to see if the passed Cellz is present
	std::vector<Cellz*>::iterator it = std::find(Links.begin(), Links.end(), cell);

	// Cellz was found before end
	return (it != Links.end());
}

void Cellz::Link(Cellz* cell)
{
	Links.push_back(cell);

	return;
}

void Cellz::Unlink(Cellz* cell)
{
	return;
}

std::vector<Cellz*> Cellz::GetNeighbors()
{
	Cellz::Neighbors.clear();

	if (Cellz::North != NULL) Cellz::Neighbors.push_back(Cellz::North);
	if (Cellz::South != NULL) Cellz::Neighbors.push_back(Cellz::South);
	if (Cellz::East != NULL) Cellz::Neighbors.push_back(Cellz::East);
	if (Cellz::West != NULL) Cellz::Neighbors.push_back(Cellz::West);

	return Cellz::Neighbors;
}
