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

void water_bfs(){
    while(!water.empty()){
        int x = water.front().first;    //1.큐에서 꺼내옴
        int y = water.front().second;
        water.pop();

        for(int i = 0 ; i < 4; i++){
            for (size_t j = 0; j < 4; j++){ //3.연결할곳 순회
                int nx = x + dx[i];
                int ny = y = dy[i];

                if(nx>=0 && nx < R && ny>=0 && nx < C ){ // 4갈수있는가
                    if(w_visited[nx][ny] == 0 && mat[nx][ny] == 0){
                        w_visited[nx][ny] = w_visited[x][y] + 1;    //5.체크인(물이 들어오는 날짜 기록) 
                        water.push({nx,ny});                        //큐에넣음
                    }
                }
            }
        }
    }
}

void bfs(int x , int y){
    queue<pair<int, int>> q;
    q.push({x,y});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4; i++){
            for (size_t j = 0; j < 4; j++){ //3.연결할곳 순회
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C) {   // 4. 갈 수 있는가? 범위 안
                    if (visited[nx][ny] == 0 && (mat[nx][ny] == 0 || mat[nx][ny] == 4)){
                        if(w_visited[nx][ny] == 0){
                            visited[nx][ny] = visited[nx][ny] + 1;
                            q.push({nx,ny});
                        }
                        else if(w_visited[nx][ny] > visited[x][y]){
                            visited[nx][ny] = visited[nx][ny] + 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
}

int main(){
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