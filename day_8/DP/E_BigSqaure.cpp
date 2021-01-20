//1915 가장 큰 정사각형
// 1000 * 1000 * 길이(1~1000)
// 주변애들이 최소 n-1 을 가지고 있어야 n의 길이를 가질 수 있다.
#include <bits/stdc++.h>
using namespace std;
#define MAX 1010

int N,M;
int dp[MAX][MAX], a[MAX][MAX];
int ans;

int main(){
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string s;
    for(int i = 1; i <=N; i++){
        cin >> s;
        for(int j = 1; j <=M; j++){
            a[i][j] = s[j-1] - '0';
        }
    }
    for(int i = 1; i <=N; i++){
        for(int j = 1; j <=M; j++){
            if(a[i][j] == 0){ //우츺ㄱ 하단에 있는 점이 0이니깐 당연히 정삭가혀을 만들 수 없음
                dp[i][j] = 0;
                continue;
            }
            // 조사해아 할 곳: 왼쪽, 위쪽, 왼쪽 위 대각선 검사
            int mn = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            dp[i][j] = mn + 1;
            ans = max(dp[i][j], ans);
        }
    }
    //출력
    cout << ans*ans;
}