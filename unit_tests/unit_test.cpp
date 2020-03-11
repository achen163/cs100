#include "gtest/gtest.h"
#include "../header/cmd.h"
#include "../header/parser.h"
int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}

TEST(evlaluateTest, TestEchoHello) {
	vector<string> sample;
	sample.push_back("echo");
	sample.push_back("hello");
	Cmd* c = new Cmd(sample);
	EXPECT_EQ(c->evaluate2(), true);
}

TEST(evaluateTest2, TestTestCmd) {
	vector<string> sample2;
	sample2.push_back("test");
	sample2.push_back("-f");
	sample2.push_back("test/file/path");
	Cmd* c2 = new Cmd(sample2);
	EXPECT_EQ(c2->evaluate2(), false);
}

TEST(evaluateTest2, TestTestCmd2) {
        vector<string> sample2;
        sample2.push_back("test");
        sample2.push_back("-d");
        sample2.push_back("test/file/path");
        Cmd* c2 = new Cmd(sample2);
        EXPECT_EQ(c2->evaluate2(), false);
}

TEST(evaluateTest2, TestTestCmd3) {
        vector<string> sample2;
        sample2.push_back("[");
        sample2.push_back("-e");
        sample2.push_back("test/file/path");
	sample2.push_back("]");
        Cmd* c2 = new Cmd(sample2);
        EXPECT_EQ(c2->evaluate2(), false);
}


TEST(evaluateTest3, TestInvalidCmd) {
	vector<string> test;
	test.push_back("echa");
	test.push_back("hello");
	Cmd* c3 = new Cmd(test);
	EXPECT_EQ(c3->evaluate2(), false);
}


TEST(executeTest, testInput) {
	Parser p;
	cout << "Testing execute(). Enter input" << endl;
	p.execute();
	
}

TEST(execute2Test, testInput) {
	Parser p;
	cout << "Testing execute2(). Enter input" << endl;
	p.execute();
}


