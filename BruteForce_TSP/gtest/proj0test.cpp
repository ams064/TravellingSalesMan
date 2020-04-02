#include <vector>
#include <gtest/gtest.h>
#include "proj0.hpp"

namespace{

	TEST(SampleTests, TestCostOfJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> journey = {0, 2, 3, 1};
		EXPECT_TRUE( costOfJourney(distances, journey) == 21);
	}

	TEST(SampleTests, TestFindJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> expected = {0, 2, 3, 1};
		EXPECT_TRUE( tsp_bruteforce(distances, 4) == expected );

	}
TEST(RealTests, Test3_11Vertices)
{
std::vector< std::vector< long > > distances =
{
{0, 193, 130, 174, 11, 60, 1, 120, 196, 112, 147},
{141, 0, 181, 192, 162, 9, 77, 80, 100000, 53, 124},
{138, 100000, 0, 10, 166, 30, 22, 73, 149, 78, 170},
{49, 112, 83, 0, 35, 195, 100000, 29, 200, 60, 181},
{29, 37, 33, 57, 0, 181, 6, 100000, 100000, 35, 17},
{60, 171, 34, 174, 14, 0, 184, 200, 154, 121, 91},
{100000, 71, 27, 26, 28, 130, 0, 100000, 94, 185, 77},
{64, 143, 36, 163, 82, 79, 165, 0, 43, 79, 19},
{168, 121, 81, 49, 45, 174, 119, 58, 0, 10, 46},
{100000, 124, 76, 10, 54, 87, 165, 69, 186, 0, 41},
{31, 176, 187, 99, 52, 90, 134, 100000, 9, 70, 0}
};
std::vector<unsigned> expected = {0, 6, 2, 3, 7, 10, 8, 9, 4, 1, 5};
std::vector<unsigned> journey = tsp_bruteforce(distances, 11);
EXPECT_TRUE( journey == expected || costOfJourney(distances, journey) == 265);
}

}
