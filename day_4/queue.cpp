//10845 큐
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    queue <int> q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);

    cin >> n;
    string s;
    while(n--){
        cin >> s;
        if(s == "push"){
            cin >> num;
            q.push(num);
        }
        else if (s == "pop"){
            if(!q.empty()){
                cout << q.front()<< "\n";
                q.pop();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(s == "size"){
            cout << q.size()<< "\n";
        }
        else if(s == "empty"){
            if(!q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << 1 << "\n";
            }
        }
        else if(s == "front"){
            if(!q.empty()){
                cout << q.front() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if (s== "back"){
            if(!q.empty()){
                cout << q.back() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }
}