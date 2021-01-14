//14476 최대공약수 하나 빼기
// left, right 에 누적 gcd 만든다.
// left : g[8], g[8,12], g[8 ~ 24], g[ 8 ~ 36] ...
// right : g[48], g[48 ~ 36] .... 뒤에서 부터 계산.
// 필요한 부분만 꺼내서 합 계산
// gcd(a, b) == gcd(b, r), r = a%b, r이 0이 되는순간 => gcd 
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int N;
int nums[MAX];
int LEFT[MAX]={0,};
int RIGHT[MAX]={0,};
vector <pair<int, int>> v;

int gcd(int a, int b){      // 최소공약수 구하는 함수
    if(a < b){
        swap(a,b);
    }

    while(b != 0){      // b가 0일때 a가 gcd가 된다.
        int r = a % b;
        a=b;
        b=r;
    }
    if(a < 0){
        return -a;
    }
    return a;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }

    LEFT[0] = nums[0];  //맨처음의 공약수
    for (int i = 1; i < N-1; i++){
        LEFT[i] += gcd(LEFT[i], nums[i+1]);
    }

    RIGHT[N-1] = nums[N-1]; // 마지막 숫자의 공약수
    for (size_t i = N-2; i >= 0; i--){  // size_t 
        RIGHT[i] += gcd(RIGHT[i+1], nums[i]);
    }

    int c_gcd;  // 현재 공약수 
    
    for (int i = 0; i < N; i++){
        if(i -1 < 0){       // 첫번째 수 제외 
            c_gcd = RIGHT[1];
        }
        else if(i >= N - 1){ // 마지막 수 제외
            c_gcd = LEFT[N-2];
        }
        else{               //그 사이 값
            c_gcd = gcd(LEFT[i-1], RIGHT[i+1]);
        }

        if(gcd(nums[i], c_gcd) == c_gcd)    //제외된 숫자가 공약수를 포함하는지 
            continue;

        v.push_back({c_gcd, nums[i]});  //정답 벡터에 저장
    }

    sort(v.begin(), v.end());   // 정렬, 가장 큰 숫자가 뒤로
    
    if(v.size() == 0){
        cout << -1 << "\n";
        return 0;
    }else{                      // 마지막 숫자 출력(가장 큰 약수)
        cout << v.back().first << " " << v.back().second;
    } 

}