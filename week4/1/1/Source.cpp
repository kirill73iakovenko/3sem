#include <iostream>

using namespace std;

struct Vector {
	float* array;
	int dim = 1;
};

Vector create_vector(float* arr, int size);
void mult_scalar(struct Vector vector, float num);
Vector sum_vectors(struct Vector vector1, struct Vector vector2);
float scalar_mult(struct Vector vector1, struct Vector vector2);

int main() {
	float* vec1 = new float[5]{1, 5, 8, 10, 3};
	int size1 = 5;
	float* vec2 = new float[5]{3.2, 14, 0, 0, -4};
	int size2 = 5;
	float* vec3 = new float[2] {1, 0};
	int size3 = 2;
	Vector vector1 = create_vector(vec1, size1);
	Vector vector2 = create_vector(vec2, size2);
	Vector vector3 = create_vector(vec3, size3);
	float num1 = 10;
	mult_scalar(vector1, num1);
	cout << "The result of multiplying the vector 1 by a number: ";
	for (int i = 0; i < 5; ++i) {
		cout <<  vector1.array[i] << " ";
	}
	cout << "\n";
	Vector vector4 = sum_vectors(vector1, vector2);
	cout << "The result of summing vectors 1 and vector 2: ";
	for (int i = 0; i < 5; ++i) {
		cout << vector4.array[i] << " ";
	}
	cout << "\n";
	float res1 = scalar_mult(vector1, vector2);
	cout << "The result of the scalar product of vectors 1 and vector 2: " << res1 << "\n";
	Vector vector5 = sum_vectors(vector1, vector3);
	float res2 = scalar_mult(vector1, vector3);

	delete[] vec1;
	delete[] vec2;
	delete[] vec3;


}



Vector create_vector(float *arr, int size) {
	Vector vector;
	vector.array = arr;
	vector.dim = size;
	return vector;
}
void mult_scalar(struct Vector vector, float num) {
	for (int i = 0; i < vector.dim; ++i) {
		vector.array[i] = num * vector.array[i];
	}

}
Vector sum_vectors(struct Vector vector1, struct Vector vector2) {
	if (vector1.dim == vector2.dim) {
		float* arr = new float[vector1.dim];
		for (int i = 0; i < vector1.dim; ++i) {
			arr[i] = vector1.array[i] + vector2.array[i];
		}
		Vector res_vector = create_vector(arr, vector1.dim);
		return res_vector;
		delete[] arr;
	}
	else {
		cout << "it was not possible to sum vectors of different dimensions"<< "\n";
	}
}
float scalar_mult(struct Vector vector1, struct Vector vector2) {
	if (vector1.dim == vector2.dim) {
		float res = 0;
		for (int i = 0; i < vector1.dim; ++i) {
			res += vector1.array[i] + vector2.array[i];
		}
		return res;
	}
	else {
		cout << "it was not possible to mult vectors of different dimensions" << "\n";
	}
}



	