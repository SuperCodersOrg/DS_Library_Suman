#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    int capacity;
    int size;
    T* arr;
public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(const DynamicArray&);
    DynamicArray& operator=(const DynamicArray&);
    void push_back(const T&);
    void insertAtIndex(int,const T&);
    void pop_back();
    void deleteAtIndex(int);
    T& get(int);
    int getSize();
    int getCapacity();
    bool isEmpty();
    bool isFull();
    void print();
    T& operator[](int index);
    const T& operator[](int index)const;
};

#include "../src/dynamicArray.cpp"
#endif