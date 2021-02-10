#include <iostream>
#include <vector>
#define MAX 100010
using namespace std;

int N , M;
int depth[MAX], ancen[MAX][18];
bool visited[MAX];
vector<int> adj[MAX];

void dfs(int parent, int cur, int cur_depth){
    if(visited[cur])
        return;
    visited[cur] = true;
    depth[cur] = cur_depth;
    ancen[cur][0] = parent;
    for(int i = 0 ; i < adj[cur].size(); i++){
        dfs(cur, adj[cur][i], cur_depth+1);
    }
}
int lca(int a, int b){
    //편의상 a를 더 큰 값으로 변경(a 가 더 아래 있다)
    if(depth[a] < depth[b])
        swap(a,b);
    //깊이가 같지 않다면...
    if(depth[a]!=depth[b]){
        int diff = depth[a] - depth[b];
        //깊이 차이만큼 j로 비트연산하며 다가간다.
        for (int i = 0, j = 1; i <= 17; i++,j*=2){
            if(diff & j){   //j로 깊이 하나씩 다가가며, 2^i 번째 찾는다.
                a = ancen[a][i];
            }
        }
    }
    if( a== b){
        return a;
    }
    for(int i = 17, j = (1<<17); i >= 0; i--, j/=2){
        if(ancen[a][i] != ancen[b][i]){
            a = ancen[a][i];
            b = ancen[b][i];
        }
    }
    return ancen[a][0];
}

int main(){
    cin >> N;
    for (int i = 0; i < N-1; i++) { // 간선 개수 만큼
        int a,b;
        cin >> a>> b;
        //양방향으로 연결
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // 기본적인 부모 관계 초기화.. (ancen[n][0])
    dfs(1, 1, 1);
    // 상위 부모 관계들 정립
    // 1~ N개 노드들의 2^i 번째 부모들 정립
    for(int i =1; i<=17; i++){
        for(int j =1; j <=N; j++){
            int tmp = ancen[j][i-1];
            // 다음 조상은 = 부모의 조상 
            ancen[j][i] = ancen[tmp][i-1];
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a>> b;
        cout << lca(a,b) << "\n";
    }
}