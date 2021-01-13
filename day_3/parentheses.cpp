//2504  괄호의 합  -> 스택에 숫자 넣지 말고 괄호만 push, 결과값은 밖에서 따로 검사
// 1. 왼쪽 괄호는 스택에 넣는다.
// 2. 오른쪽 괄호 나왔을 경우 pop, 바로 직전 인덱스가 왼쪽 괄호인 경우 결과값에 tmp+, 이후 tmp /3
// 3. 괄호 짝 안맞는 경우 탈출,  마지막에도 스택이 다 비었는지 확인
//https://jaimemin.tistory.com/820
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int num;
    char c;
} data1;

stack<char> s;

int main() {
    string input;
    cin >> input;

    int tmp = 1;        // tmp 를 통해 숫자는 따로 계산
    long long result = 0;
    bool TF = false;

    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {          
            tmp *= 2;       
            s.push('(');
        } else if (input[i] == '[') {
            tmp *= 3;
            s.push('[');
        } else if (input[i] == ')' && (s.empty() || s.top() != '(')) {
            TF = true;
            break;
        } else if (input[i] == ']' && (s.empty() || s.top() != '[')) {
            TF = true;
            break;
        } else if (input[i] == ')') {
            if (input[i - 1] == '(')
                result += tmp;
            s.pop();
            tmp /= 2;
        } else if (input[i] == ']') {
            if (input[i - 1] == '[')
                result += tmp;
            s.pop();
            tmp /= 3;
        }
    }
    if (TF || !s.empty()) {
        cout << 0;
    } else {
        cout << result;
    }
}