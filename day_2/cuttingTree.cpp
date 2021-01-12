//2805 나무자르기  파라메트릭 서치
// 1 <= N <= 1000000   1<=M<=2000000000  큰 수를 보면 이진탐색을 떠올리자
// int형 범위 +-20억// sum 변수의 경우는 longlong으로 해줘야 통과
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int tmp;
    for (size_t i = 0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    //sort(v.begin(), v.end());
    int low=0, hi=*max_element(v.begin(), v.end()), mid;
    long long sum=0, result;
    while(low <= hi){
        sum=0;
        mid = (low+hi)/2;
        for(int i =0; i < v.size(); i++){
            if(v[i] > mid)
                sum+= v[i]-mid;
        }
        if(sum < M){
            hi = mid-1;
        }else{
            result = mid;
            low = mid+1;
        }
    }
    cout << result;
}