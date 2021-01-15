//1759 암호만들기 // 작성중

#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> v;

void dfs(int x, int cnt) {
    if (cnt == 4) {
        cout <<
    }
    for (int i = 0; i < v.size(); i++) {
    }
}

int main() {
    cin >> L >> C;
    char c;
    for (size_t i = 0; i < C; i++) {
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    dfs(0, 0);
}