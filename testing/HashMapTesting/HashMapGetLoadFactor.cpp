#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapGetLoadFactorTest, EmptyHashMapHasZeroLoadFactor)
{
    HashMap<int, int> map;

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
}

TEST(HashMapGetLoadFactorTest, LoadFactorAfterSingleInsertion)
{
    HashMap<int, int> map;

    int key = 1;
    int value = 10;

    map.insert(key, value);

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 1.0f / 16.0f);
}

TEST(HashMapGetLoadFactorTest, LoadFactorAfterMultipleInsertions)
{
    HashMap<int, int> map;

    for (int i = 0; i < 5; i++)
    {
        int key = i;
        int value = i * 10;
        map.insert(key, value);
    }

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 5.0f / 16.0f);
}

TEST(HashMapGetLoadFactorTest, DuplicateKeyDoesNotChangeLoadFactor)
{
    HashMap<int, int> map;

    int key = 5;
    int value1 = 100;
    int value2 = 500;

    map.insert(key, value1);

    float oldLoadFactor = map.getLoadFactor();

    map.insert(key, value2);

    EXPECT_FLOAT_EQ(map.getLoadFactor(), oldLoadFactor);
}

TEST(HashMapGetLoadFactorTest, LoadFactorBecomesZeroAfterClear)
{
    HashMap<int, int> map;

    for (int i = 0; i < 3; i++)
    {
        int key = i;
        int value = i;
        map.insert(key, value);
    }

    map.clear();

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
}