#include <bits/stdc++.h>
using namespace std;

long long  X, Y, Z;

int main(){
    cin >> X >> Y;

    Z = Y*100 / X;

    long long low=0, hi= 1e9;
    long long  result =0 ;
    while(low<=hi){
        int mid = (low+hi)/2;
        int tmpz = (Y+mid)*100 / (X+mid);
        
        if(tmpz <= Z){
            low = mid+1;
            result = mid+1;
        }
        else if(tmpz > Z){
            hi = mid-1;
        }
    }
    if(Z >= 99)
        cout << -1;
    else
        cout << result;
}