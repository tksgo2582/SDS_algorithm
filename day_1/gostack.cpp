//3425
#include <bits/stdc++.h>

using namespace std;
#define MAX 1000000000  // 최대 값 , long long 타입 사용!

vector<pair<string, long long>> v;
stack<long long> s;

int NUM(long long num) {
    s.push(num);
    return 0;
}
int POP() {
    if (!s.empty()) {
        s.pop();
        return 0;
    } else
        return 1;
}
int INV() {
    if (!s.empty()) {
        long long num = s.top();
        s.pop();
        if(num > MAX)
            return 1;
        s.push(-num);
        return 0;
    } else
        return 1;
}
int DUP() {
    if (!s.empty()) {
        s.push(s.top());
        return 0;
    } else
        return 1;
}
int SWP() {
    if (s.size() >= 2) {
        long long num1 = s.top();
        s.pop();
        long long num2 = s.top();
        s.pop();

        s.push(num1);
        s.push(num2);
        return 0;
    } else
        return 1;
}
int ADD() {
    if (s.size() >= 2) {
        long long num1 = s.top();
        s.pop();
        long long num2 = s.top();
        s.pop();

        if (num1 + num2 > MAX)
            return 1;
        s.push(num1 + num2);
        return 0;
    } else
        return 1;
}
int SUB() {
    if (s.size() >= 2) {
        long long num1 = s.top();
        s.pop();
        long long num2 = s.top();
        s.pop();

        if (num2 - num1 > MAX)
            return 1;
        s.push(num2 - num1);
        return 0;
    } else
        return 1;
}
int MUL() {
    if (s.size() >= 2) {
        long long num1 = s.top();
        s.pop();
        long long num2 = s.top();
        s.pop();

        if (num1 * num2 > MAX)
            return 1;
        s.push(num1 * num2);
        return 0;
    } else
        return 1;
}
int DIV() {
    int neg = 0 ;
    if (s.size() >= 2) {
        long long num1 = s.top();
        s.pop();
        if(num1 <0)
            neg++;
        long long num2 = s.top();
        s.pop();
        if(num2 <0)
            neg++;

        if (num1 == 0 || num2 / num1 > MAX) // 0으로 나눈 경우 
            return 1;
        if(neg == 1){
            s.push(-abs(num2 / num1));
        }else{
            s.push(abs(num2 / num1));
        }
        return 0;
    } else
        return 1;
}
int MOD() {
    int neg =0;
    if (s.size() >= 2) {
        long long num1 = s.top();
        s.pop();
        if(num1 <0)
            neg++;
        long long num2 = s.top();
        s.pop();
        if(num2 <0)
            neg++;

        if (num1 == 0 || num2 % num1 > MAX)
            return 1;
        if(neg == 1){
            s.push(-abs(num2 % num1));
        }else{
            s.push(abs(num2 % num1));
        }
        return 0;
    } else
        return 1;
}
int main() {
    string word;
    long long num;
    int N;
    int errChk = 0;
    
    while (1) {
        errChk = 0;
        while (1) {
            cin >> word;        //명령어 받기
            num = 0;
            if (word == "NUM")  //NUM 연산시 숫자 받기
                cin >> num;
            if (word == "END")  //END, QUIT 동작
                break;
            if (word == "QUIT") 
                return 0;
            v.push_back({word, num});  // 명령어 저장
        }
        cin >> N; // 수행횟수 
        while (N--) {
            cin >> num;
            s.push(num);
            if(num > MAX)
                errChk = 1;
            for (int i = 0; i < v.size(); ++i) {    // 각 숫자에 대한 연산 진행
                if (v[i].first == "NUM") {
                    errChk = NUM(v[i].second);
                } else if (v[i].first == "POP") {
                    errChk = POP();
                } else if (v[i].first == "INV") {
                    errChk = INV();
                } else if (v[i].first == "DUP") {
                    errChk = DUP();
                } else if (v[i].first == "SWP") {
                    errChk = SWP();
                } else if (v[i].first == "ADD") {
                    errChk = ADD();
                } else if (v[i].first == "SUB") {
                    errChk = SUB();
                } else if (v[i].first == "MUL") {
                    errChk = MUL();
                } else if (v[i].first == "DIV") {
                    errChk = DIV();
                } else if (v[i].first == "MOD") {
                    errChk = MOD();
                }
                if (!s.empty() && (s.top() > MAX || s.top() < -MAX)) {
                    errChk = 1; //마지막 스택이 없거나, 범위 밖
                }
                if (errChk == 1) { 
                    break;
                }
            }

            if (errChk == 1 || s.size() != 1) {
                cout << "ERROR\n";
            }else {
                cout << s.top() << "\n";
            }
            while (!s.empty()) { // 스택 초기화
                s.pop();
            }
        }
        v.clear();              // 명령어 초기화
        cout << "\n";
    }
    return 0;
}
