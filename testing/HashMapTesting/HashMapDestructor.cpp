#include <gtest/gtest.h>
#include "hashMap.h"

TEST(HashMapDestructorTest, DestroyEmptyHashMap)
{
    {
        HashMap<int, int> map;
    }

    SUCCEED();
}

TEST(HashMapDestructorTest, DestroyPopulatedHashMap)
{
    {
        HashMap<int, int> map;

        for (int i = 0; i < 100; i++)
        {
            int key = i;
            int value = i * 10;

            map.insert(key, value);
        }
    }

    SUCCEED();
}