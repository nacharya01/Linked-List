#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node * createNewNode();
struct node * addToEmpty(struct node* ,int);
struct node * addAtEnd(struct node * , int);
struct node * addAtAny(struct node * ,int,int);
struct node * deletion(struct node * ,int);
struct node * createList(struct node * );
void displayList(struct node *);

struct node {
  int info;
  struct node *next;
};

struct node * createNewNode(){
  struct node * temp;
 temp= (struct node *) malloc(sizeof(struct node));
 return temp;
}
struct node* addAtBeg(struct node *last,int value){
  struct node * temp;
  temp=createNewNode();
  temp->info=value;
  temp->next=last->next;
  last->next=temp;
  return (last);
}
void displayList(struct node * last){
  struct node * n;
  n=last->next;
  if(last==NULL){
    printf("List is empty ");
  }
  else{
    do{
    printf("%d ",n->info);
    n=n->next;
    }while(n!=last->next);
  }
}
struct node * createList(struct node * last){
  int value,n;
  printf("Enter how many numbers do you want to add\n");
  scanf("%d",&n);
  printf("Enter the first number that you want to add to the empty list \n");
  scanf("%d",&value);
  last=addToEmpty(last,value);
  printf("Enter the numbers that you want to add in your list\n");
  for(int i=2;i<=n;i++){
    scanf("%d",&value);
    last=addAtEnd(last,value);
  }
  return (last);
}

struct node * addToEmpty(struct node *last,int value){
  struct node *t;
  t=createNewNode();
  t->info=value;
  last=t;
  t->next=last;
  return (last);
}

struct node* addAtEnd(struct node *last, int value){
  struct node *temp;
  temp=createNewNode();
  temp->info=value;
  temp->next=last->next;
  last->next=temp;
  last=temp;
  return(last);
}

struct node * addAtAny(struct node * last,int value,int valueAfter){
  struct node * temp;
  temp=createNewNode();
  struct node * t;
  t=last->next;
  do{
    if(t->info==valueAfter){
      temp->info=value;
      temp->next=t->next;
      t->next=temp;
      if(t==last){
        last=temp;
        return (last);
      }
    }
    t=t->next;

  }while(t!=last->next);
}

struct node* deletion(struct node * last,int value){
  struct node * t,*p;

  if(last==last->next && last->info){
    t=last;
    last=NULL;
    free(t);
    return (last);
  }
  if(last->next->info==value){
    t=last->next;
    t->next=last->next;
    free(t);
    return (last);
  }
  p=last->next;
  while(p->next!=last){
    if(p->next->info==value){
      t=p->next;
      p->next=t->next;
      free(t);
      return last;
    }
    p=p->next;
  }
  if(last->info==value){
    t=last;
    p->next=last->next;
    free (t);
    return (last);
  }
  return (last);
}


int main(){
  struct node * last= NULL;
  int value,choice;
  printf("1. Enter to add number to empty list\n");
  printf("2. Enter to add number at begin\n");
  printf("3. Enter to add number to end \n");
  printf("4. Enter to delete the number after a particular value\n");
  printf("5. Enter to create the list\n");
  printf("6. Enter to exit the programming \n");
  printf("7. Enter to display the lists\n");
  scanf("%d",&choice);
  while(1){
    switch(choice){
      case 1: printf("Enter a number that you want to add to empty list \n");
               scanf("%d",&value);
               last=addToEmpty(last,value);
               break;
      case 2: printf ("Enter a number that you want to add at Begin\n");
               scanf("%d",&value);
               last=addAtBeg(last,value);
               break;
      case 3: printf("Enter a number that you want to add at the end \n");
               scanf("%d",&value);
               last=addAtEnd(last,value);
               break;
      case 4: printf("Enter a value before that number to be deleted \n");
               scanf("%d",&value);
               last=deletion(last,value);
               break;
      case 5: last=createList(last);
               break;
      case 6: exit(0);
               break;
      case 7: displayList(last);
              break;
      default : printf("Invalid Entry\n");
    }
  }
  getch();
  return 0;
}

