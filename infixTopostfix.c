#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;
}


char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}


char peek() {
    if (top == -1) return -1;
    return stack[top];
}


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i, k = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        }
     
        else if (c == '(') {
            push(c);
        }
        
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }

        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}