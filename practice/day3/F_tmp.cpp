#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int root, num, cnt;
bool flag;

struct info {
    int value, left, right;
};

vector<info> tree;
void Make(int P, int idx) {
    if (tree[P].value > tree[idx].value) {
        if (tree[P].left == 0)
            tree[P].left = idx;
        else
            Make(tree[P].left, idx);
    } else {
        if (tree[P].right == 0)
            tree[P].right = idx;
        else
            Make(tree[P].right, idx);
    }
}

void SayPath(int now) {
    if (tree[now].left != 0)
        SayPath(tree[now].left);
    if (tree[now].right != 0)
        SayPath(tree[now].right);
    cout << tree[now].value << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cout.tie(NULL);
    //cin.tie(NULL);

    cin >> num;
    tree.push_back({num, 0, 0});

    while (cin >> num) {
        cnt++;
        tree.push_back({num, 0, 0});
        Make(0, cnt);
    }

    SayPath(0);

    return 0;
}