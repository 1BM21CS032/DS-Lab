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

    int k=0, i, choice;

    Node *head = NULL;
    Node *temp = (Node *)malloc(sizeof(Node));

    while (1){
        printf ("\n1:Push\n2:Display\n3:Quit\n");
        scanf ("%d", &choice);

    switch (choice){

        /*case 1:
        for (int i=0; i<10; i++){

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
        break;*/

        case 1:printf ("Enter element to add:\n");
        scanf ("%d",&i);
        head = push_stack (head, i);

        break;

        case 2:display (head);
        break;

        case 3:exit(0);
        break;

        default:printf ("Invalid input!\n");
        break;
    }


    }

    return 0;
}
