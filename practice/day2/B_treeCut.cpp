#include <bits/stdc++.h>
using namespace std;

int N, M; //20억
vector<int> v;

int main(){
    cin >> N >> M;
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    long long low =0, hi = *max_element(v.begin(), v.end()), mid;
    long long sum =0, result=0;
    while(low <= hi){
        mid = (low+hi)/2;
        sum = 0;

        for(int i =0; i<N; i++){
            if(v[i] > mid)
                sum += (v[i]-mid);
        }
        if(sum < M){
            hi = mid-1;
        }else if(sum == M){
            result = mid;
            break;
        }else{
            low = mid + 1;
            result = max(mid, result);
        }
    }
    cout << result;
}