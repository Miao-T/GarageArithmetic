#include <iostream>
using namespace std;

//bubble sort
void bubble_sort(int array_bubble[]) {
	int temp;
	for (int j = 1; j < 16; j++) {
		for (int i = 0; i < 16 - j + 1; i++) {
			if (array_bubble[i] < array_bubble[i + 1]) {
				temp = array_bubble[i];
				array_bubble[i] = array_bubble[i + 1];
				array_bubble[i + 1] = temp;
			}
		}
	}
}

//select the num in matrix
void selectNum(int arrayOneDim[], int matrixTwoDim[][4], int n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arrayOneDim[n] == matrixTwoDim[i][j]) {
				matrixTwoDim[i][j] = 0;
			}
		}
	}
}

bool judgementLine4Zero(int matrixTwoDim[][4]) {
	int lineJudgement = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrixTwoDim[i][j] == 0) {
				lineJudgement++;
			}
		}
		if (lineJudgement == 4) {
			return false;
			break;
		}
		lineJudgement = 0;
	}
}

bool judgementRow4Zero(int matrixTwoDim[][4]) {
	int rowJudgement = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (matrixTwoDim[i][j] == 0) {
				rowJudgement++;
			}
		}
		if (rowJudgement == 4) {
			return false;
			break;
		}
		rowJudgement = 0;
	}
}

bool judementLine3Zero(int matrixTwoDim[][4]) {
	int lineJudgement = 0;
	int lineNum = 0;
	int zeroLocation = 1111;
	int zeroLocationBefore = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrixTwoDim[i][j] == 0) {
				lineJudgement++;
				zeroLocation = zeroLocation - 1 << (4 - j);
			}
		}
		if (lineJudgement == 3) {
			lineNum++;
			if (lineNum == 1) {
				zeroLocationBefore = zeroLocation;
			}
		}
		if ((lineNum == 2) && (zeroLocationBefore == zeroLocation)) {
			return false;
			break;
		}
		lineJudgement = 0;
		zeroLocation = 1111;
	}
}

bool judementRow3Zero(int matrixTwoDim[][4]) {
	int rowJudgement = 0;
	int rowNum = 0;
	int zeroLocation = 1111;
	int zeroLocationBefore = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (matrixTwoDim[i][j] == 0) {
				rowJudgement++;
				zeroLocation = zeroLocation - 1 << (4 - i);
			}
		}
		if (rowJudgement == 3) {
			rowNum++;
			if (rowNum == 1) {
				zeroLocationBefore = zeroLocation;
			}
		}
		if ((rowNum == 2) && (zeroLocationBefore == zeroLocation)) {
			return false;
			break;
		}
		rowJudgement = 0;
		zeroLocation = 1111;
	}
}

bool judgement(int matrixTwoDim[][4]) {
	return judgementLine4Zero(matrixTwoDim)
		&& judgementRow4Zero(matrixTwoDim)
		&& judementLine3Zero(matrixTwoDim)
		&& judementRow3Zero(matrixTwoDim);
}

int main() {
	bool flag = true;
//	int matrix[4][4] = { {4,8,7,15},{7,9,17,14},{6,9,12,8},{6,7,14,6} };
	int matrix[4][4] = { {6,5,7,5},{5,9,8,12},{10,8,11,13},{13,15,12,8} };
	int matrixToArray[16];

	int a = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrixToArray[a] = matrix[i][j];
			a++;
		}
	}
	int result = matrixToArray[0];
	for (int i = 0; i < 16; i++) {
		cout << matrixToArray[i] << '\t';
	}
	cout << '\n';

	bubble_sort(matrixToArray);

	for (int i = 0; i < 16; i++) {
		cout << matrixToArray[i] << '\t';
	}
	cout << '\n';

	for (int i = 0; i < 16; i++) {
		selectNum(matrixToArray, matrix, i);
		if (!judgement(matrix)) {
			result = matrixToArray[i];
			break;
		}
	}
	cout << result << '\t';
}