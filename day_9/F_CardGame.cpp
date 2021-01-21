//11062 카드게임
//서로 최선을 다한다. 내 점수 높이는것도 중요하지만, 상대방이 큰 점수 못 가져가게 하는것도 중요.
//내 예상 : 
//  현재의 내가 가져갈 수있는 숫자와 다음 턴에 내가 가져갈 수 있는 숫자의 조합 크기를 비교???
#include <bits/stdc++.h>
using namespace std;
#define MAX 1010

int T, N;
int card[MAX];
int k_dp[MAX][MAX], m_dp[MAX][MAX], subsum[MAX];    //메모이제이션..

int k_play(int , int );
int m_play(int , int );

int getsum(int s, int e){   //카드 s부터 e까지의 합
    return subsum[e] - subsum[s -1 ];
}

int k_play(int s, int e){
    //play
    if(s == e){
        return card[s];
    }
    if(k_dp[s][e] != -1){
        return k_dp[s][e];
    }
    int left =0, right =0;
    //가장 왼쪽을 가져가거나
    //근우가 카드로 얻는 값 : card[s]
    //명우가 최선을 다해서 얻는 점수 : m_play(s+1,e)
    //근우가 나머지 플레이에서 얻는 점수 :  [s + 1 ~ e]까지의 합 - "명우가 최선을 다해서 얻는 점수"
    left = card[s] + getsum(s+1,e) - m_play(s+1,e);
    right = card[e] + getsum(s, e-1) - m_play(s, e-1);

    // 최종 근우는 left, right 중에 큰 것을 하면 됨
    k_dp[s][e] = max(left, right); 
    return k_dp[s][e];
}
int m_play(int s, int e){
    //play
    if (s == e){
        return card[s];
    }
    if(m_dp[s][e] != -1){
        return m_dp[s][e];
    }
    int left=0, right =0;
    left = card[s] + getsum(s+1, e) - k_play(s+1, e);
    right = card[e] + getsum(s, e-1) - k_play(s, e-1);

    m_dp[s][e] = max(left, right); 
    return m_dp[s][e];
}

int main(){
    cin >> T;
    while(T--){
        memset(k_dp, 0xff, sizeof(k_dp));
        memset(m_dp, 0xff, sizeof(m_dp));
        memset(card, 0x00, sizeof(card));
        memset(subsum, 0x00, sizeof(subsum));
        cin >> N;
        for(int i = 1 ; i <= N; i++){
            cin >> card[i];
            subsum[i] = subsum[i-1] + card[i];
        }
        // 점수를 높이기 위한 일
        
        cout << k_play(1, N) << "\n";
    }
}