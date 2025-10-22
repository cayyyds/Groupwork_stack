#include<iostream>
#include"Stack.h"
using namespace std;
int isp(char op);
int osp(char op);
bool cal(char op,double x,double y,double &r);
void GetNextChat(char &ch);
bool isdigit(char ch);
bool isoperator(char ch);

//盛佳一编写Get2Operands函数
bool Get2Operands(LStack<double> &OPEN,double &x,double &y){
    if (OPEN.length() < 2)
        return false; //若Stack的长度小于2，返回flase
    else{
        x = OPEN.pop();
        y = OPEN.pop();
        return true;
    }
}

int main() {
    LStack<double> OPEN;
    LStack<char> OPTR;

    char ch;
   

    
}
int isp(char op){
    switch(op){
        case '=':return 0;
        case '+':return 3;
        case '-':return 3;
        case '*':return 5;
        case '/':return 5;
        case '%':return 5;
        case '(':return 1;
        case ')':return 8;
        case '^':return 7;
        case '&':return 7;
    }
}//给出各个运算符的栈内优先级
int osp(char op){
    switch(op){
        case '=':return 0;
        case '+':return 2;
        case '-':return 2;
        case '*':return 4;
        case '/':return 4;
        case '%':return 4;
        case '(':return 8;
        case ')':return 1;
        case '^':return 6;
        case '&':return 6;
    }
}//给出各个运算符的栈外优先级

bool isdigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isoperator(char ch) {
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
           ch=='%' || ch=='^' || ch=='&' ||
           ch=='(' || ch==')' || ch=='=';
}

