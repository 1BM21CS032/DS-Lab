#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *push_queue (int x){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *push_stack (Node *head_ref, int x){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = x;
    new->next = head_ref;
    return new;
}

void display (Node *headref){
    Node *temp = headref;
    while (temp!=NULL){
        printf ("%d\t",temp->data);
        temp = temp->next;
    }
}

int main (){

    int k=0, choice;

    Node *head = NULL;
    Node *temp = (Node *)malloc(sizeof(Node));

    printf ("1:Queue\t2:Stack:");
    scanf ("%d", &choice);

    switch (choice)
    {
    case 1:for (int i=0; i<10; i++){

        if (k==0){
            temp = push_queue(i);
            head = temp;
        }
        else{
            temp->next = push_queue(i);
            temp = temp->next;
        }
        k++;
    }
    break;
    
    case 2:for (int i=0; i<10; i++){
        head = push_stack (head, i);
    }
    break;

    default:printf ("Invalid input!\n");
        break;
    }
    
    display (head);

    return 0;
}