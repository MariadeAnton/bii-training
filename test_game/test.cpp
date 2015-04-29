#include "game.h"
#include "google/gtest/gtest.h"
#include "stdio.h"

// Tests ConvertScreenToWorld()

// Tests conversion of coordinates between Box2D world to glut window
TEST(ConvertScreenToWorldTest, SimpleTest) {
	b2Vec2 result = ConvertScreenToWorld(20, 20, 10.0, 10.0, 1.0, 1.0);

	EXPECT_FLOAT_EQ(1.1, result.x);
	EXPECT_FLOAT_EQ(1.1, result.y);

	result = ConvertScreenToWorld(20, 20, 20, 20, 0, 0);
	EXPECT_FLOAT_EQ(2, result.x);
	EXPECT_FLOAT_EQ(2, result.y);

	result = ConvertScreenToWorld(20, 20, 0, 0, 0, 0);
	EXPECT_FLOAT_EQ(0, result.x);
	EXPECT_FLOAT_EQ(0, result.y);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
