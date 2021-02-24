//1654 랜선자르기
// 파라메트릭 서치..이분탐색
// 전체 long long 범위를 통해서 찾아야 하네..
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX (int)1e5
using namespace std;

int K, N;
long long lan[MAX];
long long lenght;

int main(){
    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> lan[i];
    }
    long long low =0, hi =LLONG_MAX;
    long long  ans= 0;
    while(low <= hi){
        long long mid = (low+hi)/2;
        int result = 0;
        for(int i = 0; i < K;i++){
            result += (lan[i]/mid);
        }
        if(result < N){
            hi = mid - 1;
            //ans = mid;
        }
        else{
            ans = max(ans,mid);
            low = mid+1;
            //break;
        }
    }
    cout << ans;
}