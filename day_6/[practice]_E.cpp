//d위상 정렬 문제,
#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int N, M;
vector<int> parent[MAX], child[MAX];
bool visited[MAX], rev_visited[MAX];
int cnt, rev_cnt, ans = 0;;
/* 1.   체크인
	2. 목적지에 도착했는가?
	3. 연결된 곳을 순회
	4.    갈 수 있는가?
	5.      간다
	6. 체크아웃 */

void dfs(int cur){
    if(visited[cur])
        return;
    visited[cur] = true;
    cnt++;
    for(int i =0 ; i < parent[cur].size(); i++){
        int next = parent[cur][i];
        dfs(next);
    }
}
void rev_dfs(int cur){
    if(rev_visited[cur])
        return;
    rev_visited[cur] = true;
    rev_cnt++;
    for(int i = 0; i < child[cur].size(); i ++){
        int tmp = child[cur][i];
        rev_dfs(tmp);
    }
}

int main(){
    cin >> N >> M;
    for(int i =0 ; i < M; i++){
        int a,b;
        cin >> a>> b;
        parent[a].push_back(b);        // a--> 연결
        child[b].push_back(a);
    }
    for(int i = 1 ; i <= N; i++){
        cnt = 0;
        memset(visited, 0x00, sizeof(visited) );
        dfs(i);
        

        rev_cnt = 0;
        memset(rev_visited, 0x00 , sizeof(rev_visited));
        rev_dfs(i);

        if(cnt+rev_cnt == N -1)
            ans++;
    }
    cout << ans;
}


