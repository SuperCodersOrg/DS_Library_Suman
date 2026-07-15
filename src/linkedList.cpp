#include "../include/linkedList.h"
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
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    head = nullptr;
    size = 0;

    Node<T>* temp = other.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
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
template<typename T>
void LinkedList<T>::push_front(const T& val) {
    Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
    if (newNode == nullptr) {
        throw bad_alloc();
    }
    new (&newNode->data) T(val);
    newNode->next = head;
    head = newNode;
    size++;
}
template<typename T>
void LinkedList<T>::push_back(const T& val) {
    Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
    if (newNode == nullptr) {
        throw bad_alloc();
    }
    new (&newNode->data) T(val);
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        size++;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}
template<typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    Node<T>* temp = head;
    head = head->next;
    temp->data.~T();
    free(temp);
    size--;
}
template<typename T>
void LinkedList<T>::pop_back() {
    if (head == nullptr) {
        throw underflow_error("List is empty");
    }
    if (head->next == nullptr) {
        head->data.~T();
        free(head);
        head = nullptr;
        size--;
        return;
    }
    Node<T>* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node<T>* last = temp->next;
    temp->next = nullptr;
    last->data.~T();
    free(last);
    size--;
}
template<typename T>
void LinkedList<T>::insertAtIndex(int index, const T& val){
    if(index<0 || index>size){
        throw out_of_range("Invalid Index");
    }
    if(index==0){
        push_front(val);
        return;
    }
    if(index==size){
        push_back(val);
        return;
    }
    Node<T>* temp=head;
    int k=0;
    while(k<index-1){
        temp=temp->next;
        k++;
    }
    Node<T>* newNode=(Node<T>*)malloc(sizeof(Node<T>));
    if(newNode==nullptr){
        throw bad_alloc();
    }
    new (&newNode->data) T(val);
    newNode->next=nullptr;
    newNode->next=temp->next;
    temp->next=newNode;
    size++;
    return;
}

template<typename T>
void LinkedList<T>::deleteAtIndex(int index){
    if(size==0){
        throw underflow_error("List is empty");
    }
    if(index==0){
        pop_front();
        return;
    }
    if(index==size-1){
        pop_back();
        return;
    }
    if(index<0 || index>=size){
        throw out_of_range("Invalid Index");
    }
    int k=0;
    Node<T>* temp=head;
    while(k<index-1){
        temp=temp->next;
        k++;
    }
    Node<T>* temp1=temp->next;
    temp->next=temp1->next;
    temp1->data.~T();
    free(temp1);
    size--;
}

template<typename T>
int LinkedList<T>::search(const T& val) const{
    if(size==0){
        throw underflow_error("List is empty");
    }
    int idx=0;
    Node<T>* temp=head;
    while(temp!=nullptr){
        if(temp->data==val){
            return idx;
        }
        temp=temp->next;
        idx++;
    }
    return -1;
}

template<typename T>
const T& LinkedList<T>::get(int index) const{
    if(size==0){
        throw underflow_error("List is empty");
    }
    if(index<0||index>=size){
        throw out_of_range("Invalid Index");
    }
    int k=0;
    Node<T>* temp=head;
    while(k<index){
        temp=temp->next;
        k++;
    }
    return temp->data;
}

template<typename T>
void LinkedList<T>::traverse() const{
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

template<typename T>
int LinkedList<T>::getSize() const{
    return size;
}
template<typename T>
Node<T>* LinkedList<T>::getHead(){
    return head;
}
template<typename T>
void LinkedList<T>::remove(T& val){
        if(size==0){
            throw underflow_error("List is empty");
        }
        Node<T>* temp=head;
        if(head->data==val){
            head=head->next;
            temp->data.~T();
            free(temp);
            size--;
            return;
        }
        while(temp->next!=nullptr && !(temp->next->data==val)){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            throw runtime_error("Given object is not present in the list");
        }
        if(temp->next->data==val){
            Node<T>* temp1=temp->next;
            temp->next=temp1->next;
            temp1->data.~T();
            free(temp1);
            size--;
            return;
        }
        throw runtime_error("Given object is not present in the list");
    }