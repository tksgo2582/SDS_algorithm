//2243 사탕상자 범위 설정 잘 보기
// 인덱스 트리로 이진 탐색 하기
// 부분합이 target 보다 큰경우 계속 들어가다가  단말노드 만나면 return

#include <bits/stdc++.h>
using namespace std;
#define max 1000000

long long n, a, b, c;
long long *nums;
long long *tree;
long long S, result;

long long makeTree(int node, int left, int right) {
    if (left == right) {
        if (left <= 1000000) {
            return tree[node] = 1;
        } else {
            return tree[node] = 0;
        }
    }
    int mid = (left + right) / 2;
    // 다음 깊이로 들어가기
    tree[node] = makeTree(node * 2, left, mid) + makeTree(node * 2 + 1, mid + 1, right);

    return tree[node];
}
long long query(int node, int left, int right, int k) {
    if ((left == right) && !result) {
        cout << left << "\n";
        return left;
    }
    int mid = (left + right) / 2;
    if (result == 0 && (node * 2 < S * 2 && tree[node * 2] >= k)) { // 왼쪽 자식이 쿼리를 포함하는 경우
        return query(node * 2, left, mid, k);
    }
    k -= tree[node * 2]; // 오른쪽 자식 검사시 쿼리(왼쪽것 제외)

    if (result == 0 && (node * 2 + 1 < S * 2 && tree[node * 2 + 1] >= k)) { // 오른쪽 자식이 포함하는지
        return query(node * 2 + 1, mid + 1, right, k);
    }
}
void update(int node, int left, int right, int index, long long diff) {
    if (left <= index && index <= right) {
        tree[node] += diff;
        if (left != right) {
            int mid = (left + right) / 2;
            update(node * 2, left, mid, index, diff);
            update(node * 2 + 1, mid + 1, right, index, diff);
        }
    }
}
// 강사님 쿼리 , 조건이 좀 더 간단.
int query_2(int node, int left, int right, int target) {
    if ((left == right)) {      //단말일 경우
        cout << left << "\n";
        return left;
    } else {
        int mid = (left + right) / 2;
        if (tree[node * 2] >= target) { //왼쪽 자식에 속하는 경우
            return query(node * 2, left, mid, target);
        }
        target -= tree[node * 2];   // 왼쪽 자식의 합 제외

        if (tree[node * 2 + 1] >= target) { //오른쪽 자식에 속하는 경우
            return query(node * 2 + 1, mid + 1, right, target);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    S = 1;
    while (S < max) {
        S *= 2;
    }
    tree = new long long[S * 2];

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            //int idx = query(1, 1, S, b);
            int idx = query(1, 1, S, b);
            result = 0;
            update(1, 1, S, idx, -1);
        } else {
            cin >> b >> c;
            update(1, 1, S, b, c);
        }
    }
}