#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
ll *tree;
ll *nums;

long long maketree(int node, int left, int right){
    if(left == right){
        if(left <= N){
            return tree[node] = nums[node];
        }
        else
            return tree[node] = 0;
    }

    int mid = (left + right) /2; 
    tree[node] = maketree(node*2, left, mid) + maketree(node*2+1 , mid + 1, right);
    return tree[node]; 
}

long long query(int node , int left, int right, int qLeft, int qRight){
    if(qRight < left || right <= qLeft){
        return 0;
    }
    else if(qLeft <= left || right <= qRight){
        return tree[node];
    }
    else{
        int mid = (left + right)/2;
        return query(node*2, left, mid, qLeft, qRight) + query(node*2+1, mid+1, right, qLeft, qRight);
    }
}

void update(int node, int left, int right, int index, long long diff){
    if(left<=index && index <=right){
        tree[node] += diff;
        if(left!=right){
            int mid = (left+right)/2;
            update(node*2, left, mid, index, diff);
            update(node*2+1, mid+1, right, index, diff);
        }
    }
}

int main(){

    cin >> N;

    int s =1;
    while(s<=N){
        s*=2;
    }
    tree = new ll[s];

    maketree(1, 1, s);


}