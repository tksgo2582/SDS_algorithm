//1920 숫자 찾기
// 1 <= N,M <= 100000    숫자범위 +-2^31 -> int형 범위 
// 범위가 넓은경우 이진탐색으로.. 복잡도 NlogN

#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<long long> num;
vector <bool> ans(100001,0);

int main(){
    cin >> N;
    int tmp;
    for (size_t i = 0; i < N; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end()); // 정렬
    
    cin >> M;
    for(int i = 0; i< M; i++){      
        cin >> tmp;
        int start=0, end=N-1, mid;
        while(start <= end){        // 이진 탐색
            mid = (start+end)/2;
            if(tmp < num[mid]){
                end = mid-1;
                
            }else if( tmp > num[mid]){
                start = mid+1;
            }
            else{
                ans[i]=1;
                break;
            }
        }
    }
    for(int i = 0; i< M; i++){
        cout << ans[i] << "\n";
    }

}