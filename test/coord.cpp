#include <stdio.h>
#include "CppUTest/TestHarness.h"

extern "C"
{
#include "coord.h"
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

