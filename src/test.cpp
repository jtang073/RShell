#include "gtest/gtest.h"
#include <iostream>

#include "Instruction.hpp"
#include "RShell.h"

#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Command.h"
#include "Connector.h"

TEST(CommandTest, EchoTest) {
        vector<char*> testvec;
        string arg = "echo";
        char* argcstring = (char*)(arg.c_str());
        string arg2 = "testing echo command!";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring);
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);

        EXPECT_EQ(command1->execute(), true);
}

TEST(CommandTest, MkdirTest) {
        vector<char*> testvec;
        string arg = "mkdir";
        char* argcstring = (char*)(arg.c_str());
        string arg2 = "newDirectory";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring);
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);

        EXPECT_EQ(command1->execute(), true);
}

TEST(CommandTest, LsTest) {
        vector<char*> testvec;
        string arg = "ls";
        char* argcstring = (char*)(arg.c_str());
        string arg2 = "-a";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring);
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);

        EXPECT_EQ(command1->execute(), true);
}

TEST(CommandTest, RmTest) {
        vector<char*> testvec;
        string arg = "rm";
        char* argcstring = (char*)(arg.c_str());
        string arg2 = "-r";
        char* argcstring2 = (char*)(arg2.c_str());
        string arg3 = "newDirectory";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring);
        testvec.push_back(argcstring2);
        testvec.push_back(argcstring3);

        Command* command1 = new Command(testvec);

        EXPECT_EQ(command1->execute(), true);
}

TEST(ConnectorTest, AndLeftTrue) {
        vector<char*> testvec;
        string mkdir = "echo";
        char* mkdirchar = (char*)(mkdir.c_str());
        string dir = "This is the lhs!";
        char* dirchar = (char*)(dir.c_str());
        testvec.push_back(mkdirchar);
        testvec.push_back(dirchar);

        vector<char*> testvec2;
        string mkdir2 = "echo";
        char* mkdirchar2 = (char*)(mkdir2.c_str());
        string dir2 = "This is the rhs!";
        char* dirchar2 = (char*)(dir2.c_str());
        testvec2.push_back(mkdirchar2);
        testvec2.push_back(dirchar2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        And* connector = new And(command1, command2);
        EXPECT_EQ(connector->execute(), true);
}

TEST(ConnectorTest, AndLeftFalse) {
        vector<char*> testvec;
        string arg1 = "false";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec2;
        string arg2 = "false";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec2.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        And* connector = new And(command1, command2);
        EXPECT_EQ(connector->execute(), false);
}

TEST(ConnectorTest, AndBothFalse) {
        vector<char*> testvec;
        string arg1 = "false";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec2;
        string arg2 = "false";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec2.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        And* connector = new And(command1, command2);
        EXPECT_EQ(connector->execute(), false);
}

TEST(ConnectorTest, OrLeftTrue) {
        vector<char*> testvec;
        string mkdir = "echo";
        char* mkdirchar = (char*)(mkdir.c_str());
        string dir = "This is the lhs!";
        char* dirchar = (char*)(dir.c_str());
        testvec.push_back(mkdirchar);
        testvec.push_back(dirchar);

        vector<char*> testvec2;
        string mkdir2 = "echo";
        char* mkdirchar2 = (char*)(mkdir2.c_str());
        string dir2 = "This is the rhs!";
        char* dirchar2 = (char*)(dir2.c_str());
        testvec2.push_back(mkdirchar2);
        testvec2.push_back(dirchar2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        Or* connector = new Or(command1, command2);
        EXPECT_EQ(connector->execute(), true);
}

TEST(ConnectorTest, OrLeftFalse) {
        vector<char*> testvec;
        string arg1 = ";jsadf";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec2;
        string arg2 = "echo";
        char* argcstring2 = (char*)(arg2.c_str());
        string arg3 = "This is the rhs!";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec2.push_back(argcstring2);
        testvec2.push_back(argcstring3);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        Or* connector = new Or(command1, command2);
        EXPECT_EQ(connector->execute(), true);
}

TEST(ConnectorTest, OrBothFalse) {
        vector<char*> testvec;
        string arg1 = "false";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec2;
        string arg2 = "false";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec2.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        Or* connector = new Or(command1, command2);
        EXPECT_EQ(connector->execute(), false);
}

TEST(ConnectorTest, SemicolonLeftTrue) {
        vector<char*> testvec;
        string mkdir = "echo";
        char* mkdirchar = (char*)(mkdir.c_str());
        string dir = "This is the lhs!";
        char* dirchar = (char*)(dir.c_str());
        testvec.push_back(mkdirchar);
        testvec.push_back(dirchar);

        vector<char*> testvec2;
        string mkdir2 = "echo";
        char* mkdirchar2 = (char*)(mkdir2.c_str());
        string dir2 = "This is the rhs!";
        char* dirchar2 = (char*)(dir2.c_str());
        testvec2.push_back(mkdirchar2);
        testvec2.push_back(dirchar2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        Semicolon* connector = new Semicolon(command1, command2);
        EXPECT_EQ(connector->execute(), true);
}

TEST(ConnectorTest, SemicolonLeftFalse) {
        vector<char*> testvec;
        string arg1 = "false";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec2;
        string arg2 = "echo";
        char* argcstring2 = (char*)(arg2.c_str());
        string arg3 = "This is the rhs!";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec2.push_back(argcstring2);
        testvec2.push_back(argcstring3);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        Semicolon* connector = new Semicolon(command1, command2);
        EXPECT_EQ(connector->execute(), true);
}

TEST(ConnectorTest, SemicolonBothFalse) {
        vector<char*> testvec;
        string arg1 = "false";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec2;
        string arg2 = "false";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec2.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        Command* command2 = new Command(testvec2);

        Semicolon* connector = new Semicolon(command1, command2);
        EXPECT_EQ(connector->execute(), false);
}

TEST(Test_Test, eFlag_SRC_TRUE) {
        vector<char*> testvec;
        string arg1 = "test";
        char* argcstring1 = (char*)(arg1.c_str());
	testvec.push_back(argcstring1);
	
	vector<char*> testve3;
        string arg3 = "-e";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring3);

        vector<char*> testvec2;
        string arg2 = "src";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), true);
}

