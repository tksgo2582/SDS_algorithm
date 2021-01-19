// 1713 후보 추천하기
// 정렬 문제. // 복잡도 시간: n^2(K*100), 공간 : 101+101
// 1~100 까지 인점 유의해서 풀기
#include <bits/stdc++.h>

using namespace std;

int N, K;
int cnt = 0;
int order = 0;
vector<int> vote(101, 0);
vector<int> when(101, 0);

struct person {
    int num;
    int count;
    int time;
};

bool operator<(person n1, person n2) {
    if (n1.count == n2.count)
        return n1.time > n2.time;
    else
        return n1.count > n2.count;
}

int main() {
    cin >> N >> K;
    int tmp;
    for (size_t i = 1; i <= K; i++) {
        cin >> tmp;
        if (vote[tmp] > 0) // 사진틀에 있는 경우
            vote[tmp]++;   // 추천수 증가
        else {              // 사진틀에 없는 경우
            if (cnt < N) {  // 사진틀 여분 O 
                vote[tmp]++;// 추천수 ++, 시간 기록
                when[tmp] = i;
                cnt++;
            } else {        // 사진틀 여분 x
                int change; // 
                int reco = 1001;
                for (int i = 1; i < 101; i++) { 
                    if (!vote[i]) // 추천 없는 사진 넘기기
                        continue;
                    if (reco > vote[i]) { // 결국 투표수 제일 낮은게 나온다.
                        change = i;
                        reco = vote[i];
                    } else if (reco == vote[i]) { // 투표수가 같다면
                        if (when[i] < when[change]) // 더 오래된거 선택
                            change = i;
                    }
                }
                vote[tmp]++;  // 사진틀에 넣은 새로운 사진 추천수 ++
                when[tmp] = i; // 시간 저장
                vote[change] = 0; // 기존 사진 삭제
                when[change] = 0;
            }
        }
    }
    for (int i = 1; i < 101; ++i)
        if (when[i]) 
            cout << i << ' ';

    return 0;
}