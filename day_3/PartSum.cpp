//2042 구간 합 구하기
#include <bits/stdc++.h>
using namespace std;

int N, M, K, S;
int a, b, c;
long long *nums;
long long *tree;

long long maketree(int node, int left, int right){
    if(left == right){
        if(left <= N){
            return tree[node] = nums[left];
        }
        else{
            return tree[node] = 0;
        }
    }

    int mid = (left + right) /2;
    tree[node] = maketree(node*2, left, mid) + maketree(node*2+1,mid+1,right); 
    
    return tree[node];
}

long long query(int node, int left, int right, int qLeft, int qRight ){
    if(qRight<left|| right < qLeft){
        return 0;
    }
    else if(qLeft <= left && right <= qRight){
        return tree[node];
    }
    else{
        int mid = (left + right)/2;
        return query(node*2, left, mid, qLeft, qRight) + query(node*2+1, mid+1, right, qLeft, qRight);
    }
}

void update(int node, int left, int right, int index, long long diff){
    if(left <= index && index <=right){
        tree[node] += diff;
        if(left != right){
            int mid = (left + right) / 2;
            update(node * 2, left, mid, index, diff);
            update(node * 2 + 1, mid+1, right, index, diff);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    nums = new long long[N+1];
    for(int i = 1; i <= N; i++){
        cin >> nums[i];
    }

    S = 1;
    while(S<N){
        S*=2;
    }
    tree = new long long[S*2];

    maketree(1, 1, S);

    for(int i =0; i<M+K; i++){
        cin >> a>> b>> c;
        if(a == 1){
            update(1, 1, S, b, c - nums[b]);
            nums[b] = c;
        }
        else{
            cout << query(1, 1, S, b, c) << "\n";
        }
    }
}