//2579 계단 오르기
#include <bits/stdc++.h>
using namespace std;
#define MAX 310

int N;
int stairs[MAX], max_point_0[MAX], max_point_1[MAX], max_point_2[MAX];

int main(){
    cin >> N;
    for(int i = 1 ; i<=N; i++){
        cin >> stairs[i];
    }
    
    max_point_1[1] = stairs[1];
    for(int i = 2; i <= N; i++){
        //max_point_0[i] 안써도 될듯?
        //관련이 있는데 i -2 에 있는 계단과 관련이 있음
        max_point_1[i] = max(max_point_1[i -2], max_point_2[i-2]) +stairs[i]; 
        
        //관련이 있는데 i -1에 있는 계단과 관련이 있음
        //시작이 아니고, 두번 밟은 애 아니고,
        max_point_2[i] = max_point_1[i-1] + stairs[i]; 
    }

    //출력????
    cout << max(max_point_1[N], max_point_2[N]);
}