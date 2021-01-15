//1256 사전
#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main(){
    int dp[201][101];
    int n,m,k;
    
    cin >> n >> m >> k;             //값 입력

    dp[0][0] = 1;                   // 0C0 설정
    for(int i = 1; i <= n+m; i++){
        for(int j = 0; j < i && j <= m; j++){
            if(i == j || j ==0)
                dp[i][j] = 1;
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                if(dp[i][j] > INF)
                    dp[i][j] = INF;
            }
        }
        if(m >= i){
            dp[i][i] = 1;
        }
    }

    k--;

    if(k >= dp[n+m][m]){
        cout << "-1\n";
        return 0;
    }

    for(int i = n+m-1; i >=0 ; i--){
        if(i >= m && dp[i][m] > k)  // "a"가 우선 순위, k번째보다 작다면 a 출력
            cout<<"a";
        else{
            cout << "z";
            k-=dp[i][m];// 검색된 단어들 넘기기 
            m--;        //z 뽑기 기회 --
        }
    }
int dp[201][201];

int combi(int n , int r){
    //r == 0, n == r => 1
    //D[n][r] = D [n-1][r-1] + D[n-1][r]

    if(n == r || r == 0){
        return 1;
    }
    else if(dp[n][r] != 0){
        return dp[n][r];
    }
    else{
        return dp[n][r] = min( (int)1e9 ,combi(n-1, r-1) + combi(n-1, r));
    }
}

void query(int n, int m, int k , string s){
    //n==0
    if(n+m == 0){
        return;
    }
    if(n == 0){
        s.push_back("z");
        query(n, m-1, k ,s);
    }else if(m == 0){
        s.push_back("a");
        query(n - 1, m, k ,s);
    }else{
        int leftCnt = combi(n+m-1, m);
        if(leftCnt >= k){
            s.push_back("a");
            query(n-1, m, k, s);
        }else{
            s.push_back("z");
            query(n, m-1, k-leftCnt , s);
        }
    }
    //m==0
    //n+m-1 C m 
}
