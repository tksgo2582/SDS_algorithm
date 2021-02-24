//2110  공유기 설치 https://do-rang.tistory.com/67
// 이분탐색, 공유기가 설치될수 있는 최소 =1 최대거리 구해서 이분탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector <long long> v;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> C;
    for(int i =0; i < N ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    long long low = 1 , hi = v[N-1] - v[0];
    long long ans = 0;
    while(low <= hi){
        long long mid = (low+hi)/2;
        int cnt = 1;
        long long start = v[0];

        for(int i = 1; i < N; i++){
            if(v[i] - start >= mid){
                start = v[i];
                cnt++;
            }
        }
        if(cnt < C){
            hi = mid-1;
        }
        else{
            low = mid +1;
            ans = mid;
        }
    }
    cout<< ans;
}