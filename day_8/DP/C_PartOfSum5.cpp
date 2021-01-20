//11660 부분합
//배열의 부분 배열 합
// 조금 어렵 배열 저장값이랑 dp값이랑 분리해서 생각?
// 배열 뺄 때 겹치는부분 생각, ++ x1,y1까지 빼는게 아닌 그 전까지 빼는 점.
#include <bits/stdc++.h>
using namespace std;
#define MAX 1030

int N, M, a[MAX][MAX];
int dp[MAX][MAX];

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int linesum = 0; // 그 라인의 누적합
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            linesum += a[i][j]; //라인합 따로 구해서 윗배열과 합한다.
            dp[i][j] += dp[i - 1][j] + linesum;

            //cout << dp[i][j] <<" ";
        }
        //cout << "\n";
    }
    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
        cout << ans << "\n";
    }
}