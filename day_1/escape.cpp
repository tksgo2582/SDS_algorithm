//3055 탈출
//bfs 활용(최단경로)
// 물이 이동하는것, 두더지가 이동하는것 두개로 나눠서 생각
#include <bits/stdc++.h>

using namespace std;

int mat[51][51];
int visited[51][51];    // 두더지
int w_visited[51][51];  // 물
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C;
int result = 0;
queue<pair<int, int>> water;  // 물 이동 큐

void water_bfs() {  // 물이 이동하는 시간
    while (!water.empty()) {
        int x = water.front().first; //1.큐에서 꺼내옴
        int y = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) { //3. 갈 수 있는 곳 순회
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C) {   // 4. 갈 수 있는가? 범위 안
                if (w_visited[nx][ny] == 0 && mat[nx][ny] == 0) {// 4. " 
                    w_visited[nx][ny] = w_visited[x][y] + 1; // 5. 체크인 시간 저장 (이전 위치 + 1)
                    water.push({nx, ny});                   //6. 큐에 넣음
                }
            }
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});     // 맨처음 큐에 넣음
    while (!q.empty()) {
        int x = q.front().first;    //1. 큐에서 꺼내옴
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) { // 3. 갈 수 있는곳 순회
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C) { //4. 갈 수 있는가?
                if (visited[nx][ny] == 0 && (mat[nx][ny] == 0 || mat[nx][ny] == 4)) {
                    if (w_visited[nx][ny] == 0) { // 물 없는곳
                        visited[nx][ny] = visited[x][y] + 1; //5. 체크인
                        q.push({nx, ny});                    //6. 큐에 넣음
                    } else {
                        if (w_visited[nx][ny] > visited[x][y] + 1) { // 물 보다 빨리 갈 수 있는곳
                            visited[nx][ny] = visited[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> R >> C;
    int x, y;
    int ex, ey;
    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == 'D') {  // 도달점 4
                mat[i][j] = 4;
                ex = i, ey = j;  // 도착위치 저장
            }
            if (s[j] == '.')  // 빈곳 0
                mat[i][j] = 0;
            if (s[j] == '*') {  // 물 1
                mat[i][j] = 1;
                water.push({i, j});  // **물 큐에 삽입
            }
            if (s[j] == 'X') {  // 바위 2
                mat[i][j] = 2;
            }
            if (s[j] == 'S') {  //두더지 시작 위치
                mat[i][j] = 0;
                x = i, y = j;  // 시작위치 저장
            }
        }
    }
    water_bfs();  // 물 이동거리 계산
    bfs(x, y);    // 두더지 이동거리 계산

    if (visited[ex][ey] != 0) {
        cout << visited[ex][ey];
    } else {
        cout << "KAKTUS\n";
    }
}