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

TEST(World, AllCellsInNewWorldAreDead)
{
	World world;
	for (int i = 0; i < World_CellCount(world); i++) {
		CHECK(Cell_IsDead(World_GetCell(world, i)));
	}
}

TEST_GROUP(Coordinate)
{
};

TEST(Coordinate, CanIterateOverEmptyListOfCoordinates)
{
	Coords coords;
	for (Coord coord = Coords_First(coords); !compare_coords(coord, NullCoord()); coord = Coords_Next(coords)) {
	}
}
