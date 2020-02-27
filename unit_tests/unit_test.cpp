#include "gtest/gtest.h"
#include "../src/cmd.cpp"
int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(executeTest, TestEchoHello) {
	vector<string> sample;
	sample.push_back("echo");
	sample.push_back("hello");
	Cmd* c = new Cmd(sample);
	EXPECT_EQ(c->evaluate(), true);
}
	
	
	



