// 1202 보석도둑 N^2을 피하자
// 1가방 1 보석
#include <bits/stdc++.h>
using namespace std;

int N, K; // 보석, 가방
pair<int, int> jewel[300001]; // 맨처음 배열 크기 잘못 선언
int bags[300001];
priority_queue<int> pq;
long long result=0; // long long 사용.

int main(){
    int m,v, tmp;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> m >> v;
        jewel[i] = {m, v};
    }
    sort(jewel, jewel + N); // 무게순으로 내림차순

    for (size_t i = 0; i < K; i++){
        cin >> bags[i];
    }
    sort(bags, bags+K);
    int idx = 0;
    for(int i =0 ; i < K; i++){
        int bag = bags[i]; //제일 작은 가방 선택
        while(idx < N && jewel[idx].first <= bag ){ //가방에 넣을수 있는건 모두 넣는다.
            pq.push(jewel[idx++].second);
        }
        if(!pq.empty()){
            result += pq.top();     //제일 가치 큰거만 결과에 +
            pq.pop();
        }
    }
    cout << result;
    
}