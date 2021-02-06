//1922 네트워크 연결
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define MAX 1010
struct info {
    int src, dest, cost;
};
bool cmp(info a, info b) {
    return a.cost < b.cost;
}
int N, M;
int a, b, c, ans = 0, cnt = 0;
info connect[100010];  // 최대크기는 노드의 크기인 1010이 아닌 간선의 크기
int parent[MAX];

int findf(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = findf(parent[a]);
}
void unionf(int a, int b) {
    a = findf(a);
    b = findf(b);
    parent[a] = b;
}
void init() {
    for (int i = 1; i < N; i++) {
        parent[i] = i;
    }
}
int main() {
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        connect[i] = {a, b, c};
    }
    sort(connect, connect + M, cmp);  //최소비용 순으로 정렬
    for (int i = 0; i < M; i++) {
        info tmp = connect[i];
        if (findf(tmp.src) != findf(tmp.dest)) {
            unionf(tmp.src, tmp.dest);
            ans += tmp.cost;
            cnt++;  //간선의 개수
        }
    }
    if (cnt == N - 1)
        cout << ans;
}