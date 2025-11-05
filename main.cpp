#include <iostream>
#include <cmath>
#include "Stack.h"
#include <sstream>
#include <iomanip>
using namespace std;
int isp(char op);
int osp(char op);
bool cal(char op, double x, double y, double &r);
void GetNextChar(char &ch);
bool isdigit(char ch);
bool isoperator(char ch);
bool Get2Operands(LStack<double> &OPEN, double &x, double &y);

int main()
{
    cout << "========================================================================================" << endl;
    cout << "                          Expression evaluation software" << endl;
    cout << "========================================================================================" << endl;
    cout << "Function Description:" << endl;
    cout << "1. Supported operations: , -, *, /, % (modulus), & (square root), ^ (exponentiation)" << endl;
    cout << "2. Supports parentheses (), and expressions end with '='" << endl;
    cout << "3. Example: (-2)*3^5   23/(45 67) - 17%3/8&2 =" << endl;
    cout << "========================================================================================" << endl
         << endl;
    cout << "Please enter an expression " << endl;
    LStack<double> OPND; // 操作数栈
    LStack<char> OPTR;   // 运算符栈

    OPTR.push('='); // 初始栈底符号

    char ch;
    char prevCh; // 前一个ch的值
    GetNextChar(ch);
    prevCh = ch; // 赋值前一个ch的值

    if (ch == '=')
    {
        cerr << "ERROR: empty expression! Please enter a valid expression before '='." << endl;
        return -1;
    }

    while (ch != '=' && ch != '\0')
    {
        // （1）盛佳一：处理单目负号（负数情况），压入opnd栈
        if (ch == '-')
        {
            if (OPND.length() == 0 || prevCh == '(') // 如果负号前没有数值，且前一个输入的字符为'('
                OPND.push(0);                        // 压入0，变成0-x的形式
        }
        prevCh = ch; // 赋值前一个ch的值
        // （2）处理小数和整数，压入 OPND
        if (isdigit(ch) || ch == '.')
        {
            string numStr;
            bool hasDot = false;

            // 处理如1.1.1的情况
            while (isdigit(ch) || ch == '.')
            {
                if (ch == '.')
                {
                    if (hasDot)
                    {
                        cerr << "ERROR: Illegal Decimal Point  '" << numStr + ch << "'" << endl;
                        return -1;
                    }
                    hasDot = true;
                }

                numStr += ch;
                GetNextChar(ch);
            }

            // 检查数字是否合法
            if (numStr == ".")
            {
                cerr << "ERROR: A Single Decimal Point Is Illegal" << endl;
                return -1;
            }

            stringstream ss(numStr);
            double num;
            if (ss >> num)
            {
                // 数字范围
                const double MAX_NUMBER = 2147483647;
                const double MIN_NUMBER = -2147483648;
                if (num > MAX_NUMBER || num < MIN_NUMBER)
                {
                    cerr << "ERROR: Number Is Out Of Range " << num << endl;
                    return -1;
                }

                OPND.push(num);
            }
            else
            {
                cerr << "ERROR: Invalid Number '" << numStr << "'" << endl;
                return -1;
            }
            continue;
        }

        // （3）处理运算符，压入 OPTR 或计算
        if (isoperator(ch))
        {
            if (isp(OPTR.topValue()) < osp(ch))
            {
                OPTR.push(ch);
                GetNextChar(ch);
            }
            else if (isp(OPTR.topValue()) > osp(ch))
            {
                double x, y, r;
                // 操作数不足错误处理
                if (!Get2Operands(OPND, x, y))
                {
                    cout << "ERROR:need more operand" << endl;
                    return 0;
                }
                char op = OPTR.pop();
                if (!cal(op, y, x, r))
                {
                    return 0;
                }
                OPND.push(r);
                continue; // 重新比较栈顶运算符和当前运算符
            }
            else
            { // 相等情况，弹出栈顶运算符
                OPTR.pop();
                GetNextChar(ch);
            }
        }
        else
        {
            cerr << "ERROR:unknown ch" << ch << "'" << endl;
            return -1;
        }
    }
    // （4）处理 '=' 后，把栈中剩余运算符全部计算
    while (OPTR.topValue() != '=')
    {
        double x, y, r;
        // 操作数不足错误处理
        if (!Get2Operands(OPND, x, y))
        {
            cout << "ERROR:need more operand" << endl;
            return 0;
        }
        char op = OPTR.pop();
        if (!cal(op, y, x, r))
        {
            return 0;
        }
        OPND.push(r);
    }
    // 结果保留两位小数
    cout << "Result = " << fixed << setprecision(2) << OPND.topValue() << endl;
    return 0;
}
// 蔡志远编写的isp和osp函数
int isp(char op)
{
    switch (op)
    {
    case '=':
        return 0;
    case '+':
        return 3;
    case '-':
        return 3;
    case '*':
        return 5;
    case '/':
        return 5;
    case '%':
        return 5;
    case '(':
        return 1;
    case ')':
        return 8;
    case '^':
        return 7;
    case '&':
        return 7;
    default:
        return 0;
    }
} // 给出各个运算符的栈内优先级
int osp(char op)
{
    switch (op)
    {
    case '=':
        return 0;
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 4;
    case '/':
        return 4;
    case '%':
        return 4;
    case '(':
        return 8;
    case ')':
        return 1;
    case '^':
        return 6;
    case '&':
        return 6;
    }
} // 给出各个运算符的栈外优先级

// 盛佳一编写Get2Operands函数
bool Get2Operands(LStack<double> &OPEN, double &x, double &y)
{
    if (OPEN.length() < 2)
        return false; // 若Stack的长度小于2，返回flase
    else
    {
        x = OPEN.pop();
        y = OPEN.pop();
        return true;
    }
}

// LiuYisen编写的cal函数
bool cal(char op, double x, double y, double &r)
{
    switch (op)
    {
    case '+': // Addition
        r = x + y;
        return true;
    case '-': // Subtraction
        r = x - y;
        return true;
    case '*': // Multiplication
        r = x * y;
        return true;
    case '/': // Division
        if (y == 0)
        {
            cerr << "ERROR: Divisor cannot be zero in division." << endl;
            return false; // Division by zero error
        }
        r = x / y;
        return true;
    case '%': // Modulus
        if (y == 0)
        {
            cerr << "ERROR: Divisor cannot be zero in modulus operation." << endl;
            return false; // Modulus by zero error
        }
        // Using fmod for double type
        r = fmod(x, y);
        return true;
    case '^': // Exponentiation
        r = pow(x, y);
        return true;
    case '&': // Root
        if (y == 0)
        {
            cerr << "ERROR: Root index cannot be zero." << endl;
            return false; // Zero root is meaningless
        }
        r = pow(x, 1.0 / y);
        return true;
    default:
        cerr << "ERROR: Unknown operator: " << op << endl;
        return false;
    }
}
// 张羿驰编写的isdigit和isoperator函数
bool isdigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isoperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
           ch == '%' || ch == '^' || ch == '&' ||
           ch == '(' || ch == ')' || ch == '=';
}
// 赵晨志编写的GetNextChar函数
void GetNextChar(char &ch)
{
    do
    {
        std::cin.get(ch); // 从输入流读取一个字符到 ch
    } while (std::isspace(static_cast<unsigned char>(ch))); // 跳过空格、回车、制表符等
    if (std::cin.eof())
    {
        ch = '\0'; // 若到达输入末尾（EOF），将 ch 设为\0，方便外部判断
    }
}
// ui
