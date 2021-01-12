//1072 게임 ,  승률 변화하는 값 구하기( 값 탐색 -> 이진 탐색)
//1. 99%의 승률에서 몇번을 이겨도 100%는 될 수 없습니다. 따라서 주어진 X와 Y에 대해 Z가 99 이상이면 -1을 출력합니다.
//2. 새로 찾는 확률은 ((Y + 횟수) * 100) / (X + 횟수)
//3. 따라서, low = 0, high = 1,000,000,000으로 두고 이분탐색을 통해 확률이 달라지는 횟수를 찾습니다.
//4. tempZ >= Z인 지점에서 결과가 갱신되기 때문에 mid +1 이 결과입니다.
// 파라메트릭 서치로 upperbound 구하는 방법도 있다. 내거는 lower 바운드 인듯?
#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

long long x, y;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    cin >> x >>y;
    int z = (y*100)/x;  // 승률 z 구하기

    if(z >= 99){        //1. 승률 99퍼인 경우
        cout << -1;
        return 0;
    }
    int low=0, high=INF, mid;
    int result = -1;
    while(low<=high){   //3. 이진탐색
        mid = (low + high) / 2;
        int tmpz = ((y+mid)*100)/(x+mid); //2.확률
        if(z >= tmpz){  // 승률 변화가 없는 경우
            result = mid + 1;   //결과값 갱신
            low = mid + 1;      //값 범위 상향
        }
        else{                   //승률 증가한 경우
            high = mid -1;      // 낮춰서 다시 검사
        }
    }
    cout << result;
}