//
//  main.cpp
//  BaseProject
//
//  Created by ruixinyi on 2021/3/1.
//

#include <iostream>
using namespace std;

// 程序的入口，不能乱写
int main() {
    cout << "Hello world" << endl;
    
    /*  以下 3 种写法等价
    // 1
    cout << "a";
    cout << "\n";
    cout << "b";
    
    // 2
    cout << "c";
    cout << endl;
    cout << "d";

    // 3
    cout << "e" << endl << "f";
    
    */
    cout << "please type a number:" << endl;
    int age;
    cin >> age;
    cout << "age is " << age << endl;
    
    /*
     get char的用途？
     等待键盘输入（如果敲回车，就会读取键盘输入）
     */
    getchar(); // 怎么用？
    getchar();
    return 0;
}

/*
 Java：先有类，再有方法
 C++：可以直接写方法
 C++完全兼容C
 */

