#include <iostream>

using namespace std;

int N, M;
int matrix[501][501];

int four_max() {
	int max = 0;
	int f;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			f = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i][j + 3];
			if (max < f) {
				max = f;
			}
		}
	}
	for (int i = 0; i < N - 3; i++) {
		for (int j = 0; j < M; j++) {
			f = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 3][j];
			if (max < f) {
				max = f;
			}
		}
	}
	return max;
}

int three_max() {
	int max = 0;
	int t, f; // three, four
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M - 2; j++){
			t = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2];
			for(int k = j; k < j + 3; k++){
				if(i != N-1){
					f = t + matrix[i + 1][k];
					if(max < f){
						max = f;
					}
				}
				if(i != 0){
					f = t + matrix[i - 1][k];
					if(max < f){
						max = f;
					}
				}
			}
		}
	}
	for(int i = 0; i < N - 2; i++){
		for(int j = 0; j < M; j++){
			t = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j];
			for(int k = i; k < i + 3; k++){
				if(j != N-1){
					f = t + matrix[k][j + 1];
					if(max < f){
						max = f;
					}
				}
				if(j != 0){
					f = t + matrix[k][j - 1];
					if(max < f){
						max = f;
					}
				}
			}
		}
	}
	return max;
}

int two_max(){
	int max = 0;
	int t, f; // two, four
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < M - 1; j++){
			t = matrix[i][j] + matrix[i][j + 1];
			f = t + matrix[i + 1][j] + matrix[i + 1][j + 1];
			if(max < f){
				max = f;
			}
			if(j != N-2){
				f = t + matrix[i + 1][j + 1] + matrix[i + 1][j + 2];
				if(max < f){
					max = f;
				}
			}
			if(j != 0){
				f = t + matrix[i + 1][j - 1] + matrix[i + 1][j];
				if(max < f){
					max = f;
				}
			}
			t = matrix[i][j] + matrix[i + 1][j];
			if(i != N - 2){
				f = t + matrix[i + 1][j + 1] + matrix[i + 2][j + 1];
				if(max < f){
					max = f;
				}
			}
			if(i != 0){
				f = t + matrix[i - 1][j + 1] + matrix[i][j + 1];
				if(max < f){
					max = f;
				}
			}
		}
	}
	return max;
}

int main(void) {
	int two, three, four, result;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix[i][j];
		}
	}
	two = two_max();
	three = three_max();
	four = four_max();
	if(two >= three && two >= four){
		cout << two;
	}
	else if(three >= two && three >= four){
		cout << three;
	}
	else{
		cout << four;
	}
}