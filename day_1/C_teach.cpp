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
//Dfs의 순서(절대적이진 않음)
 // 1.   체크인
//	2. 목적지에 도착했는가?
//	3. 연결된 곳을 순회
//	4.    갈 수 있는가?
//	5.      간다
//	6. 체크아웃


void dfs(int index, int cnt){
    visited[index] = 1;     //1. 체크인 배웠다고 체크

    if(cnt == K){           //2. 목적지인가?
        int num = 0;
        for(int i =0; i < word.size(); i++){ // 단어개수 만큼
            bool flag = false;
            for(int j =0; j < word[i].size(); j++){ // 단어 길이만큼
                if(!visited[word[i][j] - 97]){  // 배운 알파벳인지 검사
                    flag = false;               // 배운게 아니라면 false
                    break;
                }
            }
            if(flag)                            // 읽을 수 있는 단어면 ++
                num++;
        }
        MAX = max(num, MAX);                    // 읽을 수 있는 단어 최대값 저장
    }
    for(int i = index; i < 26; i++){            // 3.연결된 곳을 순회
        if(visited[i])                          // 4.갈 수 있는가?
            continue;
        visited[i] = 1;                         // 체크인
        dfs(i, cnt + 1);                        // 간다.
        visited[i] = 0;                         // 체크아웃
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
    dfs(0, 0);
    //      }
    //  }
    cout << MAX;
}