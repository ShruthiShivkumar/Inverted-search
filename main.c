/*Documentation
Name : Shruthi Shivkumar
Date : 26-12-2024
DES  : Inverted search
*/ 

#include "inverted.h"


int create=0;
int update=0;
file *head = NULL;

int main(int argc, char *argv[])
{
    

    //read and validate
    if (read_and_validate(&head,argc, argv) != SUCCESS)
    {
        return 0;
    }
    
    print_list(head);
   int size = 28;
   hash HT[size];
   //creating hash table
   create_HT(HT,size); 
   int option,flag=0;
   char ch;
   
   
   
    do
   {
      printf("\n");
      printf("Enter the choice among the below operation\n");
      printf("1. Create Database\n");
      printf("2. Display Database\n");
      printf("3. Update Database\n");
      printf("4. Search\n");
      printf("5. Save Database\n");
      printf("Enter your choice: ");
      scanf("%d", &option);

      switch (option)
      {
        case 1:
           //creating database
           create_database(head,HT);
           break;

        case 2:
            //displaying database
            display_database(HT,28);
            break;

        case 3:
            //update_database
            char name[20];
            update_database(HT,name);
            break;
    
        case 4:
            //search word
            char word[50];
            printf("Enter the word you want to search:");
            scanf("%s",word);
            search_database(word,HT);
            break;

        case 5:
            //save files
            char filename[50];
            printf("Enter the file name you want to save: ");
            scanf("%s",filename);
            
            save_database(HT,filename);
            break;


        default:
           printf("Invalid choice.Please try again\n");
      }
      printf("\n");
      printf("Enter y/Y to continue and n/N to discontinue : ");
      scanf(" %c",&ch);
   }while(ch!='N' && ch!='n');
                
                
                
                

               

               
   }





