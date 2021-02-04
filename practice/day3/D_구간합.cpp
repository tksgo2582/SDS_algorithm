#include <iostream>
#include <string>
using namespace std;

int N, M, K, S;
long long *nums, *tree;

long long maketree(int node, int left, int right){      //트리 생성
    if(left == right){                                  // 단말이라면 + N보다 작다면
        if(left <= N){                      // ?? 이해가 잘 가지 않음..
            return tree[node] = nums[left];             // 단말 값 저장
        }
        else{
            return tree[node] = 0;                      //비어 있는 값
        }
    }

    int mid = (left + right) /2;
    tree[node] = maketree(node*2, left, mid) + maketree(node*2+1, mid+1, right);    

    return tree[node];
}

long long query(int node, int left, int right, int qLeft, int qRight){
    if(qRight < left || right < qLeft){         //원하는 범위가 기존의 트리 값 밖
        return 0;
    }
    else if(qLeft <= left && right <= qRight){  //원하는 범위 안에 있을 때
        return tree[node];
    }
    else{                                       // 범위에 걸쳐 있을 때
        int mid = (left + right) /2;
        return query(node*2, left, mid, qLeft, qRight) + query(node*2+1, mid+1, right, qLeft, qRight);
    }
}

void update(int node, int left, int right, int index, long long diff){
    if(left <= index && index <= right){        //update하려는 값이 범위 안에 있다면
        tree[node] += diff;                     // 위의 값 update
        if(left != right){                      //단말이 아니라면
            int mid = (left + right)/2;
            update(node*2, left, mid, index, diff); // 각각 들어가서 다시 업데이트
            update(node*2+1, mid+1, right, index, diff);
        }
    }
}

int main(){
    cin >> N >> M >> K;
    nums = new long long [N+1];     //공간 할당
    for(int i  = 1 ; i <= N; i++){
        cin >> nums[i];
    }
    S = 1;
    while(S<N){
        S*=2;       // 2배씩 증가
    }
    tree = new long long [S*2]; // 인덱스트리 공간 설정
    long long a, b, c;              //c의 경우 int의 범위를 넘어가는 경우도 존재
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
    return 0;
}