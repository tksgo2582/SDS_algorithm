//11657 타임머신
//가중치로 음수가 나온다??  --> 벨만 포드 알고리즘

#include <bits/stdc++.h>
using namespace std;
#define MAX 510
#define INF 1e8

struct Info {
    int b, c;
    Info(int bb, int cc) {
        b = bb;
        c = cc;
    }
};

int N, M;
long long dist[MAX];  //1차원 배열만 사용, 시작에서 끝만 나타낼거니까
vector<Info> adj[MAX];
bool has_minus_cycle = false;

void bell() {
    //시작점 초기화  ** 0 이 아닌 1부터 시작....
    dist[1] = 0;
    for (int i = 0; i < N - 1; i++) {   // 최대한 방문할 수 있는 간선의 개수만큼 돌림 : N-1번 돌림
        for (int j = 1; j <= N; j++) {  // j점 주변에 있는 점들을 업데이트 할 수 있는지 확인함
            for (int k = 0; k < adj[j].size(); k++) {
                Info next = adj[j][k];  //next.b : j점 주변의 점, next.c : 그 점까지 이동하는데 걸리는 비용
                if(dist[j] == INF)  // ***둘 중 하나라도 INF 라면 처리불가x 
                    continue;
                if (dist[j] + next.c < dist[next.b])
                    dist[next.b] = dist[j] + next.c;  //j ---> next 이동하는데 더 적은 비용으로 이동 가능하면 업데이트
            }
        }
    }
    //전제 : n-1번 수행했기 때문에, 가장 먼 경로더라도 충분히 도달했을것임
    // 그리고 그 경로가 최단경로였을 것이다.
    //왜냐면 더 추가해서 방문을 했으면 경로의 값이 커질테니까....
    //하지만!! 중간에 감소하는 구간이 있었다면???
    //뭔가 처리 해야함.  ---> 한번 더해봄

    for (int j = 1; j <= N; j++) {  // j점 주변에 있는 점들을 업데이트 할 수 있는지 확인함
        for (int k = 0; k < adj[j].size(); k++) {
            Info next = adj[j][k];  //next.b : j점 주변의 점, next.c : 그 점까지 이동하는데 걸리는 비용
             if( dist[j] == INF)  // ***둘 중 하나라도 INF 라면 처리불가x 
                    continue;
            if (dist[j] + next.c < dist[next.b]){
            //이런 일이 벌어질 수 있을까??
            // 뭔가 처리가 필요함
                has_minus_cycle = true;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    bell();
    //*예외처리 먼저
    //시간이 무한히 되돌아가면 -1
    if (has_minus_cycle) {
        cout << "-1\n";
    } else {
        //각 지점까지 거리 출력
        //출력
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)  //어떤 도시까지 가는 경로가 없으면 -1
                cout << "-1\n";
            else
                cout << dist[i] << "\n";
        }
    }
}