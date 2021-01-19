#include <bits/stdc++.h>

using namespace std;

int N, M, pr[1000010];

int findf(int a){
    if(a == pr[a])  // 부모가 없는 경우  -> 자기 자신을 가리키고 있다.
        return a;
    //return findf(a); // 돌때마다 재귀 들어가면 쫌 걸림
    pr[a] = findf(pr[a]); // findf 함수에 a가 아닌 pr[a] 를 넣어줘야 한다.
    return pr[a];
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    pr[a] = b;
}
void init(){
    for(int i = 0; i < N; i++){
        pr[i] = i;
    }
}

int main(){
    cin >> N >> M;
    init();
    while(M--){
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if(cmd == 0){
            unionf(a,b);
        }else{
            if(findf(a) == findf(b)){
                cout <<"YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}