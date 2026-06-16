#include <stdio.h>

// 定义一个栈，10000 的大小对于一般的表达式足够了
int stack[10000];
int top = -1; // 栈顶指针，-1 表示栈为空

// 压栈操作 
void push(int val) {l
    stack[++top] = val;
}

// 出栈操作
int pop() {
    return stack[top--];
}

int main() {
    char c;
    int current_num = 0;   // 用于拼接多位数
    int is_building = 0;   // 标记当前是否正在读取数字

    // 逐个字符读取，直到遇到 @ 或者文件结束
    while ((c = getchar()) != EOF && c != '@') {
        
        if (c >= '0' && c <= '9') {
            // 遇到数字字符，将其拼接到当前数字中
            current_num = current_num * 10 + (c - '0');
            is_building = 1;
        } 
        else if (c == '.') {
            // 遇到小数点，说明一个数字读取完毕，将其压入栈中
            if (is_building) {
                push(current_num);
                current_num = 0; // 清零，为读取下一个数字做准备
                is_building = 0;
            }
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 遇到运算符，弹出两个数字进行计算
            int op2 = pop(); // 先弹出的是右操作数
            int op1 = pop(); // 后弹出的是左操作数
            int result = 0;
            
            if (c == '+') result = op1 + op2;
            else if (c == '-') result = op1 - op2;
            else if (c == '*') result = op1 * op2;
            else if (c == '/') result = op1 / op2; // 题目一般默认整除
            
            // 将计算结果压回栈中
            push(result);
        }
    }

    // 表达式读取结束，栈顶元素就是最终结果
    printf("%d\n", stack[top]);

    return 0;
}