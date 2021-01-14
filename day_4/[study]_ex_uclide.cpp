#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> v;

// ax + by = c => as + bt = r 을 만족하는 s, t, r 조합을 찾기(r이 gcd(a,b) 일때)
vector<tuple<int, int ,int>> eGcd(int a, int b){
    // 기본값 세팅. 표
    int S0 = 1, T0 = 0, R0 = a;
    int S1 = 0, T1 = 1, R1 = b;

    int tmp;
    while(R1 != 0){
        int q = R0 / R1;

        tmp = R0 - q * R1; // => 새로운 r 값 저장
        R0 = R1;
        R1 = tmp;

        tmp = S0 - q*S1;
        S0 = S1;
        S1 = tmp;

        tmp = T0 - q*T1;
        T0 = T1;
        T1 = tmp;
    }
    v.push_back({S0, T0, R0});
    
    return v;

}

int main(){

}