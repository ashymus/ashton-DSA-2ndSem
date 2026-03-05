#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {

        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');  
        }
        else {

            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                default: 
                    printf("Invalid operator: %c\n", exp[i]);
                    return -1;
            }
        }
    }
    return pop(); 
}

int main() {
    char exp[MAX];
    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}