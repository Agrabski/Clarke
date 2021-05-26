#include <gtest/gtest.h>
#include <sstream>
#include "../Clarke.Engine.Core/WorldPosition.hpp"
#include "../Clarke.Messages/MessageOperator.hpp"

using namespace clarke::engine::core;
using namespace clarke::messages;

TEST(Serialization, WorldPosition)
{
	std::stringstream ss;
	print(ss, WorldPosition());
	EXPECT_EQ(ss.str(), "(WorldPosition 0 0)");
}

TEST(Serialization, WorldPosition_non_default_values)
{
	std::stringstream ss;
	print(ss, WorldPosition(12, 15));
	EXPECT_EQ(ss.str(), "(WorldPosition 12 15)");
}

TEST(Desrialization, WorldPosition)
{
	std::stringstream ss("(WorldPosition 0 0)");
	WorldPosition wp;
	EXPECT_FALSE(read(ss, wp).fail());
	EXPECT_EQ(wp.x(), 0);
	EXPECT_EQ(wp.y(), 0);
}

TEST(Deserialization, WorldPosition_non_default_values)
{
	std::stringstream ss("(WorldPosition 12 15)");
	WorldPosition wp;
	EXPECT_FALSE(read(ss, wp).fail());
	EXPECT_EQ(wp.x(), 12);
	EXPECT_EQ(wp.y(), 15);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}