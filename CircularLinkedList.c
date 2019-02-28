#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node * createNewNode();
void addToEmpty(struct node* ,int);
void addAtEnd(struct node * , int);
void addAtAny(struct node * ,int,int);
void deletion(struct node * ,int);
void createList(struct node * );

struct node {
  int info;
  struct node *next;
};

void createList(struct node * last){
  int value,n;
  printf("Enter how many numbers do you want to add\n");
  scanf("%d",&n);
  printf("Enter the first number that you want to add to the empty list \n");
  scanf("%d",&value);
  addToEmpty(last,value);
  printf("Enter the numbers that you want to add in your list\n");
  for(int i=2;i<=n;i++){
    scanf("%d",&value);
    addAtEnd(last,value);
  }
}

struct node * createNewNode(){
  struct node * temp;
 temp= (struct node *) malloc(sizeof(struct node));
 return temp;
}

void addToEmpty(struct node *last,int value){
  struct node *t;
  t=createNewNode();
    last=t;
    t->next=last;
    last->info=value;
}

void addAtBeg(struct node *last,int value){
  struct node * temp;
  temp=createNewNode();
  if(last!=NULL){
    temp->next=last->next;
    last->next=temp;
    temp->info=value;
  }
  else{
    int choice;
    printf("Your list is empty.So, If you wanna choose the option to add element to Empty. Then enter 1");
    scanf("%d",&choice);
    if(choice==1){
      addToEmpty(last,value);
    }
    else{
      exit(0);
    }
 }
}

void addAtEnd(struct node *last, int value){
  struct node *temp;
  temp=createNewNode();
  temp->next=last->next;
  last->next=temp;
  last=temp;
}

void addAtAny(struct node * last,int value,int valueAfter){
  struct node * temp;
  temp=createNewNode();
  struct node * t;
  t=last->next;
  while(t!=last->next){
    if(t->info==valueAfter){
      temp->next=t->next;
      t->next=temp;
    }
    t=t->next;
  }
}

void deletion(struct node * last,int valueAfter){
  struct node * t; 
  if(last->next->info==valueAfter){
    t=last->next;
    t->next=last->next;
    free(t);
  }
  else if(last->info==valueAfter){
    struct node * temp;
    temp=last->next;
    while(temp!=last){
      temp=temp->next;
    }
    temp->next=last->next;
    last=temp;
  }
  else{
    struct node * p=last->next;
    for(struct node * i=p->next;i<last;i=i->next){
      if(i->info==valueAfter){
        struct node * p1;
        p1=i->next;
        i->next=p1->next;
        free(p1);
      }
    }
  }
}
void displayList(struct node * last){
  struct node * n;
  n=last->next;
  while(n!=last->next){
    printf("%d ",n->info);
    n=n->next;
  }
}

int main(){
  struct node * last= NULL;
  int value,choice,valueAfter;
  printf("1. Enter to add number to empty list\n");
  printf("2. Enter to add number at begin\n");
  printf("3. Enter to add number to end \n");
  printf("4. Enter to delete the number after a particular value\n");
  printf("5. Enter to create the list\n");
  printf("6. Enter to exit the programming \n");
  scanf("%d",&choice);
  while(1){
    switch(choice){
      case 1: printf("Enter a number that you want to add to empty list \n");
               scanf("%d",&value);
               addToEmpty(last,value);
               break;
      case 2: printf ("Enter a number that you want to add at Begin\n");
               scanf("%d",&value);
               addAtBeg(last,value);
               break;
      case 3: printf("Enter a number that you want to add at the end \n");
               scanf("%d",&value);
               addAtEnd(last,value);
               break;
      case 4: printf("Enter a value before that number to be deleted \n");
               scanf("%d",&valueAfter);
               deletion(last,valueAfter);
               break;
      case 5: createList(last);
               break;
      case 6: exit(0);
               break;
      default : printf("Invalid Entry\n");
    }
  }
}

