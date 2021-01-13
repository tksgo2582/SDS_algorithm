//2517  달리기
//단순 비교 x , 특수한 이론 필요!
// inversion count. -> mergesort 하며 숫자가 뒤바뀌는 횟수 기록
// 앞에서 내려온거는 카운팅 x 뒤에 새로 온 순간만 체크
// 뒤에서 내려올때 내 앞에 남아있는 숫자가 나보다 더 큰 수의 개수 카운트.
// *문제에서는 내림차순으로 정렬 후 카운트
//https://eine.tistory.com/entry/%EB%B0%B1%EC%A4%80-2517-%EB%8B%AC%EB%A6%AC%EA%B8%B0-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4
#include <bits/stdc++.h>
using namespace std;

int N;
typedef pair<int, int> pii;
pii A[500005];
pii T[500005];
int ans[500005];
void merged(int s, int m, int e) {
    int p1 = s;
    int p2 = m;
    int k = s;
    while (p1 < m && p2 < e) { // 나누어진 배열 안에서
        if (A[p1].first <= A[p2].first) { // 오름차순 정렬
            T[k++] = A[p1++];
        } else {                  // 앞이 더 크다면
            int advance = p1 - s; // 몇칸 앞으로 갈 수 있는지
            int origin_rank = A[p2].second; // 실제 등수
            if (advance) {
                ans[origin_rank] -= advance; 
                /* printf("%d의 원래 순위는 %d이고, %d개를 앞지를 수 있다.\n", A[p2].first, origin_rank, advance); for (int i=s; i < p1; i++) { printf("\t%d를 앞지른다.\n", A[i]); } */
            }
            T[k++] = A[p2++];
        }
    }
    while (p1 < m) {
        T[k++] = A[p1++];
    }
    while (p2 < e) {
        int advance = p1 - s;
        int origin_rank = A[p2].second;
        if (advance) {
            ans[origin_rank] -= advance; /* printf("%d의 원래 순위는 %d이고, %d개를 앞지를 수 있다.\n", A[p2].first, origin_rank, advance); for (int i=s; i < p1; i++) { printf("\t%d를 앞지른다.\n", A[i]); } */
        }
        T[k++] = A[p2++];
    }
    for (int i = s; i < e; i++) {
        A[i] = T[i];
    }
}
void mergeSort(int s, int e){
    int m = (s + e)/2;
    if(s < m){
        mergeSort(s, m);
        mergeSort(m, e);
        merged(s, m, e);
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >>A[i].first;
        A[i].second = i;
        ans[i] = i;
    }
    mergeSort(1, N + 1);
    for (int i = 1; i <= N; i++) {
        printf("%d\n", ans[i]);
    }
}