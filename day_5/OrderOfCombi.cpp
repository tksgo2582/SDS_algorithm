//1722 순열의 순서
//https://kosaf04pyh.tistory.com/211
// 최대값을 확인한 후 자료형 정하기
#include <bits/stdc++.h>
using namespace std;
#define MAX 21

long long N, K;     // k는 최대 20! -> long long
int nums[21];
bool check[MAX];
long long fac[MAX];
vector<int> v;

int main(){
    cin >> N;
    int P;
    cin >> P;

    fac[0]=1;
    for(int i = 1; i < MAX; i++){   // 1.팩토리얼들 미리 계산
        fac[i] = fac[i-1] * i;
    }

    if(P == 1){
        cin >> K;
        for(int i = 1; i <= N; i++){ // 첫번째 숫자부터 확인
            for(int j = 1; j <=N; j++){
                if(check[j]){       // 사용한 숫자인지 확인
                    continue;
                }
                if(K > fac[N - i]){ // 다음 숫자가 앞에 와야 한다.
                    K -= fac[N - i]; // 앞에 있는 순서들은 제외 
                }
                else{                   // K번째 포함하는 자리수?
                    v.push_back(j);     //사용한 숫자 넣어준다.
                    check[j] = true;    // 사용했다고 표시
                    break;
                }
            }
        }
        for(int i = 0; i < N; i++){ //숫자 차례대로 출력
            cout << v[i] << " ";
        }
    }
    else{
        for(int i =1; i<= N; i++){  // 숫자 순서 입력
            cin >> nums[i];
        }
        long long result = 0;   // 몇번째인지 알려줄 변수

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <nums[i]; j++){
                if(check[j]){   //사용한 숫자 인지 확인
                    continue;
                }
                result += fac[N-i]; // 사용안한 숫자라면 (N-i)! 그만큼 횟수 증가.
            }
            check[nums[i]] = true; // 입력받은 배열의 숫자 사용 체크
        }
        cout << result + 1;         // 그 숫자 전까지 찾았으니 원하는 숫자는 +1
    }

}