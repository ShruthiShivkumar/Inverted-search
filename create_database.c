#include "inverted.h"
#include <string.h>

int insert_hash_table(hash *HT,int index,const char *word,char *filename)
{
   if(HT[index].link == NULL)
   {
    //creating main node
       mainnode *newmain = malloc(sizeof(mainnode));
       if(newmain == NULL)
       {
        return FAILURE;
       }
     //creating subnode
       sub *newsub = malloc(sizeof(sub));
       if(newsub == NULL)
       {
        return FAILURE;
       }
    //storing values in main node
       strcpy(newmain -> word,word);
       newmain->filecount = 1;
       newmain->main_link = NULL;
       newmain->sub_link = newsub;
       HT[index].link = newmain;
    //storing values in sub node
       newsub->wordcount = 1;
       strcpy(newsub->filename,filename);
       newsub ->sublink = NULL;
       

   }

   else
   {
     mainnode *temp = HT[index].link;
     while(temp!=NULL)
     {
        //word is in same file
        if(strcmp(temp->word,word)==0)
        {
            sub* temp1 = temp->sub_link;
            sub *prev = NULL;
            while(temp1!=NULL)
            {
                if(strcmp(temp1->filename,filename)==0)
                {
                    temp1->wordcount=(temp1->wordcount)+1;
                    return SUCCESS;
                }
                prev = temp1;
                temp1 = temp1 -> sublink;
            }
                //word is in different file
                    sub *newsub1 = malloc(sizeof(sub));
                     if(newsub1 == NULL)
                    {
                      return FAILURE;
                    }
                    //subnode for new file
                    strcpy(newsub1->filename,filename);
                    newsub1->wordcount = 1;
                    newsub1->sublink = NULL;
                    if(prev!=NULL)
                    {
                        prev -> sublink = newsub1;
                    }
                    else
                    {
                         temp -> sub_link = newsub1;
                    }
                    
                    temp -> filecount = (temp -> filecount)+1;
                    return SUCCESS;   
            }
            temp = temp -> main_link;
     }
    mainnode *newmain1 = malloc(sizeof(mainnode));
    if(newmain1 == NULL)
    {
        return FAILURE;
    }
    //new node for new word
    strcpy(newmain1 -> word,word),
       newmain1->filecount = 1;
       newmain1->main_link = HT[index].link;
       HT[index].link = newmain1;

       sub *newsub2 = malloc(sizeof(sub));
       if(newsub2 == NULL)
       {
        return FAILURE;
       }

       newsub2->wordcount = 1;
       strcpy(newsub2->filename,filename);
       newsub2 ->sublink = NULL;
       newmain1->sub_link = newsub2;

   }
   return SUCCESS;
}

int read_word(FILE *fptr,hash *HT,char *filename)
    {
        char word[50];
       while (fscanf(fptr, "%s", word) != EOF)
        {
            //printf("%s\n",word);
            int index = find_index(word);
            //printf("%d\n",index);
            if(insert_hash_table(HT,index,word,filename)==FAILURE)
            {
                return FAILURE;
            }
            //fclose(fptr);
            
        }
        return SUCCESS;
    } 
int open_files(file *head,hash* HT)
    {
        FILE *fptr;
        char *filename;
        file* temp = head;
        while(temp != NULL)
        {
            filename = temp->filename;
            fptr = fopen(filename,"r");
            if(fptr == NULL)
            {
                return FAILURE;
            }
            char ch;
            char word[50];
            read_word(fptr,HT,filename);
            temp = temp->link;
        }
        return SUCCESS;
    }

   

int create_database(file *head,hash *HT)
{
    if(create == 1)
    {
        printf("INFO: Database already created\n");
        return FAILURE;
    }
    
   //creating hash table
   
    if(open_files(head,HT)==SUCCESS)
    {
        create = 1;
    }
    printf("INFO : Database creation Successful\n");
    return SUCCESS;

}

