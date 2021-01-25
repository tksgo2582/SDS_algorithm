#include <bits/stdc++.h>
using namespace std;

struct reco {
    int num, many, time;
};
bool oper(reco r1, reco r2) {
    if (r1.many == r2.many) {
        return r1.time > r2.time;
    } else {
        return r1.many > r2.many;
    }
}
bool oper2(reco r1, reco r2) {
    return r1.num < r2.num;
}

int N, M;
vector<reco> v;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int tmp;
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        int flag = 0;
        for (int i = 0; i < v.size(); i++) {
            reco tmpv = v[i];
            if (tmpv.num == tmp) {
                v[i].many++;
                flag = 1;
            }
        }
        if (cnt < N && flag == 0) {
            v.push_back({tmp, 1, i});
            cnt++;
        } else {
            if (!flag) {
                sort(v.begin(), v.end(), oper);
                v.pop_back();
                v.push_back({tmp, 1, i});
            }
        }
    }
    sort(v.begin(), v.end(), oper2);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].num << " ";
    }
}