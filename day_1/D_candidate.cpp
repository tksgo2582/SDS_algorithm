// 1713 후보 추천하기
// 정렬 문제. // 복잡도 시간: n^2(K*100), 공간 : 101+101
// 1~100 까지 인점 유의해서 풀기
#include <bits/stdc++.h>

using namespace std;

struct person {
    int num;
    int vote;
    int time;
};
bool operator<(person p1, person p2){
    if(p1.vote == p2.vote)
        return p1.time > p2.time;
    else
        return p1.vote < p2.vote;
}

int N, K;
int cnt = 0;
int order = 0;
vector<person> v(101);

int main(){
    cin >> N >> K;
    int tmp;
    v[0].vote = 1001;
    for(int i = 1; i <= K; i++){
        cin >> tmp;
        cnt++;
        if(v[tmp].vote){
            v[tmp].vote++;
            cnt--;
        }
        else{
            if(cnt <= 3){
                v[tmp].num = tmp;
                v[tmp].vote++;
                v[tmp].time = i;
            }else{
                int change;
                int reco = 1001;
                for(int i = 1; i < 101; i++){
                    if(!v[i].vote)
                        continue;
                    if(reco > v[i].vote){
                        change = i;
                        reco = v[i].vote;
                    }
                    else if (reco == v[i].vote){
                        if(v[i].time < v[change].time)
                            change = i;
                    }
                }
                v[tmp].vote++;
                v[tmp].time = i;
                v[change].vote =0;
                v[change].time = 0;
            }
        }
    }
    for (int i = 1; i < 101; ++i)
        if (v[i].vote) 
            cout << v[i].num << ' ';

    return 0;
}