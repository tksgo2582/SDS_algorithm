//3955 캔디 분배 
// 확장 유클리드 호제법
//K k 대소문자 구분 못해서 몇시간날림..
#include <bits/stdc++.h>
using namespace std;

vector<tuple<long , long , long>> v;

long long gcd(long long a, long long  b){      // 최소공약수 구하는 함수
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

// ax + by = c => as + bt = r 을 만족하는 s, t, r 조합을 찾기(r이 gcd(a,b) 일때)
auto eGcd(int a, int b){
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
    // x : 인당 나눠줄 사탕의 개수  A : 사람 수
    // y : 사탕 봉지의 수          B : 봉지의 사탕 수
    // A *x + 1 = B*y
    // Ax + By = C 형태로 변환
    // -Ax + By = 1
    // A(-x) + By = 1
    int N, A, B, D ;
    long long K, C;
    cin >> N;
    int idx =0;

    while(N--){
        cin >> A >> B;
    // A, B 입력
    //    D = gcd(A, B);
    // D = gcd(A, B)
    // D * K = C  ==> C % D == 0 이어야만 해를 가질 수 있다( 베주 항등식) , C는 원래방정식 상수, D는 약분? 한 방정식 상수
    /* if(D != 1){     // <- **이 부분 체크
        cout << "IMPOSSIBLE\n";
        continue;
    } */

    //해가 존재하는 경우, => 확장 유클리드 호제법 이용하여 s,t,r = D 을 찾아낸다.
    eGcd(A,B);
    long long s,t,r;
    tie(s,t,r) = v[idx++];
    //cout << s <<" "<< t << " "<< r<< "";
    //v.clear();
    // x0 = s * C/D
    // y0 = t * C/D
    D = r;
    if(D != 1){     // <- **이 부분 체크
        cout << "IMPOSSIBLE\n";
        continue;
        }
    long x0 = s * (1/D); //현재는 D도 1..
    long y0 = t * (1/D);

    //일반해 공식 ( 둘의 부호는 달라야 한다. (하나 증가시, 하나는 감소))
    // x = x0 + B/D * k
    // y = y0 - A/D * k

    // x < 0 -> 위에서 x를 오른쪽으로 넘겼으니 음수 형태
    // x0 + B/D * K < 0
    // k < -x0 / B * D
    
    // 0 < y <= 10^9
    // 0 < y0 - A/D *k <= 10^9
    // -y0 < -A/D * k <= 10^9 - y0
    // (y0 - 10^9) / A * D <= k < y0 / A * D
    
    // (y0 - 10^9) / A * D   <=  k  <    y0 / A * D  (음수 가능..)
    //                           k  <   -x0 / B * D
    
    long kFromY = ((long)ceil((double)y0 /((double)A * (double)D))) -1;
    long kFromX = ((long)ceil((double)-x0 / ((double)B * (double)D))) -1;
    
    // k의 max 를 구한 후 그 k를 이용해서 y값을 구해냅니다. => k 가 커지면 y가 작아지므로
    // 그렇게 구한 y는 가장 작은 y 값입니다.
    long k = min(kFromX, kFromY);

    long long y = y0 -  (A/D) * k;
    
    // 그 구한 y값이 10^9 보다 작거나 같다면 가능한 답
    // 아니면 불가능한 답 
    
    if(y <= 1e9){   //(y0 - 10^9) / A * D   <=  k   이부분 범위 확인
        cout << y <<"\n";
    }else{
        cout << "IMPOSSIBLE\n";
    }

   /*  if(A == 1){     // 사람 1명일때
        if(B == 1)
            cout << "2\n";
        else 
            cout << "1\n";
        continue;
    }
    if (B == 1){    //봉지의 사탕이 1개 일때
        if(A + 1 > 1e9){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << A+1 << "\n";
        }
        continue;
    } */
    }
}