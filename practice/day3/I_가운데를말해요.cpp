//1655 가운데를 말해요
// 중간값을 찾는 문제, 시간제한 -> heap 이용
// maxq, minq 를 활용하여 문제 해결
//      1. 최대힙의 크기는 항상 최소힙의 크기보다 같거나 1만큼 더 크다
//      2. 최소힙의 모든 원소는 최대힙의 모든 원소보다 항상 크거나 같아야 한다.
// 항상 가운데를 가르키고 있는 형태..
#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> maxq, minq;

int main(){
    int N, tmp;
    cin >> N;

    while(N--){
        cin >> tmp;
        if(maxq.size() > minq.size())   //최대힙의 크기가 더 크다면 최소힙에 push
            minq.push(-tmp);
        else
            maxq.push(tmp);
        if(maxq.empty() == false && minq.empty() == false){ //둘 다 값이 있다면
            if(maxq.top() > - minq.top()){                  // 최대 힙이 더 크다면
                int max_value = maxq.top();                 //두개의 값 교환
                int min_value = -minq.top();

                maxq.pop(); minq.pop();

                maxq.push(min_value);
                minq.push(-max_value);
            }
        }
        cout << maxq.top() << "\n";
    }
}