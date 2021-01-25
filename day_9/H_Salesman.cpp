//2098 외판원 순회
// bit 마스킹을 통해 풀이.
#include <bits/stdc++.h>
using namespace std;
#define MAX 16
#define INF 1e7

int N, W[MAX][MAX];     // i -> j까지 이동한는 거리
int dp[1 << MAX][MAX];  //[선택한 도시들 ][마지막 여행한 도시], 선택한 도시는 제곱될수 있음
                        //도시를 i처럼 거쳐왔고, 현재 j에 있을때 이동한 거리
//int w[][];               //비용
//시작점으로 다시 와야함
// 0번도시 1번도시 2번도시 ....
// 0 0 0 0 0 0 0 1 1 0 0 0 0 0  : 6, 7번 도시만 선택함

// pos번째에 비트를 셋팅함 :  가장 낮은 자리수가 0
int bit_set(int orgbit, int pos) {
    return orgbit | (1 << pos);
}
int bit_unset(int orgbit, int pos) {
    return orgbit & ~(1 << pos);
}
int bit_check(int orgbit, int pos) {
    if ((orgbit & (1 << pos)) == 0)
        return false;
    return true;
}
void init() {
    for (int i = 0; i < (1 << MAX); i++) {
        for (int j = 0; j < 16; j++) {
            dp[i][j] = INF;
        }
    }
}

int main() {
    //int x;
    //x |= (1 << 10)      //masking
    //x & (1 << 10)       //check
    //unmask
    init();

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];             //가중치 셋팅
        }
    }
    // 시작점 셋팅 : 0번쨰 도시에서 시작 .... [0번쨰 도시를 거쳐왔고][현재 0번쨰에 있으니까]
    dp[1][0] = 0; 
    for (int i = 0; i < (1 << N); i++) {    //돌 수 있는 만큼
        //전개 dp[i][j]
        for (int j = 0; j < N; j++) {       // 중간에 거치는 도시
            for (int k = 0; k < 16; k++) {  // 도착 지점
                //k로 갈 수 있는지
                if (bit_check(i, k) == true)
                    continue;
                if (W[j][k] == 0)       //가중치 0 이면 못가는거.
                    continue;
                int next = bit_set(i, k);   //
                dp[next][k] = min(dp[next][k], dp[i][j] + W[j][k]);
            }
        }
    }
    int answer = INF;
    int last_state = (1 << N) - 1;  // 모든 도시를 방문한 상태이고
    //시작으로 가는 처리르 하면서 답을 구함 (시작점을 임의로 줘도 답은 결국 하나...)
    for (int i = 0; i < N; i++) {
        if(W[i][0] == 0)
            continue;
        int tmp = dp[last_state][i] + W[i][0];
        if(tmp < answer)
            answer = tmp;
    }
    cout << answer;
}