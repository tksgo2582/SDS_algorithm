#include <bits/stdc++.h>
using namespace std;
#define MOD 10007

#define N  1000
int D[N+1][N+1];

int main(){

    int n, k;
    
    cin >> n >> k;

        for(int i = 1; i <= n; i ++){
            for(int j = 0 ; j <= k; j++){
                if(j == 0)   //j 안 뽑을때 n C 0
                    D[i][j] = 1;
                else if(i == j) // 모두 뽑을때 n C n
                    D[i][j] = 1;
                else        // 이외의 상황
                    D[i][j] = D[i-1][j-1] + D[i-1][j];

                D[i][j] = D[i][j] % MOD;
            }
        }
    cout << D[n][k] % MOD;
    //k == 0 =>1
    //n == k => 1
    //D[n][k] = D[n-1][k-1] + D[n-1][k];
}