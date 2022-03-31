#include <stdio.h>
#include <stdlib.h>

typedef struct books
 {
    char name [20] ;
    char publisher [20] ;
    int price ;
    struct books * next ;

 }book ;



book * newbook ( char* name , char * publisher , int price )
{
    book * temp = NULL;
    int i = 0 ;
    temp=malloc(sizeof(book));
    if (temp!=NULL)
    {
        temp ->price = price ;
        while (name[i]!=NULL)
        {
           temp -> name[i] = name[i];
           i++;
        }
        i=0 ;
        while (publisher[i]!=NULL)
        {
           temp -> publisher[i] = publisher[i];
           i++;
        }
        temp ->next = NULL ;
    }
    return temp ;
}



void printall(book*first)
{
    book * current=first;
    while(1)
    {
        printf("name : %s , publisher : %s , price : %d \n",current->name,current->publisher,current->price);
        if (current->next!=NULL)
        {
            current=current->next;
        }
        else
        {
            break;
        }
    }
}


void printpublishers (book*first)
{
    book * current=first;
    int i =0 ;
    while(1)
    {
        i++;
        printf("%d - %s \n",i,current->publisher);
        if (current->next!=NULL)
        {
            current=current->next;
        }
        else
        {
            break;
        }
    }
}


void highest(book*first)
{
    book * current     = first;
    book * highestbook = first;
    int highestprice   = first->price;

    while(1){
        if (current->price>highestprice)
        {
            highestprice=current->price;
            highestbook = current;
        }
        if (current->next!=NULL)
        {
            current=current->next;
        }
        else
        {
            break;
        }
    }
    printf("name : %s , publisher : %s , price : %d \n",highestbook->name,highestbook->publisher,highestbook->price);
}



int main()
{
   book * first = NULL;
   book * added = NULL;
   int ch ;
   char name [20] ;
   char publisher [20] ;
   int command ;
   int price ;
   while (1)
    {

        printf("enter the number of the command :\n 1 - add book \n 2 - display all books information \n 3 - display highest price book \n 4 - display list of publishers \n 5 - exit \n");
        scanf("%d",&command);
        if (command == 5)
        {
            printf("bye \n"); ;
            break;
        }
        else if(command == 4)
        {
            printpublishers(first);
        }
        else if(command == 3)
        {
            highest(first);
        }
        else if(command == 2)
        {
            printall(first);
        }
        else if(command == 1)
        {
            printf("enter the name \n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            fgets(name,20,stdin);
            printf("enter the publisher\n");
            fgets(publisher,20,stdin);
            printf("enter the price \n");
            scanf("%d",&price);


            if (first == NULL)
            {
                first = newbook(name , publisher , price);
                if (first!=NULL)
                {
                    added = first ;
                }
            }
            else
            {
                added->next = newbook(name , publisher , price);
                if (added->next!=NULL)
                {
                    added = added->next ;
                }
            }
        }

    }

    return 0;
}
