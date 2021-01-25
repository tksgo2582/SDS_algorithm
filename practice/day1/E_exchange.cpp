#include <bits/stdc++.h>
using namespace std;
#define MAX 1e6

string N;
int K, result;
queue<pair<string, int>> q;
set<string> s;
int m_flag=0;
string __swap(string s1, int i, int j){
    swap(s1[i],s1[j]);
    return s1;
}

int BFS(){
    int cnt = 0;
    q.push( {N, cnt});

    while(!q.empty()){
        string str = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();
        /* if(s.count(str))
            continue; 
        s.insert(str); */
        if(cur_cnt == K){
            result = max( result, stoi(str) );
            continue;
        }
        for(int i = 0; i< str.size()-1; i++){
            for(int j = i+1; j <str.size(); j++){
                if(i == 0 && str[j] == '0'){
                    m_flag = 1;
                    continue;
                }
                string newstr = __swap(str,i,j);    //재정의한 swap 함수, 
                if(!s.count(newstr)){               //set에 없는것만 큐에 넣는다.
                    q.push({newstr, cur_cnt+1});
                    s.insert(newstr);
                }
                //swap(str[i], str[j]);
            }
        }
        s.clear();
    }
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;

    BFS();
    if(!m_flag){
        cout << result;
    }else
        cout << -1;
}