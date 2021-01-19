//1753 최단경로 - 단방향 그래프
//다익스트라 알고리즘 구현
#include <bits/stdc++.h>
using namespace std;
#define MAX 20010
#define INF 1e6         //INF 값 설정 잘 하기

struct Info {  //이거 말고 pair 로 하는방법도 있다.
    int b, c;
    Info(int bb, int cc) {
        b = bb;
        c = cc;
    }
};

struct Dijk_Info {
    int node_num, node_dist;
    Dijk_Info(int nn, int nd) {
        node_num = nn;
        node_dist = nd;
    }
};

struct comp {
    bool operator()(Dijk_Info a, Dijk_Info b) {
        return a.node_dist > b.node_dist;
    }
};

int V, E, start_point;
int dist[MAX];
vector<Info> adj[MAX];

void dijk() {
    priority_queue<Dijk_Info, vector<Dijk_Info>, comp> pq;
    //시작점 거리 세팅 + pq에 읿력
    dist[start_point] = 0;
    pq.push(Dijk_Info(start_point, 0));

    while (!pq.empty()) {
        Dijk_Info cur = pq.top();
        pq.pop();

        if(dist[cur.node_num] < cur.node_dist) //기존 비용보다 이미 더 큰경우
            continue;

        //cur 주변을탐색한다.
        for (size_t i = 0; i < adj[cur.node_num].size(); i++) {
            Info next = adj[cur.node_num][i];
            int tmp = cur.node_dist + next.c; // 현재점(cur) - >다음점(next)로 이동할 때 드는 비용
            if(tmp < dist[next.b]){             // 현재 경로가 다른 경로보다 작을 경우만 update, 큐에 넣어준다.
                dist[next.b] = tmp;
                pq.push(Dijk_Info(next.b, tmp)); //이 if 문 안에 넣은 이유는 좀 더 최적화, 굳이 같은값을 또 넣을 필요가 없다.
            }
        }
        //도대체 시작점부터 그 점까지 최단거리는 언제 세팅하는가?
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
        adj[a].push_back({b, c});  // a -- > b, 가중치는 c
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