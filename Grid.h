/*
The Grid object
*/

#pragma once

#include "Cell.h"
#include <iostream>
#include <string>

// To make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

class Grid
{

public:

	Grid(int32 Rows, int32 Columns);
	~Grid();

	// Methods
	Cellz* GetCell(int32 Row, int32 Column);
	int32 GetGridSize();
	virtual FString ContentsOf(Cellz* Cellz);
	void OutputString();

	Cellz** Cells() { return _cells; }
	int32 NumRows() { return _numRows; }
	int32 NumColumns() { return _numColumns; }

private:

	// The 2D array of Cells is defined as a pointer to a pointer to an Cellz (Cellz**), and is set to point to array of pointers to Cells.
	Cellz** _cells;

	// The vertical dimension of this Grid.
	int32 _numRows;

	// The horizontal dimension of this Grid.
	int32 _numColumns;

	int32 _defaultRows;
	int32 _defaultColumns;

	void Prepare();
	void Configure_Cells();
};
