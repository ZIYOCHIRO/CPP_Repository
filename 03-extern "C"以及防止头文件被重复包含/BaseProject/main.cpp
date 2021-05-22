//
//  main.cpp
//  BaseProject
//
//  Created by ruixinyi on 2021/3/1.
//

#include <iostream>
using namespace std;
/* C 语言不支持重载，两种写法
extern "C" void func() {}
extern "C" void func(int a) {}
 
 extern "C" {
 void func() {}
 void func(int a) {}
 }
 */

/* 声明要用extern "C"标记， 有以下两种写法：
extern "C" void func();
extern "C" void func(int a);

 extern "C" {
 void func();
 void func(int a);
 }

 */

/* 这样是可以调用的
 最终生成的两个函数名字是不一样的
 */
void func();  // name mangling
extern "C" void func(int a);

/* 二义性问题，在main()函数里调用func()时，不知道调用的事哪个函数
void func()
extern "C" void func()
 */


/*
 C++ 调用 C 的方法
 */
extern "C" {
//int sum(int v1, int v2);
//int sub(int v1, int v2);
void other();
}

// include 会将math.h里的所有内容copy到这里
#include "math.h"

int main() {
    cout << "Hello world" << endl;
    
    cout << sum(10,20) << endl;
    cout << sub(30,20) << endl;
    other();
    
    return 0;
}

// 实现
void func() {
    cout << "func()" << endl;
}
void func(int a) {
    cout << "func(int a)" << a << endl;
}

/*
 Q：什么时候用 extern "C" 标记
 A：C、C++混合开发中， C++ 调用C语言时

 */

