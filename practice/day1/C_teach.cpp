#include <bits/stdc++.h>
using namespace std;
#define MAX 55

int N, K;
//int alpa[26];
vector<string> s;
int result=0;
//int teach_cnt=0;
int get_cnt(int []);

void dfs(int index, int teach_cnt, int *alpa) {

    if(teach_cnt == K){
        result = max(result, get_cnt(alpa));
        return;
    }
    for(int i = index; i < 26; i++){
        if(alpa[i] == 0){
            alpa[i] = 1;
            dfs(i, teach_cnt + 1, alpa);
            alpa[i] = 0;
        }
    }
}

int get_cnt(int alpa[]) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        bool flag = 1;
        for (int j = 0; j < s[i].size(); j++) {
            if (!alpa[s[i][j] - 'a']) {
                flag = false;
                break;
            }
        }
        if(flag){
            cnt++;
        }
    }
    //cout << cnt;
    return cnt;
}

int main() {
    int alpa[26];
    cin >> N >> K;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        s.push_back(str);
    }
    alpa['a' - 'a'] = 1;
    alpa['n' - 'a'] = 1;
    alpa['t' - 'a'] = 1;
    alpa['i' - 'a'] = 1;
    alpa['c' - 'a'] = 1;
    K -= 5;

    dfs(0, 0, alpa);

    cout << result;
}