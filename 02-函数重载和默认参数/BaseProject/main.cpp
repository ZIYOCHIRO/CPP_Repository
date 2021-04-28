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

// 3.函数的【返回值】类型不同，不可以被重载。返回值类型鱼函数重载无关
// functions that differ only in their return types cannot be overloaded.
//void fun() {
//
//}
//int fun() {
//    return 1;
//}


//4.参数的隐式转换会产生二义性

//void display(int a) {
//    cout << "display(int a)" << endl;
//}
void display(long a) {
    cout << "display(long a)" << endl;
}

void display(double a) {
    cout << "display(double a)" << endl;
}


//5.默认参数
/*
C++允许函数设置默认参数，在调用时可以根据情况省略实参，规则如下：
 
什么情况下用默认参数？
如果函数的实参经常是同一个值
*/
int testFunc(int v1 = 5, int v2 = 6) {
    return v1 + v2;
}

int testFunc1(int v1, int v2 = 6) {
    return v1 + v2;
}

// 声明
int testFunc2(int v1 = 5, int v2 = 6);
// 程序的入口，不能乱写

int age = 20;
int testFunc2_1(int v1 = 5, int v2 = age);


void test(int a) {
    cout << "test(int)" << a << endl;
}

void anotherFunc(int v1, void(*t)(int)) {
    t(v1);
}

void anotherFunc_1(int v1, void(*t)(int) = test) {
    t(v1);
}


//6.函数重载和默认参数可能会产生冲突、二义性（建议优先选择使用默认参数）
/*
 
 */
int main() {
    
    /*
    display(10); // 不明确是调用display(long a)还是display(double a)
    display(10L);
    display(10.0);
    */
    
    cout << testFunc() << endl;       //11
    cout << testFunc(10) << endl;     //16
    cout << testFunc(10,20) << endl;  //30
    
    testFunc2();
    
    //p指针所指向的函数没有返回值，但是有参数
    void(*p)(int) = test;
    p(10);
    
    // 将10传给v1，将test传给指针t
    anotherFunc(15, test);
    anotherFunc_1(15);
    anotherFunc_1(15, test);
    return 0;
}


// 实现
int testFunc2(int v1, int v2) {
    return v1 + v2;
}

int testFunc2_1(int v1, int v2) {
    return v1 + v2;
}

/* C语言不支持函数重载，但是C++支持
 C++采用了name mangling 或者 name decoration 技术，对函数名进行改编、修饰
 重载时会生成多个不同的函数名，不同编译器（MSVC、g++）有不同的生成规则
改编后：display_int
void display(int a) {
    cout << "display(int a)" << endl;
}
 改编后：display_long
 void display(long a) {
     cout << "display(long a)" << endl;
 }
 改编后：display_double
 void display(double a) {
     cout << "display(double a)" << endl;
 }
*/


/*
 1010 1010 1111 0001 1010 1011
 AA F1 AB
 2个16进制代表1个字节(1byte = 8bits)
 */

/*
 Debug模式：
 Release
 */
