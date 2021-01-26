#include <bits/stdc++.h>
using namespace std;

int board[9][9];

bool Col[9][9], Row[9][9], square[9][9];

void sdoku(int cnt) {
    int x = cnt / 9;
    int y = cnt % 9;
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    if (board[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (Row[x][i] == false && Col[y][i] == false && square[(x / 3) * 3 + y / 3][i]==false) {
                Col[y][i] = true;
                Row[x][i] = true;
                square[(x / 3) * 3 + y / 3][i] = true;
                board[x][y] = i;
                sdoku(cnt + 1);
                Col[y][i] = false;
                Row[x][i] = false;
                square[(x / 3) * 3 + y / 3][i] = false;
                board[x][y] = 0;
            }
        }
    } else
        sdoku(cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0) {
                Col[j][board[i][j]] = true;
                Row[i][board[i][j]] = true;
                square[(i / 3 * 3) + (j / 3)][board[i][j]] = true;
            }
        }
    }

    sdoku(0);
}