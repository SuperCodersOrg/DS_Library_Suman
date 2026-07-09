#include "linkedList.h"
using namespace std;

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        temp->data.~T(); 
        free(temp);
    }
    head = nullptr;
    size = 0;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this == &other) {
        return *this;
    }
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        temp->data.~T();
        free(temp);
    }
    head = nullptr;
    size = 0;
    Node<T>* temp = other.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
    return *this;
}