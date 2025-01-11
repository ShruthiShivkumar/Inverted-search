#include "inverted.h"
#include <string.h>

int check_files(char filename[],file **head)
{
    file *temp = *head;
    while (temp != NULL) 
    {
        if(strcmp(temp->filename,filename)==0)
        {
            
           return FAILURE;
        }
        temp = temp->link;
    }
    return SUCCESS;
}

int insert_at_last(file **head, char *filename) 
{
     if(check_files(filename,head)!=SUCCESS)
     {
        printf("INFO: %s is repeated, the file won't be added to the list.\n",filename);
          return FAILURE;
     }
        
     // create new node
    file *new = malloc(sizeof(file));
    if (new == NULL) 
    {
        return FAILURE;
    }
    // copy the filename
    strcpy(new ->filename,filename);
    new->link = NULL;

    // check if list is empty
    if (*head == NULL) {
        *head = new;
        return SUCCESS;
    }

    // traverse up to last node
    file *temp = *head;
    while (temp->link != NULL) 
    {
        if(strcmp(temp -> filename,filename)==0)
        {
            return FAILURE;
        }
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS; 
    
}

//creating hash table
void create_HT(hash *HT, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        HT[i].key = i;
        HT[i].link = NULL;
    }
}

void print_list(file *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%s -> ", head -> filename);

		    /* Travering in forward direction */
		    head = head -> link;
		    
	    }
    	printf("NULL\n");
    }
}

//finding the index for the word
int find_index(const char *data)
{
    int i,index=0;
    if(*data >= 'a' && *data <= 'z')
    {
        index = *data - 'a';
    }
    else if(*data >= 'A' && *data <= 'Z')
    {
        index = *data - 'A';
    }
    else if(*data >= '0' && *data <= '9')
    {
        index = 26;
    }
    else 
    {
        index = 27;
    }
    return index;
}

//delete element from the list
int delete_element(char filename[])
{
   file *temp = head;
   file *temp1 = NULL;
   if(head == NULL)
   {
       return FAILURE;
   }
   if(strcmp(head->filename,filename)==0)
   {
       head = temp->link;
       free(temp);
       return SUCCESS;
   }
   
   while(temp->link!=NULL)
   {
       if(strcmp(temp->link->filename,filename)==0)
       {
           temp1 = temp->link->link;
           free(temp->link);
           temp->link = temp1;
           return SUCCESS;
       }
       temp = temp->link;
   }
   return FAILURE;
}

