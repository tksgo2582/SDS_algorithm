//1932 정수삼각형
//dp 문제,  삼각형 내려오면서 가질 수 있는 가장 큰 값 저장 
#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int N;
int tri[MAX][MAX], dp[MAX][MAX];

int main(){
    cin >> N;
    int tmp;
    for(int i= 1; i<= N; i++){
        for(int j =1; j < i+1; j++){
            cin >> tri[i][j];
        }
    }
    dp[1][1] = tri[1][1];

    for(int i= 2; i <= N; i++){
        for(int j =1 ; j <i+1; j++){
            //dp[i][j] = dp[i-1][j], dp[i-1][j-1];
            //j 벗어나는지 처리를 해주면
            //안해줘도 되는 이유 -> 어차피 0이니까
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tri[i][j];
        }
    }
    int ans=0;
    for(int i =1 ; i <=N; i++)
        ans = max(dp[N][i], ans);
    cout << ans;
}