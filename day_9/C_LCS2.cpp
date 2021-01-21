//9252 LCS2

#include <bits/stdc++.h>

using namespace std;

string str1, str2;
int len1, len2;
int dp[1010][1010];
pair<int, int> tracking[1010][1010];

//p1, p2 까지의 것들 중에서 LCS(꼭 p1,p2를 포함할 필요는 없음)
int calc(int p1, int p2){
    if(p1 <0 || p2 <0)
        return 0;
    if(dp[p1][p2] != -1){
        return dp[p1][p2];
    }
    //문자가 같으면
    if(str1[p1] == str2[p2]){
        dp[p1][p2] = calc(p1 - 1, p2 - 1) + 1;
        tracking[p1][p2].first = p1 -1;
        tracking[p1][p2].second = p2 -1;

        return dp[p1][p2];
    }
    //다르면
    int tmp1, tmp2;
    tmp1 = calc(p1-1, p2);  //str1의 끝 문자를 빼고 고려
    tmp2 = calc(p1, p2-1);  //str2의 끝 문자를 빼고 고려
    if(tmp1 > tmp2){        // 더 긴쪽으로 이동
        dp[p1][p2] = tmp1;
        tracking[p1][p2].first = p1-1;
        tracking[p1][p2].second = p2;
    }else{
        dp[p1][p2] = tmp2;
        tracking[p1][p2].first = p1;
        tracking[p1][p2].second = p2-1;
    }
    //dp[p1][p2] = max(calc(p1-1, p2), calc(p1,p2-1));
    return dp[p1][p2];
}

int main(){
    memset(dp, 0xff, sizeof(dp));
    cin >> str1 >> str2;
    len1 = str1.size();
    len2 = str2.size();
    cout << calc(len1 - 1, len2 - 1) << "\n";
    // 문자열 출력은 어떻게??
    int p1 = len1 -1 , p2 = len2-1;
    vector<char> stk;

    while(0<=p1 && 0<=p2){
        if(str1[p1] == str2[p2])
            stk.push_back(str1[p1]);
        pair<int, int> next = tracking[p1][p2];     //바로 넣지 말고 next에 따로 뺴서처리.. 다음거 넣기전에 먼저 변경되는 경우가 생기기도 한다.
        p1 = next.first;
        p2 = next.second;
    }
    int len = stk.size();
    for(int i = 0 ; i < len; i++){
        cout << stk.back();
        stk.pop_back();
    }
}
