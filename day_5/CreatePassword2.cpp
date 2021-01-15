//1837 암호제작
// pw % p(2~k) = 0 이면 안 좋은 암호
// 각 자리수 별로 나눈다??
#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e6

bool checked[MAX];
string P;
int K;

bool check(int num){
	int sum = 0;	
	// 주어진 수 P 를 각 자리수별로(큰 자리수부터) 나누어 본다
	for(int i=0; P[i];i++) 
		sum = (sum*10+(P[i]-'0'))%num;
	if(sum==0) 
        return true;
	return false;
}

bool checkIsBad(int x){ //BigInteger 라고 불린다. -> BigInteger 사칙연산 구연할 수 있어야 한다.
    int r =0;           //r은 k 에 따라 범위 설정(k 가 int 범위 넘어가면 r 도 넘어간다.)
    for(int i = 0; i< P.size(); i++){
        r = (r * 10 + (P[i] - '0')) % x;
    }
    if(r == 0)
        return true;
    else
        return false;
}

int main(){
    //int MAX = 120;
    cin >> P >> K;
    bool good = true;
    int ans = 0;
    vector<int> v;
    
    /* for(int i = 2; i < K; i++){
        if(checked[i] == false){
            v.push_back(i);
            //cout << i <<"\n";
            for(int j = i + i; j < K ; j += i){ //j는 i만큼 증가(에라토네스 체) i * k 형태 수 체크
                checked[j] = true;
            }
        }
    } */
    for(int prime : v){
        if(prime >= K){
            break;
        }
        if(checkIsBad(prime)){
            cout << "BAD";
            return 0;
        }
    }

    if(good) 
        cout << "GOOD" << '\n';
    else 
        cout << "BAD " << ans << '\n';

    return 0;
}