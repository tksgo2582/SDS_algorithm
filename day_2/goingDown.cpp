//2096 내려가기  dfs?? 최종점에서의 min, max 값 구하기?
// 4MB 제한 -> dp   한층씩 내려가며 최소, 최대값 저장
// 계산 모두 저장할 필요 x, 이전 값과 최종값만 있으면 가능
// min,max 3개 이상일때는 {}로 묶어주면 가능
//DP[n][n] =  number[n][n] + max(DP[n-1][n], DP[n-1][n-1], DP[n-1][n+1])
#include <bits/stdc++.h>
using namespace std;

int N;
int min_dp[2][3]={0,}; // min 값 저장
int max_dp[2][3]={0,}; // max 값 저장

int main(){
    cin >> N;
    int n1,n2,n3;

    for(int i =0; i< N; i++){
        cin >> n1 >> n2 >> n3;
        min_dp[1][0] = min(min_dp[0][0],min_dp[0][1])+n1;
        min_dp[1][1] = min({min_dp[0][0],min_dp[0][1],min_dp[0][2]})+n2;
        min_dp[1][2] = min(min_dp[0][1],min_dp[0][2])+n3;

        max_dp[1][0] = max(max_dp[0][0],max_dp[0][1])+n1;
        max_dp[1][1] = max({max_dp[0][0],max_dp[0][1],max_dp[0][2]})+n2;
        max_dp[1][2] = max(max_dp[0][1],max_dp[0][2])+n3;

        for(int i =0; i<3; i++){
            min_dp[0][i] = min_dp[1][i];
            max_dp[0][i] = max_dp[1][i];
        }
    }
    cout << max({max_dp[1][0],max_dp[1][1],max_dp[1][2]})<< " ";
    cout << min({min_dp[0][0],min_dp[0][1],min_dp[0][2]});

}