#include <gtest/gtest.h>
#include "hashMap.h"


TEST(HashMapRehashTest, RehashDoublesCapacityAndUpdatesLoadFactor)
{
    HashMap<int, int> map;

    for(int i = 0; i < 5; i++)
    {
        int key = i;
        int value = i * 10;
        map.insert(key, value);
    }

    EXPECT_EQ(map.getSize(), 5);

    map.rehash();

    EXPECT_FLOAT_EQ(map.getLoadFactor(), 5.0f / 32.0f);
}


TEST(HashMapRehashTest, RehashPreservesExistingIntegerData)
{
    HashMap<int, std::string> map;

    int key1 = 1;
    int key2 = 2;

    std::string value1 = "One";
    std::string value2 = "Two";

    map.insert(key1, value1);
    map.insert(key2, value2);


    map.rehash();


    EXPECT_EQ(map.get(key1), "One");
    EXPECT_EQ(map.get(key2), "Two");
}


TEST(HashMapRehashTest, RehashPreservesStringKeys)
{
    HashMap<std::string, int> map;

    std::string key1 = "apple";
    std::string key2 = "banana";

    int value1 = 100;
    int value2 = 200;


    map.insert(key1, value1);
    map.insert(key2, value2);


    map.rehash();


    EXPECT_EQ(map.get(key1), 100);
    EXPECT_EQ(map.get(key2), 200);
}


TEST(HashMapRehashTest, RehashEmptyHashMap)
{
    HashMap<int, int> map;


    EXPECT_NO_THROW(
        map.rehash();
    );

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 0.0f);
}