#include "gtest/gtest.h"
#include "../header/connectorToken.h"

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(ConnectorTest, EchoHello) {
	ConnectorToken* test = new ConnectorToken("echo hello");
	EXPECT_EQ(test->parser(), "hello");
}

