//https://skyde47.tistory.com/53
#include <bits/stdc++.h>
using namespace std;
#define MAX 55

int N, M;
int board[MAX][MAX];
int visited[MAX][MAX];
int dp[MAX][MAX] = {
    -1,
};
int ret, result = 0;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int INF;

bool dfs(int x, int y, int cnt) {
    if (ret == -1)      //ret 이 존재하지 않는다면
        return true;
    if (cnt > ret)      // 이동횟수가 더 많다면 업데이트
        ret = cnt;
        
    visited[x][y] = 1;  // 체크인
    dp[x][y] = cnt;     // ****현재 이동횟수 저장
    //result = max(result, cnt);
    for (int i = 0; i < 4; i++) {   //순회
        int nx = x + dx[i] * board[x][y];
        int ny = y + dy[i] * board[x][y];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] > 0) {
            if (visited[nx][ny]) {  //사이클 존재
                ret = -1;           //-1
                INF = 1;
                break;
            }
            if(dp[nx][ny] && cnt < dp[nx][ny])  
            // 이전에 방문한적이 존재, 이동횟수가 더 많다면 스킵
                continue;
            if(dfs(nx, ny, cnt + 1))    // 중간에 갈 수 없는 부분 나온다면 
                return true;
        }
    }
    visited[x][y] = 0;  // 체크아웃
    return false;
}

int main() {
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'H')
                board[i][j] = -1;
            else
                board[i][j] = s[j] - '0';
        }
    }
    dfs(0, 0, 1);
    if (INF)
        cout << "-1";
    else
        cout << ret;
}