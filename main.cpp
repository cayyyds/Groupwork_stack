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

}

