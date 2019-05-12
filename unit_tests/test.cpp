#include "gtest/gtest.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Command.h"

TEST(CommandTest, AndFunction) {
	RShell.run();
	
	
}

TEST(CommandTest, OrFunction) {

}

TEST(CommandTest, SemicolonFunction) {

}

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

