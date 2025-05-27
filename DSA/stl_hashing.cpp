#include<bits/stdc++.h>
using namespace std;


// pairs : used to store a pair of integers

// int main(){
//     pair<int,int>p={54,163};
//     cout<<p.first<<endl;
//     cout<<p.second<<endl;
   
   
//    // now this pairing can't store a more than two integers at a time, hence to store more than two digits at a time, we use nested pairs
//     pair<pair<int,int>,pair<int,int>>q={{45,12},{48,16}};
//     cout<<q.first.first<<endl;
//     cout<<q.second.second<<endl;
//     cout<<q.second.first<<endl;
//     cout<<q.first.second<<endl;
    

//     // array of pairs
//     pair<int,int>array[]={{1,2},{3,4},{6,5}};
//     cout<<array[0].first<<endl;
//     cout<<array[2].first<<endl;
//     return 0;
// }

// arrays 

// int main(){
//     array<int,6> a={1,2,3,4,6};   // array keyword <datatype,size> name={values}
//     int size=a.size();
//     cout<<size<<endl;
//     for(int i=0;i<size;i++){
//         cout<<a[i]<<"\t";
//     }
//     cout<<endl;
//     cout<<"2nd position:"<<a.at(2)<<endl;
//     cout<<"First element:"<<a.front()<<endl;
//     cout<<"Last element:"<<a.back()<<endl;
//     cout<<"Empty or not:"<<a.empty()<<endl;

// }


// vector: dynamic array : length can be varied
// size of array means maximum possible elements that it can accomodate, there is nothing like capacity in array
// for vecotr : size is no of elements present in vector whereas capacity means total no of elements it can accomodate

int main(){
//     vector<int>a;
//     a.push_back(5);
//     cout<<"Element:"<<a.at(0);
//     cout<<"SIZE:"<<a.size()<<"capacity:"<<a.capacity()<<endl;
//     a.push_back(6);
//     cout<<"Element:"<<a.at(1);
//     cout<<"SIZE:"<<a.size()<<"capacity:"<<a.capacity()<<endl;
//     a.push_back(7);
//     cout<<"Element:"<<a.at(2);
//     cout<<"SIZE:"<<a.size()<<"capacity:"<<a.capacity()<<endl;
//     a.push_back(8);
//     cout<<"Element:"<<a.at(3);
//     cout<<"SIZE:"<<a.size()<<"capacity:"<<a.capacity()<<endl;
//     a.push_back(9);
//     cout<<"Element:"<<a.at(4);
//     cout<<"SIZE:"<<a.size()<<"capacity:"<<a.capacity()<<endl;

//     // results: 
//     // Element:5 SIZE:1 capacity:1
//     // Element:6 SIZE:2 capacity:2
//     // Element:7 SIZE:3 capacity:4
//     // Element:8 SIZE:4 capacity:4
//     // Element:9 SIZE:5 capacity:8

//     // a.pop_back(); -- removes last elemennt
//     // a.clear(); -- removes all elements and makes size zero not capacity
//     //cout<<"2nd position:"<<a.at(2)<<endl;
//     //cout<<"First element:"<<a.front()<<endl;
//     //cout<<"Last element:"<<a.back()<<endl;
//     //cout<<"Empty or not:"<<a.empty()<<endl;

    //  creating vector of pair data type:
    // vector<pair<int,int>> v;
    // v.push_back({1,2});
    // v.emplace_back(3,5);


    //iterating through a vector using iterator
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // vector<int>::iterator it=v.begin();
    // for(int i=0;i<4;i++){
    //     cout<<(*it);
    //     it++;
    // }
    // vector<int>::iterator it=v.end();
    // for(int i=0;i<4;i++){
    //     it--;
    //     cout<<(*it);

    // }
    // auto it=v.begin(); --- analogous shorter declaration

    // for(auto i:v){
    //     cout<<i;
    // }
    // return 0;
}

// int main(){
//     //other methods of initializing a vector:
//     vector<int> a(5,2);
//     for(int i:a){
//         cout<<i<<endl;
//     }

//     // copying whole vector into another vector:
//     vector<int> copy(a);
//     for(int i:copy){
//         cout<<i<<endl;
//     }
//     return 0;
// }

// in vectors, elements can be inserted or deleted at the end only
// for doing both end and beginning operations, we use deque

// int main(){
//     deque<int>d;
//     d.push_back(5);
//     d.push_front(6);
//     d.push_back(3);
//     d.push_front(4);
//     d.pop_back();
//     d.pop_front();
//     cout<<d.front()<<endl;
//     cout<<d.back()<<endl;
//     cout<<d.empty()<<endl;
//     cout<<d.size()<<endl;
//     for(int i:d){
//         cout<<i<<"\t";
//     }
//     cout<<endl;
//     d.push_back(7);
//     d.push_back(3);
//     for(int i:d){
//         cout<<i<<"\t";
//     }
//     cout<<endl;
//     d.erase(d.begin(),d.begin()+2);
//     for(int i:d){
//         cout<<i<<"\t";
//     }
//     cout<<d.max_size();  -- depends upon compiler not equal to capacity
//     return 0;
// }

// list has same functions like deque

// stack has same fucntions  as vector:
// push_back is replaced by push
// pop_back is replaced by pop
// the last element is retrived first by using top() function


// queue: same as stack just that first element is retrived first using front() method