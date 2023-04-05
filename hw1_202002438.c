#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

// 추가로 헤더파일이 필요한 경우 자유롭게 추가해도 됩니다.

#define MAX_LEN	100

// 스택 구조체
typedef struct {
    double* arr;
    int top;
} Stack;

// 스택 초기화 함수
void initStack(Stack* stack, int size) {
    stack->arr = (double*)malloc(size * sizeof(double));
    stack->top = -1;
}

// 스택 삽입 함수
void push(Stack* stack, double value) {
    // YOUR CODE
    stack->arr[++(stack->top)] = value;
}

// 스택 삭제 함수
double pop(Stack* stack) {
    // YOUR CODE
    if (isEmpty(stack)) exit(1);
    return stack->arr[--(stack->top)];
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
    // YOUR CODE
    return stack->top == -1;

}

// 스택에서 값을 읽어오는 함수
double peek(Stack* stack) {
    // YOUR CODE
    return stack->arr[stack->top];
}

// 연산자 우선순위를 반환하는 함수
int getPriority(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// prefix notation 문자열을 계산하는 함수
double prefix_calculate(char* expression) {
    // YOUR CODE
    Stack stack;
    initStack(&stack, MAX_LEN);
    int len, idx = 0;
    double p1, p2, s;
    char revExpression[MAX_LEN] = "";
    len = strlen(expression);

    for (int i = len - 1; i >= 0; i--) {
        revExpression[idx++] = expression[i];
    }
    for (int i = 0; i < len; i++) {
        double num = 0; 
        int temp;
        int power = 1, t_power, sw = 0;
        int j = i;

        if (isdigit(revExpression[j])) {
            while (isdigit(revExpression[j])) {
                num += (revExpression[j++] - '0') * power;
                power *= 10;
            }
            i = j;
            if (revExpression[j] == '.') {
                temp = num;
                t_power = power;
                num = 0;
                power = 1;
                sw = 1;

                while (isdigit(revExpression[j + 1])) {
                    num += (revExpression[++j] - '0') * power;
                    power *= 10;
                }
                i = j;
            }

            if (sw == 1) num += 1.0 * temp / t_power;
            push(&stack, num);
        }

        else {
            if (getPriority(revExpression[j]) == 0) continue;
            else {
                p1 = peek(&stack);
                pop(&stack);
                p2 = peek(&stack);
                pop(&stack);
                if (getPriority(revExpression[j]) == 2) {
                    if (revExpression[j] == '*') push(&stack, p1 * p2);
                    else if (revExpression[j] == '/') push(&stack, p1 / p2);
                }
                else {
                    if (revExpression[j] == '+') push(&stack, p1 + p2);
                    else push(&stack, p1 - p2);
                }
            }
        }
    }
    s = peek(&stack);
    return s;
}

int main() {

    // 아래 main 함수는 수정하지 마세요. 
    char expression[MAX_LEN];
    // 개행문자를 제외한 모든 사용자 입력을 받는다는 의미입니다.
    scanf("%[^\n]", expression);

    double result = prefix_calculate(expression);
    printf("%.2lf\n", result);

    return 0;
}
