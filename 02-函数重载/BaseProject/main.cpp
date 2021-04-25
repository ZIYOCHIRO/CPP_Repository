//
//  main.cpp
//  BaseProject
//
//  Created by ruixinyi on 2021/3/1.
//

#include <iostream>
using namespace std;

// 1.函数名相同，参数的【个数】不同
int sum(int v1, int v2) {
    return v1 + v2;
}

int sum(int v1, int v2, int v3) {
    return v1 + v2 + v3;
}
// 2.函数名相同，参数的【类型，顺序】不同
void func(int v1, double v2) {
    cout << "func(int v1, double v2)" << endl;
}

void func (double v1, int v2) {
    cout << "func (double v1, int v2)" << endl;
}

// 3.函数的【返回值】类型不同，不可以被重载
// functions that differ only in their return types cannot be overloaded.
//void fun() {
//
//}
//int fun() {
//    return 1;
//}
// 程序的入口，不能乱写
int main() {
    cout << "Hello world" << endl;
    return 0;
}
