//2143 두 배열의 합  시간 복잡도 : n^2
//각 배열의 부분합들을 모두 구해놓고
// 포인터 이용하여 하나씩 합해본다. lower_bound, upper_bound 활용
#include <bits/stdc++.h>

using namespace std;

long long T, n, m;
vector<long long> v1, A;
vector<long long> v2, B;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;  
    long long tmp;
    cin >> n;           //배열 입력
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v1.push_back(tmp);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        v2.push_back(tmp);
    }
    // V1, V2 부분합 구하기 각각 A,B에 저장
    for (int i = 0; i < n; i++) {
        long long sum = v1[i];
        A.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += v1[j];
            A.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++) {
        long long sum = v2[i];
        B.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += v2[j];
            B.push_back(sum);
        }
    }
    sort(A.begin(), A.end());   // 오름차순 정렬
    sort(B.begin(), B.end());

    long long result = 0;
    for (int i = 0; i < A.size(); i++) {
        int low = lower_bound(B.begin(), B.end(), T - A[i]) - B.begin();
        int high = upper_bound(B.begin(), B.end(), T - A[i]) - B.begin();
        result += high - low;  // A[i]에 대해 만족하는 B원소의 개수 구하기
    }
    cout << result;
}