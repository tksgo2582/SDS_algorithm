//11049 행렬 곱셈순서
// 곱하는 순서에 따라서 연산 횟수가 차이가난다.
// 2^31 -1  보다 작거나 같다 --> int 형 쓰면 된다라고 착각 
//          --->!!! 그러나 중간값은 int 아닐 수도

#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int N,R,C;
int dp[MAX][MAX];
vector<pair<int, int>> v(MAX);

//행렬의 s부터 e까지 계산을 해서 최적의 값을 내는 함수
int calc(int s, int e){
    if(e-s == 1){
        return v[s].first * v[s].second * v[e].second;      //행렬곱
    }
    if(e == s)
        return 0;
    // 적절한 처리를 통해서 계산량을 줄일 예정
    // calc(s,e)를 처음으로 계산한 적이 있으면, 그떄 계산했던 결과를 사용함
    // if..
    if(){
        
    }

    //처음으로 계산을 하니깐 일단 계산을 함
    //부분으로 다 나눠서 괜찮은 값을 구하는데...
    int mn = -1;
    for(int mid = s; mid <= e-1 ; mid ++){
        int tmp = calc(s, mid) + calc(mid+1, e) + v[s].first * v[s].second * v[e].second;
        //최소값??
        if(mn == -1 || tmp < mn)
            mn = tmp;
    }

    //처음으로 계산 했기 떄문에 계산 결과를 저장함
    return mn;
}

int main(){
    cin >> N;
    for(int i =1 ; i <=N; i++){
        cin >> v[i].first >> v[i].second;
    }
    cout << calc(1, N);
}