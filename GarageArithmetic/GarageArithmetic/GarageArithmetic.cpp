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
void selectNum(int arrayOneDim[], int matrixTwoDim[][4],int zeroOneArray[][4], int n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arrayOneDim[n] == matrixTwoDim[i][j]) {
				zeroOneArray[i][j] = 0;
			}
		}
	}
}

bool judgementLine4Zero(int zeroOneArray[][4]) {
	int lineJudgement = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (zeroOneArray[i][j] == 0) {
				lineJudgement++;
			}
		}
		if (lineJudgement == 4) {
			return false;
			break;
		}
	}
}

bool judgementRow4Zero(int zeroOneArray[][4]) {
	int rowJudgement = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (zeroOneArray[i][j] == 0) {
				rowJudgement++;
			}
		}
		if (rowJudgement == 4) {
			return false;
			break;
		}
	}
}

bool judementRow3Zero(int zeroOneArray[][4]) {

}

bool judementLine3Zero(int zeroOneArray[][4]) {

}

bool judgement(int zeroOneArray[][4]) {
	return judgementLine4Zero(zeroOneArray) && judgementRow4Zero(zeroOneArray);
}

int main() {
	bool flag = true;
	int matrix[4][4] = { {4,8,7,15},{7,9,17,14},{6,9,12,8},{6,7,14,6} };
	int matrixBool[4][4] = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
	int matrixToArray[16];
	int a = 0;
	int result;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			matrixToArray[a] = matrix[i][j];
			a++;
		}
	}

	for (int i = 0; i < 16; i++) {
		cout << matrixToArray[i] << '\t';
	}

	bubble_sort(matrixToArray);
	for (int i = 0; i < 16; i++) {
		cout << matrixToArray[i] << '\t';
	}

	while (flag) {
		for (int i = 0; i < 16; i++) {
			selectNum(matrixToArray, matrix, matrixBool, i);
			if (judgement(matrixBool)) {
				flag = false;
			}
			result = matrixToArray[i];
		}
		cout << result << '\t';
	}
}