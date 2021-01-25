#include <bits/stdc++.h>
using namespace std;
#define MAX 55

int R, C;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int visited[MAX][MAX], water_visited[MAX][MAX];
bool water[MAX][MAX];   //물이 들어왔는지 체크
char mat[MAX][MAX];
queue<pair<int, int>> wq;
queue<pair<int, int>> q;

void water_bfs() {
    while (!wq.empty()) {
        int x = wq.front().first;  //1, 큐에서 꺼냄
        int y = wq.front().second;
        wq.pop();
        water[x][y] = 1;
        for (int i = 0; i < 4; i++) {  //3.순회
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || water_visited[nx][ny] || mat[nx][ny] == 'X'||mat[nx][ny] == 'D') {
                continue;  //4. 갈 수 있나?
            } else {
                water_visited[nx][ny] = water_visited[x][y] + 1;  //5.체크인
                wq.push({nx, ny});                                //5. 큐에 넣음
            }
        }
    }
}

void bfs() {
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            cnt++; //일차 표시
            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny] || mat[nx][ny] == 'X' || (visited[x][y] + 1 >= water_visited[nx][ny] && water[nx][ny]) ) {
                continue;  //4. 갈 수 있나?
            } else {
                if(mat[nx][ny] == 'D'){
                    visited[nx][ny] = visited[x][y] + 1;
                    continue;
                }
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main() {
    int s,e;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == '*') {
                wq.push({i, j});
                water_visited[i][j] = 1;
            }
            if (mat[i][j] == 'S') {
                q.push({i, j});
                visited[i][j] = 1;
            }
            if(mat[i][j] == 'D'){
                s=i, e=j;
            }
        }
    }
    water_bfs();
    bfs();
 /*    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << water_visited[i][j] << " ";
        }
        for (int j = 0; j < C; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    } */
    if(visited[s][e]){
        cout << visited[s][e]-1;
    }else
        cout << "KAKTUS";
}
