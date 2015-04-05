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


TEST_GROUP(Coordinates)
{
};

#define FOR_EACH_COORD(Y, X) for (Coord Y = Coords_First(X); !compare_coords(Y, NullCoord()); Y = Coords_Next(X))
TEST(Coordinates, CanIterateOverEmptyListOfCoordinates)
{
	Coords coords = Coords_Create();

	CHECK_EQUAL(0, Coords_Count(coords));

	int loop_counter = 0;
	FOR_EACH_COORD(coord, coords) {
		loop_counter++;
	}

	CHECK_EQUAL(0, loop_counter);

	Coords_Destroy(coords);
}

TEST(Coordinates, Iterator)
{
	Coords coords = Coords_Create();
	CHECK(compare_coords(Coords_First(coords), NullCoord()));
	Coords_Destroy(coords);
}

TEST(Coordinates, CanAddCoordinateToList)
{
	Coords coords = Coords_Create();

	Coord a = new_Coord(3, 8);
	Coords_Add(coords, a);
	CHECK_EQUAL(1, Coords_Count(coords));

	int loop_counter = 0;
	FOR_EACH_COORD(coord, coords) {
		loop_counter++;
		CHECK_EQUAL(3, coord.x);
		CHECK_EQUAL(8, coord.y);
	}

	CHECK_EQUAL(1, loop_counter);

	Coords_Destroy(coords);
}

TEST(Coordinates, CanAddMultipleCoordinatesToList)
{
	Coords coords = Coords_Create();

	Coord a = new_Coord(3, 8);
	Coord b = new_Coord(9, 4);
	Coords_Add(coords, a);
	Coords_Add(coords, b);
	CHECK_EQUAL(2, Coords_Count(coords));

	Coord coord = Coords_First(coords);
	CHECK(compare_coords(coord, a));

	coord = Coords_Next(coords);
	CHECK(compare_coords(coord, b));

	coord = Coords_Next(coords);
	CHECK(compare_coords(coord, NullCoord()));

	Coords_Destroy(coords);
}


TEST_GROUP(Coordinate)
{
};

TEST(Coordinate, CanInitializeNewCoordinate)
{
	Coord coord = new_Coord(1, 2);
	CHECK_EQUAL(1, coord.x);
	CHECK_EQUAL(2, coord.y);

	coord = new_Coord(6, 4);
	CHECK_EQUAL(6, coord.x);
	CHECK_EQUAL(4, coord.y);
}

TEST(Coordinate, SimilarCoordsAreComparedEqual)
{
	Coord a = new_Coord(1, 2);
	Coord b = new_Coord(1, 2);
	CHECK(compare_coords(a, b));
}

TEST(Coordinate, RegularCoordCanBeDifferentiatedFromNullCoord)
{
	Coord a = new_Coord(3, 4);
	Coord b = NullCoord();
	CHECK(!compare_coords(a, b));
}

TEST(Coordinate, CanGetNeighbourCells)
{
	Coord a = new_Coord(3, 4);

	Coords coords = Coord_GetNeighbourCoords(a);
	CHECK_EQUAL(8, Coords_Count(coords));

	Coords_Destroy(coords);
}
