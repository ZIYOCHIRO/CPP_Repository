## extern "C"

### 1.被extern "C" 修饰的代码会按照C语言的方式去编译

```
extern "C" void func() {
    cout << "func()" << endl;
}

extern "C" void func(int age) {
    cout << "func(int age) " << age << endl;
}

// 另一种写法
extern "C" {
    void func() {
        cout << "func()" << endl;
    }

void func(int age) {
        cout << "func(int age) " << age << endl;
    }
}
```

### 2.如果函数同时有声明和实现，要让函数声明被extern "C" 修饰，函数实现可以不修饰


```
// ----- 声明 -----

extern "C" void func();
extern "C" void func(int age);
// 另一种写法
extern "C" {
void func();
void func(int age);
}


// ----- 实现 -----

void func() {
    cout << "func()" << endl;
}

void func(int age) {
    cout << "func(int age) " << age << endl;
}
```

### 3.什么时候用extern "C" 标记？

C、C++混合开发中， C++ 调用C语言时。
例如，有一个math.c文件，里面实现了加法和减法两个方法：
```
//math.h
int sum(int v1, int v2);
int sub(int v1, int v2);

// ----- 分割线 -----

//math.c
#include <stdio.h>
#include "math.h"
int sum(int v1, int v2) {
    return v1 + v2;
}

int sub(int v1, int v2) {
    return v1 - v2;
}

```
如果想要在main.cpp里调用这两个方法，需要先#include "math.h"，再调用
 include 会将math.h里的所有内容copy到这里
```

#include "math.h"
/* 上面的include等同于
int sum(int v1, int v2);
int sub(int v1, int v2);
*/

int main() {
    cout << "Hello world" << endl;
    
    cout << sum(10,20) << endl;  //调用加法
    cout << sub(30,20) << endl;  //调用减法
    return 0;
}
```


## 防止头文件被重复包含

```
#include "math.h"   // <<< 1 >>>
#include "math.h"   // <<< 2 >>>

int main() {
    cout << "Hello world" << endl;
    
    cout << sum(10,20) << endl;  //调用加法
    cout << sub(30,20) << endl;  //调用减法
    return 0;
}
```
如果一个头文件被include了两次，那么就会将头文件的所有内容copy两次，为了防止头文件被重复包含，可以用下面两种方法：
### 1.使用#ifndef、#define、#endif

在math.h中：
```
#ifndef __MATH_H         //防止重复包含，宏一般与文件名称相同(math.h)
#define __MATH_H


#ifdef __cplusplus       // 只有在C++环境被extern "C" 修饰
extern "C" {
#endif                   // 对应ifdef __cplusplus
int sum(int v1, int v2);
int sub(int v1, int v2);
#ifdef __cplusplus       // 只有在C++环境有"{"
}
#endif                   // 对应ifdef __cplusplus

#endif                   // 对应ifndef __MATH_H
```
当math.h 在main.cpp里被include两次时，相当于将头文件内容copy两次，如下：
```
//========= 1 =========
#ifndef __MATH_H        // 如果没有定义「__MATH_H」这个宏，定义这个宏
#define __MATH_H


#ifdef __cplusplus     
extern "C" {
#endif                   
int sum(int v1, int v2);
int sub(int v1, int v2);
#ifdef __cplusplus       
}
#endif                  

#endif                   // 对应ifndef __MATH_H

//========= 2 =========
#ifndef __MATH_H         // 由于上面已经定义「__MATH_H」这个宏了，下面的代码都不会执行
#define __MATH_H


#ifdef __cplusplus       
extern "C" {
#endif                   
int sum(int v1, int v2);
int sub(int v1, int v2);
#ifdef __cplusplus       
}
#endif                   

#endif                   // 对应ifndef __MATH_H

//========= main =========
int main() {
    cout << "Hello world" << endl;
    
    cout << sum(10,20) << endl;  //调用加法
    cout << sub(30,20) << endl;  //调用减法
    return 0;
}
```


### 2.使用#pragma once - 可以防止整个文件的内容被重复包含

在头文件的首行加#pragma once，如在math.h中
```
#pragma once

#ifdef __cplusplus       // 只有在C++环境被extern "C" 修饰
extern "C" {
#endif                   // 对应ifdef __cplusplus
int sum(int v1, int v2);
int sub(int v1, int v2);
#ifdef __cplusplus       // 只有在C++环境有"{"
}
#endif                   // 对应ifdef __cplusplus

```

两种方法的区别：
- #ifndef、#define、#endif受C\C++标准的支持，不受编译器的任何限制
- 有些编译器不支持#pragma once（较老编译器不支持，如GCC 3.4版本之前），兼容性不够好
- #ifndef、#define、#endif可以针对一个文件中的部分代码，而#pragma once只能针对整个文件

