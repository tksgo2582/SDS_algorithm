//11659 부분합 4
// 배열 크기 제한  N,M 100,000 제한
// 세그먼트 트리 사용도 가능 BUT 값이 변경되는 경우 없으니 그냥 dp 사용!

//출력이 많은 경우니 ios_base~~ 써주기..
#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int N, M;
int dp[MAX];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> dp[i];
    }
    for(int i =1; i <= N; i++){
        dp[i] += dp[i-1];  
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << dp[b] - dp[a-1] <<"\n";
    }
}