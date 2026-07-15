#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapCopyAssignmentTest, AssignEmptyHashMap)
{
    HashMap<int, int> source;
    HashMap<int, int> destination;

    destination = source;

    EXPECT_EQ(destination.getSize(), 0);
    EXPECT_FLOAT_EQ(destination.getLoadFactor(), 0.0f);
}

TEST(HashMapCopyAssignmentTest, AssignPopulatedStringKeyHashMap)
{
    HashMap<std::string, int> source;

    std::string k1 = "one";
    std::string k2 = "two";
    int v1 = 1;
    int v2 = 2;

    source.insert(k1, v1);
    source.insert(k2, v2);

    HashMap<std::string, int> destination;
    destination = source;

    EXPECT_EQ(destination.getSize(), 2);
    EXPECT_EQ(destination.get(k1), 1);
    EXPECT_EQ(destination.get(k2), 2);
}

TEST(HashMapCopyAssignmentTest, AssignmentPerformsDeepCopy)
{
    HashMap<int, std::string> source;

    int key = 10;
    std::string value = "Apple";

    source.insert(key, value);

    HashMap<int, std::string> destination;
    destination = source;

    source.get(key) = "Orange";

    EXPECT_EQ(destination.get(key), "Apple");
    EXPECT_EQ(source.get(key), "Orange");
}

TEST(HashMapCopyAssignmentTest, SelfAssignmentLeavesHashMapUnchanged)
{
    HashMap<int, int> map;

    for (int i = 0; i < 5; i++)
    {
        int key = i;
        int value = i * 10;
        map.insert(key, value);
    }

    map = map;

    EXPECT_EQ(map.getSize(), 5);

    for (int i = 0; i < 5; i++)
    {
        int key = i;
        EXPECT_EQ(map.get(key), i * 10);
    }
}