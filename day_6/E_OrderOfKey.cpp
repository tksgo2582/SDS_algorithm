//2458 키 순서  //위상정렬?
//나보다 위에 있는애들, 아래 있는애들 체크(반대방향 간선도 하나 만들어줌)
// 애매하게 남는 애들도 있는지 체크(동일한 위상에 있는 사람)
// 완전탐색으로 
// 복붙 시에는 항상 조심.. 변수, 함수명 잘 바꾸기..
#include <bits/stdc++.h>

using namespace std;
#define MAX 510

int N, M, answer, visited_cnt, visited_rev_cnt;
vector<int> parent[MAX], child[MAX];
bool visited[MAX];
bool rev_visited[MAX];

void dfs(int curr){
    if(visited[curr])
        return;
    visited[curr] = true;
    visited_cnt++;
    for(int i =0; i < parent[curr].size(); i++){
        dfs(parent[curr][i]);
    }
}
void dfs_rev(int curr){
    if(rev_visited[curr])
        return;
    rev_visited[curr] = true;
    visited_rev_cnt++;
    for(int i =0; i < child[curr].size(); i++){
        dfs_rev(child[curr][i]);
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    //입력으로 그래프 구성
    while(M--){
        int a, b;
        cin >> a>> b;
        //a가 b 보다 작음   //a -----> b
        parent[a].push_back(b);
        child[b].push_back(a); // b -----> a
    }
    
    for(int  i = 1; i <=N ; i++){
        //나보다 큰 수를 셈
        visited_cnt = 0;
        memset(visited, 0x00, sizeof(visited)); // 초기화
        dfs(i);

        //나보다 작은 수를 셈
        visited_rev_cnt = 0;
        memset(rev_visited, 0x00, sizeof(rev_visited)); // 초기화
        dfs_rev(i);
        // **cnt 에 내가 모두 포함...  
        //visited_cnt -1 + visited_rev_cnt -1 == n -1
        if((visited_cnt + visited_rev_cnt) == N + 1 )
            answer++;
    }
    
    //i 번째 학생의 순서를 알 수 있는지 없는지 판단
    //나보다 큰학생 수 + 작은 학생수 + 1 == N 이면 순서 알 수 있다.
    //모두 다 포함이 되었는지 확인
    cout << answer;
}
