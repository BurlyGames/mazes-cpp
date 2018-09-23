/*

The Grid object implementation

// A 1D array of Cells is defined as a pointer to an array of Cells (Cellz*), and is set to point to array of Cells.
// A 2D array of Cells is defined as a pointer to a pointer to a Cellz (Cellz**), and is set to point to array of pointers to Cells.
// A 3D array of Cells is defined as a pointer to a pointer to a pointer to a Cellz (Cellz***), and is set to point to array of pointers to an array of pointers to Cells.
// etc..

// NOTE on getting the Dimension sizes at runtime
// There is no clear way to get the dimension size of dynamically allocated arrays at runtime.
// Options:
//   - Keep track of the dimensioned size along with the object.
//   - Or add an extra element to the array, stash the size at p, and return p+1 to point to the array.

// TODO Reimplement this using vectors instead of arrays

*/

#pragma once

#include "Grid.h"
#include <iostream>

using int32 = int;

Grid::Grid(int32 Rows, int32 Columns)
{
	_numRows = Rows;
	_numColumns = Columns;

	Grid::Prepare();
	Grid::Configure_Cells();
}

Grid::~Grid()
{
	// Deallocate the Cellz arrays
	for (int row = 0; row < Grid::_numRows; row++)
	{
		delete[] _cells[row];
	}
	delete[] _cells;
}

// Set up a fresh 2D array of Cellz instances
void Grid::Prepare()
{
	_cells = new Cellz*[Grid::_numRows];

	int32 _roomNumber = 0;

	// Run through each row, create a Cellz array for each
	for (int row = 0; row < Grid::_numRows; row++)
	{
		_cells[row] = new Cellz[Grid::_numColumns];

		// Initialize each Cellz
		for (int col = 0; col < Grid::_numColumns; col++)
		{
			_cells[row][col] = Cellz(row, col, "Room " + std::to_string(_roomNumber++));
		}
	}

	return;
}

// Tells each Cellz who its immediate neighbors are to the north, south, east, and west
void Grid::Configure_Cells()
{
	for (int row = 0; row < Grid::_numRows; row++)
	{
		for (int col = 0; col < Grid::_numColumns; col++)
		{
			// If not in the first row, then the "north" cell is the previous row, same column
			if (row > 0)
				_cells[row][col].North = &_cells[row - 1][col];
			else
				_cells[row][col].North = NULL;

			// If we're not in the last row, then the "south" cell is the next row, same column
			if ((row + 1) < Grid::_numRows)
				_cells[row][col].South = &_cells[row + 1][col];
			else
				_cells[row][col].South = NULL;

			// If we're not in the first column, then the "west" cell is the same row, previous column
			if (col > 0)
				_cells[row][col].West = &_cells[row][col - 1];
			else
				_cells[row][col].West = NULL;

			// If we're not in the last column, then the "east" cell is the same row, next column
			if ((col + 1) < Grid::_numColumns)
				_cells[row][col].East = &_cells[row][col + 1];
			else
				_cells[row][col].East = NULL;
		}
	}

	return;
}

Cellz* Grid::GetCell(int32 Row, int32 Column)
{
	return &Grid::_cells[Row][Column];
}

int32 Grid::GetGridSize()
{
	return _numRows * _numColumns;
}

FString Grid::ContentsOf(Cellz* Cellz)
{
	return FString("   ");
}

void Grid::OutputString()
{
	std::cout << "\n\n";

	// Top Edge
	std::cout << "+";
	for (int i = 0; i < Grid::_numColumns; i++)
	{
		std::cout << "---+";
	}
	std::cout << "\n";

	// Each Row
	for (int row = 0; row < Grid::_numRows; row++)
	{
		FString topline = "|";
		FString bottomLine = "+";

		for (int col = 0; col < Grid::_numColumns; col++)
		{
			// If East is linked then open, else a wall edge
			FString body = ContentsOf(&Grid::_cells[row][col]);
			FString east_boundary = "|";
			if (Grid::_cells[row][col].IsLinked(Grid::_cells[row][col].East))
			{
				east_boundary = " ";
			}
			else
			{
				east_boundary = "|";
			}

			topline += body + east_boundary;

			// If South is linked then open, else a wall edige
			FString south_boundary = "---";
			if (Grid::_cells[row][col].IsLinked(Grid::_cells[row][col].South))
			{
				south_boundary = "   ";
			}
			else
			{
				south_boundary = "---";
			}

			FString corner = "+";
			bottomLine += south_boundary + corner;
		}

		std::cout << topline << "\n";
		std::cout << bottomLine << "\n";
	}

	std::cout << "\n\n";

	return;
}
