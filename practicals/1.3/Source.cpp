#include <iostream>
#include <locale>

using namespace std;

int main()
{
	locale::global(locale(""));

    int A = 3;
	int B = 4;
	int C = 25;

	if (A < B + C && B < A + C && C < A + B) {
		cout << "Цi величини можуть бути сторонами трикутника";
	}
	else {
		cout << "Цi величини не можуть бути сторонами трикутника";
	}

	return 0;
}
