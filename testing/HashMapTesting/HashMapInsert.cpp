#include <gtest/gtest.h>
#include "hashMap.h"
#include <string>

//
// Primitive Type Tests
//

TEST(HashMapInsertTest, InsertSingleElement)
{
    HashMap<int, int> map;

    int key = 10;
    int value = 100;

    map.insert(key, value);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 1.0f / 16.0f);
}

TEST(HashMapInsertTest, InsertMultipleUniqueElements)
{
    HashMap<int, int> map;

    for (int i = 0; i < 5; i++)
    {
        int key = i;
        int value = i * 10;

        map.insert(key, value);
    }

    EXPECT_EQ(map.getSize(), 5);
    EXPECT_FLOAT_EQ(map.getLoadFactor(), 5.0f / 16.0f);
}

TEST(HashMapInsertTest, DuplicateKeyUpdatesValueWithoutIncreasingSize)
{
    HashMap<int, int> map;

    int key = 5;
    int value1 = 100;
    int value2 = 500;

    map.insert(key, value1);
    map.insert(key, value2);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_EQ(map.get(key), 500);
}

//
// Standard Library Type Test
//

TEST(HashMapInsertTest, InsertStringKeyIntegerValue)
{
    HashMap<std::string, int> map;

    std::string key = "Alice";
    int value = 25;

    map.insert(key, value);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_EQ(map.get(key), 25);
}

//
// User-defined type with hashCode()
//

class Student
{
public:
    int roll;

    Student(int r) : roll(r) {}

    int hashCode() const
    {
        return roll;
    }

    bool operator==(const Student& other) const
    {
        return roll == other.roll;
    }
};

TEST(HashMapInsertTest, EquivalentUserDefinedKeysUsingHashCodeUpdateExistingEntry)
{
    HashMap<Student, std::string> map;

    Student s1(10);
    Student s2(10);

    std::string first = "Alice";
    std::string second = "Bob";

    map.insert(s1, first);
    map.insert(s2, second);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_EQ(map.get(s1), "Bob");
    EXPECT_EQ(map.get(s2), "Bob");
}

//
// User-defined type WITHOUT hashCode()
// Uses generic fallback hashing
//

struct Point
{
    int x;
    int y;

    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

TEST(HashMapInsertTest, UserDefinedKeyWithoutHashCodeUsesFallbackHash)
{
    HashMap<Point, int> map;

    Point p{2, 3};
    int value = 50;

    map.insert(p, value);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_EQ(map.get(p), 50);
}

TEST(HashMapInsertTest, EquivalentFallbackKeysUpdateExistingEntry)
{
    HashMap<Point, int> map;

    Point p1{5, 8};
    Point p2{5, 8};

    int value1 = 10;
    int value2 = 20;

    map.insert(p1, value1);
    map.insert(p2, value2);

    EXPECT_EQ(map.getSize(), 1);
    EXPECT_EQ(map.get(p1), 20);
    EXPECT_EQ(map.get(p2), 20);
}