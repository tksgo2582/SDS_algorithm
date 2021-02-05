//1202 보석도둑
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct info{
    int m, v;
};

int N, K;
vector<info> jewel; //무게 가격
long long *bags;           //가방무게

bool cmp(info j1, info j2){
    return j1.v > j2.v;
}
bool cmp2(info j1, info j2){
    return j1.m < j2.m;
}
int main(){
    cin >> N >> K;
    for(int i = 0 ; i < N; i++){
        int m, v;
        cin >> m >> v;
        jewel.push_back({m,v});
    }
    bags = new long long[K+1];
    for(int i =0 ; i < K; i++){
        cin >> bags[i];
    }

    sort(jewel.begin(), jewel.end(), cmp2);
    sort(bags, bags+K);
    long long result = 0;
    int idx = 0;
    priority_queue<int> can_jewel;

    for(int i = 0; i < K; i++){
        long long bag = bags[i];
        for(int j = idx; j <N; j++){
            if(bag < jewel[j].m){
                break;
            }
            idx++;
            can_jewel.push(jewel[j].v);
        }
        if(!can_jewel.empty()){
            result += can_jewel.top();
            can_jewel.pop();
        }
    }
    cout << result;
}