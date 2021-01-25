#include <bits/stdc++.h>

using namespace std;
#define MAX 32010

int N, M;
vector<int> parent[MAX];
int indegree[MAX];
queue<int> q;

int main(){
    cin >> N >>M;
    while(M--){
        int a, b;
        cin >> a >> b;
        parent[a].push_back(b);
        indegree[b]++;
    }
    for(int i = 1; i <= N ; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i =0; i< parent[cur].size(); i++){
            int tmp = parent[cur][i];
            indegree[tmp]--;
            if(indegree[tmp] == 0)
                q.push(tmp);
        }
        cout << cur<< " ";
    }
}