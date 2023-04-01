#include <iostream>

using namespace std;

class SquareMatrix {
private:
	int size;
	int** mat;
public:
	explicit SquareMatrix(int sz) : size(sz) {
		mat = new int* [size];
		for (int i = 0; i < size; i++) {
			mat[i] = new int[size];
			for (int j = 0; j < size; j++) {
				mat[i][j] = 0;
			}
		}
	}
	SquareMatrix(int sz, int** m) : size(sz) {
		mat = new int* [size];
		for (int i = 0; i < size; i++) {
			mat[i] = new int[size];
			for (int j = 0; j < size; j++) {
				mat[i][j] = m[i][j];
			}
		}
	}

	SquareMatrix(const SquareMatrix& other) : size(other.size) {
		mat = new int* [size];
		for (int i = 0; i < size; i++) {
			mat[i] = new int[size];
			for (int j = 0; j < size; j++) {
				mat[i][j] = other.mat[i][j];
			}
		}
	}
	int getEntry(int i, int j) const {
		return mat[i][j];
	}
	int getSize() const {
		return size;
	}
	SquareMatrix operator*(const SquareMatrix& rhs) const {
		SquareMatrix result(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
				}
				result.mat[i][j] %= 1000;
			}
		}
		return result;
	}
	SquareMatrix operator%(const int rhs) const {
		SquareMatrix result(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result.mat[i][j] = mat[i][j] % rhs;
			}
		}
		return result;
	}

	SquareMatrix power(long long n) {
		SquareMatrix result(size);
		if (n == 1) {
			return (*this % 1000);
		}
		else if (n % 2 == 0) {
			SquareMatrix temp = power(n / 2);
			return temp * temp;
		}
		else {
			SquareMatrix temp = power(n - 1);
			return temp * (*this);
		}
	}

	friend ostream& operator<<(ostream&, const SquareMatrix& sqm);

	~SquareMatrix() {
		for (int i = 0; i < size; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}
};

ostream& operator<<(ostream& os, const SquareMatrix& sqm) {
	for (int i = 0; i < sqm.size; i++) {
		for (int j = 0; j < sqm.size; j++) {
			os << sqm.mat[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

int main(void) {
	int n; // 2 <= N <= 5
	long long b; // 1 <= b <= 100,000,000,000
	int** arr;

	cin >> n >> b;

	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	SquareMatrix mat(n, arr);

	cout << mat.power(b) << endl;

	// free memory
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}