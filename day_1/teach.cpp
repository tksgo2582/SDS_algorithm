//1062 가르침
//dfs 배울수 있는 글자수 까지 dfs
// 전체 검색.
#include <bits/stdc++.h>

using namespace std;

bool visited[26];
vector<string> word;
int cnt = 0;
int MAX = 0;
int N, K;

void dfs(int index, int count) {
    visited[index] =1;
    if (count == K) {  //2. 목적지인가? 배울 수 있는 글자 수 K
        int num = 0;
        for (int i = 0; i < word.size(); i++) {  // 단어들 읽을 수 있는지 체크
            bool flag = true;
            for (int j = 0; j < word[i].size(); j++) {
                if (!visited[word[i][j] - 97]) {  //배운 글자인지 확인
                    flag = false;
                    break;
                }
            }
            if (flag)
                num++;  //읽을 수 있는 단어 ++
        }
        MAX = max(MAX, num);  // 최댓값 갱신
    }
    for (int i = index; i < 26; i++) {  //3. 연결된곳 순회
        if (visited[i])                //4. 갈수 있는가?
            continue;
        visited[i] = 1;     //1. 체크인
        dfs(i, count + 1);  //5. 간다
        visited[i] = 0;     //6. 체크아웃
    }
}

int main() {
    cin >> N >> K;
    string s;
    // a,n,t,i,c
    visited['a' - 'a'] = 1;
    visited['n' - 'a'] = 1;
    visited['t' - 'a'] = 1;
    visited['i' - 'a'] = 1;
    visited['c' - 'a'] = 1;
    K -= 5;  // 5글자는 필수
    //word 입력
    for (int i = 0; i < N; i++) {
        cin >> s;
        s.replace(0,4,"");  //공통 부분 삭제
        s.replace(s.find("tica"),4,"");
        word.push_back(s);
    }

    //    for(int i = 0; i <26; i++){
    //       if(visited[i] == false){
    dfs(0, 0);
    //      }
    //  }
    cout << MAX;
}