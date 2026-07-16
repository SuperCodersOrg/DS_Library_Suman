// #include<iostream>
// #include "include/hashMap.h"
// using namespace std;

// // int main(){
// //     DynamicArray<string> v;
// //     v.push_back("hello1");
// //     v.push_back("hello2");
// //     v.insertAtIndex(1,"hi");
// //     cout<<v.getSize()<<endl;
// //     v.deleteAtIndex(1);
// //     v.push_back("hello3");
// //     v.push_back("hello4");
// //     cout<<v.get(3)<<endl;
// //     v.insertAtIndex(0,"helllo0");
// //     cout<<v.getSize()<<endl;
// //     v.insertAtIndex(5,"hello5");
// //     v.print();
// //     v.deleteAtIndex(3);
// //     v.print();
// //     return 0;
// // }

// int main() {

//     cout << "================ HASHMAP TESTING ================\n\n";

//     HashMap<string, int> map;

//     //====================================================
//     // Test 1 : Empty HashMap
//     //====================================================
//     cout << "TEST 1 : Empty HashMap\n";
//     cout << "Size        : " << map.getSize() << endl;
//     cout << "Load Factor : " << map.getLoadFactor() << endl;
//     map.printBuckets();


//     //====================================================
//     // Test 2 : Insert
//     //====================================================
//     cout << "\nTEST 2 : Insert\n";

//     string k1="One";      int v1=1;
//     string k2="Two";      int v2=2;
//     string k3="Three";    int v3=3;
//     string k4="Four";     int v4=4;
//     string k5="Five";     int v5=5;

//     map.insert(k1,v1);
//     map.insert(k2,v2);
//     map.insert(k3,v3);
//     map.insert(k4,v4);
//     map.insert(k5,v5);

//     cout<<"Size : "<<map.getSize()<<endl;
//     cout<<"Load Factor : "<<map.getLoadFactor()<<endl;

//     map.printBuckets();


//     //====================================================
//     // Test 3 : exists()
//     //====================================================
//     cout<<"\nTEST 3 : exists()\n";

//     cout<<"Exists(One)   : "<<map.exists(k1)<<endl;
//     cout<<"Exists(Five)  : "<<map.exists(k5)<<endl;

//     string dummy="Dummy";
//     cout<<"Exists(Dummy) : "<<map.exists(dummy)<<endl;


//     //====================================================
//     // Test 4 : get()
//     //====================================================
//     cout<<"\nTEST 4 : get()\n";

//     cout<<"One   -> "<<map.get(k1)<<endl;
//     cout<<"Three -> "<<map.get(k3)<<endl;
//     cout<<"Five  -> "<<map.get(k5)<<endl;


//     //====================================================
//     // Test 5 : Update value using get()
//     //====================================================
//     cout<<"\nTEST 5 : Modify value returned by get()\n";
//     int x=100;
//     map.insert(k2,x);

//     cout<<"Updated value of Two = "<<map.get(k2)<<endl;


//     //====================================================
//     // Test 6 : remove()
//     //====================================================
//     cout<<"\nTEST 6 : remove()\n";

//     map.remove(k3);

//     cout<<"After removing Three\n";
//     cout<<"Size : "<<map.getSize()<<endl;
//     map.printBuckets();


//     //====================================================
//     // Test 7 : Exception from get()
//     //====================================================
//     cout<<"\nTEST 7 : get() Exception\n";

//     try{
//         cout<<map.get(k3)<<endl;
//     }
//     catch(exception &e){
//         cout<<"Exception : "<<e.what()<<endl;
//     }


//     //====================================================
//     // Test 8 : Exception from remove()
//     //====================================================
//     cout<<"\nTEST 8 : remove() Exception\n";

//     try{
//         map.remove(k3);
//     }
//     catch(exception &e){
//         cout<<"Exception : "<<e.what()<<endl;
//     }


//     //====================================================
//     // Test 9 : Copy Constructor
//     //====================================================
//     cout<<"\nTEST 9 : Copy Constructor\n";

//     HashMap<string,int> copyMap(map);

//     copyMap.printBuckets();


//     //====================================================
//     // Test 10 : Copy Assignment
//     //====================================================
//     cout<<"\nTEST 10 : Copy Assignment\n";

//     HashMap<string,int> assignMap;

//     assignMap=map;

//     assignMap.printBuckets();


//     //====================================================
//     // Test 11 : Deep Copy Verification
//     //====================================================
//     cout<<"\nTEST 11 : Deep Copy Verification\n";

//     string k6="Six";
//     int v6=6;

//     map.insert(k6,v6);

//     cout<<"\nOriginal\n";
//     map.printBuckets();

//     cout<<"\nCopy Constructor Object\n";
//     copyMap.printBuckets();

//     cout<<"\nAssignment Object\n";
//     assignMap.printBuckets();


//     //====================================================
//     // Test 12 : Rehash
//     //====================================================
//     cout<<"\nTEST 12 : Rehash\n";

//     for(int i=7;i<=20;i++){

//         string key="Key"+to_string(i);
//         int value=i;

//         map.insert(key,value);
//     }

//     cout<<"Size : "<<map.getSize()<<endl;
//     cout<<"Load Factor : "<<map.getLoadFactor()<<endl;

//     map.printBuckets();

//     //====================================================
//     // Test 14 : Clear
//     //====================================================
//     cout<<"\n Test 14: Clear\n";
//     map.clear();
//     cout<<"Size : "<<map.getSize()<<endl;
//     cout<<"Load Factor : "<<map.getLoadFactor()<<endl;

//     map.printBuckets();


//     //====================================================
//     // Test 13 : Destructor
//     //====================================================
//     cout<<"\nTEST 13 : Destructor\n";

//     {
//         HashMap<int,string> temp;

//         int a=10;
//         string s1="Ten";

//         int b=20;
//         string s2="Twenty";

//         temp.insert(a,s1);
//         temp.insert(b,s2);

//         temp.printBuckets();
//     }

//     cout<<"Temporary object destroyed successfully.\n";


//     cout<<"\n================ ALL TESTS PASSED ================\n";

//     return 0;
// }


#include<iostream>
#include "src/redisLite.cpp"
int main(){
    RedisLite redis;
    redis.run();
    return 0;
}