//11438번 LCA2
#include <bits/stdc++.h>

using namespace std;
#define MAX 100010
int N, M;
int depth[MAX], ancen[MAX][18];  //2^0, 2^1, 2^2 .....2^17 번째 조상을 담음
vector<int> adj[MAX];
bool visited[MAX];
//1 = 2^0
//2 = 2^1
//...
//
//root = 1

void dfs(int parent, int cur, int param_depth){
    if(visited[cur])
        return;
    visited[cur] = true;
    depth[cur] = param_depth;
    ancen[cur][0] = parent;
    for (size_t i = 0; i < adj[cur].size(); i++)    {
        dfs(cur, adj[cur][i], param_depth + 1);
    }
}

int lca(int a, int b){
    //a의 깊이가 b 보다 더 깊게 만들어서 쉽게 처리하려고
    if(depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }
    //만약에 깊이가 서로 다르면 맞춰준다.
    if(depth[a] != depth[b]){
        // a ---> b까지 깊이를 맞춘다. 얼마나??
        int diff = depth[a] - depth[b];
        for(int i = 0, j =1; i<=17; i++, j*=2){
            //if(diff & (1 <<i))
            if(diff & j){
                a = ancen[a][j];
            }
        }
    }
    //depth[a] == depth[b] 인 상태
    if(a==b)
        return a;

    for(int i =17, j =(1 << 17); i >=0; i--, j/=2){
        if(ancen[a][i] != ancen[b][i]){
            a = ancen[a][i];
            b = ancen[b][i]l
        }
    }
    //LCA의 바로 아래까지 옴
    return ancen[a][0];
}

int main(){
    cin >> N >> M;
    for(int i =0; i < M; i++){
        int a,b;
        cin >> a>>b;
        //일단 양방향으로 연결
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //LCA를 위한 자료 수집 : 깊이, 1/2/4/.. 조상
    dfs(1, 1, 1);
    //2^1, 2^2, 2^3.... 조상
    for(int i =1 ; i<=17; i++){         // 2^i번째 조상
        for(int j = 1; j <= N; j++){    // 1번 노드, 2번 노드, ... n번 노드
            int tmp = ancen[j][i-1];
            ancen[j][i] = ancen[tmp][i-1];      //sparse table
        }
    }
    cin >> M;
    for(int i =0 ;i < M ; i++){
        int a,b;
        cin >> a >> b;
    }
}