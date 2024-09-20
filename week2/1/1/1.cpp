#include <iostream>
using namespace std;

int main() {
	int num;
	int res = 0;
	cin >> num;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) res = i;
	}
	if (res == 0) {
		cout << "Prime number";
	}
	else {
		cout << res;
	}
	return 0;
}