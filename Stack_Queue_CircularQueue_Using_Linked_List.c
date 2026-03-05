#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void pop(){
    struct node *temp;
    if(top==NULL)
        printf("Stack Underflow\n");
    else{
        temp=top;
        printf("Deleted: %d\n",temp->data);
        top=top->next;
        free(temp);
    }
}

void displayStack(){
    struct node *temp=top;
    if(temp==NULL)
        printf("Stack Empty\n");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

struct node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;

    if(front==NULL)
        front=rear=newnode;
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct node *temp;
    if(front==NULL)
        printf("Queue Underflow\n");
    else{
        temp=front;
        printf("Deleted: %d\n",temp->data);
        front=front->next;
        free(temp);
    }
}

void displayQueue(){
    struct node *temp=front;
    if(temp==NULL)
        printf("Queue Empty\n");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

struct node *cfront=NULL,*crear=NULL;

void cenqueue(int x){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;

    if(cfront==NULL){
        cfront=crear=newnode;
        crear->next=cfront;
    }
    else{
        crear->next=newnode;
        crear=newnode;
        crear->next=cfront;
    }
}

void cdequeue(){
    struct node *temp;
    if(cfront==NULL)
        printf("Circular Queue Empty\n");

    else if(cfront==crear){
        temp=cfront;
        printf("Deleted: %d\n",temp->data);
        cfront=crear=NULL;
        free(temp);
    }
    else{
        temp=cfront;
        printf("Deleted: %d\n",temp->data);
        cfront=cfront->next;
        crear->next=cfront;
        free(temp);
    }
}

void displayCQueue(){
    struct node *temp=cfront;
    if(temp==NULL)
        printf("Circular Queue Empty\n");
    else{
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=cfront);
        printf("\n");
    }
}

int main(){
    int choice,val;

    while(1){
        printf("\n1.Push (Stack)");
        printf("\n2.Pop (Stack)");
        printf("\n3.Display Stack");

        printf("\n4.Enqueue (Queue)");
        printf("\n5.Dequeue (Queue)");
        printf("\n6.Display Queue");

        printf("\n7.Enqueue (Circular Queue)");
        printf("\n8.Dequeue (Circular Queue)");
        printf("\n9.Display Circular Queue");

        printf("\n10.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d",&val);
                enqueue(val);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                printf("Enter value: ");
                scanf("%d",&val);
                cenqueue(val);
                break;

            case 8:
                cdequeue();
                break;

            case 9:
                displayCQueue();
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}