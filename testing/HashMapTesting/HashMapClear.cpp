#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapClearTest, ClearEmptyHashMap)
{
    HashMap<int, int> map;

    map.clear();

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
}

TEST(HashMapClearTest, ClearPopulatedHashMap)
{
    HashMap<int, int> map;

    for(int i = 0; i < 5; i++)
    {
        int key = i;
        int value = i * 10;
        map.insert(key, value);
    }

    map.clear();

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);

    int key = 0;
    EXPECT_FALSE(map.exists(key));
}

TEST(HashMapClearTest, HashMapCanBeReusedAfterClear)
{
    HashMap<int, std::string> map;

    int key1 = 1;
    std::string value1 = "One";
    map.insert(key1, value1);

    map.clear();

    int key2 = 2;
    std::string value2 = "Two";
    map.insert(key2, value2);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_EQ(map.get(key2), "Two");

    EXPECT_FALSE(map.exists(key1));
}

class Student
{
public:
    int roll;

    Student(int r) : roll(r) {}

    bool operator==(const Student& other) const
    {
        return roll == other.roll;
    }

    int hashCode() const
    {
        return roll;
    }
};

TEST(HashMapClearTest, ClearWorksForUserDefinedKeyType)
{
    HashMap<Student, std::string> map;

    Student key(101);
    std::string value = "Suman";

    map.insert(key, value);

    map.clear();

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
    EXPECT_FALSE(map.exists(key));
}