#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
      int value;
      struct Node *next;
      struct Node *prev;
};

typedef struct Node *Node;

Node getNode(){

      Node temp;
      temp=(Node)malloc(sizeof(struct Node));

      if(temp==NULL){
            printf("Memory not allocated\n");
      }
      return temp;
}

Node insert_beg(Node first,int item){
      Node new;
      new=getNode();
      new->value=item;
      new->prev=NULL;
      new->next=NULL;
      if(first==NULL){
            return new;
      }
      new->next=first;
      first->prev=new;
      return new;
}

Node insert_left(Node first,int key,int item){

    Node temp,new;

    new=getNode();
    new->value=item;
    new->prev=NULL;
    new->next=NULL;

    if(first==NULL){
        printf("List is empty");
        return NULL;
    }
    if (first->value==key){
        first=insert_beg(first, item);
        return first;
    }
    
    if(first->next==NULL && first->value!=key){
        printf("Elements does not exist!\n");
        return first;
    }

    if(first->next==NULL && first->value==key){
        first=insert_beg(first,new->value);
    }
    temp=first;

    while(temp->value!=key && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->value==key){
        new->next=temp;
        new->prev=temp->prev;
        (temp->prev)->next=new;
        temp->prev=new;
        return first;
    }
    if(temp->value!=key){
         printf("value not found\n");
        return first;
    }
}


Node delete_specific(Node first,int key){
      Node curr,temp;
      curr=first;
      if(first==NULL){
            printf("list empty!\n");
            return NULL;
      }
      if(first->next==NULL && first->value==key){
            free(first);
            return NULL;
      }
      if(first->value==key){
            (first->next)->prev=NULL;
            temp=first->next;
            free(first);
            return temp;
      }
      while(curr!=NULL){
            if(curr->value==key)
            break;
            curr=curr->next;
      }
      if(curr==NULL){
            printf("Element not found\n");
      }
      (curr->prev)->next=curr->next;

      if(curr->next!=NULL){
            (curr->next)->prev=curr->prev;
      }
      return first;
}

void display(Node first){
      Node temp;

      if(first==NULL){
            printf("List is empty\n");
      }
      temp=first;
      while(temp!=NULL){
            printf("%d  ",temp->value);
            temp=temp->next;
      }
}

void main(){
    Node first=NULL;
    int choice,key,item;
    while(1){

    printf("\n1.Insert\n2.Insert left\n3.Delete\n4.Display\n5.Exit\n");
    scanf("%d",&choice);

    switch(choice){
    case 1:printf("\nEnter the value to be inserted at the begining\n");
            scanf("%d",&item);
            first=insert_beg(first,item);
            break;

    case 2:printf("\nEnter the value to be inserted at the left\n");
            scanf("%d",&item);
            printf("\nEnter element before\n");
            scanf("%d",&key);
            first=insert_left(first,key,item);
            break;

    case 3:printf("\nEnter the value to be deleted\n");
        scanf("%d",&key);
        first=delete_specific(first,key);
        break;

    case 4:display(first);
        break;

    case 5:exit(0);
    break;

    default:exit(0);
      }
      }
}
