#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 32010

vector<int> parent[MAX];
int indegree[MAX];
int N,M;
queue<int> q;

void unionf(int a, int b){
    //a = findf(a);
    //b = findf(b);
    parent[a].push_back(b);
    indegree[b]++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int a,b;
    for(int i= 0; i < M; i++){
        cin >> a>>b;
        unionf(a,b);
    }
    for(int i = 1; i <= N; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur <<" ";

        for(int i =0; i < parent[cur].size(); i++){
            int next = parent[cur][i];
            indegree[next]--;
            if(indegree[next]==0)
                q.push(next);
        }
    }
}