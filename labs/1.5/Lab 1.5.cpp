/*
    Done by :
    Student Name : Artem Bereznii
    Student Group : 123
    Lab 1.5
*/
    
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    //Task 1
    {
        int a1 = 6;
        int b1 = 2;
        int c1 = 7;
        int d1 = 14;

        // <скн1> (<скн2> (A<нб1>B) <акн> (<скн3> (C<нб2>D)))
        //  empty (  !    (a1 == b1)    ^   (   !   (c1 != d1)))
        bool res1 = (!(a1 == b1) ^ (!(c1 != d1)));
        cout << "res1: " << boolalpha << res1 << endl;
    }
    
    //Task 2
    {
        int a2 = 7;
        int b2 = 7;
        int c2 = 24;
        int d2 = 1;

        // <скн1> (<скн2> (A<нб1>B) <акн> (<скн3> (C<нб2>D)))
        //  empty (  !    (a2 == b2)    ^   (   !   (c2 != d2)))
        bool res2 = (!(a2 == b2) ^ (!(c2 != d2)));
        cout << "res2: " << boolalpha << res2 << endl;
    }

    //Task 3
    {
        const int a3 = 356;
        int b3 = 35;
        float c3;
        float* pc3;
        pc3 = &c3;
        *pc3 = 151.27;
        //Literal 5
        int e3 = 57;
        float f3;

        //((A <ан1> <сн> B) <юн1> <ян> C) <нб>( D <юн2>( E <ан2> <аЮГн> F))
        // a3   |     ~  b3    /    *  pc3  >   5   +   e3  <<   sizeof f3 ;
        bool res3 = ((a3 | ~b3) / *pc3) > (5 + (e3 << sizeof(f3)));
        cout << "res3: " << boolalpha << res3 << endl;
    }

    return 0;
}