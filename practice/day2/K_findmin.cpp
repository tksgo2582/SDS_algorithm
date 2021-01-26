#include <bits/stdc++.h>
using namespace std;

int N , L;
deque<pair<int, int>> pq;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    int low =0 , hi = low+L;
    for(int i =0; i < N; i++){
        int tmp;
        cin >> tmp;
        if(!pq.empty() && pq.front().second <= i -L){ //(왼쪽)비어있지 않고, 인덱스가 범위 밖에 있다면 pop
            pq.pop_front();
        }
        while(pq.size() && pq.back().first >= tmp){    //(오른쪽)비어있지 않고, 값이 input 보다 크다면 pop
            pq.pop_back();
        }

        pq.push_back({tmp, i});
        cout << pq.front().first << " ";
    }
}