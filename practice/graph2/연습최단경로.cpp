#include <iostream>
#include <vector>
#include <queue>
#define MAX 10010
#define INF 1e6
using namespace std;

struct info{
    int node_num, node_dist;
};

struct cmp{
    bool operator()(info a, info b){
        return a.node_dist < b.node_dist;
    }
};
void dfs(){
    priority_queue<info, vector<info>, cmp> pq;
    pq.push({start, 0});
    dist[start] = 0;

    while(!pq.empty()){
        info cur = pq.top();
        pq.pop();

        if(dist[cur.node_num] < cur.node_dist)
            continue;
        for(int i = 0; i < adj[cur.node_num].size(); i++){
            info next = adj[cur.node_num][i];
            //다음으로 가는 비용 + 현재까지 온 비용()
            int cost = next.node_dist + cur.node_dist;
            if(cost < dist[next.node_num]){
                dist[next.node_num] = cost;
                pq.push({next.node_num, cost});
            }
        }
    }
}

int V,E, start;
vector <info> adj[MAX];
int dist[MAX];
int main(){
    cin >> V >> E >> start;
    int a ,b, c;
    for(int i = 0 ; i < E;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    for(int i = 1; i <= V; i++){
        dist[i] = INF;
    }
    dfs();
}
