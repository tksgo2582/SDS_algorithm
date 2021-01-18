//1922 네트워크 연결
// MST 문제  원하는 구조체 선언, 구조체 배열 선언
// N (1 ≤ N ≤ 1000), M (1 ≤ M ≤ 100,000) -> 각 배열의 크기 다른점 주의
//크루스칼 알고리즘, 비용으로 오름차순 (비용 작은 것부터 union)
#include <bits/stdc++.h>

using namespace std;
#define MAX 1010

int N, M;
int parent[MAX];

struct Info{
    int a, b, c;
    //Info() {}
};

Info edge[100010];

bool comp(Info c1, Info c2){
    return c1.c < c2.c;
}

int findf(int a){
    if(a == parent[a])
        return a;
    parent[a] = findf(parent[a]);
    return parent[a];
    
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    parent[a] = b;
}

int main(){
    cin >> N >>M;
    int a, b, cost , ans=0;
    for (size_t i = 1; i <= N; i++){
        parent[i] = i;
    }
    int cnt = 0;

    for(int i =0 ; i <M; i++){
        cin >> a >> b >> cost;
        // 어디에 어떻게 넣을까?
        edge[i].a = a;  // 한쪽 끝 노드
        edge[i].b = b;  // 다른쪽 끝 노드
        edge[i].c = cost; // 간선의 비용
    }
    sort(edge, edge+M, comp);   //간선의 비용을 오름차순으로 정렬

    //크루스칼 알고리즘 사용 => 간선의 비용이 작은것부터 트리 구성
    // union-find 이용 
    for(int i =0 ; i <M; i++){
        int a, b, cost;
        // 간선 정보 읽어옴
        a = edge[i].a;  // 한쪽 끝 노드
        b = edge[i].b;  // 다른쪽 끝 노드
        cost = edge[i].c; // 간선의 비용
        //둘이 연결되어 있는지  = 같은 그룹인지 확인
        if(findf(a) != findf(b)){
            //서로 다른 그룹이면 연결, 비용도 추가
            unionf(a, b);
            ans += cost;        //비용 계산
            cnt ++;
        }
    }
    // cnt != N-1 ???? ==> mst 구성이 안됨
    if(cnt == N-1)
        cout << ans;
    
}