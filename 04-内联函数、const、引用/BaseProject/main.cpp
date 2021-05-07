//
//  main.cpp
//  BaseProject
//
//  Created by ruixinyi on 2021/3/1.
//

#include <iostream>
using namespace std;


// 开辟栈空间
inline void func() {
    cout << "func()" << endl;
}
// 回收栈空间

inline int sum(int v1, int v2) {
    return v1 + v2;
}

inline void run() {
    run();
}

#define add(v1, v2) v1 + v2
#define add_1(v) v + v
inline int add_2(int v) {
    return v + v;
}


struct Date {
    int year;
    int month;
    int day;
};

// 程序的入口，不能乱写
int main() {
    cout << "Hello world" << endl;
    
    func();
    int c = sum(10, 20);
    cout << c << endl;
    
    int d = add(10, 20);
    cout << d << endl;
    
    int a = 10;
    int b = 10;
    // (++a) + (++a) = 23
    cout << add_1(++a) << endl;
    // (11) + (11) = 22
    cout << add_2(++b) << endl;


    
    
    const int number = 10; // 常量
    Date date = {2011, 2, 4};
    Date date2 = {2017, 12, 4};
    
    //加上const，不能通过指针修改结构体
    //const Date *p = &date;
    Date *p = &date; //date的地址值
    p->year = 2015;
    (*p).month = 4;
    *p = date2;
    
    int age = 10;
    const int *p1 = &age;
    int const *p2 = &age;
    int * const p3 = &age;
    const int * const p4 = &age;
    int const * const p5 = &age;
    

    return 0;
}



/*
 int a = 1;
 int b = 2;
 (a = b) = 4;
 
 a = 4, b= 2
 
 (a > b ? a : b) = 4
 a = 1, b = 4
 */
