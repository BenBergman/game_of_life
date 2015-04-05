#include <stdio.h>
#include "CppUTest/TestHarness.h"

extern "C"
{
#include "game_of_life.h"
}

TEST_GROUP(Cell)
{
};

TEST(Cell, NewCellsAreDead)
{
    Cell cell;
    CHECK(Cell_IsDead(cell));
}

TEST_GROUP(World)
{
};

TEST(World, Iterator)
{
	World world = World_Create();

	CHECK(!compare_cells(World_FirstCell(world), NullCell()));

	World_Destroy(world);
}

TEST(World, AllCellsInNewWorldAreDead)
{
	World world = World_Create();

	int loop_counter = 0;
	for (Cell cell = World_FirstCell(world); !compare_cells(cell, NullCell()); cell = World_NextCell(world)) {
		loop_counter++;
		CHECK(Cell_IsDead(cell));
	}

	CHECK(loop_counter != 0);
	World_Destroy(world);
}


TEST(World, CanGetNeighbourCells)
{
	Coord a = new_Coord(3, 4);
	World world = World_Create();

	Coords coords = World_GetNeighbourCoords(world, a);
	CHECK_EQUAL(8, Coords_Count(coords));

	Coords_Destroy(coords);
	World_Destroy(world);
}
