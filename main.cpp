// main.cpp : Defines the entry point for the console application.
//

#include "DistanceGrid.h"
#include "BinaryTree.h"
#include "Sidewinder.h"

using FText = std::string;

int main()
{
	// Generate a new Grid
	DistanceGrid* _grid = new DistanceGrid(10, 10);

	// Process it by the BinaryTree maze algorithm
	Sidewinder().Process(_grid);

	// Print the output
	_grid->OutputString();

	// Keep the window open until user enters 'x'
	FText Response = "";
	getline(std::cin, Response);
	if (Response != "x")
	{
		delete _grid;
		return main();
	}

	return 0;
}
