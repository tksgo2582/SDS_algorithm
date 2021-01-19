#include <bits/stdc++.h>  // 위상정렬
using namespace std;
#define MAX 510

int N, M;
vector<int> parent[MAX];
int build_time[MAX], indegree[MAX], ans[MAX];
int before_max[MAX];
queue<int> q;

int main() {
    cin >> N;
    int tmp;
    for (size_t i = 1; i <= N; i++) {
        cin >> build_time[i];

        while (1) {  //입렵 부분
            cin >> tmp;
            if (tmp == -1) {
                break;
            } else {
                //tmp --> i
                parent[tmp].push_back(i);  // 건물들 짓기 위해 필요한 건물 넣어줌
                indegree[i]++;             // 몇개의 건물이 있어야 지을 수 있는지 알려줌
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){ // 시작점
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans[cur] = before_max[cur] + build_time[cur]; // 내가 들어 와야 갱신
        for(int i = 0 ; i < parent[cur].size(); i++){
            int next = parent[cur][i];
            //before_max[next] = before_max[cur] + build_time[cur] ;
            indegree[next]--;
            if(before_max[next] < ans[cur])
                before_max[next] = ans[cur];
            if(indegree[next]==0)
                q.push(next);
        }
    }
    for (size_t i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}