TEST(Test_Test, dFlag_SRC_TRUE) {
        vector<char*> testvec;
        string arg1 = "test";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testve3;
        string arg3 = "-d";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring3);

        vector<char*> testvec2;
        string arg2 = "src";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), true);
}

TEST(Test_Test, fFlag_NAMESTXT_TRUE) {
        vector<char*> testvec;
        string arg1 = "test";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testve3;
        string arg3 = "-f";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring3);

        vector<char*> testvec2;
        string arg2 = "names.txt";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), true);
}

TEST(Test_Test, eFlag_HaveMercyOnUs_FALSE) {
        vector<char*> testvec;
        string arg1 = "test";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testve3;
        string arg3 = "-e";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring3);

        vector<char*> testvec2;
        string arg2 = "HaveMercyOnUs";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), false);
}

TEST(Test_Test, dFlag_WeDontKnowWhatWereDoing_FALSE) {
        vector<char*> testvec;
        string arg1 = "test";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testve3;
        string arg3 = "-d";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring3);

        vector<char*> testvec2;
        string arg2 = "HaveMercyOnUs";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), false);
}

TEST(Test_Test, fFlag_CriesInBinary_FALSE) {
        vector<char*> testvec;
        string arg1 = "test";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testve3;
        string arg3 = "-f";
        char* argcstring3 = (char*)(arg3.c_str());
        testvec.push_back(argcstring3);

        vector<char*> testvec2;
        string arg2 = "HaveMercyOnUs";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), false);
}

TEST(RedirectorTest, InputRedirection) {
	vector<char*> testvec;
	string arg1 = "cat";
	char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

	vector<char*> testvec3;
	string arg3 = "<";
	char* argcstring3 = (char*)(arg3.c_str());

        vector<char*> testvec2;
        string arg2 = "names.txt";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);
	
	Command* command1 = new Command(testvec);
	EXPECT_EQ(command1->execute(), true);
}

TEST(RedirectorTest, OutputRedirection) {
	vector<char*> testvec;
        string arg1 = "echo";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);
	
	vector<char*> testvec1;
	string arg = "hi";
	char* argcstring = (char*)(arg.c_str());
	testvec.push_back(argcstring);

        vector<char*> testvec3;
        string arg3 = ">";
        char* argcstring3 = (char*)(arg3.c_str());

        vector<char*> testvec2;
        string arg2 = "test.txt";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), true);
}

TEST(RedirectorTest, InAndOutRedirection) {
	vector<char*> testvec;
        string arg1 = "cat";
        char* argcstring1 = (char*)(arg1.c_str());
        testvec.push_back(argcstring1);

        vector<char*> testvec3;
        string arg3 = "<";
        char* argcstring3 = (char*)(arg3.c_str());

        vector<char*> testvec2;
        string arg2 = "names.txt";
        char* argcstring2 = (char*)(arg2.c_str());
        testvec.push_back(argcstring2);
	
	vector<char*> testvec0;
        string arg0 = ">";
        char* argcstring0 = (char*)(arg0.c_str());

        vector<char*> testvec9;
        string arg9 = "test.txt";
        char* argcstring9 = (char*)(arg9.c_str());
        

        Command* command1 = new Command(testvec);
        EXPECT_EQ(command1->execute(), true);

}

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

