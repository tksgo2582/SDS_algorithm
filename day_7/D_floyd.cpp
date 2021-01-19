// 11404  플루이드
// 경로v -> u에서 중간에 다른 노드 x 를 거처서 가는 모든 경우 중 가장 작은 값 구해보기
// 보통 주어지는 값들이 크다 BUT N이 너무작다 ??  --> floyd 알고리즘 의심.(N^3 이 1억+- 라면....)
#include <bits/stdc++.h>

using namespace std;
#define MAX 110
#define INF 1e8

struct Info{
    int b, c;
    Info(int bb, int cc){
        b = bb; 
        c = cc;
    }
};

int N, M, dist[MAX][MAX];   //[i][j]    i -> j 로 가는 비용
//vector<Info> adj[MAX];
int adj[MAX][MAX];

void floyd(){       //i ,j, k 위치 잘 생각해보기
    for(int j = 1; j <=N; j++){         // 중간점
        for(int i = 1 ; i <= N; i++){   // 시작점
            for(int k =1; k <= N; k++){ // 끝점
                if(dist[i][j] == INF || dist[j][k] == INF)  // ***둘 중 하나라도 INF 라면 처리불가x 
                    continue;
                if(dist[i][j] + dist[j][k] < dist[i][k]){     //중간에 경유하는게 더 빠르다면
                    dist[i][k] = dist[i][j] + dist[j][k];     //값 update
                }
            }
        }
    }
}
void init(){
    for(int i = 1; i <=N; i++){
        for(int j = 1; j <=N; j++){
            if(i != j)  // i == j 일때는 0으로 세팅
                dist[i][j] = INF;
        }
    }
}

int main(){
    cin >> N >> M;
    init();
    for(int i = 0 ; i< M; i++){
        int a,b,c;
        cin >>a >>b>>c;
        //adj[a].push_back({b,c});
        if(dist[a][b] > c )  //***최소값의 경로만 유지
            dist[a][b] = c;
    }
    
    floyd();        //함수 작성하고 수행을 안했네;;;

    for(int i = 1; i <=N; i++){
        for(int j = 1; j <=N; j++){
            if(dist[i][j] == INF)
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout <<"\n";
    }
}