//7579 앱
// 비용 순으로 계산해본다. 0 1 2 3 ....
#include <bits/stdc++.h>
using namespace std;
#define MAX 110

int N,M, cost[MAX], mem[MAX], ans;
//int dp[10001];   // cost[i]를 사용해서 구할 수 있는 메모리의 최대 크기
int dp[MAX][10001]; // [j][i] j까지 app을 대상으로 살펴봤을때 cost i 로 얻을 수 있는 최대 메모리

int main(){
    //memset(dp,0x00,sizeof(dp));
    cin >> N >> M;
    for(int i =1; i <= N; i++){
        cin >> mem[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
    }
    //app을 하나만 지우는 처리를 위해서 코드를 변형해봄
    for (int j = 1; j <= N; j++){
        //뭔가 계산
        for (int i = 0; i <= 10000; i++){
            //[j][i] : j 앱까지 고려했을 때(대상으로 했을 떄) cost i 로 확보할 수 있는 최대 메모리
            //mem[j] + i - cost
            //j번째 앱을 사용하지 않거나/ 사용하거나
            //둘 중에 큰 값
            dp[j][i] = dp[j-1][i]; //사용 x

            if((i - cost[j]) >= 0){        //사용 o
                dp[j][i] = max(dp[j][i], dp[j-1][i-cost[j]] + mem[j]);
            }
        }
    }
    //답을 낼것임
    // 비용을 찾아보면서, m 이상의 메모리를 확보했는지 확인해봄
    for (int i = 0; i <= 10000; i++){
        if(dp[N][i] >= M){
            ans = i;
            break;
        }
    }
    cout << ans;
}