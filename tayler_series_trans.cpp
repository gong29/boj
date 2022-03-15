#include <stdio.h>
#include <cmath>
using namespace std;

// f(x) = x^2
float func(float x) {
	return x * x;
}

// Tayler series 변형식
// f(x+h) = f(x) + f'(x)h + f''(x)/2!*h^2 + ...

// 미분 #1
// f'(x) = (f(x+h)-f(x))/h + O(h)
float diff1(float x, float h) {
	float diff;
	diff = (func(x + h) - func(x)) / h;
	return diff;
}

// 미분 #2
// f'(x) = (f(x+h)-f(x-h))/2h + O(h^2)
float diff2(float x, float h) {
	float diff;
	diff = (func(x + h) - func(x - h)) / 2.0 / h;
	return diff;
}

int main() {
	// 얘는 뭘까..?
	float h = pow(2.0, -23);
	printf("diff1 = %.35f\n", diff1(1.0, h));
	printf("diff2 = %.35f\n", diff2(1.0, h));
	// 2^-23은 너무 작은 경계에 가까운 수라서 O(h) 에러를 만들지 않음
	h = pow(2., -23);
	printf("diff1 = %.35f\n", diff1(1.0, h));
	printf("diff2 = %.35f\n", diff2(1.0, h));
	// 2^-8은 O(h) 에러 표시 남
	h = pow(2., -8);
	printf("diff1 = %.35f\n", diff1(1.0, h));
	printf("diff2 = %.35f\n", diff2(1.0, h));
}