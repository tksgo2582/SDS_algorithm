//9202 보글
// 팔방 탐색(dfs) + trie
// 중복 x

#include <bits/stdc++.h>

using namespace std;

class Trie {
   public:
    Trie* children[26];
    bool isFinish;

    Trie() {
        this->isFinish = false;
        for (size_t i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i])
                delete this->children[i];
        }
    }

    void insert(string key, int idx) {
        if (key[idx] == NULL)
            isFinish = true;
        else {
            int next = key[idx] - 'A';
            if (children[next] == NULL)
                children[next] = new Trie();
            children[next]->insert(key, idx + 1);
        }
    }

    bool search(string key, int idx) {
        if (key[idx] == NULL) {
            if (isFinish)
                return true;
            return false;
        }
        int current = key[idx] - 'A';
        if (children[current] == NULL)
            return false;
        return children[current]->search(key, idx + 1);
    }
} Trie;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
    dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

set<string> s;
int N, B, len, word_cnt, res;
string word, a, longgest;

/*  DFS 법칙
    1. 체크인
    2. 목적지에 도달하였는가?
    3. 연결된 곳을 순회
    4. 가능한가?
    5. 간다
    6. 체크아웃  */
void Dfs(int x, int y, string word, int cnt, string boggle[][5], bool visited[][5]) {
    if (cnt == 9)
        return;
    if (Trie.search(word, 0)) {
        if (s.find(word) == s.end()) {
            s.insert(word);
            word_cnt++, res += score[cnt];
            if (longgest.size() < cnt)
                longgest = word;
            else if (longgest.size() == cnt)
                longgest = min(longgest, word);
        }
    }
    //3. 연결된 곳을 순회
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
    //4. 가능한가? -> 맵, 방문 여부, node 에 자식 존재 여부
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visited[nx][ny]) {
            visited[nx][ny] = true;       //1. 체크인
            word += boggle[nx][ny];       // 1.
            Dfs(nx, ny, word, cnt + 1, boggle, visited);
            visited[nx][ny] = false;      //6. 체크아웃
            word.resize(word.size() - 1); //6.
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word;
        Trie.insert(word, 0);
    }
    cin >> B;
    for (int b = 0; b < B; b++) {
        string boggle[5][5];
        bool visited[5][5] = {
            false
        };
        for (int i = 0; i < 4; i++) {
            cin >> a;
            for (int j = 0; j < 4; j++) 
                boggle[i][j] = a[j];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                visited[i][j] = true;
                Dfs(i, j, boggle[i][j], 1, boggle, visited);
                visited[i][j] = false;
            }
        }
        cout << res << " " << longgest << " " << word_cnt << "\n";
        res = 0, longgest = "", word_cnt = 0, s.clear();
    }
    return 0;
}