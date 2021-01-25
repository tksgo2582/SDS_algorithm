//1102 발전소
//특정 상태가 되었을때의 비용이 최소가 되는 값....

#include <bits/stdc++.h>
using namespace std;
#define MAX 16
#define INF 1e4

int N, cost[16][16], P;
string s;
int dp[1 << 16];  // 상태를 만들기 위한 최소 비용 (16개의 자리 필요)
bool onoff[MAX];  //꺼져 있는지 on/off 체크

int bitcount(int x) {  //bit 수 체크.. (이미 함수로 존재)
    int cnt = 0;
    while (x != 0) {
        if (x & 1)
            cnt++;
        x /= 2;
    }
    return cnt;
}

int bit_check(int b, int pos) {
    return (b & (1 << pos));
}
int bit_set(int b, int pos) {
    return (b | (1 << pos));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    cin >> s;

    for (int i = 0; s[i]; i++) {  // string for문 돌릴때 전체라면 이렇게 처리해줘도 좋다
        if (s[i] == 'Y')
            onoff[i] = true;
    }
    cin >> P;

    for (int i = 0; i < (1 << 16); i++) {
        dp[i] = INF;
    }

    //최초 시작은 어떻게 진행해야 할까??
    //힌트 : 최초에 켜져있는 발전소를 아니까, 상태를 만들어서, 그 상태의 dp[] = 0 으로...
    int first_state = 0;
    for (int i = 0; i < N; i++) {
        if (onoff[i]) {  //켜져있는거  bit로 표현
            first_state = bit_set(first_state, i);
        }
    }
    dp[first_state] = 0;

    //시작
    for (int state = 0; state < (1 << N); state++) {
        for (int i = 0; i < N; i++) {
            // state인 상태에서 i발전소를 켤 수 있을까??
            // 켜게되면 비용은 어떻게 될까?
            // 그때 state는 어떤 모양일까? : next_state
            // next_state에는 어떤 값이 있었을까?
            int next_state, next_cost;
            if (bit_check(state, i)) {  // state : 발전소가 켜져있는것, i 가 있다는 것은 이미 켜져있다는것
                continue;
            }
            next_state = bit_set(state, i); //다음 발전소의 상태 
            for (int j = 0; j < N; j++) {
                if (bit_check(state, j)) {
                    next_cost = dp[state] + cost[j][i];
                    if (next_cost < dp[next_state]) {
                        dp[next_state] = next_cost;
                    }
                }
            }
        }
    }
    //답을 출력할때는 P를 고려해서 P보다 큰가를 본다.
    int answer = INF;
    for (int i = 0; i < (1 << N); i++) {
        if (bitcount(i) >= P) {
            if (dp[i] < answer) {
                answer = dp[i];
            }
        }
    }
    if(answer == INF)
        answer = -1;
    cout << answer;
}