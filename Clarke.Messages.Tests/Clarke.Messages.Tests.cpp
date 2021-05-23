#include <gtest/gtest.h>


TEST(ABC, TEST1) {
	EXPECT_EQ(true, false);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}