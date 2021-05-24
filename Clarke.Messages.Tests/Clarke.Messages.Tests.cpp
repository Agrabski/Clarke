#include <gtest/gtest.h>
#include <tuple>
#include <sstream>
#include "../Clarke.Messages/MessageOperator.hpp"
#include "../Clarke.Messages/Message.hpp"

using namespace clarke::messages;

struct testMessage : Message<int, int>
{
	
	CONSTRUCTORS(testMessage);
	PROPERTY(x, 0);
	PROPERTY(y, 1);
};

struct testMessage2 : Message<testMessage, int, int>
{
	
	CONSTRUCTORS(testMessage2);

	PROPERTY(a, 0);
	PROPERTY(b, 1);
	PROPERTY(c, 2);
};

REGISTER_MESSAGE(testMessage);
REGISTER_MESSAGE(testMessage2);


TEST(Serialization, serialize_simple_message) {
	std::stringstream ss;
	print(ss, testMessage());
	EXPECT_EQ(ss.str(), "(testMessage 0 0)");
}

TEST(Serialization, serialize_simple_message_non_default_values) {
	std::stringstream ss;
	print(ss, testMessage{1, 12});
	EXPECT_EQ(ss.str(), "(testMessage 1 12)");
}

TEST(Serialization, serialize_compound_message) {
	std::stringstream ss;
	print(ss, testMessage2());
	EXPECT_EQ(ss.str(), "(testMessage2 (testMessage 0 0) 0 0)");
}

TEST(Serialization, serialize_compound_message_non_default_values) {
	std::stringstream ss;
	print(ss, testMessage2{ testMessage{ 1, 12 }, 3, 4 });
	EXPECT_EQ(ss.str(), "(testMessage2 (testMessage 1 12) 3 4)");
}

TEST(Deserialization, deserialize_simple_message) {
	std::stringstream ss;
	print(ss, testMessage());
	EXPECT_EQ(ss.str(), "(testMessage 0 0)");
	FAIL() << "TODO";
}

TEST(Deserialization, deserialize_simple_message_non_default_values) {
	std::stringstream ss;
	print(ss, testMessage{ 1, 12 });
	EXPECT_EQ(ss.str(), "(testMessage 1 12)");
	FAIL() << "TODO";
}

TEST(Deserialization, deserialize_compound_message) {
	std::stringstream ss;
	print(ss, testMessage2());
	EXPECT_EQ(ss.str(), "(testMessage2 (testMessage 0 0) 0 0)");
	FAIL() << "TODO";
}

TEST(Deserialization, deserialize_compound_message_non_default_values) {
	std::stringstream ss{ "(testMessage2 (testMessage 1 12) 3 4)" };
	testMessage2 tm;
	read(ss, tm);
	auto expected = testMessage2{ testMessage{ 1, 12 }, 3, 4 };
	EXPECT_EQ(tm, expected);
	EXPECT_FALSE(ss.fail());
}



TEST(Property, simple_message_has_getter) {
	const testMessage tm{};
	EXPECT_EQ(tm.x(), 0);
	EXPECT_EQ(tm.y(), 0);
}

TEST(Property, simple_message_has_getter_non_default_constructor) {
	const testMessage tm{3, 4};
	EXPECT_EQ(tm.x(), 3);
	EXPECT_EQ(tm.y(), 4);
}

TEST(Property, simple_message_has_getter_compound_type) {
	const testMessage2 tm{};
	EXPECT_EQ(tm.a(), testMessage{});
	EXPECT_EQ(tm.b(), 0);
	EXPECT_EQ(tm.c(), 0);
}

TEST(Property, simple_message_has_getter_non_default_constructor_compound_type) {
	const testMessage2 tm{ testMessage{1, 2}, 3, 4 };
	EXPECT_EQ(tm.a().x(), 1);
	EXPECT_EQ(tm.a().y(), 2);
	EXPECT_EQ(tm.b(), 3);
	EXPECT_EQ(tm.c(), 4);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}