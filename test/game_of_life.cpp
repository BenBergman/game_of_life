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


TEST_GROUP(Coordinates)
{
};

TEST(Coordinates, CanIterateOverEmptyListOfCoordinates)
{
	Coords coords = new_Coords();
	CHECK_EQUAL(0, Coords_Count(&coords));

	int loop_counter = 0;
	for (Coord coord = Coords_First(&coords); !compare_coords(coord, NullCoord()); coord = Coords_Next(&coords)) {
		loop_counter++;
	}

	CHECK_EQUAL(0, loop_counter);
}

TEST(Coordinates, Iterator)
{
	Coords coords = new_Coords();
	CHECK(!compare_coords(Coords_First(&coords), NullCoord()));
}

TEST(Coordinates, CanAddCoordinateToList)
{
	Coords coords = new_Coords();
	Coord coord = new_Coord(3, 8);
	Coords_Add(&coords, coord);
	CHECK_EQUAL(1, Coords_Count(&coords));

	int loop_counter = 0;
	for (coord = Coords_First(&coords); !compare_coords(coord, NullCoord()); coord = Coords_Next(&coords)) {
		loop_counter++;
		CHECK_EQUAL(3, coord.x);
		CHECK_EQUAL(8, coord.y);
	}

	CHECK_EQUAL(1, loop_counter);
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
