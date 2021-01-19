//11266 단절점
// 단절점 개념 문제 
// 필요 변수 : 연결 리스트, 방문 순서배열,
#include <bits/stdc++.h>

using namespace std;
#define MAX 10010

int V, E, cnt, num = 1;
vector<int> adj[MAX];
bool ans[MAX];      // 단절점이라면 true
int visited_order[MAX];

// 예외 : 루트일 경우
// 나의 방문 순서와 자식들이 만나는 방문순서 중 가장 작은 값을 비교
int dfs(int parent, int cur, bool isRoot){
    int min_visit_order = 1e5;  // *내 자식들이 만날 수 있는 점중에서 가장 작은 점 --> 나의 번호로 초기화 가능!.
    int chlcnt = 0 ;            // 자식들의 수
    //if(visited_order[cur] != 0)  //아래에 동일 코드 동작
    //    return 0;
    visited_order[cur] = num;   //나의(=cur) 방문 순서 기록
    //int min_visit_order = num; // 자식들이 최소한 나와 연결.
    num++;
    for (size_t i = 0; i < adj[cur].size(); i++){
        int next = adj[cur][i];
        if(next == parent)  //부모를 만난다면 배제.
            continue; 
        if(visited_order[next]){    //이미 방문한 곳은 방문할 필요 x, 방문한 곳의 순서만 가져온다.
            min_visit_order = min(min_visit_order, visited_order[next]);
        }else{  // 새롭게 방문하는 경우, 그 자식들이 어딘가 연결되어 있는지 체크
            int tmp = dfs(cur ,next, false);
            min_visit_order = min(min_visit_order, tmp);
            if( !isRoot && tmp >= visited_order[cur]){ //루트가 아니고, 
                ans[cur] = true;
                //cnt++;
            }
            chlcnt++;
        }
    }
    //만약 리프노드라면, 단절점 처리를 해주지 않음.
    if(adj[cur].size() == 1){
        return visited_order[cur];
    }
    if(isRoot){
        //자식이 두개 이상이면 단절점
        if(chlcnt >= 2){
            ans[cur] = true;
            //cnt++;
        }
    }
    /* else if(min_visit_order >= visited_order[cur]){ //현재노드보다 작다면 단절점 x
        // 단절점
        ans[cur] = true;
        cnt++;
    } */
    return min(visited_order[cur], min_visit_order);  //내가 만난 점(나, 자식)중에서 방문순서가 자장 낮은점을 반환함
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
    //단절점 찾고
    for(int i =1; i <= V; i++){
        if(visited_order[i] == 0){   //서로 떨어져 있는 그래프가 있을 수 있다.
            dfs(0, i, true);           //시작한 점을 root 로 정해서 순회
        }
    }
    // 출력
    //개수
    for (size_t i = 1; i <= V; i++){
        if(ans[i])
            cnt++;
    }
    
    cout << cnt << "\n"; 
    for (size_t i = 1; i <= V; i++)
    {
        if(ans[i])
        cout << i << " ";
    }
    
}