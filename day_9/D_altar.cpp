//
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n, h[10010];
int dp[10010][5010];  // [i][j] i번쨰 제단까지 진행을 했을때 높이가 j인 경우의 수

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    //양쪽 끝 비교 0이 아니면 ==> 0
    if (h[1] > 0 || h[n] > 0) {
        cout << 0;
        return 0;
    }
    //가장 높은 높이 빕교 == > 실패
    memset(dp, 0x00, sizeof(dp));
    dp[1][0] = 0;
    //i번째 제단에서 가능한 높이 경우의 수를 넣는다
    for (int i = 2; i <= n; i++) {
        //i번쨰 제단이 j번째 높이를 갖는 경우의 수
        if (h[i] != -1) {
            int j = h[i];
            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1], dp[i][j] % MOD;
            }
            dp[i][j] += dp[i - 1][j], dp[i][j] % MOD;
            if (j + 1 <= 5000) {
                dp[i][j] += dp[i - 1][j + 1], dp[i][j] % MOD;
            }  //if(j != h[i])   => 계산하면 안됨
            //else 계산해야됨 dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
        } else {
            for (int j = 0; j <= n / 2; j++) {
                //j --> 이전의 높이가 j+1, j-1 합쳐지는 경우의 수
                //dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                //long long 으로 캐스팅해서 한번에 처리해줘도 된다.
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j - 1], dp[i][j] % MOD;
                }
                dp[i][j] += dp[i - 1][j], dp[i][j] % MOD;
                if (j + 1 <= 5000) {
                    dp[i][j] += dp[i - 1][j + 1], dp[i][j] % MOD;
                }
            }
        }
    }
    cout << dp[n][0];
}