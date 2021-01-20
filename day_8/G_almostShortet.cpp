//5719 거의 최단경로

void dijk(){
    while(!pq.empty()){
        //cur
        //주변탐색
        for (size_t i = 0; i < adj[cur].size(); i++)
        {
            next
            if(new_distance < dist[next]){
                dist[next] = new_distance
                how_come[next] = 간선정보를 추가????
            }
            else if(new_distance < dist[next] == dist[next]){
                how_come[next] = 간선정보를 추가???
            }
        }
        
    }
}
//추가한 간선 정보를 어떻게??
//사용하지 않게 한 상태에서
//다시 dijkstra를 사용

//간선을 사용할 수 있는지 판단하는 접근법
//1. 건선의 번호를 부여해서 관리하는 방법
//2. N*N 배열을 이용해서 사용하는 방법