#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(){
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter element:\n");
    scanf("%d",&(temp->data));

    temp->next=NULL;
    return temp;
}

void add_front(struct node **head){
    if(*head==NULL){
        *head=create();
    }
    else{
        struct node* temp=create();
        temp->next=*head;
        *head=temp;
    }
}

void add_end(struct node **head){
    if(*head==NULL){
        *head=create();
    }
    else{
        struct node* temp=*head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=create();
    }
}

void display(struct node **head){
    if(*head==NULL){
        printf("List empty\n");
    }else{
    struct node* i=*head;
    while (i->next!=NULL)
    {
        printf("%d ",i->data);
        i=i->next;
    }
    printf("%d  ",i->data);
    printf("\n");
    }
}

void delete_front(struct node **head){
    if(*head==NULL){
        printf("List empty!\n");
    }
    else{
        struct node* temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void main(){
    struct node* head = NULL;
    int choice;
    printf("1:Stack\n2:Queue\n3:Exit\n");
    while (1)
    {
        printf("Enter choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        while(1){
            printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
            
                printf("Enter choice\n");
                int s;
                scanf("%d",&s);
                switch(s){
                    case 1:add_front(&head);
                    break;

                    case 2:delete_front(&head);
                    break;

                    case 3: display(&head);
                    break;

                    case 4: exit(0);

                    default: printf("Invalid inputs\n");
                }
            }

        case 2: while(1){
                printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
                
                printf("Enter choice\n");
                int s;
                scanf("%d",&s);
                switch(s){
                    case 1:add_end(&head);
                    break;

                    case 2:delete_front(&head);
                    break;

                    case 3: display(&head);
                    break;

                    case 4:exit(0);

                    default: printf("Invalid inputs\n");
                }
            }
        case 3: exit(0);
        default:printf("Invalid choice\n");
            break;
        }
    }


}