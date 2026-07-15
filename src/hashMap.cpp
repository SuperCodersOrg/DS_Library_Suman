#include<iostream>
#include<iomanip>
#include "../include/hashMap.h"
using namespace std;

template<typename K, typename V>
HashNode<K,V>::HashNode() = default;

template<typename K, typename V>
HashNode<K,V>::HashNode(const K& key, const V& value): key(key), value(value){}

template<typename K, typename V>
HashNode<K,V>::HashNode(const K& key): key(key), value(){}

template<typename K, typename V>
HashNode<K,V>::HashNode(const HashNode<K,V>& other): key(other.key), value(other.value){}
template<typename K, typename V>
HashNode<K,V>::~HashNode()=default;

template<typename K, typename V>
bool HashNode<K,V>::operator==(const HashNode& other) const {
    return key == other.key;
}
template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const HashNode<K,V>& node) {
    os << "{Key: " << node.key << ", Value: " << node.value << "}";
    return os;
}
template<typename K, typename V>
HashMap<K,V>::HashMap(){
    size=0;
    capacity=16;
    loadfactor=0.0;
    threshold=0.70;
    for(int i=0;i<16;i++){
        bucketArray.push_back(nullptr);
    }
}
template<typename K, typename V>
HashMap<K,V>::~HashMap(){
    clear();
}
template<typename K, typename V>
HashMap<K,V>& HashMap<K,V>::operator=(const HashMap<K,V>& other){
    if(this == &other){
        return *this;
    }       
    clear();
    bucketArray = DynamicArray<LinkedList<HashNode<K,V>>*>();
    size = other.size;
    capacity = other.capacity;
    loadfactor = other.loadfactor;
    threshold = other.threshold;
    for(int i = 0; i < capacity; i++){
        if(other.bucketArray[i] == nullptr){
            bucketArray.push_back(nullptr);
        }
        else{
            LinkedList<HashNode<K,V>>* list =(LinkedList<HashNode<K,V>>*)malloc(sizeof(LinkedList<HashNode<K,V>>));
            if(list == nullptr){
                throw bad_alloc();
            }    
            new (list) LinkedList<HashNode<K,V>>(*other.bucketArray[i]);
            bucketArray.push_back(list);
        }
    }
    return *this;
}
template<typename K, typename V>
HashMap<K,V>::HashMap(const HashMap<K,V>& other){
    size = other.size;
    capacity = other.capacity;
    loadfactor = other.loadfactor;
    threshold = other.threshold;
    for(int i = 0; i < capacity; i++){
        if(other.bucketArray[i] == nullptr){
            bucketArray.push_back(nullptr);
        }
        else{
            LinkedList<HashNode<K,V>>* list =(LinkedList<HashNode<K,V>>*)malloc(sizeof(LinkedList<HashNode<K,V>>));
            if(list == nullptr){
                throw bad_alloc();
            }
            new (list) LinkedList<HashNode<K,V>>(*other.bucketArray[i]);
            bucketArray.push_back(list);
        }
    }
}

