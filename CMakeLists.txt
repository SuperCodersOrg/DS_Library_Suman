cmake_minimum_required(VERSION 3.16)

project(DS_Library)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(include)
include_directories(src)
add_executable(main
    main.cpp
    src/hashFunction.cpp
)

# Google Test Setup

enable_testing()

find_package(GTest REQUIRED)


add_executable(DynamicArrayTesting

    testing/DynamicArrayTesting/DynamicArrayInsert.cpp
    testing/DynamicArrayTesting/DynamicArrayConstructor.cpp
    testing/DynamicArrayTesting/DynamicArrayDestructor.cpp
    testing/DynamicArrayTesting/DynamicArrayPushBack.cpp
    testing/DynamicArrayTesting/DynamicArrayPopBack.cpp
    testing/DynamicArrayTesting/DynamicArrayDelete.cpp
    testing/DynamicArrayTesting/DynamicArrayGet.cpp
    testing/DynamicArrayTesting/DynamicArrayBracket.cpp
    testing/DynamicArrayTesting/DynamicArrayCopy.cpp
    testing/DynamicArrayTesting/DynamicArrayCopyAssignment.cpp
    testing/DynamicArrayTesting/DynamicArrayGetSize.cpp
    testing/DynamicArrayTesting/DynamicArrayGetCapacity.cpp
    testing/DynamicArrayTesting/DynamicArrayEmpty.cpp
    testing/DynamicArrayTesting/DynamicArrayFull.cpp
    testing/DynamicArrayTesting/DynamicArrayPrint.cpp
)


target_link_libraries(DynamicArrayTesting

    GTest::gtest
    GTest::gtest_main

)

add_executable(LinkedListTesting
    testing/LinkedListTesting/LinkedListPushFront.cpp
    testing/LinkedListTesting/LinkedListPushBack.cpp
    testing/LinkedListTesting/LinkedListConstructor.cpp
    testing/LinkedListTesting/LinkedListDestructor.cpp
    testing/LinkedListTesting/LinkedListCopyConstructor.cpp
    testing/LinkedListTesting/LinkedListCopyAssignment.cpp
    testing/LinkedListTesting/LinkedListGetSize.cpp
    testing/LinkedListTesting/LinkedListGetHead.cpp
    testing/LinkedListTesting/LinkedListInsert.cpp
    testing/LinkedListTesting/LinkedListPopFront.cpp
    testing/LinkedListTesting/LinkedListPopBack.cpp
    testing/LinkedListTesting/LinkedListDelete.cpp
    testing/LinkedListTesting/LinkedListRemove.cpp
    testing/LinkedListTesting/LinkedListGet.cpp
    testing/LinkedListTesting/LinkedListSearch.cpp
    testing/LinkedListTesting/LinkedListTraverse.cpp
)

target_link_libraries(LinkedListTesting

    GTest::gtest
    GTest::gtest_main
)

add_executable(HashMapTesting
    testing/HashMapTesting/HashMapConstructor.cpp
    testing/HashMapTesting/HashMapDestructor.cpp
    testing/HashMapTesting/HashMapCopyConstructor.cpp
    testing/HashMapTesting/HashMapAssignment.cpp
    testing/HashMapTesting/HashMapBucketIndex.cpp
    testing/HashMapTesting/HashMapRehash.cpp
    testing/HashMapTesting/HashMapInsert.cpp
    testing/HashMapTesting/HashMapRemove.cpp
    testing/HashMapTesting/HashMapGet.cpp
    testing/HashMapTesting/HashMapGetSize.cpp
    testing/HashMapTesting/HashMapExists.cpp
    testing/HashMapTesting/HashMapGetLoadFactor.cpp
    testing/HashMapTesting/HashMapPrintBuckets.cpp
    testing/HashMapTesting/HashMapClear.cpp
    src/hashFunction.cpp
)

target_link_libraries(HashMapTesting

    GTest::gtest
    GTest::gtest_main
)

add_executable(RedisLiteTesting
    testing/RedisLiteTesting/RedisLiteCLI.cpp
    src/redisLite.cpp
    src/hashFunction.cpp
)

target_link_libraries(RedisLiteTesting

    GTest::gtest
    GTest::gtest_main
)


include(GoogleTest)

gtest_discover_tests(DynamicArrayTesting)
gtest_discover_tests(LinkedListTesting)
gtest_discover_tests(HashMapTesting)
gtest_discover_tests(RedisLiteTesting)