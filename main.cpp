#include<iostream>
#include "dynamicArray.h"
using namespace std;

int main(){
    DynamicArray<string> v;
    v.push_back("hello1");
    v.push_back("hello2");
    v.insertAtIndex(1,"hi");
    cout<<v.getSize()<<endl;
    v.deleteAtIndex(1);
    v.push_back("hello3");
    v.push_back("hello4");
    cout<<v.get(3)<<endl;
    v.insertAtIndex(0,"helllo0");
    cout<<v.getSize()<<endl;
    v.insertAtIndex(5,"hello5");
    v.print();
    v.deleteAtIndex(6);
    v.print();
    return 0;
}