#include <iostream>
using namespace std;

int main()
{
    // ���� ������
    unsigned short nA;
    int nB;
    float nC;
    double nD;

    // ���� �������� ������
    unsigned short* pnA;
    int* pnB;
    float* pnC;
    double* pnD;

    // ����������� �������� ������ �������� ������
    pnA = &nA;
    pnB = &nB;
    pnC = &nC;
    pnD = &nD;

    // ���� ����������� ������� �����
    void* pF;
    pF = pnA; // ��������� ������ ����� nA

    // ������ ������������ �� ��������� ������� ����� ���������
    *pnA = 120;
    *pnB = -4986;
    *pnC = 234.9877775;
    *pnD = 3.4e-55;

    //���������� ������ ��� ������ 
    int sizeShort = sizeof(nA); // 2
    int sizeShortP = sizeof(pnA); // 8
    int sizeInt = sizeof(nB); // 4
    int sizeIntP = sizeof(pnB); // 8
    int sizeFloat = sizeof(nC); // 4
    int sizeFloatP = sizeof(pnC); // 8 
    int sizeDouble = sizeof(nD); // 8
    int sizeDoubleP = sizeof(pnD); // 8 
    int sizeVoid = sizeof(pF); // 8

    // ���� ��������� 
    int& linkB = nB;

    return 0;
}
