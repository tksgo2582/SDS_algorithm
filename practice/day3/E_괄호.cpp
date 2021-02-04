#include <iostream>
#include <stack>

using namespace std;

string str;
stack<char> s;

int main() {
    cin >> str;
    int middle = 0, large = 0;
    long long ans = 0;
    int tmp = 1;
    bool tf = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            tmp *= 2;
            s.push('(');
        } else if (str[i] == '[') {
            tmp *= 3;
            s.push('[');
        } else if (str[i] == ')' && (s.empty() || s.top() != '(')) {
            tf = true;
            break;
        } else if (str[i] == ']' && (s.empty() || s.top() != '[')) {
            tf = true;
            break;
        } else if (str[i] == ')') {
            if (str[i - 1] == '(')
                ans += tmp;
            s.pop();
            tmp /= 2;
        } else if (str[i] == ']') {
            if (str[i - 1] == '[')
                ans += tmp;
            s.pop();
            tmp /= 3;
        }
    }
    if (tf || !s.empty())
        cout << 0;
    else
        cout << ans;
}