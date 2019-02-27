#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node {
     int info;
     struct node * link;
};
struct node * START=NULL;
struct node* createNode(){
     struct node * newNode;
     newNode= (struct node *)malloc(sizeof(struct node));
     return newNode;
}

void insertElement() {
     struct node * temp;
     temp= createNode();
     printf("Enter a number ");
     scanf("%d",&temp->info);
     if(START==NULL){
        START=temp;
        temp->link=NULL;
     }
     else {
        struct node * t;
        t=START;
        while(t->link!=NULL){
            t=t->link;
            t->link=temp;
            }
     }
}
void deletion(){
struct node * temp2;
   if(START==NULL){
    printf("List is empty\n");
   }
   else{
    temp2=START;
    START=temp2->link;
    free(temp2);
   }

}

void traversing(){
     struct node * temp1;
     temp1=START;
     while(temp1!=NULL){
        printf("%d ",temp1->info);
        temp1=temp1->link;
     }
}
 int menu(){
   int ch;
   printf("\n\n\n1. Enter to insert a number at the end of the list\n");
   printf("2. Enter to delete the first element from the list\n");
   printf("3. Enter to traversing \n");
   printf("4. Enter to exit \n");
   scanf("%d",&ch);
   return ch;
   }

 int main()
 {
    while(1){
     switch(menu()){
       case 1: insertElement();
               break;
       case 2: deletion();
               break;
       case 3: traversing();
               break;
       case 4: exit(0);
               break;
       default: printf("Invalid Entry");
    }
   }
   getch();
   return 0;
}

