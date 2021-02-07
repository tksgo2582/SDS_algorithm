#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
#define MAX 510

int N, M, a, b,ans=0;
vector <int> indegree[MAX], outdegree[MAX];
int parent[MAX];
int visit[MAX], re_visit[MAX];
int cnt, re_cnt;

void dfs(int curr){
    if(visit[curr])
        return;
    visit[curr] = true;
    cnt++;
    for(int i = 0; i <indegree[curr].size(); i++){
        dfs(indegree[curr][i]);
    }
}
void re_dfs(int curr){
    if(re_visit[curr])
        return;
    re_visit[curr] = true;
    re_cnt++;
    for(int i = 0; i <outdegree[curr].size(); i++){
        re_dfs(outdegree[curr][i]);
    }
}

void init(){
    /* for(int i =1; i <=N; i++){
        parent[i] = i;
    } */
    memset(visit, 0, sizeof(visit));
    memset(re_visit, 0, sizeof(re_visit));
    cnt=0;re_cnt=0;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        indegree[a].push_back(b);
        outdegree[b].push_back(a);
        //unionf(a,b);
    }
    for(int i = 1 ; i <= N; i++){
        init();
        dfs(i);
        re_dfs(i);
        if(cnt+re_cnt == N+1){
            ans++;
        }
        //cout << indegree[i] + outdegree[i]<<" ";
    }
    cout << ans;
}

