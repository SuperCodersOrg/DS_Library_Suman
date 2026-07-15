#include <gtest/gtest.h>
#include "../../include/hashMap.h"
#include <string>

TEST(HashMapExistsTest, ReturnsFalseForEmptyHashMap)
{
    HashMap<int, std::string> map;

    int key = 10;

    EXPECT_FALSE(map.exists(key));
}

TEST(HashMapExistsTest, ReturnsTrueForInsertedKey)
{
    HashMap<int, std::string> map;

    int key = 25;
    std::string value = "Twenty Five";

    map.insert(key, value);

    EXPECT_TRUE(map.exists(key));
}

TEST(HashMapExistsTest, ReturnsFalseForMissingKey)
{
    HashMap<int, std::string> map;

    int key1 = 1;
    int key2 = 2;

    std::string value = "One";

    map.insert(key1, value);

    EXPECT_FALSE(map.exists(key2));
}

TEST(HashMapExistsTest, ReturnsFalseAfterRemoval)
{
    HashMap<int, std::string> map;

    int key = 100;
    std::string value = "Hundred";

    map.insert(key, value);
    map.remove(key);

    EXPECT_FALSE(map.exists(key));
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

TEST(HashMapExistsTest, WorksWithUserDefinedKeyType)
{
    HashMap<Student, std::string> map;

    Student key(101);
    std::string value = "Suman";

    map.insert(key, value);

    EXPECT_TRUE(map.exists(key));
}