template<typename K, typename V>
int HashMap<K,V>::getbucketIndex(int hashcode){
    return ((hashcode%capacity)+capacity)%capacity;
}
template<typename K, typename V>
void HashMap<K,V>::rehash(){
    int oldCapacity = capacity;
    capacity *= 2;
    DynamicArray<LinkedList<HashNode<K,V>>*> bucketArray2;
    loadfactor=float(size)/capacity;
    for(int i = 0; i < capacity; i++){
        bucketArray2.push_back(nullptr);
    }
    for(int i = 0; i < oldCapacity; i++){
        if(bucketArray[i]==nullptr){
            continue;
        }
        Node<HashNode<K,V>>* current = bucketArray[i]->getHead();
        while (current != nullptr) {
            int hashcode = h.generateHash(current->data.key);
            int bucketIndex = getbucketIndex(hashcode);
            if (bucketArray2[bucketIndex] == nullptr) {
                LinkedList<HashNode<K,V>>* list =(LinkedList<HashNode<K,V>>*)malloc(sizeof(LinkedList<HashNode<K,V>>));
                if (list == nullptr){
                    throw bad_alloc();
                }
                new (list) LinkedList<HashNode<K,V>>();
                bucketArray2[bucketIndex] = list;
            }
            bucketArray2[bucketIndex]->push_front(current->data);
            current = current->next;
        }
    }
    for (int i = 0; i < oldCapacity; i++) {
        if (bucketArray[i] != nullptr) {
            bucketArray[i]->~LinkedList<HashNode<K,V>>();
            free(bucketArray[i]);
        }
    }
    bucketArray = bucketArray2;
}
template<typename K, typename V>
void HashMap<K,V>::insert(K& key, V& value){
    if(loadfactor>threshold){
        rehash();
    }
    if(exists(key)){
        get(key)=value;
        return;
    }
    int hashcode= h.generateHash(key);
    int bucketIndex=getbucketIndex(hashcode);
    HashNode<K,V> temp(key,value);
    if(bucketArray[bucketIndex]==nullptr){
        LinkedList<HashNode<K,V>>* list=(LinkedList<HashNode<K,V>>*)malloc(sizeof(LinkedList<HashNode<K,V>>));
        if(list == nullptr){
            throw bad_alloc();
        }
        new(list) LinkedList<HashNode<K,V>>();
        bucketArray[bucketIndex]=list;
        list->push_front(temp);
    }
    else{
        bucketArray[bucketIndex]->push_front(temp);
    }
    size++;
    loadfactor = (float)size / capacity;
}
template<typename K, typename V>
void HashMap<K,V>::remove(K& key){
    if(!exists(key)){
        throw runtime_error("Given key is not present");
    }
    int hashcode= h.generateHash(key);
    int bucketIndex=getbucketIndex(hashcode);
    LinkedList<HashNode<K,V>>* list = bucketArray[bucketIndex];
    HashNode<K,V>temp(key);
    list->remove(temp);
    if(list->getSize() == 0){
        list->~LinkedList<HashNode<K,V>>();
        free(list);
        bucketArray[bucketIndex] = nullptr;
    }
    size--;
    loadfactor=(float)size/capacity;
}
template<typename K, typename V>
bool HashMap<K,V>::exists(K& key){
    int hashcode= h.generateHash(key);
    int bucketIndex=getbucketIndex(hashcode);
    if(bucketArray[bucketIndex]==nullptr){
        return false;
    }
    else{
        Node<HashNode<K,V>>* current = bucketArray[bucketIndex]->getHead();
        while(current != nullptr) {
            if(current->data.key == key) {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}
template<typename K, typename V>
V& HashMap<K,V>:: get(K& key){
    int hashcode= h.generateHash(key);
    int bucketIndex=getbucketIndex(hashcode);
    if(bucketArray[bucketIndex]==nullptr){
        throw runtime_error("Given key is not present");
    }
    Node<HashNode<K,V>>* current = bucketArray[bucketIndex]->getHead();
    while(current != nullptr) {
        if(current->data.key == key) {
            return current->data.value;
        }
        current = current->next;
    }
    throw runtime_error("Given key is not present");
}
template<typename K, typename V>
int HashMap<K,V>::getSize(){
    return size;
}
template<typename K, typename V>
float HashMap<K,V>::getLoadFactor(){
    return loadfactor;
}
template<typename K, typename V>
void HashMap<K,V>::clear(){
    for(int i = 0; i < capacity; i++){
        if(bucketArray[i] != nullptr){
            bucketArray[i]->~LinkedList<HashNode<K,V>>();
            free(bucketArray[i]);
            bucketArray[i]=nullptr;
        }
    }
    size=0;
    loadfactor=0.0;
}
template<typename K, typename V>
void HashMap<K,V>::printBuckets() {
    for(int i = 0; i < capacity; i++) {
        cout << i << " : ";
        if(bucketArray[i] == nullptr) {
            cout << "NULL";
        }
        else {
            bucketArray[i]->traverse();
        }
        cout << endl;
    }
}
template<typename K, typename V>
void HashMap<K,V>::showAll() const{
    cout << left<< setw(20) << "Key"<< "Value" << endl;
    cout << string(35, '-') << endl;
    for(int i = 0; i < capacity; i++){
        if(bucketArray[i] != nullptr){
            Node<HashNode<K,V>>* temp = bucketArray[i]->getHead();
            while(temp != nullptr){
                cout << left<< setw(20) << temp->data.key<< temp->data.value<< endl;
                temp = temp->next;
            }
        }
    }
}
