/*
The individual Cellz object
*/

#pragma once
#include <string>
#include <vector>

// To make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

class Cellz
{
public:

	// Constructors
	Cellz();
	Cellz(int32 Row, int32 Column, FString Name);

	// Members
	FString Name;
	Cellz* North;
	Cellz* South;
	Cellz* East;
	Cellz* West;
	std::vector<Cellz*> Links;
	std::vector<Cellz*> Neighbors;

	// Methods
	bool IsLinked(Cellz* cell);
	void Link(Cellz* cell);
	void Unlink(Cellz* cell);
	std::vector<Cellz*> GetNeighbors();

	// Distances GetDistances();

private:

	int32 _row, _column;
	FString _name;

	Cellz* _north;
	Cellz* _south;
	Cellz* _east;
	Cellz* _west;
};

