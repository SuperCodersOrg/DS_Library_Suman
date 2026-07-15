#include <gtest/gtest.h>
#include "../../include/hashMap.h"
#include <string>

TEST(HashMapGetSizeTest, EmptyHashMapHasSizeZero)
{
    HashMap<int, std::string> map;

    EXPECT_EQ(map.getSize(), 0);
}

TEST(HashMapGetSizeTest, SizeIncreasesAfterInsertions)
{
    HashMap<int, std::string> map;

    int k1 = 1, k2 = 2, k3 = 3;
    std::string v1 = "One", v2 = "Two", v3 = "Three";

    map.insert(k1, v1);
    map.insert(k2, v2);
    map.insert(k3, v3);

    EXPECT_EQ(map.getSize(), 3);
}

TEST(HashMapGetSizeTest, UpdatingExistingKeyDoesNotChangeSize)
{
    HashMap<int, std::string> map;

    int key = 10;
    std::string value1 = "First";
    std::string value2 = "Updated";

    map.insert(key, value1);
    map.insert(key, value2);

    EXPECT_EQ(map.getSize(), 1);
}

TEST(HashMapGetSizeTest, SizeBecomesZeroAfterClear)
{
    HashMap<int, std::string> map;

    for (int i = 0; i < 10; i++)
    {
        std::string value = "Value";
        int key = i;
        map.insert(key, value);
    }

    map.clear();

    EXPECT_EQ(map.getSize(), 0);
}

TEST(HashMapGetSizeTest, WorksWithGenericKeyAndValueTypes)
{
    HashMap<std::string, int> map;

    std::string k1 = "Apple";
    std::string k2 = "Banana";

    int v1 = 10;
    int v2 = 20;

    map.insert(k1, v1);
    map.insert(k2, v2);

    EXPECT_EQ(map.getSize(), 2);
}