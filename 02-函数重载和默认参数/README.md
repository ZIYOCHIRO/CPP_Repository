## 函数重载

1.函数名相同，参数的【个数】不同
```
int sum(int v1, int v2) {
    return v1 + v2;
}

int sum(int v1, int v2, int v3) {
    return v1 + v2 + v3;
}
```
2.函数名相同，参数的【类型，顺序】不同
```
void func(int v1, double v2) {
    cout << "func(int v1, double v2)" << endl;
}

void func (double v1, int v2) {
    cout << "func (double v1, int v2)" << endl;
}
```
3.函数的【返回值】类型不同，不可以被重载。返回值类型鱼函数重载无关
(functions that differ only in their return types cannot be overloaded.)
```
void fun() {
}

int fun() {
    return 1;
}
```
4.参数的隐式转换会产生二义性
```
void display(long a) {
    cout << "display(long a)" << endl;
}

void display(double a) {
    cout << "display(double a)" << endl;
}

int main() {
    display(10L);  //参数类型为long，找到display(long)
    display(10.0); //参数类型为double，找到display(double)
    display(10);   //参数类型为int，调用哪个display()???
    return 0;
}
```
5.C语言不支持函数重载，但是C++支持。
 C++采用了name mangling 或者 name decoration 技术，对函数名进行改编、修饰。 重载时会生成多个不同的函数名，不同编译器（MSVC、g++）有不同的生成规则。
```

void display(int a) {
    cout << "display(int a)" << endl;
}
改编后：
void display_i(long a){}

void display(long a) {
     cout << "display(long a)" << endl;
 }
改编后：
void display_l(long a){}

void display(double a) {
     cout << "display(double a)" << endl;
 }
改编后：
void display_d(double a){}

int main() {
    // 根据传入参数的类型不同，找到对应的函数调用；
    display(10);
    display(10L);
    display(10.0);

    return 0;
}
```


## 默认参数

C++允许函数设置默认参数，在调用时可以根据情况省略实参
```
// testFunc的默认参数v1=5， v2=6
int testFunc(int v1 = 5, int v2 = 6) {
    return v1 + v2;
}

int main() {
    cout << testFunc() << endl;       //11 一个参数都不传  v1 = 5,v2 = 6
    cout << testFunc(10) << endl;     //16 传一个参数     v1 = 10,v2 = 6
    cout << testFunc(10,20) << endl;  //30 传两个参数     v1 = 10,v2 = 20
    return 0;
}
```
默认参数的设置有以下几个规则：
1.默认参数只能按照右到左的顺序
```
int testFunc1(int v1, int v2 = 6) {
    return v1 + v2;
}
int testFunc1_1(int v1, int v2 = 6, int v3 = 7) {
    return v1 + v2 + v3;
}
int main() {
    testFunc1(5);   //v1 = 5, v2 = 6（默认）
    testFunc1(1,2); //v1 = 1, v2 = 2
  
    
    testFunc1_1(5); //v1 = 5, v2 = 6（默认）, v3 = 7（默认）

    return 0;
}
```
2.如果函数同时有声明，实现，默认参数只能放在函数声明中
```
#include <iostream>
using namespace std;

// 函数声明：默认参数只能放在函数声明中
int testFunc2(int v1 = 5, int v2 = 6);

int main() {
    // 调用testFunc2
    testFunc2();
    return 0;
}
// 实现
int testFunc2(int v1, int v2) {
    return v1 + v2;
}
```
3.默认参数的值可以是常量、全局符号（全局变量、函数名）
```
1.常量
int testFunc2(int v1 = 5, int v2 = 6) {}
2.全局变量
int age = 20;
int testFunc2_1(int v1 = 5, int v2 = age) {}
3.函数名
void test(int a) {
    cout << "test(int)" << a << endl;
}
// 函数作为参数
void testFunc2_2(int v1, void(*t)(int)) {
    t(v1);
}
// 函数作为参数 且默认函数名为test
void testFunc2_3(int v1, void(*t)(int) = test) {
    t(v1);
}

int main() {
    // 将15传给v1，将test传给指针t
    testFunc2_2(15, test);
    testFunc2_3(15);
    testFunc2_3(15, test);

    return 0;
}
```
Q:什么情况下用默认参数？
A:如果函数的实参经常是同一个值

函数重载和默认参数可能会产生冲突、二义性（建议优先选择使用默认参数）
```
void display(int a, int b = 20) {
    cout << "a is " << a << endl;
}

void display(int a) {
    cout << "a is " << a << endl;
}

int main {
    display(10); //当只传一个参数时，不能确认是调用上面的还是下面的display方法
    return 0;
}
```

Other

Debug模式：很多调试信息，生成的可执行文件比较臃肿
Release模式：去除调试信息，并且优化，生成的可执行文件比较精简、高效



```
1010 1010 1111 0001 1010 1011
AA F1 AB
2个16进制代表1个字节(1byte = 8bits)
```











