// input 2 2 2  // output azaz
#include <bits/stdc++.h>

using namespace std;

int main(){
    int dp[201][101];
    int n,m,k;
    
    cin >> n >> m >> k;     //값 입력

    dp[0][0] = 1;           // 0C0 설정
    for(int i = 0; i<= n + m; i++){ // n+m개의 a,z 뽑기
        dp[i][0] = 1;       // nC0 설정
        for(int j = 1; j < i && j<=m; j++){ // 조건 설정 (J는 z 뽑는경우)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //n-1 C k-1 + n-1 C k
            if(dp[i][j]> INT_MAX) //자료형 범위 넘어가는 부분 처리
                dp[i][j] = INT_MAX;
        }
        if(i <= m)          // z개수보다 뽑는 수가 작다.(a만 뽑힌다.)
            dp[i][i] = 1;   // nCn 설정
    }
    k--;                    // K번째
    if(dp[n+m][m] <= k){    // k 보다 작다면 
        cout<<"-1";
        return 0;
    }
    for(int i = n+m-1; i>=0; i-- ){ //
        if(i >= m && dp[i][m] > k)  // z 만 뽑히면 되는 경우 + 
            cout<<"a";
        else{
            cout << "z";
            k-=dp[i][m];//
            m--;        //z 뽑기 기회 --
        }
    }
    cout << "\n";
}