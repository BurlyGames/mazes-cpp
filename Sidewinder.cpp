/*

	Sidewinder maze algorithm
	Process each row of the grid once.  While walking the cells in each row, randomly carve north unless at the north boundary.

	Take in a pointer to a Grid
	Run the algorithm on the grid and return the pointer

	TODO Determine if I should stick to predictable seed so the mazes can be recreated from a simple unsigned Int32
*/

#include <vector>
#include <random>
#include <chrono>
#include "Grid.h"
#include "Sidewinder.h"

Grid* Sidewinder::Process(Grid* grid)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	// Loop through each Row
	for (int row = 0; row < grid->NumRows(); row++)
	{
		std::vector<Cell*> run;
		run.reserve(grid->NumColumns());
		int32 _runCount = 0;

		// Loop through each cell in this row
		for (int col = 0; col < grid->NumColumns(); col++)
		{
			// Add this cell to the run
			Cell* cell = &grid->Cells()[row][col];

			run.push_back(cell);
			_runCount++;

			// Boundary check
			auto _northBoundary = cell->North == NULL;
			auto _eastBoundary = cell->East == NULL;
			auto _5050 = (rand() % 2 == 0);
			auto _shouldCloseOut = _eastBoundary || (!_northBoundary && _5050);

			if (_shouldCloseOut)
			{
				// Pick a cell at random from the current "run" and Link it to the North
				int32 _randomIndex = rand() % _runCount;
				Cell* target = run.at(_randomIndex);

				if (target->North != NULL)
				{
					target->Link(target->North);
					target->North->Link(target);
				}

				// Clear the current "run"
				run.clear();
				_runCount = 0;
			}
			else
			{
				// Link to the East
				cell->Link(cell->East);
				cell->East->Link(cell);
			}
		}
	}

	return grid;
}