#pragma once
#include "Grid.h"

class DistanceGrid : public Grid
{

public:
	DistanceGrid(int32 Rows, int32 Columns) : Grid(Rows, Columns) {};

	virtual FString DistanceGrid::ContentsOf(Cellz* Cellz);
};
