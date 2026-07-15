#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapConstructorTest, DefaultConstructorInitialState)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
}

TEST(HashMapConstructorTest, NewlyConstructedMapIsEmpty)
{
    HashMap<int, int> map;

    int key = 10;

    EXPECT_FALSE(map.exists(key));
}

TEST(HashMapConstructorTest, CanInsertAfterConstruction)
{
    HashMap<int, int> map;

    int key = 1;
    int value = 100;

    map.insert(key, value);

    EXPECT_EQ(map.getSize(), 1);
}