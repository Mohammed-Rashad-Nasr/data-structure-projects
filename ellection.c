// libraries
//*************************************
#include <stdio.h>
#include <stdlib.h>
//*************************************

//the user defined structure which contains cadidates' data
//*************************************
typedef struct candidate
 {
    char name [20] ;
    int votes ;
    struct candidate * link ;

 }Candidate ;

Candidate*head=NULL;
//*************************************
Candidate* NewCandidate(int vote, char name[])
{
    int i = 0 ;
    Candidate* newnode=malloc(sizeof(Candidate));
    while (name[i]!=NULL)
        {
           newnode -> name[i] = name[i];
           i++;
        }
    newnode->votes=vote;
    newnode->link=NULL;
    return newnode;
}
void insertAtEnd(int vote, char name[])
{
    Candidate*ptr=head;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=NewCandidate(vote,name);
}
void FindLeadingCandidate()
{
    Candidate * current     = head;
    Candidate * highestCand = head;
    int highestvote   = head->votes;

    while(1){
        if (current->votes>highestvote)
        {
            highestvote=current->votes;
            highestCand = current;
        }
        if (current->link!=NULL)
        {
            current=current->link;
        }
        else
        {
            break;
        }
    }
    printf("name : %s , votes : %d \n",highestCand->name,highestCand->votes);
}
void castTheVote(int num)
{
    if(num==1)
    {
        head->votes+=1;
    }
    else if(num==2)
    {
        head->link->votes+=1;
    }
     else if(num==3)
    {
        head->link->link->votes+=1;
    }
     else if(num==4)
    {
        return 0;
    }
    return 0;
}
void FindVoteCount()
{
    if(head==NULL)return;
    Candidate*ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->votes);
        ptr=ptr->link;
    }
}


int main()
{
  head=NewCandidate(0,"Ahmed");
  insertAtEnd(0,"Hassan");
  insertAtEnd(0,"Omar");
  insertAtEnd(0,"Mohammed");
  int command;
   while (1)
    {

        printf("enter the number of the command :\n 1 - Cast the vote \n 2 - Find vote count \n 3 - Find Leading Candidate \n 4- exit \n");
        scanf("%d",&command);
        if (command == 4)
        {
            printf("bye \n"); ;
            break;
        }
        else if(command == 3)
        {
            FindLeadingCandidate();
        }
        else if(command == 2)
        {
            FindVoteCount();
        }
        else if(command == 1)
        {
            int num;
            printf(" 1 - Ahmed \n 2 - Hassan \n 3 - Omar \n 4- none of them\n");
           printf("enter your choice \n");
           scanf("%d",&num);
           castTheVote(num);
        }

    }

    return 0;
}
