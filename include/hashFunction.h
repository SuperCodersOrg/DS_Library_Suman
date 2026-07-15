#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H

#include <string>
#include <cstdint>

class HashFunction
{
public:
    int generateHash(int key);
    int generateHash(char key);
    int generateHash(bool key);
    int generateHash(const std::string& key);
    int generateHash(float key);
    int generateHash(double key);
    int generateHash(long key);
    int generateHash(short key);
    template<typename K>
    int generateHash(const K& obj)
    {
        if constexpr (requires(const K& value){
            { value.hashCode() } -> std::convertible_to<int>;}){
            return obj.hashCode();
        }else{
            static_assert(std::is_trivially_copyable_v<K>,"Type must either provide hashCode() or be trivially copyable.");
            const unsigned char* bytes =reinterpret_cast<const unsigned char*>(&obj);

            int hash = 0;
            for (size_t i = 0; i < sizeof(K); ++i){
                hash = hash * 31 + bytes[i];
            }
            return hash;
        }
    }
};



#endif