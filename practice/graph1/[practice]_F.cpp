#include <iostream>
#include <vector>
#include <queue>
#define MAX 510
using namespace std;

int N;
int indegree[MAX], buildTime[MAX], answer[MAX], before_max[MAX];
vector <int> building[MAX];
queue<int> q;
int main(){
    cin >> N;

    for(int i =1; i <= N; i++){
        int time, pre;
        cin >> time;
        buildTime[i] = time;
        while(1){
            cin >> pre;
            if(pre == -1)
                break;
            building[pre].push_back(i); //i를 짓기위해 필요한 건물들 pre
            indegree[i]++;
        }
    } 
    for(int i = 1; i <=N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        answer[cur] = before_max[cur]+buildTime[cur];

        for(int i = 0; i< building[cur].size(); i++){
            int next = building[cur][i];
            indegree[next]--;
            //다음 건물 짓기전까지 걸린 시간과   현재건물 짓기까지 걸린 시간
            before_max[next] = max(before_max[next], answer[cur]);

            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
     for(int i = 1; i <=N; i++){
        cout << answer[i] <<"\n";
     }
}