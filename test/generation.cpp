#include <stdio.h>
#include "CppUTest/TestHarness.h"

extern "C"
{
#include "generation.h"
}

TEST_GROUP(Generation)
{
};

/*
TEST(Generation, CanInitializeNewCoordinate)
{
	Coord coord = new_Coord(1, 2);
	CHECK_EQUAL(1, coord.x);
	CHECK_EQUAL(2, coord.y);

	coord = new_Coord(6, 4);
	CHECK_EQUAL(6, coord.x);
	CHECK_EQUAL(4, coord.y);
}
*/

TEST(Generation, NewGenerationStartsAllDead)
{
    Generation gen = Generation_Create();

    CHECK_EQUAL(0, Generation_GetLiveCellCount(gen));

    Generation_Destroy(gen);
}
