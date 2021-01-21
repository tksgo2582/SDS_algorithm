//11049 행렬 곱셈순서
// 곱하는 순서에 따라서 연산 횟수가 차이가난다.
// 2^31 -1  보다 작거나 같다 --> int 형 쓰면 된다라고 착각
//          --->!!! 그러나 중간값은 int 아닐 수도
// 이해 못했다.

#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int N, R, C;
int dp[MAX][MAX];  //[i][j] : 행렬 i 부터 j까지 연산한 결과의 최소의 값
pair<int, int> v[MAX];

//행렬의 s부터 e까지 계산을 해서 최적의 값을 내는 함수
int calc(int s, int e) {
    if (e - s == 1) {
        return v[s].first * v[s].second * v[e].second;  //행렬곱
    }
    if (e == s)
        return 0;
    // 적절한 처리를 통해서 계산량을 줄일 예정
    // calc(s,e)를 처음으로 계산한 적이 있으면, 그떄 계산했던 결과를 사용함
    // if..
    if (dp[s][e] != -1) {
        return dp[s][e];
    }

    //처음으로 계산을 하니깐 일단 계산을 함
    //부분으로 다 나눠서 괜찮은 값을 구하는데...
    int mn = -1;
    for (int mid = s; mid <= e - 1; mid++) {
        int tmp = calc(s, mid) + calc(mid + 1, e) + v[s].first * v[mid].second * v[e].second;
        //최소값??
        if (mn == -1 || tmp < mn)
            mn = tmp;
    }

    //처음으로 계산 했기 떄문에 계산 결과를 저장함
    dp[s][e] = mn;
    return mn;
}

//길이base 바텀업
void calc2() {
    int len, s, e;
    for (len = 2; len <= N; len++) {  //행렬 곱의 길이
        for (s = 1; s + len - 1 <= N; s++) {
            e = s + len - 1;
            //dp[s][s + len-1] 값을 구하고 싶음
            int mn = -1;
            for (int mid = s; mid <= e - 1; mid++) {
                int tmp = dp[s][mid] + dp[mid + 1][e] + v[s].first * v[mid].second * v[e].second;
                if (mn == -1 || tmp < mn)
                    mn = tmp;
            }
            dp[s][e] = mn;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // memset(dp, 0xff, sizeof(dp));   //-1로 초기화
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    calc2();
    //cout << calc(1, N);
    cout << dp[1][N];
    return 0;
}