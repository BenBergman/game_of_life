#include <stdio.h>
#include "CppUTest/TestHarness.h"

extern "C"
{
#include "coords.h"
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

TEST(Coordinates, DuplicateCoordinatesAreNotStored)
{
	Coords coords = Coords_Create();

	Coord a = new_Coord(3, 8);
	Coord b = new_Coord(3, 8);
	Coords_Add(coords, a);
	Coords_Add(coords, b);
	CHECK_EQUAL(1, Coords_Count(coords));

	Coord coord = Coords_First(coords);
	CHECK(compare_coords(coord, a));
	CHECK(compare_coords(coord, b));

	coord = Coords_Next(coords);
	CHECK(compare_coords(coord, NullCoord()));

	Coords_Destroy(coords);
}
