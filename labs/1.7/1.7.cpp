/**
 * Done by:
 * Student Name: Artem Bereznii
 * Student Group: 123
 * Lab 1.7
 */

using namespace std;    
/*
//Task 1
int main()
{
    {
        int nA = 5;
    }

    {
        int nB = 4;
        {
            nB = 7;
            int nC = 2;
        }
    }
}
*/
//Task 2
/*
static int A = 10;
static int B;

int main()
{
    B = 20;
    {
        static int E = 5;
        int C;
        C = A * 12;
        E = C + B;
    }
    A += 10;
    B++;

//Task 3

    float K = 20;
    int L = 0;

    for (int i = 0; i < 5; i++) {
        static int F = 0;
        F++;
        int S = 0;
        S++;
        L++;
    }

    char cA = '!';
    {
        char cA = '?';
        int Q = 1;
        {
            char cA = '@';
            int Q = 2;
            int M = 6;
        }
        Q = Q + 5;
        Q++;
    }

    for (int i = 0; i < 5; i = i + 1) {
        static int iA = 0;
        int iB = 0;
        iA = iA + 1;
        iB = iB + 1;
    }
}
*/
//Task 4
/*
static int A = 10;
static int B;

int main () 
{
    B = 20;
    {
        static int E = 5;
        int C;
        int A = 5;
        C = ::A * 12;
        E = C + B;
    }
    A += 10;
    B++;
}
*/

//Task 5

int main() {
    int* I;
    I = new int;
    *I = 25;

    int* W;
    W = new int;
    *W = 10;
    W = I;
    delete W;
}
