//1516 게임 개발 위상정렬?
// 값들 받을 때 따로따로 선언해서 받는게 편하다.

#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int N;
int build_time[MAX], answer[MAX], indegree[MAX], before_max[MAX];
vector<int> parent[510];  // 먼저건물 -> 나중건물
//vector
queue<int> q;       //큐를 통해서 시작부터 순서대로 동작

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
    //위상정렬을 통해서 ,  *시작점 = 들어오는 간선없는것들
    for (size_t i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    //각각의건물이 지어지는 최소시간... ===> answer
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        //지금은 cur를 처리함... 이미 before_max는 어떤값이 잘 들어있다고 생각할 수 있음. 이유는??
        answer[cur] = before_max[cur] + build_time[cur];
        //다음 건물을 처리해줌.... 
        //간선을 하나 빼주고 && 그 건물이 지어지기 전에 가장큰 값(before_max)
        for (int i = 0; i < parent[cur].size(); i++) {
            int next = parent[cur][i];
            indegree[next]--;  // ***간선을 하나 빼줌(필수 건물 한개 지었다.)
            if (before_max[next] < answer[cur]) {
                before_max[next] = answer[cur];
            }
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    //출력
    for (size_t i = 1; i <= N; i++) {
        cout << answer[i] << "\n";
    }
}