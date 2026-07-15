#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>
#include <cstdint>
#include <type_traits>
#include <utility>

// Checks whether T has:
// int hashCode() const;
template<typename, typename = void>
struct HasHashCode : std::false_type {};

template<typename T>
struct HasHashCode<
    T,
    std::void_t<
        decltype(std::declval<const T&>().hashCode())
    >
> : std::is_convertible<
        decltype(std::declval<const T&>().hashCode()),
        int> {};

class HashFunction {
public:
    int generateHash(int key);
    int generateHash(char key);
    int generateHash(bool key);
    int generateHash(const std::string& key);
    int generateHash(float key);
    int generateHash(double key);
    int generateHash(long key);
    int generateHash(short key);
    template<typename T>
    int generateHash(const T& obj);
};

#include "../src/hashFunction.cpp"

#endif