#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *push_stack (Node **head_ref, int x){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = x;
    new->next = *head_ref;
    return new;
}

void display (Node **headref){
    Node *temp = *headref;
    while (temp!=NULL){
        printf ("%d\t",temp->data);
        temp = temp->next;
    }
}

Node *reverse (Node *temp){
    Node *prev=NULL, *next=NULL;

    while (temp != NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}

void sort (Node *head){

    for(Node *ptr=head; ptr->next!=NULL; ptr=ptr->next){
        for(Node *temp=ptr->next; temp!=NULL; temp=temp->next){

            if (ptr->data > temp->data){
                int swap = ptr->data;
                ptr->data = temp->data;
                temp->data = swap;
            }
        }
    }
}

void concat (Node **node1, Node *node2){
    Node *temp = *node1;
    
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node2;
}

int main (){

    int k=0, i, choice, pos;

    Node *head = NULL, *head2 = NULL;
    Node *temp = (Node *)malloc(sizeof(Node));

    while (1){
        printf ("\n1:Insert begining\n2:Display\n3:Exit\n4:Reverse\n5:Concatenate\n6:Sort\n");
        scanf ("%d", &choice);

    switch (choice){

        case 1:printf ("Enter element to add:\n");
        scanf ("%d",&i);
        head = push_stack (&head, i);
        break;

        case 2:display (&head);
        break;

        case 3:exit(0);
        break;

        case 4:head = reverse(head);
        break;

        case 5:
        while (k==0){
            printf ("\n1:Insert element of second list:\n2:Exit\n");
            scanf ("%d", &choice);
            switch (choice){
                case 1:printf ("Enter element to add:\n");
                scanf ("%d",&i);
                head2 = push_stack(&head2, i);
                break;

                case 2:k=1;
                break;

            default:printf ("Invalid input!\n");
            break;
            }
        }
        concat (&head, head2);
        display (&head);
        break;

        case 6:sort (head);
        display (&head);
        break;

        default:printf ("Invalid input!\n");
        break;
    }
    }
    return 0;
}
