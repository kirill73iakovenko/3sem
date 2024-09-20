#include <iostream>
using namespace std;

int main() {
	int res, num;
	res = 0;
	cin >> num;
	while (num != 0) {
		if (num > 0) {
			res = res + num;
		}
		cout << "result:\t" << res;
		cin >> num;
	}
	return 0;
}