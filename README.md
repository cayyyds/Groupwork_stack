# Expression Evaluation (Calculator) — Groupwork_stack

轻量级命令行表达式求值器（基于栈的中缀表达式解析），支持加减乘除、取模、乘方、开方与括号。无需复杂 UI，直接在命令行输入表达式并以 `=` 结尾进行计算。

## 功能
- 支持运算符：`+  -  *  /  %  ^  &`  
  - `%` 为取模（对 double 使用 `fmod`）  
  - `^` 为幂运算（pow）  
  - `&` 表示开方（y 为开方指数，计算 x^(1/y)）
- 支持小数与整数
- 支持括号 `(` `)`
- 支持一元负号（例如 `-2+3=`）
- 输入以 `=` 结尾表示表达式结束（程序以 `=` 为终结符）
- 输出保留两位小数，错误信息为英文

## 文件说明
- `main.cpp` — 主程序，包含表达式解析与求值逻辑（使用栈方式实现）
- `Stack.h` — 链式栈模板（LStack），用于操作数和运算符栈
- 其它实现/工具函数都在 `main.cpp` 文件内（请根据需要拆分）

## 快速编译（Windows / MinGW / PowerShell）
在项目根目录运行：
```powershell
g++ -g c:\Users\chris\Documents\GitHub\Groupwork_stack\main.cpp -o c:\Users\chris\Documents\GitHub\Groupwork_stack\main.exe
```
如果 `g++` 未加入 PATH，请改成你的编译器完整路径（例如 MinGW-w64 安装路径）。

## 运行与示例
在 PowerShell（建议设置 UTF-8）：
```powershell
chcp 65001
.\main.exe
```
示例交互：
```
Please enter an expression
> (-2)*3^5=
Result = -486.00
```
另例：
```
> 2+3*4=
Result = 14.00
```

注意：表达式必须以 `=` 结尾。

## 常见问题
- "undefined reference" 链接错误：若你把模板实现移到 `.cpp`，请确保同时编译对应 `.cpp` 并/或对需要的类型做显式实例化（推荐把模板实现放在 `Stack.h`）。
- 控制台乱码：程序现在输出为英文。若你将来使用中文输出，请在 Windows 控制台执行 `chcp 65001` 并确保源文件以 UTF‑8 保存。

## 开发与调试建议
- 在 VS Code 中使用 C/C++ 扩展并确保 launch/tasks 中的路径与本机编译器路径一致（不要使用不存在的 msys64 路径）。
- 单元测试：可将表达式解析/求值逻辑抽成函数并添加单元测试（GoogleTest / Catch2）。

## 扩展建议
- 添加支持函数（如 `sqrt()`, `sin`, `cos`）
- 支持变量与赋值
- 改进错误消息定位（给出位置/子串）

## 许可
按团队约定使用（无特别 LICENSE 指定时视为私有/内部学习用）。
