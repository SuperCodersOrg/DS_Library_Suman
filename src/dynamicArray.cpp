#include "dynamicArray.h"
using namespace std;

template<typename T>
DynamicArray<T>::DynamicArray() {
        size = 0;
        capacity = 1;
        arr = (T*)malloc(sizeof(T) * capacity);
        if (arr == nullptr) {
            throw bad_alloc();
        }
    }

template<typename T>
DynamicArray<T>::~DynamicArray() {
    for (int i = 0; i < size; i++) {
        arr[i].~T();
    }
    free(arr);
    arr=nullptr;
}
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& arr2){
    size=arr2.size;
    capacity=arr2.capacity;
    arr=(T*)malloc(sizeof(T)*capacity);
    if (arr == nullptr) {
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++) {
        new (&arr[i]) T(arr2.arr[i]);
    }
}
template<typename T>
T& DynamicArray<T>::operator[](int index) {
     if (index < 0 || index >= size) {
        throw out_of_range("Invalid index");
    }
    return arr[index];
}
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>&arr2) {
    if (this == &arr2){
        return *this;
    }
    for(int i=0;i<size;i++){
        arr[i].~T();
    }
    free(arr);
    size=arr2.size;
    capacity=arr2.capacity;
    arr=(T*)malloc(sizeof(T)*capacity);
    if (arr == nullptr) {
        throw bad_alloc();
    }
    for (int i = 0; i < size; i++) {
        new (&arr[i]) T(arr2.arr[i]);
    }
    return *this;
}
template<typename T>
void DynamicArray<T>::push_back(const T& val) {
        if (size == capacity) {
            capacity *= 2;
            T* arr2 = (T*)malloc(sizeof(T) * capacity);
            if (arr2 == nullptr) {
                throw bad_alloc();
            }
            for (int i = 0; i < size; i++) {
                new (&arr2[i]) T(arr[i]);
            }
            for (int i = 0; i < size; i++) {
                arr[i].~T();
            }
            free(arr);
            arr = arr2;
        }
        new (&arr[size]) T(val);
        size++;
    }
template<typename T>
void DynamicArray<T>::insertAtIndex(int index, const T& val) {
        if (index < 0 || index > size) {
            throw out_of_range("Invalid index");
        }
        if (size == capacity) {
            capacity *= 2;
            T* arr2 = (T*)malloc(sizeof(T) * capacity);
            if (arr2 == nullptr) {
                throw bad_alloc();
            }
            for (int i = 0; i < size; i++) {
                new (&arr2[i]) T(arr[i]);
            }
            for (int i = 0; i < size; i++) {
                arr[i].~T();
            }
            free(arr);
            arr = arr2;
        }
        for (int i = size; i > index; i--) {
            new (&arr[i]) T(arr[i - 1]);
            arr[i - 1].~T();
        }
        new (&arr[index]) T(val);
        size++;
    }
template<typename T>
void DynamicArray<T>::pop_back() {
        if (size == 0) {
            throw underflow_error("Vector is empty");
        }
        size--;
        arr[size].~T();
    }
template<typename T>
void DynamicArray<T>::deleteAtIndex(int index){
        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index");
        }
        if (size == 0) {
            throw underflow_error("Dynamic Array is empty");
        }
        arr[index].~T();
        for (int i =index; i<size-1; i++) {
            new (&arr[i]) T(arr[i+1]);
            arr[i + 1].~T();
        }
        size--;
}
template<typename T>
T& DynamicArray<T>::get(int index){
    if (index < 0 || index >= size){
        throw std::out_of_range("Invalid index");
    }
    return arr[index];
}
template<typename T>
int DynamicArray<T>::getSize(){
        return size;
    }

template<typename T>
int DynamicArray<T>::getCapacity(){
        return capacity;
    }

template<typename T>
bool DynamicArray<T>::isEmpty(){
        return size == 0;
    }
template<typename T>
bool DynamicArray<T>::isFull(){
        return size==capacity;
    }

