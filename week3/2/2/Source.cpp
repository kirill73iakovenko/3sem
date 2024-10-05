#include <iostream>



using namespace std;

int find_elem(int arr[], int elem, int size);
float find_elem(float arr[], float elem, int size);
char find_elem(char arr[], char elem, int size);

int main(){
	int arr1[] = {1 ,7 ,10, 15};
	float arr2[] = {1.7, 2.6, 8.7, 6.3};
	char arr3[] = {'H', 'O', 'L', 'S'};
	int elem1 = 10;
	float elem2 = 10.5;
	char elem3 = 'O';
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);
	int size3 = sizeof(arr3) / sizeof(arr3[0]);
	
	find_elem(arr1, elem1, size1);
	find_elem(arr2, elem2, size2);
	find_elem(arr3, elem3, size3);
	return 0;

}

int find_elem(int arr[], int elem, int size) {
	int ind = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == elem) {
			cout << "Yes" << '\t';
			ind += 1;
			break;
		}
	}
	if (ind == 0) {
		cout << "No" << '\t';
	}
	return elem;
}
float find_elem(float arr[], float elem, int size) {
	int ind = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == elem) {
			cout << "Yes" << '\t';
			ind += 1;
			break;
		}
	}
	if (ind == 0) {
		cout << "No" << '\t';
	}
	return elem;
}
char find_elem(char arr[], char elem, int size) {
	int ind = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == elem) {
			cout << "Yes" << '\t';
			ind += 1;
			break;
		}
	}
	if (ind == 0) {
		cout << "No" << '\t';
	}
	return elem;
}