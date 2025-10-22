#include<iostream>
#include"Stack.h"
using namespace std;
int isp(char op);
int osp(char op);
bool cal(char op,double x,double y,double &r);
void GetNextChat(char &ch);
bool isdigit(char ch);
bool isoperator(char ch);
bool Get2Operands(LStack<double> &OPEN,double &x,double &y);

int main() {
    LStack<double> OPEN;
    LStack<char> OPTR;

    
}
