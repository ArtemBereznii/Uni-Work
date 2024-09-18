/*
    Done by :
    Student Name : Artem Bereznii
    Student Group : 123
    Lab 1.6
*/

#include <iostream>

int main()
{
    // Part 1
    const char CONST1 = '%';
    char chVar1;
    chVar1 = 'k';
    char chVar2 = '8';

    const char CONST2 = 0x12; // 18
    char chVar3;
    chVar3 = 0x70;// p 
    char chVar4 = 0x5a;// Z

    // Part 2
    // 
    //Task 1
    int a;
    float b;
    unsigned short c;

    //Task 2
    a = 23678;
    b = 1.23e4;
    c = 11974;

    //Task 3
    double d;
    int e;
    char f;

    //Task 4.1
    d = a;
    e = b;
    f = c;

    //Task 4.2
    d = (double)a;
    e = (int)b;
    f = (char)c;

    //Task 4.3
    void* pV;

    double* pD;
    pV = &a;
    pD = (double*)pV;
    d = *pD;

    int* pE;
    pV = &b;
    pE = (int*)pV;
    e = *pE;

    char* pF;
    pV = &c;
    pF = (char*)pV;
    f = *pF;
}
