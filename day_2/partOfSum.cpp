//1806 수들의 합 2  시간 제한 : 0.5초
// 부분합 문제  포인터 2개 이용하여 문제풀이(2003 재활용)
#include <bits/stdc++.h>

using namespace std;
#define INF 9999999
int N;
long long M;
vector<int> v;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int tmp;

    for (int i = 0; i < N; i++) {  // 배열 입력 부분
        cin >> tmp;
        v.push_back(tmp);
    }
    int sum = v[0];
    int cnt = 1;
    int low = 0, hi = 0;
    int result= INT_MAX;

    while (low <= hi && hi < N) {  // 부분합 찾기, M 이상이면 됨.
        if (sum < M){               // 원하는 값에 도달x , sum 범위 증가
            sum += v[++hi];
            cnt ++;                 // sum에 사용된 숫자 개수
        }
        else if (sum == M) {  // 원하는 값 도달, cnt증가
            result = min(result,cnt);
            cnt++;
            sum += v[++hi];
        }else if (sum > M) {           // 합 초과
            result = min(result,cnt);
            sum -= v[low++];
            cnt--;            // sum 범위 감소
            if (low > hi && low < N) {  // low가 hi보다 높아졌다면
                hi = low;               // low hi 재설정
                sum = v[low];           //sum 초기화
                cnt = 0;
            }
        }
    }
    
    if(result == INT_MAX)
        cout << 0;
    else
        cout << result;
}