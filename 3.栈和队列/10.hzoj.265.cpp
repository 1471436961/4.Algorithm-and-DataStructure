/*************************************************************************
	> File Name: 10.hzoj.265.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Aug 2023 09:57:47 PM CST
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define MAX_N 10000
char str[MAX_N + 5];
int match[MAX_N + 5] = {0};
stack<int> s;

int main() {
    cin >> (str + 1); //编码技巧，偏移字符数组
    for (int i = 1; str[i]; i++) {
        switch (str[i]) {
            case '(':
            case '[':
            case '{': s.push(i);break; //编码技巧，栈存储匹配括号对应的下标
            case ')': {
                if (!s.empty() && str[s.top()] == '(') {
                    match[s.top()] = i;
                    match[i] = s.top(); // delete
                    s.pop();
                } else {
                    s.push(i); //信息阻隔，运行到此行说明前面的括号序列均非法
                } 
            } break;
            case ']': {
                 if (!s.empty() && str[s.top()] == '[') {
                    match[s.top()] = i;
                    match[i] = s.top();
                    s.pop();
                } else {
                    s.push(i);
                } 
            } break;
            case '}': {
                 if (!s.empty() && str[s.top()] == '{') {
                    match[s.top()] = i;
                    match[i] = s.top(); 
                    s.pop();
                } else {
                    s.push(i);
                } 
            } break;
        }
    }
    int temp_ans = 0, ans = 0, i = 1;
    while (str[i]) {
        if (match[i]) {
            temp_ans += (match[i] - i + 1);
            i = match[i] + 1;
        } else {
            i += 1;
            temp_ans = 0;
        }
        if (temp_ans > ans) ans = temp_ans;
    }
    cout << ans << endl;
    return 0;
}
