#include <gtest/gtest.h>
#include "dataset.h"
#include "dataset.cpp"

TEST(DatasetTest, Initialization)
{
	Dataset dataset("C:\\Users\\Екатерина\\source\\repos\\Project8\\Project8\\dataset.txt");
	EXPECT_NO_THROW(dataset.head(3));
}

TEST(DatasetTest, HeadFunction)
{
	Dataset dataset("C:\\Users\\Екатерина\\source\\repos\\Project8\\Project8\\dataset.txt");
	testing::internal::CaptureStdout();
	dataset.head(3);
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_FALSE(output.empty());
}

TEST(DatasetTest, InsertRow)
{
	Dataset dataset("C:\\Users\\Екатерина\\source\\repos\\Project8\\Project8\\dataset.txt");
	dataset.insert(0, { "4", "new", "5.5" });
	EXPECT_NO_THROW(dataset.head(4));
}

TEST(DatasetTest, RemoveRow)
{
	Dataset dataset("C:\\Users\\Екатерина\\source\\repos\\Project8\\Project8\\dataset.txt");
	dataset.remove(0);
	EXPECT_NO_THROW(dataset.head(3));
}

TEST(DatasetTest, DescribeColumn)
{
	Dataset dataset("C:\\Users\\Екатерина\\source\\repos\\Project8\\Project8\\dataset.txt");
	testing::internal::CaptureStdout();
	dataset.describe("col3");
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_TRUE(output.find("Maximum") != std::string::npos);

}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}