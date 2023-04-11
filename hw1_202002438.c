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
    Stack stack; // 스택 지정
    initStack(&stack, MAX_LEN); // 스택 초기화
    int len, idx = 0; // len : 문자열의 길이, idx : revExpression의 index
    double p1, p2, s; // 각 top을 넣어줄 실수. s는 계산 후 합.
    char revExpression[MAX_LEN] = ""; // 거꾸로 만들어줄 문자열 배열
    len = strlen(expression); // 길이.

    for (int i = len - 1; i >= 0; i--) { // 반대로 문자열을 넣어준다. 
        revExpression[idx++] = expression[i];
    }
    for (int i = 0; i < len; i++) { // 연산자와 피연산자를 구분하여 계산한다. 
        double num = 0; // 피연산자를 구할 실수
        int temp; // 소수
        int power = 1, t_power, sw = 0; // sw : 소수 판별기, power : 자릿수 맞추기, t_power : 소수점 밑 자리수 맞추기
        int j = i; // j는 i로 맞춰준다. 

        if (isdigit(revExpression[j])) { // 문자열이 수인 경우.
            while (isdigit(revExpression[j])) { // 수의 문자열만큼 반복한다. 
                num += (revExpression[j++] - '0') * power; // 아스키 코드를 이용해 수를 만들고 power를 이용해 자릿수를 맞춘다.
                power *= 10; // 자릿수는 10씩 곱해주며 맞춰준다. 1 -> 10 -> 100...
            }
            i = j; // 소숫점 윗부분을 위해 j를 i로 다시금 맞춘다. 
            if (revExpression[j] == '.') { // 소숫점이 나올 경우
                temp = num; // 일전에 넣었던 수는 임시 temp에 넣는다. 
                t_power = power; // 일전에 넣었던 자릿수는 임시 t_power에 넣는다. 
                num = 0; // 수 초기화
                power = 1; // 자릿수 초기화
                sw = 1; // 소숫점 판별기를 킨다. (= 실수라는 의미)

                while (isdigit(revExpression[j + 1])) { // 실수에서 1 윗부분을 구해준다. 
                    num += (revExpression[++j] - '0') * power; // num으로 값을 구한 뒤, power로 자릿수를 맞춘다. 
                    power *= 10; // 1 -> 10 -> 100....
                }
                i = j; // i를 j로 맞춰준다. 
            }

            if (sw == 1) num += 1.0 * temp / t_power; // 실수인 경우(sw==1), 두번째로 구한 수 + 일전에 밑 부분을 구한다.
            push(&stack, num); // 스택에 담는다. 
        }

        else {
            if (getPriority(revExpression[j]) == 0) continue;
            else {
                p1 = peek(&stack); // top을 뽑는다. 
                pop(&stack); // pop으로 삭제
                p2 = peek(&stack); // top을 뽑느다. 
                pop(&stack); // 삭제
                if (getPriority(revExpression[j]) == 2) { // 각 연산자에 맞춰 계산한다. 
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
    return s; // 반환한다.
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
