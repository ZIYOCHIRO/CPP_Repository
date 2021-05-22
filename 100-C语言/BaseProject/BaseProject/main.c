//
//  main.c
//  BaseProject
//
//  Created by ruixinyi on 2021/5/22.
//

#include <stdio.h>
#include "string.h"
int main(int argc, const char * argv[]) {

    return 0;
}







void baseDataType(){
    
   // 基本数据类型 整型int 浮点型float(单精度浮点数) double（双精度浮点数） 字符型char
    int a;
    int a_1 = 10;
    char b = 'A';
    char b_1 = 65;  // char的取值范围是：ASCII码字符 或者 -128~127的整数

    //在64位环境下，short占2个字节(16位)，int占4个字节(32位)，long占8个字节(64位)。
    short int s1 = 1;
    int s2 = 2;
    long int s3 = 3;
    
    
    //signed的取值范围是-32768~32767，那么unsigned的取值范围是0~65535，当然，不同的编译器有不同的取值范围
    signed int s4 = 1;
    unsigned int s5 = 2;
}

void arrayFunc() {
    // 数据
    int a[4]; // 定义含有4个int类型元素的数组
    //数组名a代表着整个数据的地址，是个常量，也就是数组的起始地址，（第一个元素的地址就是整个数组的地址）
    a == &a[0];
    
    printf("a is %p\n a[0] address is %p\n a[1] address is %p\n a[2] address is %p\n a[3] address is %p\n " , a, &a[0], &a[1], &a[2], &a[3]);
    
    int b[4] = {1, 2};
    b[2] = 3;
    b[3] = 4;
}


void stringFunc() {
    // 字符串
    char a[3] = {'h', 'i', '\0'};
    
    char b[3];
    b[0] = 'h';
    b[1] = 'i';
    b[2] = '\0';
    
    char c[3] = "hi";  //系统会自动在字符串尾部加上一个\0结束符
    
    char d[] = "hi";
    
    int size = strlen("hi");
    char e[] = "hello";
    int size1 = strlen(e);
    printf("%d, %d\n", size, size1);
    
    
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "aBc";
    char s4[] = "ccb";
    
    printf("%d, %d, %d\n", strcmp(s1, s2), strcmp(s1, s3), strcmp(s1, s4));
}
