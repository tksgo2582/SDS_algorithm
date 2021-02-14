#include <iostream>
#include <vector>
#include <queue>
#define MAX 20010
#define INF 1e6
using namespace std;

struct Info{
    int node_dist, node_num;
};
struct cmp{
    bool operator()(Info a, Info b){
        return a.node_dist > b.node_dist;
    }
};

int V, E, start_point;
int dist[MAX];
vector<Info> adj[MAX];

void dijk(){
    //priority_queue<int, vector<int>, compare>pq; // 자료형 int, 컨테이너 vector, 사용자 정의 비교연산자 compare
    priority_queue<Info, vector<Info>, cmp> pq;
    dist[start_point] = 0;
    pq.push({0,start_point});

    while(!pq.empty()){
        Info cur = pq.top();
        pq.pop();

        if(dist[cur.node_num] < cur.node_dist)
            continue;
        for(int i = 0; i < adj[cur.node_num].size(); i++){
            Info next = adj[cur.node_num][i];
            int tmp = cur.node_dist + next.node_dist;
            if(tmp < dist[next.node_num]){
                dist[next.node_num] = tmp;
                pq.push({tmp, next.node_num});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> start_point;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});  // a -- > b, 가중치는 c
    }
    for (int i = 1; i <= V; i++)
        dist[i] = INF;
    //dikstra
    dijk();
    // 출력
    for (int i = 1; i <= V; i++) {
        if(dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
            //INF 는 ?? --> 20000 * 10 이상으로 설정
    }
}