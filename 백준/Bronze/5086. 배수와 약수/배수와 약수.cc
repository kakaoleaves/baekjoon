#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int a, b;
	do {
		cin >> a >> b;
		if (b == 0) continue;
		else if (a % b == 0) cout << "multiple" << endl;
		else if (b % a == 0) cout << "factor" << endl;
		else cout << "neither" << endl;
	} while (a != 0 && b != 0);
	
	return 0;
}