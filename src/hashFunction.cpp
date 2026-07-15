#include "../include/hashFunction.h"
#include <cstring>
#include <type_traits>
#include <utility>

// Helper function: used when K has hashCode()
template<typename K>
int generateHashImpl(const K& obj, std::true_type)
{
    return obj.hashCode();
}

// Helper function: used when K does not have hashCode()
template<typename K>
int generateHashImpl(const K& obj, std::false_type)
{
    const unsigned char* bytes =
        reinterpret_cast<const unsigned char*>(&obj);

    int hash = 0;

    for (size_t i = 0; i < sizeof(K); ++i)
    {
        hash = hash * 31 + bytes[i];
    }

    return hash;
}

int HashFunction::generateHash(int key) {
    return key;
}

int HashFunction::generateHash(char key) {
    return static_cast<int>(key);
}

int HashFunction::generateHash(bool key) {
    return key;
}

int HashFunction::generateHash(const std::string& key) {
    int hash = 0;
    for (char c : key)
        hash = hash * 31 + c;
    return hash;
}

int HashFunction::generateHash(float key) {
    if (key == 0.0f) return 0;
    uint32_t bits;
    memcpy(&bits, &key, sizeof(float));
    return static_cast<int>(bits);
}

int HashFunction::generateHash(double key) {
    if (key == 0.0) return 0;
    uint64_t bits;
    memcpy(&bits, &key, sizeof(double));
    bits ^= (bits >> 32);
    return static_cast<int>(bits);
}

int HashFunction::generateHash(long key) {
    return static_cast<int>(key);
}

int HashFunction::generateHash(short key) {
    return static_cast<int>(key);
}

template<typename K>
int HashFunction::generateHash(const K& obj)
{
    return generateHashImpl(obj, HasHashCode<K>{});
}