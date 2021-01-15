#include <bits/stdc++.h>
using namespace std;
#define MAX 120

bool check[MAX+1];

int main(){
    //int MAX = 120;
    
    for(int i = 2; i <= MAX; i++){
        if(check[i] == false){
            cout << i <<"\n";
            for(int j = i + i; j <= MAX ; j += i){ //j는 i만큼 증가(에라토네스 체) i * k 형태 수 체크
                check[j] = true;
            }
        }
    }


}