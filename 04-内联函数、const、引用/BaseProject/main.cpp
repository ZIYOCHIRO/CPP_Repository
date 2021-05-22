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


void swap_custom(int &v1, int &v2) {
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}

void testArray(int b[]) {
    b[0] = 9;
}

// 程序的入口，不能乱写
int main() {
    int a = 10;
    int b = 20;
    swap_custom(a, b);
    cout << "a = " << a << " b = " << b << endl; //a = 20 b = 10
    
    func();
    int c = sum(10, 20);
    cout << c << endl;
    
    int d = add(10, 20);
    cout << d << endl;
    
    
    /*
    int a = 10;
    int b = 10;
    // (++a) + (++a) = 23
    cout << add_1(++a) << endl;
    // (11) + (11) = 22
    cout << add_2(++b) << endl;
    */

    
    
    const int number = 10; // 常量
    Date date = {2011, 2, 4};
    Date date2 = {2017, 12, 4};
    
    //加上const，不能通过指针修改结构体
    //const Date *p = &date;
    Date *p = &date; //date的地址值
    p->year = 2015;
    (*p).month = 4;
    *p = date2;
    
    
    /*
    struct Student {int age;};
    
    Student stu1 = {10};
    Student stu2 = {20};
    
    Student *const pStu2 = &stu2;
    *pStu2 = stu1;
    (*pStu2).age = 30;
    pStu2->age = 30;
    pStu2 = &stu1;;
    */
    
    
    /*
    int age = 10;
    // *p1是常量， p1不是常量
    const int *p1 = &age;
    // *p2是常量， p2不是常量
    int const *p2 = &age;
    // p3是常量，*p3不是常量
    int * const p3 = &age;
    // *p4 和 p4 都是常量
    const int * const p4 = &age;
    // *p5 和 p5 都是常量
    int const * const p5 = &age;
    */
    
    
    /*
    int age = 10;
    // 定义了一个age的引用， ref 相当于是age的别名
    int &ref = age;
    ref = 20;
    ref += 30;
    cout << age << endl; //50
     */
    
    
    /*
    int age = 10;
    // 定义了一个age的引用， ref 相当于是age的别名
    int &ref = age;
    int &ref1 = ref;
    int &ref2 = ref1;
    
    ref += 10;
    ref1 += 10;
    ref2 += 10;
    cout << age << endl;  //40
    */
    
    
    
    
    

    
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

