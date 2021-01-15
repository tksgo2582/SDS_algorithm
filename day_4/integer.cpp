// 확장 유클리드 호제법

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    while(b != 0){ // b가 0일때 a가 gcd가 된다.
        int r = a % b;
        a=b;
        b=r;
    }
    return a;
}

int main(){

}