#include<iostream>
#include<cmath>
#include"Stack.h"
using namespace std;
int isp(char op);
int osp(char op);
bool cal(char op,double x,double y,double &r);
void GetNextChar(char &ch);
bool isdigit(char ch);
bool isoperator(char ch);
bool Get2Operands(LStack<double> &OPEN,double &x,double &y);


int main() {
    LStack<double> OPND;  // 操作数栈
    LStack<char> OPTR;    // 运算符栈

    OPTR.push('=');       // 初始栈底符号

    char ch;
    GetNextChar(ch);

    while (ch != '=') {
    //（1）处理单目负号（负数情况），压入opnd栈
       if(ch=='-'){
           
       }
    //（2）处理小数和整数，压入 OPND
         if(isdigit(ch)||ch=='.'){
              
         }
    //（3）处理运算符，压入 OPTR 或计算
        else if(isoperator(ch)){
            
        }
    }
    //（4）处理 '=' 后，把栈中剩余运算符全部计算
    while (OPTR.topValue() != '=') {
        double x, y, r;
        //操作数不足错误处理
        if (!Get2Operands(OPND, x, y)) {
            cout << "ERROR:操作数不足" << endl;
            return 0;
        }
        char op = OPTR.pop();
        if (!cal(op, y, x, r)) {
            return 0;
        }
        OPND.push(r);
    }
    cout << "Result = " << OPND.topValue() << endl;
    return 0;
    
}
//蔡志远编写的isp和osp函数
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
} //给出各个运算符的栈内优先级
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
} //给出各个运算符的栈外优先级

// 盛佳一编写Get2Operands函数
bool Get2Operands(LStack<double> &OPEN,double &x,double &y){
    if (OPEN.length() < 2)
        return false; //若Stack的长度小于2，返回flase
    else{
        x = OPEN.pop();
        y = OPEN.pop();
        return true;
    }
}

// LiuYisen编写的cal函数
bool cal(char op, double x, double y, double& r) {
    switch (op) {
        case '+': // 加法
            r = x + y; 
            return true;
        case '-': // 减法
            r = x - y; 
            return true;
        case '*': // 乘法
            r = x * y; 
            return true;
		case '/': // 除法
            if (y == 0) {
				cerr << "ERROR被除数不能为0" << endl;
				return false; // 除0错误
            }
            r = x / y; 
            return true;
        case '%': // 取模
            // 对于 double 使用 fmod
            r = fmod(x, y);
            return true;
        case '^': // 乘方
			r = pow(x, y);
			return true;
        case '&': // 开方
            if (y == 0) {
                cerr << "ERROR:y不能为0" << endl;
				return false; // 开0次方无意义
            }
			r = pow(x, 1.0 / y);
            return true;
        default:
            cerr << "ERROR:这是一个未知操作符" << op << endl;
            return false;
	}
}
//张羿驰编写的isdigit和isoperator函数
bool isdigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isoperator(char ch) {
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
           ch=='%' || ch=='^' || ch=='&' ||
           ch=='(' || ch==')' || ch=='=';
}
//赵晨志编写的GetNextChar函数
void GetNextChar(char& ch) {
    do {
        std::cin.get(ch); // 从输入流读取一个字符到 ch
    } while (std::isspace(static_cast<unsigned char>(ch)));// 跳过空格、回车、制表符等
    if (std::cin.eof()) {
        ch = '\0'; //若到达输入末尾（EOF），将 ch 设为\0，方便外部判断
    }
}
