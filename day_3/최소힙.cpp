#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue <int> pq;

    int n;
    int tmp;
    cin >> n;
    for (size_t i = 0; i < n; i++){
        cin >> tmp;
        if(tmp == 0){
            if(!pq.empty()){
                cout << -pq.top() <<"\n";
                pq.pop();
            }
            else{
                cout << 0 << "\n";
            }
        }else{
            pq.push(-tmp);
        }
    }
    
}