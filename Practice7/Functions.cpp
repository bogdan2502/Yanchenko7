#include <random>
#include <cassert>

#include "Fibonacci.h"

#define USE_MATRIX_CONSTANTS

#include "Matrix.h"
using namespace std;

random_device rd;


int rand_int(int min, int max) {
	assert(min <= max);
	return min + rd() % (max - min);
}

double rand_double(int min, int max) {
	assert(min <= max);
	double fract = (double)rd() / RAND_MAX;
	return min + fract * ((double)max - (double)min);
}

int* rand_int_array(int x, int min, int max) {
	int* rand_array = new int[x];
	for (int i = 0; i < x; ++i) {
		rand_array[i] = rand_int(min, max);
	}
	return rand_array;
}
Matrix2x2 multMatrix2x2(const Matrix2x2 first, const Matrix2x2 second) {
	long _11 = first._11 * second._11 + first._12 * second._21;
	long _12 = first._11 * second._12 + first._12 * second._22;
	long _21 = first._21 * second._11 + first._22 * second._21;
	long _22 = first._21 * second._12 + first._22 * second._22;
	return Matrix2x2{ _11, _12, _21, _22 };
}

Vector2 multVector(const Matrix2x2 matrix, const Vector2 vec) {
	long _1 = matrix._11 * vec._1 + matrix._12 * vec._2;
	long _2 = matrix._21 * vec._1 + matrix._22 * vec._2;
	return Vector2{ _1, _2 };
}

Matrix2x2 power(const Matrix2x2 base, const unsigned int power) {
	Matrix2x2 result = onezzoneMatrix;
	Matrix2x2 input_matrix = base;
	unsigned int input_power = power;
	while (input_power > 0) {
		if (input_power % 2) {
			result = multMatrix2x2(result, input_matrix);
			--input_power;
		}
		else {
			input_matrix = multMatrix2x2(input_matrix, input_matrix);
			input_power /= 2;
		}
	}
	return result;
}

long fib(const unsigned int a) {
	unsigned int n_1 = 1;
	unsigned int n_0 = 0;
	for (int i = 0; i < a; ++i) {
		n_1 += n_0;
		n_0 = n_1 - n_0;
	}
	return n_0;
}


long fibFaster(const unsigned int a) {
	long result = 0;
	if (a == 0) {
		result = 0;
	}
	else {
		Vector2 start_condition = Vector2{ 1, 0 };
		Matrix2x2 matrix = Matrix2x2{ 1, 1, 1, 0 };
		result = multVector(power(matrix, a - 1), start_condition)._1;
	}
	assert(result == fib(a));
	return result;
}
