#include <iostream>
#include <vector>
#include <queue>
#define MAX 510
#define INF 1e8
using namespace std;
struct info{
    int node, cost;
};
int N,M,a,b,c;
long long dist[MAX];                //long long  으로 써야하는점..
vector<info> adj[MAX];
bool minus_flag = false;

void bell(){
    dist[1] = 0;
    for(int i =0; i < N -1; i++){   //n-1 번 도는 점..
        for(int j = 1; j <= N; j++){
            for(int k =0 ; k < adj[j].size(); k++){
                info next = adj[j][k];
                if(dist[j] == INF)  // inf 라면 돌 필요 없는 점
                    continue;
                if(dist[j] + next.cost < dist[next.node])
                    dist[next.node] = dist[j] + next.cost;
            }
        }
    }

    for(int j = 1; j<= N; j++){     //다시 한번 돌면서 감소하는 게 있다면 사이클 발생..
        for(int k =0; k < adj[j].size(); k++){
            info next = adj[j][k];
            if(dist[j] == INF)
                continue;
            if(dist[j] + next.cost < dist[next.node])
                minus_flag = true;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < M; i++){
        cin >> a >> b>> c;
        adj[a].push_back({b , c});
    }
    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }
    bell();

    if(minus_flag){
        cout << "-1\n";
    }else {
        for(int i = 2; i <= N; i++){
            if(dist[i] == INF)
                cout <<"-1\n";
            else {
                cout << dist[i] <<"\n";
            }
        }
    }
}
