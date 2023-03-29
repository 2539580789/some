#include<iostream>
using namespace std;
int main(){
    int p = 20;
    int * const p1 = &p; //指针常量 顶层const
    auto *p2 = p1;
    *p2 = 1;
    
    cout << *p2 << endl;
    cout << p << endl;
    return 0;
}