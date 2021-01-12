//9663 nqueen문제 
// dfs 비슷한 문제 
// 1차원 배열을 2차원처럼 생각
#include <bits/stdc++.h>

using namespace std;

int N, cnt =0;
int result = 0;
int queen[16];
bool possible(int x){ // 가능 여부 확인
    for(int i =0 ;i < x; i++){ // 1. 같은 열에 중복 2. 대각선 위치 검사
        if((queen[i] == queen[x]) || abs(x-i) == abs(queen[x] - queen[i]))
            return false;
    }
    return true;
}

void Nqueen(int x){
    if(x == N)
        cnt++;
    else{
        for(int i =0; i < N; i++){
            queen[x] = i;       // 몇번째 열에 놓을지 결정

            if(possible(x)){    // 놓을 수 있는지 감별
                Nqueen(x+1);    // 가능하다면 다음 줄 검사
            }
        }
    }
}

int main(){
    cin >> N;
    Nqueen(0);
    cout << cnt;
    }