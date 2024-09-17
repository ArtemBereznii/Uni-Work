#include <iostream>
using namespace std;

int A = 0;

int main()
{
	if (A > 0) {
		A++;
	}
	else if (A < 0) {
		A -= 2;
	}
	else {
		A = 10;
	}
	return 0;
}


