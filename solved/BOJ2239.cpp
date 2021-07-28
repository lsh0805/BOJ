#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define ll long long

typedef pair<int, int> P;
typedef pair<int, pair<int,int>> P2;

const int INF = 2e9;
const int MINF = -2e9;

int N, sudoku[9][9];
char temp;

bool test(int y, int x, int value){
	for(int y_ = 0; y_ < 9; y_++)
		if(sudoku[y_][x] == value) return false;
	
	for(int x_ = 0; x_ < 9; x_++)
		if(sudoku[y][x_] == value) return false;

	int sy = (y / 3) * 3, sx = (x / 3) * 3;
	for(int y_ = sy; y_ < sy + 3; y_++)
		for(int x_ = sx; x_ < sx + 3; x_++)
			if(sudoku[y_][x_] == value) return false;

	return true;
}

bool solve(int y, int x){
	if(x == 9) return solve(y + 1, 0);
	if(y == 9) return true;
	if(sudoku[y][x] != 0) return solve(y, x + 1);

	for(int i = 1; i <= 9; i++){
		if(test(y, x, i)){
			sudoku[y][x] = i;
			if(solve(y, x + 1)) return true;
			sudoku[y][x] = 0;
		}
	}
	return false;
}

int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			scanf("%1d", &sudoku[i][j]);
		}
		cin.get();
	}
	solve(0, 0);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			printf("%d", sudoku[i][j]);
		printf("\n");
	}
    return 0;
}