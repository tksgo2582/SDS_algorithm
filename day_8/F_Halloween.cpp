//3860 할로윈 묘지
#include <bits/stdc++.h>
using namespace std;
#define MAX 40
#define INF 1e8

struct Info{
    int x, y, t;
    Info(int xx, int yy, int tt){
        x = xx; y=yy; t=tt;
    }
};

int W, H, G, E;  //너비, 높이, 묘비수, 귀신구멍
int mat[MAX][MAX], dist[MAX][MAX];
bool visited[MAX], tomstone[MAX][MAX];
vector<Info> gost[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bell(){
    dist[0][0] = 0;

    for (size_t i = 0; i < W*H-G; i++){
        for (size_t j = 0; j < W; j++){
            for(size_t k = 0; k < H; k++){
                if(tomstone[j][k] || dist[j][k] == INF || (W-1 == j && k == H-1))       
                    continue;
                if(mat[j][k] == 2){ //귀신 구멍
                    
                }
            }
        }
        
    }
    
}
void init(){
    for(int i = 0; i < MAX; i++){
        visited[i] = false;
        for(int  j =0 ; j < MAX; j++){
            tomstone[i][j] = 0;
            dist[i][j] = INF;
            mat[i][j] = 0;
        }
    }
}

int main() {
    while (1) {
        cin >> W >> H >> G;

        while (G--) {
            int x, y;   //묘비
            cin >> x >>y;
            tomstone[x][y] = true;  //묘비 표시
        }
        cin >> E;
        for(int i = 0; i <E; i++){
            int x1,y1,x2,y2,t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;
            gost[x1][y1].push_back({x2,y2,t});       //귀신구멍 좌표 입력
            mat[x1][y1] = 2;                        //귀신구멍 표시
        }

        bell();
    }
}