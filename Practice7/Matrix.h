#pragma once
struct Matrix2x2
{
	long _11, _12, _21, _22;
};

struct Vector2
{
	long _1, _2;
};


#ifdef USE_MATRIX_CONSTANTS
const Matrix2x2 onezzoneMatrix = Matrix2x2{ 1, 0, 0, 1 };
#endif

Vector2 multVector(Matrix2x2 matrix, Vector2 vector);
Matrix2x2 multMatrix2x2(Matrix2x2 first, Matrix2x2 second);
Matrix2x2 power(const Matrix2x2 base, const unsigned int power);
