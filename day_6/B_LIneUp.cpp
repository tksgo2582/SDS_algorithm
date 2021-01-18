//2252 줄 세우기
//위상 정렬 문제, 일의 순서를 정하는 정렬 -> 인접리스트 사용

#include <bits/stdc++.h>

using namespace std;
#define MAX 32010
int N,M;
//int parent[MAX];
vector <int> parent[MAX];
int indegree[MAX];
queue<int> q;

void unionf(int a, int b){
    //a = findf(a);
    //b = findf(b);
    //parent[a] = b;
    parent[a].push_back(b);
    indegree[b]++;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    
    int a, b;
    while(M--){
        cin >> a >> b;
        // a -> b 형식
        unionf(a,b);
    }
    //indegree가 0 인것을 찾는다.
    // 어딘가 모아 놓는다.
    for(int i = 1; i <= N; i ++){
        //queue에 넣는다.
        if(indegree[i] == 0)
            q.push(i);
    }
    //모아 놓은걸 하나씩 queue에서 뽑으면서 출려갛고
    //연결된것들의 간선을 하나씩 줄여준다.
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur<< " ";
        //연결된 간선을 하나씩 줄여준다.
        for(int i = 0; i <parent[cur].size(); i++){
            int next = parent[cur][i];
            indegree[next]--;
            if(indegree[next]==0)
                q.push(next);
        }
    }
}