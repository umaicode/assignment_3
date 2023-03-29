// matrixMultiplication.cpp - 2차원 행렬을 1차원으로 저장, + 구현 
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "time.h"
// 보통 행렬에 대하여add, sub, mult, transpose 구현하는 코딩
class Matrix {
public:
	Matrix(int row, int col);
	//~Matrix() { delete[]Term; }
	int GetData();
	Matrix Transpose();
	int Display(); // 행렬 모양: A[rows][cols] 출력
	Matrix Add(Matrix b);
	Matrix Multiply(Matrix b);

private:
	int rows, cols;
	//int Term[rows][cols];
	int* Term;// a[i][j] = i * cols + j
};

Matrix::Matrix(int row, int col) {
	this->rows = row;
	this->cols = col;
	this->Term = new int[row * col];
}

int Matrix::GetData() {
	for (int i = 0; i < this->rows * this->cols; i++) {
		this->Term[i] = rand() % 10;
	}
	return 1;
}

int Matrix::Display() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			cout << this->Term[i * this->cols + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 1;
}

Matrix Matrix::Add(Matrix b) {
	if (this->rows != b.rows || this->cols != b.cols) {
		cout << "안됨" << endl;
		return Matrix(0,0);
	}

	Matrix a2(this->rows, this->cols);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			a2.Term[i * this->cols + j] = this->Term[i * this->cols + j] + b.Term[i * this->cols + j];
		}
	}
	return a2;
}

Matrix Matrix::Multiply(Matrix b) {
	Matrix c(this->rows, b.cols);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < b.cols; j++) {
			int sum = 0;
			for (int k = 0; k < this->cols; k++) {
				sum += this->Term[i * this->cols + k] * b.Term[k * b.cols + j];
			}
			c.Term[i * c.cols + j] = sum;
		}
	}
	return c;
}

Matrix Matrix::Transpose() {
	Matrix d(this->cols, this->rows);
	for (int i = 0; i < this->cols; i++) {
		for (int j = 0; j < this->rows; j++) {
			d.Term[i * d.cols + j] = this->Term[j * this->cols + i];
		}
	}
	return d;
}

int main()
{
	Matrix a(2, 3); Matrix a1(2, 3); Matrix a2(2, 3);
	Matrix b(3, 4);
	Matrix c(2, 4);
	srand(time(NULL));
	cout << "matrix a[2][3]의 입력: " << endl;
	a.GetData();
	a.Display();

	cout << "matrix a1[2][3]의 입력: " << endl;
	a1.GetData();
	a1.Display();

	a2 = a.Add(a1);
	cout << "a2 = a + a1" << endl;
	a2.Display();

	cout << "matrix b[3][4]의 입력: " << endl;
	b.GetData();
	b.Display();

	Matrix d(4, 3);
	d = b.Transpose();
	cout << "Transpose() of Matrix b" << endl;
	d.Display();

	cout << "Multiply of Matrix a,b" << endl;
	c = a.Multiply(b);
	c.Display();

	system("pause");
	return 0;
}

