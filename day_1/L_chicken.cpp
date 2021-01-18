//15686 치킨배달
// 조합 만들어보기 전체 탐색 시간: n * n * n ~n*n 사이
// next_permutation 한 집에서 제일 가까운 치킨집의 거리 계산 후 결과 저장 
// 모든 조합의 치킨 거리 계산 후 제일 작은 거리 출력

#include <bits/stdc++.h>
using namespace std;
#define MAX 51
int N, M;
int mat[MAX][MAX];
vector<pair<int, int>> chicken, house;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 1){
                house.push_back({i,j});
            }else if(mat[i][j] == 2){
                chicken.push_back({i,j});
            }
        }
    }
    // 조합을 위한 행렬 생성, 치킨집 개수만큼
    int ind[chicken.size()] = {0,};
    for(int i = 0; i < M; i++){
        ind[i] = 1;
    }
    vector<int> ans;    //정답 저장할 벡터
    sort(ind, ind+chicken.size());   // 순열 쓰기전 항상 정렬
    do
    {   
        int result = 0; //그 집에서 제일 가까운 치킨집 저장
        for(int i = 0; i < house.size(); i++){ 
            int tmp = 1e4;
            for(int j= 0; j < chicken.size(); j++){ // 한집에 대한 치킨집들의 거리 계산
                if(ind[j] == 1){
                    tmp = min(tmp, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
                }
            }
            result += tmp;
        }
        ans.push_back(result);
    } while (next_permutation(ind, ind+chicken.size())); // 조합을 위한 순열 만든다.
    
    cout << *min_element(ans.begin(), ans.end());

}