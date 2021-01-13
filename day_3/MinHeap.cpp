//1927 최소 힙
#include <bits/stdc++.h>
using namespace std;

vector<int> heap(1, 0);
int heap_a[100001];
int heapsize=0;
void swap_heap(int A, int B){
    int tmp = heap_a[A];
    heap_a[A] = heap_a[B];
    heap_a[B] = tmp;
}

void insert(int x){
    //heap.push_back(x);
    heap_a[++heapsize] = x;
    //int cur = heap.size()-1;
    int cur = heapsize;
    while(cur != 1){
        if(heap_a[cur] < heap_a[cur / 2]){
            swap(heap_a[cur], heap_a[cur / 2]);
            cur /=2;
            continue;
        }
        break;
    }
}
int pop(){
    //if(heap.size() == 1)
    if(heapsize == 0)
        return 0;

    int result = heap_a[1];
    //heap[1] = heap.back();
    //heap.pop_back();
    heap_a[1] = heap_a[heapsize--];
    int cur = 1;

    int target;
    while(cur <= heapsize){
        if(cur * 2 <= heapsize){
            target = cur*2;
            if(cur *2 +1 <= heapsize){
                target = heap_a[cur*2] <= heap_a[cur*2+1] ? target : cur*2+1;
            }

            if(heap_a[cur] > heap_a[target] ){
                swap_heap(cur, target);
                cur = target;
                continue;
            }
        }
        break;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) 
            cout << pop() << '\n';
        else 
            insert(x);
    }
}