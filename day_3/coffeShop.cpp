//1275 커피숍2 인덱스트리 구현문제
// 트리 만들때 동적으로 만든다면 left 가 N보다 작을때 조건!
// 값 갱신시 nums 의 값도 갱신!
#include <bits/stdc++.h>
using namespace std;

long long S, N, Q;
long long *nums;
long long *tree;
//left, right : 구간합의 시작, 끝 1~N
long long makeTree(int node, int left, int right){
    if(left == right){              //리프노드
        if(left <= N){
            return tree[node] = nums[left]; // 리프노드에 저장
        }else{                      // 포화 이진트리 만들기
            return tree[node] = 0;
        }
    }
    int mid = (left + right)/2;
    // 다음 깊이로 들어가기
    tree[node] = makeTree(node*2, left, mid) + makeTree(node*2+1, mid +1, right);
    
    return tree[node];      
}
//부분합 함수 qLeft, qRight : 최종으로 원하는 부분합 범위 -> 변화x
long long query(int node, int left, int right, int qLeft, int qRight){  
    if(qRight < left || right < qLeft){ //1. 구간 밖
        return 0;
    }
    else if(qLeft <=left && right <= qRight){ // 2. 구간 안
        return tree[node];
    }
    else{                               //3. 구간에 걸쳐있는 경우
        int mid = (left + right) / 2;
        return query(node*2, left, mid, qLeft, qRight ) + query(node*2+1, mid + 1, right, qLeft, qRight ) ;
    }
}
//트리의 값 일부 갱신
void update(int node, int left, int right, int index, long long diff){
    if(left<=index && index <=right){   // 구간안에 존재
        tree[node] += diff;             // 차이만큼 증감
        if(left != right){              // 리프 노드가 아니라면
            int mid = (left + right) /2;
            update(node*2, left, mid, index, diff);
            update(node*2+1, mid+1, right, index, diff);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    long long x, y, a, b;
    nums = new long long[N+1];
    for(int i = 1 ; i <= N; i ++){
        cin >> nums[i];
    }
    // S값의 크기 구하기, N을 2의 제곱수로 만들고 S는 그 2배
    S=1;
    while(S < N){
        S *= 2;
    }
    tree = new long long[S * 2];

    makeTree(1 ,1, S);

    for(int i =0; i < Q; i++){
        cin >> x >> y >> a>> b;
        if(x>y)
            cout << query(1, 1, S, y, x) << "\n";
        else
            cout << query(1, 1, S, x, y) << "\n";
        long long diff = b -nums[a];
        nums[a] = b;        //nums 배열 업데이트
        update(1, 1, S, a, diff);
    }
}