#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "redisLite.h"

using namespace std;

class RedisLiteRunTest : public ::testing::Test
{
protected:
    streambuf* oldCin = nullptr;
    streambuf* oldCout = nullptr;
    istringstream input;
    ostringstream output;

    void execute(const string& commands)
    {
        input.str(commands);

        oldCin = cin.rdbuf(input.rdbuf());
        oldCout = cout.rdbuf(output.rdbuf());

        RedisLite redis;
        redis.run();

        cin.rdbuf(oldCin);
        cout.rdbuf(oldCout);
    }
};

TEST_F(RedisLiteRunTest, ExitImmediately)
{
    execute("exit\n");

    EXPECT_NE(output.str().find("Redis Lite Database"), string::npos);
    EXPECT_NE(output.str().find("Thank you for using Redis Lite."), string::npos);
}

TEST_F(RedisLiteRunTest, SetCommandStoresKeyValuePair)
{
    execute(
        "set name suman\n"
        "get name\n"
        "exit\n");

    EXPECT_NE(output.str().find("SUCCESS: Key-value pair stored successfully."), string::npos);
    EXPECT_NE(output.str().find("Value: suman"), string::npos);
}

TEST_F(RedisLiteRunTest, DuplicateSetUpdatesExistingValue)
{
    execute(
        "set city delhi\n"
        "set city mumbai\n"
        "get city\n"
        "exit\n");

    EXPECT_NE(output.str().find("Value: mumbai"), string::npos);
}

TEST_F(RedisLiteRunTest, ExistsCommandForExistingKey)
{
    execute(
        "set language cpp\n"
        "exists language\n"
        "exit\n");

    EXPECT_NE(output.str().find("exists"), string::npos);
}

TEST_F(RedisLiteRunTest, ExistsCommandForMissingKey)
{
    execute(
        "exists java\n"
        "exit\n");

    EXPECT_NE(output.str().find("does not exists"), string::npos);
}

TEST_F(RedisLiteRunTest, DeleteCommandRemovesKey)
{
    execute(
        "set x 100\n"
        "del x\n"
        "count\n"
        "exit\n");

    EXPECT_NE(output.str().find("SUCCESS: Key deleted successfully."), string::npos);
    EXPECT_NE(output.str().find("Total Key-Value Pairs : 0"), string::npos);
}

TEST_F(RedisLiteRunTest, CountCommandReturnsCorrectSize)
{
    execute(
        "set a 1\n"
        "set b 2\n"
        "count\n"
        "exit\n");

    EXPECT_NE(output.str().find("Total Key-Value Pairs : 2"), string::npos);
}

TEST_F(RedisLiteRunTest, ClearRemovesAllEntries)
{
    execute(
        "set a 10\n"
        "set b 20\n"
        "clear\n"
        "count\n"
        "exit\n");

    EXPECT_NE(output.str().find("Database cleared successfully"), string::npos);
    EXPECT_NE(output.str().find("Total Key-Value Pairs : 0"), string::npos);
}

TEST_F(RedisLiteRunTest, ShowDisplaysStoredEntries)
{
    execute(
        "set name suman\n"
        "set city kolkata\n"
        "show\n"
        "exit\n");

    EXPECT_NE(output.str().find("name"), string::npos);
    EXPECT_NE(output.str().find("suman"), string::npos);
    EXPECT_NE(output.str().find("city"), string::npos);
    EXPECT_NE(output.str().find("kolkata"), string::npos);
}

TEST_F(RedisLiteRunTest, HelpCommandDisplaysMenu)
{
    execute(
        "help\n"
        "exit\n");

    EXPECT_NE(output.str().find("Available Commands"), string::npos);
    EXPECT_NE(output.str().find("SET <key> <value>"), string::npos);
    EXPECT_NE(output.str().find("GET <key>"), string::npos);
}

TEST_F(RedisLiteRunTest, CommandsAreCaseInsensitive)
{
    execute(
        "SeT Name Suman\n"
        "GeT Name\n"
        "ExIt\n");

    EXPECT_NE(output.str().find("Value: suman"), string::npos);
}

TEST_F(RedisLiteRunTest, IgnoresExtraSpacesBetweenTokens)
{
    execute(
        "   set     age      22\n"
        "   get      age\n"
        "exit\n");

    EXPECT_NE(output.str().find("Value: 22"), string::npos);
}

TEST_F(RedisLiteRunTest, EmptyInputShowsError)
{
    execute(
        "\n"
        "exit\n");

    EXPECT_NE(output.str().find("ERROR: No command entered."), string::npos);
}

TEST_F(RedisLiteRunTest, UnknownCommandShowsError)
{
    execute(
        "abcdef\n"
        "exit\n");

    EXPECT_NE(output.str().find("Unknown command"), string::npos);
}

TEST_F(RedisLiteRunTest, InvalidArgumentCountShowsUsage)
{
    execute(
        "set key\n"
        "count extra\n"
        "help extra\n"
        "exit\n");

    EXPECT_NE(output.str().find("Usage -> SET <key> <value>"), string::npos);
    EXPECT_NE(output.str().find("Usage -> COUNT"), string::npos);
    EXPECT_NE(output.str().find("Usage -> help"), string::npos);
}

TEST_F(RedisLiteRunTest, ExceptionIsCaughtAndDisplayed)
{
    execute(
        "get unknown\n"
        "exit\n");

    EXPECT_NE(output.str().find("ERROR:"), string::npos);
}