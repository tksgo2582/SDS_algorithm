#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 510
int N;
int indegree[MAX], buildTime[MAX], answer[MAX], before_max[MAX];
bool visit[MAX];
vector<int> building[MAX];
queue<int> q;

int main(){
    cin >> N;
    int t,pre;
    for(int i=1; i<=N; i++){
        cin >> t;
        buildTime[i] = t;
        while(1){
            cin >> pre;
            if(pre == -1)
                break;
            building[pre].push_back(i);
            indegree[i]++;
        }
    }
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        answer[cur] = buildTime[cur] + before_max[cur];
        for(int i=0; i<building[cur].size(); i++){
            int next = building[cur][i];
            indegree[next]--;
            before_max[next] = max(before_max[next], answer[cur]);

            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i=1; i <=N; i++){
        cout << answer[i] << "\n";
    }
}