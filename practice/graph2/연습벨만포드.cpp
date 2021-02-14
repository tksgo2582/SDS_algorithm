#include <iostream>
#include <vector>
#include <queue>
#define MAX 510
#define INF 1e8
using namespace std;

struct info{
    int node, dist;
};

int N, M;
long long dist[MAX];
vector<info> adj[MAX];
bool minus_cycle= false;

void dfs(){
    dist[1] = 0;

    for(int i = 0 ; i < N-1; i ++){
        for(int j =1; j <= N; j++){
            for(int k =0 ; k < adj[j].size(); k++){
                info next = adj[j][k];
                if(dist[next.node] == INF)
                    continue;
                if(dist[next.node] > next.dist + dist[j]){
                    dist[next.node] = next.dist+dist[j];
                }
            }
        }
    }
    for(int j =1; j <= N; j++){
            for(int k =0 ; k < adj[j].size(); k++){
                info next = adj[j][k];
                if(dist[next.node] == INF)
                    continue;
                if(dist[next.node] > next.dist + dist[j]){
                    minus_cycle = true;
                }
            }
        }
}
