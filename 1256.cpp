// input 2 2 2  // output azaz
#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

int main(){
    int dp[201][101];
    int n,m,k;
    
    cin >> n >> m >> k;             //값 입력

    dp[0][0] = 1;                   // 0C0 설정
    //1.(dp표 제작)
    for(int i = 0; i<= n + m; i++){ // n+m개의 a,z 뽑기
        dp[i][0] = 1;               // nC0 설정
        for(int j = 1; j < i && j<=m; j++){       // 조건 설정 (J는 z 뽑는경우)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //'n-1 C k-1'+'n-1 C k'
            if(dp[i][j]> MAX)   //자료형 범위 넘어가는 부분 처리(백준 제한범위로 변경해야 정답처리)
                dp[i][j] = MAX;
        }
        if(i <= m)          // z개수보다 뽑는 수가 작다.(a만 뽑힌다.)
            dp[i][i] = 1;   // nCn 설정
    }

    k--;                    // K번째 (인덱스 0부터 시작하니 1 줄여준다.)
    //2. k번째가 없는 경우
    if(dp[n+m][m] <= k){    // k 보다 작다면(k번째 존재 x) 
        cout<<"-1";
        return 0;
    }
    //3. 사전 문자열 하나씩 출력
    for(int i = n+m-1; i>=0; i-- ){ // 맨 뒤부터 시작
        if(i >= m && dp[i][m] > k)  // "a"가 우선 순위, k번째보다 작다면 a 출력
            cout<<"a";
        else{
            cout << "z";
            k-=dp[i][m];// 검색된 단어들 넘기기 
            m--;        //z 뽑기 기회 --
        }
    }
    cout << "\n";
}