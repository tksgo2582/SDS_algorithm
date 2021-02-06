//서로소 집합 문제... 같은 집합에 포함되어있는지 판단
#include <iostream>
using namespace std;
#define MAX 1000000

int parent[MAX];
int N, M;

int findf(int a){
    if(parent[a] == a)
        return a;
    else
        return parent[a] = findf(parent[a]);
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);

    parent[a] = b;
}
void init(){
    for(int i = 1 ;i <= N; i++){
        parent[i] = i;
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int a,b,c;
    init(); //집합 배열 자기자신으로 초기화
    for(int i = 0; i < M; i++){
        cin >> a>> b >> c;
        if(a == 0){
            unionf(b, c);
        }
        else{
            if(findf(b) == findf(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}