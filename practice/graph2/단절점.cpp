#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10010
using namespace std;
int V, E, num = 1;
vector<int> adj[MAX];
int visited_order[MAX], ans[MAX];

int dfs(int parent, int cur, bool isRoot){
    int min_visit_order = 1e5;
    int chlcnt = 0;
    visited_order[cur] = num;
    num++;
    for(int i = 0; i<adj[cur].size(); i++){
        int next = adj[cur][i];
        if(next == parent)
            continue;
        if(visited_order[next])
            min_visit_order = min(min_visit_order, visited_order[next]);
        else{
            int tmp = dfs(cur, next, false);
            min_visit_order = min(min_visit_order, tmp);
            if(!isRoot && tmp >= visited_order[cur]){
                ans[cur] = true;
            }
            chlcnt++;
        }
    }
    if(adj[cur].size() == 1){
        return visited_order[cur];
    }
    if(isRoot){
        if(chlcnt >= 2){
            ans[cur] = true;
        }
    }
    return min(visited_order[cur], min_visit_order);
}

int main(){
    cin >> V >> E;
    for(int i =0 ; i < E; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =1 ;i <=V; i++){
        if(visited_order[i] == 0){
            dfs(0 , i , true);
        }
    }
    cout << count(ans, ans+V+1, true) << "\n";
    for(int i = 1; i <=V; i++){
        if(ans[i])
            cout << i << " ";
    }
}