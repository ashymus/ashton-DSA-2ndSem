 
//For the Stack using an Array.
#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(){
    int value;
    if (top==MAX-1){
        printf("Stack overflow! Cannot insert element.");
    }else{
        printf("Enter value to push:\n");
        scanf("%d", &value);
        top++;
        stack[top]=value;
        printf("%d pushed successfully.\n", value);
    }
}
void pop(){
    if(top == -1){
         printf("Underflow! Stack is empty. Insert elements first.\n");
    }else{
        printf("%d poped successfully.\n", stack[top]);
        top--;
    }
}
void peek(){
    if(top==-1){
        printf("Stack is empty. No top element.\n");
    }else{
        printf("Top element is: %d", stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty.\n");
}else{
    printf("Elements are:\n");
    for( int i=top; i>=0; i--){
        printf("%d\n", stack[i]);
        }
    }
}
int main() {
    int choice;
    do{
    printf("\n__Stack Menu__\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Peek\n");
    printf("4.Display\n");
    printf("5.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    
    switch(choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: peek();
                    break;
            case 4: display();
                    break;
            case 5: printf("Exiting the program");
                    break;
            default:
                    printf("Invalid choice! Please try again\n");
        }
    }while(choice!=5);
    return 0;

// Queue using an Array
#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front>rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued: %d\n", queue[front++]);
    }
}

void displayQueue() {
    if (front == -1 || front>rear ) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for(int i = front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1); enqueue(6); enqueue(17); enqueue(8);
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}
//Circular Queue using an Array.
#include <stdio.h>
#define MAX 5
int cqueue[MAX], cfront = -1, crear = -1;

void cenqueue(int x) {
    if ((cfront == 0 && crear == MAX - 1) || ((crear + 1) % MAX == cfront)) {
        printf("Circular Queue Overflow\n");
    } else {
        if (cfront == -1) cfront = 0; // first element
        crear = (crear + 1) % MAX;
        cqueue[crear] = x;
    }
}

void cdequeue() {
    if (cfront == -1) {
        printf("Circular Queue Underflow\n");
    } else {
        printf("Dequeued: %d\n", cqueue[cfront]);
        if (cfront == crear) {
            cfront = crear = -1; // queue becomes empty
        } else {
            cfront = (cfront + 1) % MAX;
        }
    }
}

void displayCQueue() {
    if (cfront == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue: ");
        int i = cfront;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == crear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    cenqueue(5); cenqueue(6); cenqueue(7); cenqueue(8);
    displayCQueue();
    cdequeue();
    displayCQueue();
    return 0;
}
