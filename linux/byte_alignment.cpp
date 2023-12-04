#include <iostream>
#include <stdio.h>

using namespace std;

struct S{
    double a;
    char b;
    short c;
};

#pragma pack (2)      //指定按2字节对齐
struct Test
{
    char a;
    int b;
    short c;
};
#pragma pack () 

int main () {

    S s;
    printf("s.size %lu\n", sizeof(Test));
    
    printf("s.a %p\n", &s.a);
    printf("s.b %p\n", &s.b);
    printf("s.c %p\n", &s.c);

    return 0;
}