#include <bits/stdc++.h>

using namespace std;
#define MAX 1010
#define MAX2 100010
int N,M,parent[MAX];

struct Info{
    int a, b, c;
};

Info edge[MAX2];
bool comp(Info o1, Info o2){
    return o1.c < o2.c;
}
int findf(int a){
    if(a == parent[a]) return a;
    parent[a] = findf(parent[a]);
    return parent[a];
}
void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    parent[a] = b;
}
void init(){
    for (size_t i = 0; i <= N; i++){
        parent[i] = i;
    }
}

int main(){
    cin >> N >> M;
    init();
    for(int i = 0; i < M; i++){
        int a,b,c;
        cin >> a>> b>> c;
        edge[i] = {a,b,c};
    }
    sort(edge, edge+M, comp);
    
    int result =0, cnt = 0;

    for(int i = 0; i< M; i++){
        int a,b,c;
        a = edge[i].a;
        b = edge[i].b;
        c = edge[i].c; 
        //printf("%d %d %d\n",a,b,c);
        if(findf(a) != findf(b)){
            unionf(a, b);
            result += c;
            cnt++;
        }
    }
    if(cnt == N-1)
        cout << result;
}