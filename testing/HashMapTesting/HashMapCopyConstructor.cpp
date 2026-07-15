#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapCopyConstructorTest, CopyEmptyHashMap)
{
    HashMap<int, int> original;

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.getSize(), 0);
    EXPECT_FLOAT_EQ(copy.getLoadFactor(), 0.0f);
}

TEST(HashMapCopyConstructorTest, CopyPreservesData)
{
    HashMap<int, int> original;

    for (int i = 0; i < 10; i++)
    {
        int key = i;
        int value = i * 100;
        original.insert(key, value);
    }

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.getSize(), original.getSize());

    for (int i = 0; i < 10; i++)
    {
        int key = i;
        EXPECT_EQ(copy.get(key), original.get(key));
    }
}

TEST(HashMapCopyConstructorTest, CopyCreatesDeepCopy)
{
    HashMap<int, int> original;

    int key = 5;
    int value = 50;

    original.insert(key, value);

    HashMap<int, int> copy(original);

    original.get(key) = 500;

    EXPECT_EQ(copy.get(key), 50);
}