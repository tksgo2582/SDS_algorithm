// 달리기 문제 -> 인덱스 트리로도 풀 수 있다.
#include <bits/stdc++.h>
using namespace std;
int N;
typedef pair<int, int> pii;
pii A[500005];
pii T[500005];
int ans[500005];
void merged(int s, int m, int e){
    int p1 = s;
    int p2 = m+1;
    int k = s;
    while(p1 <= m && p2 <= e){
        if(A[p1].first >= A[p2].first){
            T[k++] = A[p1++];
        }else{ // 뒤가 더 큰 경우
            int count = m - p1 + 1; // ?? 왜 미드부터 비교할까?
            int original = A[p2].second;
            ans[original] -= count;
        }
    }
    while(p1 <= m){
        T[k++] = A[p1++];
    }
    while(p2 <= e){
        T[k++] = A[p2++];
    }
    for(int i = s; i <= e; i ++){
        A[i] = T[i];
    }
}
void mergesort(int s, int e){
    int m;
    if ( s < e){
        m = (s+e)/2;
        mergesort(s, m);
        mergesort(m + 1, e);
        merged(s, m, e);
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >>A[i].first;
        A[i].second = i+1;
        ans[i] = i+1;
    }
    mergesort(0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d\n", ans[i]);
    }
}