#include <iostream>
#define ARR_SIZE  5
#define DYNAMIC_MEMORY
#ifdef DYNAMIC_MEMORY
	#define ARR_MAKER int* arr = new int[ARR_SIZE]
	#define ARR_REF int*& parr = arr
	#define ARR_DELETER delete [] arr
#else
	#define ARR_MAKER int arr[ARR_SIZE]
	#define ARR_REF int (&parr)[ARR_SIZE] = arr
	#define ARR_DELETER
#endif
using namespace std;
#ifdef DYNAMIC_MEMORY
	void arr_func(int* (&farr)) {
		for (int i = 0; i < ARR_SIZE; ++i) {
			farr[i] = i;
			cout << farr[i] << '\t';
		}
	}
#else
	void arr_func(int (&farr)[ARR_SIZE]) {
		for (int i = 0; i < ARR_SIZE; ++i) {
			farr[i] = i;
			cout << farr[i] << '\t';
		}
	}
#endif

int main() {
	ARR_MAKER;
	ARR_REF;
	arr_func(parr);
	ARR_DELETER;
	return 0;
}
