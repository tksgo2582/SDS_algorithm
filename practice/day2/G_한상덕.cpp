#include<bits/stdc++.h>
using namespace std;
#define MAX 55

int N;
char Map[MAX][MAX];
int height[MAX][MAX];
bool visited[MAX][MAX];
int dx[8] = {1,1,1,0,-1,-1,-1,0}, dy[8] = {1,0,-1,-1,-1,0,1,1};
int house = 0;
int homex,homey;

bool bfs(int s, int e){
    queue<pair<int, int>> q;
    q.push({homex,homey});          //시작점 넣고, 1. 방문 체크인
    visited[homex][homey] = true;
    int tmp = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(Map[x][y] == 'K'){       // 배달
            tmp++;
            if(tmp == house)        //2. 도달 여부
                return true;
        }
        for(int i = 0 ; i < 8; i++){    //3. 순회
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx < N && ny >=0 && ny < N && !visited[nx][ny]){    // 4. 가능한가?
                if(s <=height[nx][ny] && height[nx][ny] <= e){              // 범위 안의 높이 인가?
                    visited[nx][ny] = true;
                    q.push({nx,ny});            // bfs
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> N;
    
    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            Map[i][j] = s[j];
            if(Map[i][j] == 'K'){
                house++;            //방문해야 하는 집 개수 체크
            }
            if(Map[i][j] == 'P'){
                homex=i, homey=j;   //시작점 체크
            }
        }
    }
    vector <int> diff_height;  
    for(int i =0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> height[i][j];
            diff_height.push_back(height[i][j]);    //각 지역의 높이 저장
        }
    }

    sort(diff_height.begin(), diff_height.end());   //높이 순으로 정렬
    diff_height.erase(unique(diff_height.begin(), diff_height.end()), diff_height.end()); // 중복값 삭제

    int ans = 987654321;
    int left=0, right=0;

    while(right < diff_height.size()){  //높이 범위 만큼
        while(1){
            bool suc = false;
            // 우체국 높이가 범위 안에 있다면 --> bfs  
            if(diff_height[left] <= height[homex][homey] &&  height[homex][homey] <= diff_height[right]){
                suc = bfs(diff_height[left], diff_height[right]);
                memset(visited, 0 ,sizeof(visited));
            }

            if(!suc) break; //배달 불가능하면 다음으로

            int diff = diff_height[right] - diff_height[left]; // 최대 높이차
            if(ans > diff)
                ans = diff;
            left++;         // 
        }
        right++;            // 다음 높이로
    }
    cout << ans;
}