#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<long long> ans;

int main(){
    cin >> N >> M;
    int tmp;
    for(int i =0;i <N; i++){
        cin >> tmp;
        ans.push_back(tmp);
    }
    int low= 0, hi= 0;
    long long sum = ans[0];
    int cnt = 0;
    while(low <=hi && hi < N){
        if(sum < M){
            sum+=ans[++hi];
        }
        else if(sum == M){
            cnt++;
            sum +=ans[++hi];
        }
        else{
            sum-=ans[low++];
            if(low >hi && low <N){
                hi = low;
                sum = ans[low];
            }
        }
    }
    cout << cnt;
}