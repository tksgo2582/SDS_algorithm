//10816 숫자카드 2
// map 이용해서 각 key값별로 개수 저장
#include <iostream>
#include <map>
using namespace std;

int N, M;
int tmp;
map <int, int> p;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> tmp;
        if(p.find(tmp)!=p.end()){
            p[tmp]++;
        }
        else{
            p.insert({tmp,1});
        }
    }
    cin >> M;
    for(int i = 0;i < M; i++){
        cin >> tmp;
        if(p.find(tmp)!=p.end()){
            cout << p[tmp];
        }
        else{
            cout << "0";
        }
        cout << " ";
    }
}