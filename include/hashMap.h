#ifndef HASHMAP_H
#define HASHMAP_H

#include "dynamicArray.h"
#include "linkedList.h"
#include "HashFunction.h"
#include <type_traits>
#include <utility>

template<typename, typename = void>
    struct HasEqual : std::false_type {};

    template<typename T>
    struct HasEqual<
        T,
        std::void_t<
            decltype(std::declval<const T&>() == std::declval<const T&>())
        >
    > : std::is_convertible<
            decltype(std::declval<const T&>() == std::declval<const T&>()),
            bool> {};

template<typename K, typename V>
class HashNode{
public:
    K key;
    V value;
    HashNode();
    HashNode(const K& key);
    HashNode(const K& key, const V& value);
    HashNode(const HashNode<K,V>& other);
    ~HashNode();
    bool operator==(const HashNode<K,V>& other) const;
    template<typename K1, typename V1>
    friend std::ostream& operator<<(std::ostream& os,const HashNode<K1,V1>& node);
};

template<typename K, typename V>
class HashMap{
private:
    DynamicArray<LinkedList<HashNode<K,V>>*> bucketArray;
    int size;
    int capacity;
    float loadfactor;
    float threshold;
    HashFunction h;
    static_assert(
        HasEqual<K>::value,
        "Key type must overload operator=="
    );

public:
    HashMap();
    ~HashMap();
    HashMap(const HashMap<K,V>& other);
    HashMap<K,V>& operator=(const HashMap<K,V>& other);
    int getbucketIndex(int hashcode);
    void rehash();
    void insert(K& key, V& value);
    void remove(K& key);
    bool exists(K& key);
    V& get(K& key);
    int getSize();
    float getLoadFactor();
    void clear();
    void printBuckets();
};

#include "../src/hashMap.cpp"

#endif