#include <gtest/gtest.h>
#include "hashMap.h"


TEST(HashMapBucketIndexTest, PositiveHashCodeReturnsValidIndex)
{
    HashMap<int, int> map;

    int index = map.getbucketIndex(25);

    EXPECT_GE(index, 0);
    EXPECT_LT(index, 16);
}


TEST(HashMapBucketIndexTest, NegativeHashCodeReturnsValidIndex)
{
    HashMap<int, int> map;

    int index = map.getbucketIndex(-5);

    EXPECT_GE(index, 0);
    EXPECT_LT(index, 16);
}


TEST(HashMapBucketIndexTest, LargeHashCodeWrapsAroundCapacity)
{
    HashMap<int, int> map;

    int index = map.getbucketIndex(100000);

    EXPECT_GE(index, 0);
    EXPECT_LT(index, 16);
}