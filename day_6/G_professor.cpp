//3830 교수님은 기다리지 않는다
//갈 수 있는지 아닌지  -> union find 로 풀 수 있다.
#include <bits/stdc++.h>

using namespace std;
#define MAX 100010
int N, M;
int parent[MAX];

int findf(int a){
    int t = parent[a];
    if(a == t)
        return t;
    findf(t);
    d[a] += d[t];
    
}

int main(){
    cin >> N >> M;
    while(1){
    if(N == 0 && M == 0)
        break;  
    }
}