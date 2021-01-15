// 트라이 개념
#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode *children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (size_t i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    ~TrieNode() {
        for (size_t i = 0; i < 26; i++) {
            if (children[i] != NULL) {
                delete children[i];
            }
        }
    }
};

int tonum(char c) {
    return tolower(c) - 'a';
}
void insert(string words) {
    TrieNode curr = root;
    if (words == '\0')
        return;
    int next = tonum(words)
}

TrieNode current = root;