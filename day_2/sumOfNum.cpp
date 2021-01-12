//2003 수들의 합 2  시간 제한 : 0.5초
// 부분합 문제  포인터 2개 이용하여 문제풀이
//low가 high 이하이고 high가 N 미만일 때 아래와 같은 상황을 계속 확인해줍니다.
//i)구간 합이 M보다 작다면 high를 하나 더 오른쪽으로 가고 해당 숫자도 구간 합에 더해줍니다.
//ii)구간 합이 M과 같다면 경우의 수를 늘려주고 high를 하나 더 오른쪽으로 가고 해당 숫자도 구간 합에 더해줍니다.
//iii)구간 합이 M보다 크다면 low를 하나 더 오른쪽으로 가주고 low 위치에 있던 숫자를 sum에서 빼줍니다.
//a)이 때, low가 high를 역전하고 low가 N 미만일 경우 while문의 조건을 맞추기 위해 high를 low 위치와 같게 만들고 구간을 low에서부터 다시 시작합니다.

#include <bits/stdc++.h>

using namespace std;

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
    int cnt = 0;
    int low = 0, hi = 0;

    while (low <= hi && hi < N) {  // 부분합 찾기
        if (sum < M)               // 원하는 값에 도달x , sum 범위 증가
            sum += v[++hi];
        else if (sum == M) {  // 원하는 값 도달, cnt증가
            cnt++;
            sum += v[++hi];
        } else if (sum > M) {           // 합 초과
            sum -= v[low++];            // sum 범위 감소
            if (low > hi && low < N) {  // low가 hi보다 높아졌다면
                hi = low;               // low hi 재설정
                sum = v[low];           //sum 초기화
            }
        }
    }
    cout << cnt;
}