//1735 분수합      2초.. 여유로운 편 시간: 3n ?
//유클리드 호제법으로 분모들의 공배수 구하고 각각 분수 계산 합

#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int gcd(int x, int y){
    int tmp;
    if(x<y){
        swap(x, y);
    }
    while(y!=0){
        tmp = x % y;
        x = y;
        y = tmp; 
    }
    return abs(x);
}
/* int lcm(int x, int y, int g){

} */

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a>>b>>c>>d;

    int G = gcd(b, d);

    int L1 = b/G, L2 = d/G; // 각 분모에 필요한 몫
    int L = L1 * L2 * G;    // 최소공배수 L
    int s = (L/b) * a + (L/d) * c; // 분모를 공배수로 바꾼뒤 분자들의 합

    int f = gcd(L,s);       // 마지막 점검

    if(f!=1){               // 기약분수 형태가 아니라면
        L /= f;             // 최대 공약수로 나눠준다.
        s /= f;
    }
    cout << s <<" " << L;
    
}