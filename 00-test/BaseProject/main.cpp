//
//  main.cpp
//  BaseProject
//
//  Created by ruixinyi on 2021/3/1.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int strStr(string haystack, string needle) {
    if (needle.length() > haystack.length()) {
        return -1;
    }
    
    if (strcmp(haystack.c_str(), needle.c_str()) == 0) {
        return 0;
    }
    
    return 1;
}

// 程序的入口，不能乱写
int main() {
    cout << "Hello world" << endl;
    int add = strStr("hello", "ll");
    cout << add << endl;
    return 0;
}
