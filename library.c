
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
//*************************************



//function to print all publishers'names
//*************************************
void printpublishers (book*first)
{
    book * current=first;                           //pointer to traverse the linked list
    int i =0 ;                                      //counter to print numbers with publishers
    while(1)
    {
        i++;
        printf("%d - %s \n",i,current->publisher);  //print statemet
        
        if (current->next!=NULL)
        {
            current=current->next;                  //if this node is not the last node move to the next address 
        }
        else
        {
            break;                                  //if this node is the last node break the loop and end the printing function
        }
    }
}
//*************************************




//function to determine the highest price book and print its data
//*************************************
void highest(book*first)
{
    book * current     = first;             //pointer to traverse the linked list
    book * highestbook = first;             //pointer to the highest price book node
    int highestprice   = first->price;      //variable to hold the highest price ad compare it with other prices

    while(1){
        if (current->price>highestprice)    //check if the price of the current book is higher or not 
        {
            highestprice=current->price;    //if the current price is higher put it on the variable as the highest until now 
            highestbook = current;          //and then point to its address
        }
        if (current->next!=NULL)
        {
            current=current->next;          //if this node is not the last node move to the next address
        }
        else
        {
            break;                          //if this node is the last node break the loop   
        }
    }
    printf("name : %s , publisher : %s , price : %d \n",highestbook->name,highestbook->publisher,highestbook->price); //print book's data
}
//*************************************




//main function
//*************************************
int main()
{
 
 //variables 
 //*******************************
   book * first = NULL;   //first node pointer
   book * added = NULL;   //pointer to the current ode while addig new nodes
   int ch ;               //variable to read stdin for flushing 
   char name [20] ;       //name string
   char publisher [20] ;  //publisher string
   int command ;          //command used to select function
   int price ;            //price variable
 //*******************************
 
 
 //the program will stuck here inside this loop until user selects exit option
 //*******************************
   while (1)
    {
        //take the command from the user
        //******************************
        printf("enter the number of the command :\n 1 - add book \n 2 - display all books information \n 3 - display highest price book \n 4 - display list of publishers \n 5 - exit \n");
        scanf("%d",&command);
        //******************************
    
        if (command == 5)
        {
            printf("bye \n");              //exit the program
            break;
        }
        else if(command == 4)
        {
            printpublishers(first);        //print publishers' names
        }
        else if(command == 3)
        {
            highest(first);                //print highest book's data
        }
        else if(command == 2)
        {
            printall(first);               //print all stored data
        }
        else if(command == 1)              //add new book
        {
            //get book's data
            //***************
            printf("enter the name \n");   
            while ((ch = getchar()) != '\n' && ch != EOF); //flush stdin
            fgets(name,20,stdin);
            printf("enter the publisher\n");
            fgets(publisher,20,stdin);
            printf("enter the price \n");
            scanf("%d",&price);
            //***************

            if (first == NULL)          //if this is the first input store it in the first node
            {
                first = newbook(name , publisher , price);         //store data in first ode address
                if (first!=NULL)
                {
                    added = first ;                                //point to the first node
                }
            }
            else                        //if it is not the first input add new node
            {
                added->next = newbook(name , publisher , price);   //store data in the next pointer of the last node
                if (added->next!=NULL)                             //make sure that the next address returned by malloc is not NULL
                {
                    added = added->next ;                          //point to the new node now
                }
            }
        }

    }

    return 0;
}
