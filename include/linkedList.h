#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstdlib>
#include<stdexcept>

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template<typename T>
class LinkedList{
private:
    int size;
    Node<T>* head;
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>&);
    LinkedList& operator=(const LinkedList<T>&);
    void push_front(const T& val);
    void push_back(const T& val);
    void pop_front();
    void pop_back();
    void insertAtIndex(int index, const T& val);
    void deleteAtIndex(int index);
    int search(const T& val);
    const T& get(int index);
};
#endif