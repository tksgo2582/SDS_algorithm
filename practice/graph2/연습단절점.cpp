#include <iostream>
#include <vector>
#define MAX 10010
using namespace std;
int V,E, num=1;
vector<int> adj[MAX];
int order[MAX], ans[MAX];

int dfs(int parent, int cur, bool isRoot){
    int min_visit_order = 1e5;  //연결된 노드의 가장 작은 노드번호
    int chlcnt =0;              // 연결된 자식 수
    order[cur] = num++;         // 현재 노드의 방문 순서 기록

    for(int i = 0 ; i<adj[cur].size(); i++){    //순회
        int next = adj[cur][i];
        if(parent == next)      //부모는 스킵
            continue;
        if(order[next])         // 이미 방문한 곳은 방문 순서만 체크
            min_visit_order = min(min_visit_order, order[next]);
        else{
            int tmp = dfs(cur , next , false);  //끝까지 들어가보며 최소 방문 순서 체크
            //끝까지 돌았을때와 현재의 방문 순서 중 최소 값 저장
            min_visit_order = min(min_visit_order, tmp);
            //루트노드가 아니고, 끝까지 돌았을 때 최소값이 현재순서보다 크다면 ...--> 현재 노드는 단절점 
            if(!isRoot && tmp >= order[cur])
                ans[cur] = true;
        }
        chlcnt++;       //자식 수 카운트
    }
    if(adj[cur].size() == 1)    //리프노드는 현재 순서 반환
        return order[cur];
    if(isRoot){                 // 루트이며, 자식이 2명 이상은 단절점
        if(chlcnt >=2){
            ans[cur] = true;
        }
    }
    return min(min_visit_order, order[cur]);
}
int main(){
    cin >> V >>E;
    for (size_t i = 0; i < E; i++)
    {
        int a,b;
        cin >> a>>b;
        adj[a].push_back(b);    //양방향 간선으로 넣음
        adj[b].push_back(a);
    }
    for(int i = 1; i <= V; i++){
        if(order[i] == 0){
            dfs(0, i, true);
        }
    }
}