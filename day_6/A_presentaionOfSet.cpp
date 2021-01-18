//1717 집합의 표현 
// 서로소 집합 개념 문제
// 같은 집합인지 확인 => 연결되어 있는 부모 노드 저장
// n(1 ≤ n ≤ 1,000,000), m(1 ≤ m ≤ 100,000)

#include <bits/stdc++.h>

using namespace std;

int n, m, pr[1000010];

//a의 부모 알려줌
int findf(int a){
    if(pr[a] == a)
        return a;
    //return findf(pr[a]);    //재귀적으로 구현시 시간초과 위험.. 최악 n*m 

    pr[a] = findf(pr[a]);   // 모두 최상위 부모로 세팅.. 한번에 최종부모에 접근 가능
    return pr[a];           // 시간 초과 해결 가능
}

//a b 합침
void unionf(int a, int b){
    a = findf(a);
    b= findf(b);
    pr[a] = b;    
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    //초기화 부분 
    for(int i = 0 ; i<=n; i++){{
        pr[i] = i;
    }}
    while (m--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 0){
            unionf(a,b);
        }
        else if (cmd == 1){
            if(findf(a) == findf(b))
                cout << "YES\n";
            else{
                cout << "NO\n";
            }
            
        }
    }
}
