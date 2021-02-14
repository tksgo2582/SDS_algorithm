//3176 도로네트워크 , 플루이드워셜 알고리즘 사용
// LCA 사용
#include <iostream>
#include <vector>
#define MAX 100010
#define inf 1000000000
using namespace std;

int N, a, b, c, K;
int depth[MAX], ancen[MAX][21], Max[MAX][21], Min[MAX][21];
bool visited[MAX];
vector<pair<int,int>> adj[MAX];
long long result;
//vector<info> Path;

void dfs(int parent, int cur, int cur_depth){
    if(visited[cur])
        return;
    visited[cur] = true;
    depth[cur] = cur_depth;
    ancen[cur][0] = parent;
    for(int i = 0; i < adj[cur].size(); i++){
        pair<int, int> tmp = adj[cur][i];
        Max[tmp.first][0] = Min[tmp.first][0] = tmp.second;
        dfs( cur, tmp.first, cur_depth+1);
    }
}
void lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int ans1 =inf, ans2 =0;
    if(depth[a]!= depth[b]){
        int diff = depth[a] - depth[b];
        for(int i = 0, j =1; i<=18; i++,j*=2){
            if(diff & j){
                ans1 = min(ans1, Min[a][i]);
                ans2 = max(ans2, Max[a][i]);
                a = ancen[a][i];
            }
        }
    }
    if(a == b){
        cout << ans1 <<" " << ans2 <<"\n"; 
        return;
    }
    for(int i = 18; i>=0 ; i--){
        if(ancen[a][i] != ancen[b][i]){
            ans1 = min(ans1, min(Min[b][i], Min[a][i]));
            ans2 = max(ans2, max(Max[b][i], Max[a][i]));
            a = ancen[a][i];
            b = ancen[b][i];
        }
    }
    ans1 = min(ans1, min(Min[b][0], Min[a][0]));
    ans2 = max(ans2, max(Max[b][0], Max[a][0]));
    
    cout<< ans1 << " " << ans2 << "\n";

    return;
}
void init(){
    for(int i= 0; i <= 18; i++){
        for(int j =0 ; j<= N; j++){
            Min[j][i] = inf;
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c; 
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,1,1); // 기초

    for(int i=1; i <= 18; i++){
        for(int j =1; j<= N; j++){
            int tmp = ancen[j][i-1];
            ancen[j][i] = ancen[tmp][i-1];
            Max[j][i] = max(Max[j][i-1], Max[tmp][i-1]);
            Min[j][i] = min(Min[j][i-1], Min[tmp][i-1]);
        }
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> a >>b;
        lca(a,b);
    }
}