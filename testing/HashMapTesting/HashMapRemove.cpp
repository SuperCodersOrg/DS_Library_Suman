#include <gtest/gtest.h>
#include "../../include/hashMap.h"
#include <string>

TEST(HashMapRemoveTest, RemoveExistingKey)
{
    HashMap<int, std::string> map;

    int key = 10;
    std::string value = "Ten";

    map.insert(key, value);
    map.remove(key);

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FALSE(map.exists(key));
}

TEST(HashMapRemoveTest, RemoveFromMultipleElements)
{
    HashMap<int, std::string> map;

    int k1 = 1, k2 = 2, k3 = 3;
    std::string v1 = "One", v2 = "Two", v3 = "Three";

    map.insert(k1, v1);
    map.insert(k2, v2);
    map.insert(k3, v3);

    map.remove(k2);

    EXPECT_EQ(map.getSize(), 2);
    EXPECT_TRUE(map.exists(k1));
    EXPECT_FALSE(map.exists(k2));
    EXPECT_TRUE(map.exists(k3));
}

TEST(HashMapRemoveTest, RemoveNonExistingKeyThrows)
{
    HashMap<int, int> map;

    int key = 100;

    EXPECT_THROW(map.remove(key), std::runtime_error);
}

TEST(HashMapRemoveTest, RemoveLastElementFromBucket)
{
    HashMap<int, int> map;

    int key = 5;
    int value = 50;

    map.insert(key, value);
    map.remove(key);

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_EQ(map.getLoadFactor(), 0.0f);

    EXPECT_THROW(map.get(key), std::runtime_error);
}

class Student
{
public:
    int roll;

    Student(int r = 0) : roll(r) {}

    bool operator==(const Student& other) const
    {
        return roll == other.roll;
    }

    int hashCode() const
    {
        return roll;
    }
};

TEST(HashMapRemoveTest, RemoveUserDefinedKey)
{
    HashMap<Student, std::string> map;

    Student s(101);
    std::string branch = "CSE";

    map.insert(s, branch);
    map.remove(s);

    EXPECT_EQ(map.getSize(), 0);
    EXPECT_FALSE(map.exists(s));
}