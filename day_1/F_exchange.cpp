//1309 교환
//한 자리수인 경우, 0으로 끝나는 두자리 수(10..) 등은 -1 출력
// i j k l m
#include <bits/stdc++.h>

using namespace std;

string N;
int K;
queue<string> q;
set<string> s;
	//k 연산별로 이전에 교체했던건지 체크
void bfs(){
    for(int i = 0 ; i < K; i++ ){  // 연산 횟수 만큼 동작
        int size = q.size();
        s.clear();             // 연산마다 초기화
        
        for(int j = 0; j < size; j++ ){    // 현재 들어있는 숫자배열 만큼
            string curr = q.front();  //1. 큐에서 꺼내옴
            q.pop();
            if(s.count(curr))         //2. 목적지에 도착했는가?(여기서는 목적지가 전체 순회)
                continue;
            s.insert(curr);           // 이전에 들어온적 없는 숫자배열이라면 set에 저장
            
            for(int k = 0; k < N.size()-1; k++){ //3. 연결된 곳을 순회,  현재 숫자 배열들에 대해서 모두 순회
                for(int l =k+1; l <N.size(); l++){
                    if(k > 0 || curr[l] != '0'){ //4.    갈 수 있는가?, 연산횟수가 남았고, 바꾸려는 숫자가 0이 아닌가?
                        swap(curr[k], curr[l]);    // 체크인
                        q.push(curr);              //5. 큐에 넣음
                        swap(curr[k],curr[l]);     // 체크 아웃
                    }
                }
            }
        }
    }
}     

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    q.push(N);

    bfs();

    string ans = "0";
    while(!q.empty()){
        ans = max(ans, q.front());
        q.pop();
    }
    if(ans[0] == '0')
        cout << "-1\n";
    else
    {
        cout << ans;
    }

}