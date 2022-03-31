
// libraries 
//*************************************
#include <stdio.h>
#include <stdlib.h>
//*************************************

//the user defined structure which contains books' data 
//*************************************
typedef struct books
 {
    char name [20] ;
    char publisher [20] ;
    int price ;
    struct books * next ;

 }book ;
//*************************************


//function to creat new book
//*************************************
book * newbook ( char* name , char * publisher , int price )
{
    book * temp = NULL;                           //pointer to the address of the new book 
    int i = 0 ;                                   //counter
    temp=malloc(sizeof(book));                    //memory allocation to get the address of the new book
    if (temp!=NULL)                               //to make sure that malloc function worked correctly ad didn't return NULL
    {
        temp ->price = price ;                    //add user defined book price
        while (name[i]!=NULL)                     //add book name using a loop to add all the characters 
        {
           temp -> name[i] = name[i];
           i++;
        }
        i=0 ;                                     //reinitialize the counter
        while (publisher[i]!=NULL)                //add book bublisher using a loop to add all the characters 
        {
           temp -> publisher[i] = publisher[i];
           i++;
        }
        temp ->next = NULL ;                      //make the next pointer point to NULL for now as there is no next node
    }
    return temp ;                                 //return the new book's pointer
}
//*************************************



//function to prit all the stored data 
//*************************************
void printall(book*first)
{
    book * current=first;                         //pointer to traverse the linked list
    while(1)
    {
        printf("name : %s , publisher : %s , price : %d \n",current->name,current->publisher,current->price); //print statement
     
     
        if (current->next!=NULL)                 //if this node is not the last node move to the next address 
        {
            current=current->next;              
        }
        else
        {
            break;                              //if this node is the last node break the loop and end the printing function 
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
