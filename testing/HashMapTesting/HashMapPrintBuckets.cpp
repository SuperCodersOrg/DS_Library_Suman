#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "hashMap.h"

using namespace std;

TEST(HashMapPrintBucketsTest, PrintEmptyHashMap)
{
    HashMap<int, int> map;

    testing::internal::CaptureStdout();

    map.printBuckets();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());

    int lineCount = 0;
    for(char ch : output)
    {
        if(ch == '\n')
            lineCount++;
    }

    EXPECT_EQ(lineCount, 16);
}


TEST(HashMapPrintBucketsTest, PrintAfterSingleInsertion)
{
    HashMap<int, int> map;

    int key = 5;
    int value = 100;

    map.insert(key, value);

    testing::internal::CaptureStdout();

    map.printBuckets();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Key: 5"), string::npos);
    EXPECT_NE(output.find("Value: 100"), string::npos);
}


TEST(HashMapPrintBucketsTest, PrintAfterMultipleInsertions)
{
    HashMap<int, int> map;

    for(int i = 0; i < 5; i++)
    {
        int key = i;
        int value = i * 10;
        map.insert(key, value);
    }

    testing::internal::CaptureStdout();

    map.printBuckets();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Key: 0"), string::npos);
    EXPECT_NE(output.find("Key: 4"), string::npos);
}


TEST(HashMapPrintBucketsTest, PrintAfterClear)
{
    HashMap<int, int> map;

    for(int i = 0; i < 4; i++)
    {
        int key = i;
        int value = i;
        map.insert(key, value);
    }

    map.clear();

    testing::internal::CaptureStdout();

    map.printBuckets();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("Key:"), string::npos);
}


TEST(HashMapPrintBucketsTest, SupportsStringKeyType)
{
    HashMap<string, int> map;

    string key = "Alice";
    int value = 25;

    map.insert(key, value);

    testing::internal::CaptureStdout();

    map.printBuckets();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Alice"), string::npos);
}