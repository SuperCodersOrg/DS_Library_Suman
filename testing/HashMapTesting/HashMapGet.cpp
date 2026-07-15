#include <gtest/gtest.h>
#include "../../include/hashMap.h"
#include <string>

TEST(HashMapGetTest, ReturnsValueForExistingIntegerKey)
{
    HashMap<int, std::string> map;

    int key = 10;
    std::string value = "Ten";

    map.insert(key, value);

    EXPECT_EQ(map.get(key), "Ten");
}

TEST(HashMapGetTest, ReturnedReferenceAllowsModification)
{
    HashMap<int, std::string> map;

    int key = 5;
    std::string value = "Five";

    map.insert(key, value);

    map.get(key) = "Updated";

    EXPECT_EQ(map.get(key), "Updated");
}

TEST(HashMapGetTest, ThrowsWhenKeyDoesNotExist)
{
    HashMap<int, int> map;

    int key = 100;

    EXPECT_THROW(map.get(key), std::runtime_error);
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

TEST(HashMapGetTest, WorksWithUserDefinedKey)
{
    HashMap<Student, std::string> map;

    Student s(1);
    std::string value = "Suman";

    map.insert(s, value);

    EXPECT_EQ(map.get(s), "Suman");
}

TEST(HashMapGetTest, DifferentObjectsWithSameLogicalKeyRetrieveValue)
{
    HashMap<Student, int> map;

    Student s1(25);
    Student s2(25);

    int value = 999;

    map.insert(s1, value);

    EXPECT_EQ(map.get(s2), 999);
}