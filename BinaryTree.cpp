/*

	BinaryTree maze algorithm
	Walk each Cellz in the Grid one time, establishing either a North or East connection.

	Take in a pointer to a Grid
	Run the algorithm on the grid and return the pointer

*/

#include <vector>
#include <random>
#include <chrono>
#include "Grid.h"
#include "BinaryTree.h"

Grid* BinaryTree::Process(Grid* grid)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Loop through each cell
	for (int row = 0; row < grid->NumRows(); row++)
	{
		for (int col = 0; col < grid->NumColumns(); col++)
		{
			// Build up a list of the North and East neighbors
			std::vector<Cellz*> _neighbors(4);
			int32 _neighborCount = 0;

			Cellz* target = &grid->Cells()[row][col];

			// If there is a cell to the North, then add it
			if (grid->Cells()[row][col].North != NULL)
			{
				_neighbors.insert(_neighbors.begin(), grid->Cells()[row][col].North);
				_neighborCount++;
			}

			// If there is a cell to the East, then add it
			if (grid->Cells()[row][col].East != NULL)
			{
				_neighbors.insert(_neighbors.begin(), grid->Cells()[row][col].East);
				_neighborCount++;
			}

			// Pick an item at random from the N/E neighbors
			if (_neighborCount > 0)
			{
				std::uniform_int_distribution<int> distribution(0, _neighborCount - 1);
				int dice_roll = distribution(generator);

				target->Link(_neighbors[dice_roll]);
				_neighbors[dice_roll]->Link(target);
			}
		}
	}

	return grid;
}
