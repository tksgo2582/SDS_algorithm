#include <iostream>
#define MAX 110
#define INF 1e7
using namespace std;

int N, M,a,b,c;
int adj[MAX][MAX];

void floyd(){
    for(int j =1; j <=N; j++){
        for(int i =1; i <= N; i++){
            for(int k = 1; k <= N; k++){
                if(adj[i][j] == INF || adj[j][k] == INF)
                    continue;
                if(adj[i][j] + adj[j][k] < adj[i][k])
                    adj[i][k] = adj[i][j] + adj[j][k];
            }
        }
    }
}

int main(){

}