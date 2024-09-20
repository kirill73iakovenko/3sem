#include <iostream>
using namespace std;

int main() {
	int size;
	int res = 0;
	cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		*(arr + i) = i * i;
		res = res + *(arr + i);
	}
	cout << res;
	delete[] arr;
		return 0;
}
