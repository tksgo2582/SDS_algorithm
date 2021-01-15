#include <bits/stdc++.h>
using namespace std;
/*
int main(){
    priority_queue <pair<int, int>> pq;

    pq.push({-1,20}); // qp는 내림차순 정렬
    pq.push({1,2});

    cout << pq.top().second;
}
*/
int S, N, M, K;
long long *nums;
long long *tree;
// 인덱스 트리 생성
long long makeTree(int node, int left, int right){
    if(left == right){ // 리프노드
        if(left <= N){ // 마지막 층에 도착한다면 node는 S 이상, left 는 1 ~ S
            return tree[node] = nums[left]; 
        }else{
            return tree[node] = 0;
        }
    }

    int mid = (left + right) / 2;   //리프노드 아니라면 아래로 탐색

    tree[node] = makeTree(node*2, left, mid);
    tree[node] += makeTree(node*2+1, mid+1,right);

    return tree[node];
}

long long query(int node, int left, int right, int qLeft, int qRight){
    if(qRight < left || right < qLeft){ // 1. 범위 밖
        return 0;
    }
    else if(qLeft <=left && right <= qRight){ // 2. 범위 안
        return tree[node];
    }
    else{                               // 3. 범위에 걸침
        int mid = (left + right) /2;
        return query(node *2, left, mid, qLeft, qRight) + query(node * 2+1, mid+1, right, qLeft, qRight);
    }
}

long long update(int node, int left, int right, int index, long long diff){
    if(left <= index && index <= right){ // index가 범위 안일때만 코드 동작
        tree[node] +=diff;
        if(left != right){
            int mid = (left + right) /2;
            update(node * 2, left, mid, index, diff);
            update(node * 2 +1, mid + 1, right, index, diff);
        }
    }
}

int main(){
    cin >> N;
    nums = new long long[N+1];
    // 배열 숫자 입력
    for (size_t i = 1; i <= N; i++){
        cin >> nums[i];
    }
    
    S = 1;
    while(S < N){
        S *= 2;
    }
    tree = new long long [2 * S];

    makeTree(1, 1, S); // N 이 아닌 S
}