#include <bits/stdc++.h>
using namespace std;

long long *tree, *nums;
int N;
long long S =1;

long long query(int node, int left, int right, int target){
    if(left == right){
        cout << left << "\n";
        return left;
    }
    else{
        int mid = (left + right)/2;
        if(tree[node*2] >= target ){
            return query(node*2, left, mid, target);
        }
        target -= tree[node*2];

        if(tree[node*2+1] >= target){
            return query(node*2+1, mid+1, right, target);
        }
    }
}

void update(int node, int left, int right, long long idx, long long diff){
    if(left<=idx && idx <=right){
        tree[node] += diff;
        if(left != right){
            int mid = (left + right) /2;
            update(node*2, left, mid, idx, diff);
            update(node*2+1,mid+1, right, idx, diff);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(S<=1e6){
        S*=2;
    }
    tree = new long long[S*2];  //-> s*2 로 해줘야 크기 적당.. 위에서 <로 하든 <= 로 하든 상관 x
    long long n , a,b,c;
    long long result;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            //int idx = query(1, 1, S, b);
            long long idx = query(1, 1, S, b);
            result = 0;
            update(1, 1, S, idx, -1);
        } else {
            cin >> b >> c;
            update(1, 1, S, b, c);
        }
    }
}