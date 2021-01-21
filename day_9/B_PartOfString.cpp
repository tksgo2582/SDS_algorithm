//dp 값을 초기화 한후, 있다면 가져다 쓰고 없으면 ...
#include <bits/stdc++.h>

using namespace std;

string str1, str2;
int len1, len2, ans;
int dp[4010][4010]; // 활용해서, 메모이제이션, 초기화(-1), 코드 바꾸기

//p1, p2 로 끝나는 문자열의 lcs
int calc(int p1, int p2){
    if(p1 < 0 || p2 < 0){
        return 0;
    }
    if(dp[p1][p2] != -1){       //위치 순서 중요
        return dp[p1][p2];
    }
    if(str1[p1] == str2[p2]){
        // +1
        dp[p1][p2] = calc(p1 -1, p2-1) + 1;
        return dp[p1][p2];
    }
    else{
        return 0;
    }
    
}

int main(){
    memset(dp, 0xff, sizeof(dp));       // dp -1로 초기화
    cin >>str1 >> str2;
    len1 = str1.size();
    len2 = str2.size();

    for(int i = 0; i<=len1-1 ; i++){
        for(int j = 0; j <= len2 -1 ; j++){
            int tmp = calc(i, j);
            if(ans < tmp)
                ans = tmp;
        }
    }

    cout << calc(len1 -1, len2 -1);
}