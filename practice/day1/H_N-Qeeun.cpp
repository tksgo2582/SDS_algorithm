#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int nqueen[16];

bool possible(int x){
    for(int i = 0 ;i < x; i++){
        if(nqueen[i] == nqueen[x] || abs(x-i) == abs(nqueen[x] - nqueen[i]))
            return false;
    }
    return true;
}

void Nqueen(int x){
    if(x == N){
        cnt++;
    }else{
        for(int i = 0; i < N; i++){
            nqueen[x] = i;

            if(possible(x)){
                Nqueen(x+1);
            }
        }
    }
}

int main(){
    cin >> N;
    cnt = 0;

    Nqueen(0);
    cout << cnt;
}