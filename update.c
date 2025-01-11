#include "inverted.h"
#include <string.h>

//open files for update
int open_files_update(hash *HT,char file[])
{
   // printf("%s",file);

    FILE *fp;
    fp = fopen(file,"r");
    if(fp==NULL)
    {
        printf("INFO: The inputed file doesn't exist in the directory\n");
        return FAILURE;
    }
    char ch,ch1;
    //fseek(fp, 0 , SEEK_SET);
    fscanf(fp,"%c",&ch);
    //printf("%c\n",ch);
   
    fseek(fp,-2, SEEK_END);
    fscanf(fp,"%c",&ch1);
    //printf("%c\n",ch1);
    if(ch != '#' || ch1 != '#')
    {
        printf("INFO: The inputed file doesn't have the database\n");
        fclose(fp);
       return FAILURE;
    }
    rewind(fp);

    int index,filecount,i,wordcount;
    char word[50];
    char filename[50];
    mainnode *temp1;
    sub *temp2;
    
    //updating the values from the saved file
    while(fscanf(fp,"#%d;%[^;];%d;",&index,word,&filecount)!=EOF)
    {
        if(HT[index].link == NULL)
        {
            mainnode *newmain = malloc(sizeof(mainnode));
            if(newmain==NULL)
            {
                return FAILURE;
            }

            sub *newsub2 = malloc(sizeof(sub));
            if(newsub2==NULL)
            {
                  return FAILURE;
            }
            
            newmain -> main_link = NULL;
            newmain -> sub_link = newsub2;

            newsub2 -> sublink = NULL;

            temp1 = newmain;
            HT[index].link = temp1;
            temp1 -> filecount = filecount;
            strcpy(temp1 -> word,word);
            
            temp2 = temp1 -> sub_link;
            fscanf(fp,"%[^;];%d;",filename,&wordcount);
            strcpy(temp2->filename,filename);
            temp2 -> wordcount = wordcount;

            if(check_files(filename,&head)==FAILURE)
            {
                delete_element(filename);
            }
            
            for(i=0;i<filecount-1;i++)
            {
                fscanf(fp,"%[^;];%d;",filename,&wordcount);

                sub *newsub = malloc(sizeof(sub));
                if(newsub==NULL)
                {
                  return FAILURE;
                }
                temp2 -> sublink = newsub;
                temp2 = temp2 -> sublink;
                temp2 -> wordcount = wordcount;
                strcpy(temp2->filename,filename);
                

                if(check_files(filename,&head)==FAILURE)
                {
                    delete_element(filename);
                }

            }
        }
        else
        {
            temp1 = HT[index].link;
            while(temp1->main_link!=NULL)
            {
                temp1 = temp1 -> main_link;
            }
            mainnode *newmain1 = malloc(sizeof(mainnode));
            if(newmain1==NULL)
            {
                return FAILURE;
            }
            sub *newsub3 = malloc(sizeof(sub));
            if(newsub3==NULL)
            {
                  return FAILURE;
            }
            
            newmain1 -> main_link = NULL;
            newmain1 -> sub_link = newsub3;

            
            newsub3 -> sublink = NULL;

            temp1 -> main_link = newmain1;
            temp1 = temp1 -> main_link;
            temp1 -> filecount = filecount;
            strcpy(temp1 -> word,word);

            temp2 = temp1 -> sub_link;
            fscanf(fp,"%[^;];%d;",filename,&wordcount);
            strcpy(temp2->filename,filename);
            temp2 -> wordcount = wordcount;

            if(check_files(filename,&head)==FAILURE)
            {
                delete_element(filename);
            }

            for(i=0;i<filecount-1;i++)
            {
                fscanf(fp,"%[^;];%d;",filename,&wordcount);
                sub *newsub1 = malloc(sizeof(sub));
                if(newsub1==NULL)
                {
                    return FAILURE;
                }
                temp2 -> sublink = newsub1;
                temp2 = temp2 -> sublink;
                temp2 -> wordcount = wordcount;
                strcpy(temp2 -> filename,filename);

                if(check_files(filename,&head)==FAILURE)
                {
                    delete_element(filename);
                }

            }

        }
        
        fscanf(fp,"#\n");
    }
    fclose(fp);
    printf("\nINFO: Database Updated Successfully\n");
    update=1;
    return SUCCESS;
}

//read and validate for updation
int read_and_validate_update(hash *HT,char filename[])
{
   if(strstr(filename,".txt")==NULL)
   {
      printf("INFO: Enter the file in .txt format\n");
      return FAILURE;
   }  

   open_files_update(HT,filename);
   return SUCCESS;

}

int update_database(hash *HT,char filename[])
{
    
    if(create == 1)
    {
        printf("INFO: Updation after creation of database not possible\n");
        return FAILURE;
    }
    if(update == 1)
    {
       printf("INFO : The database cannot be updated again\n");
       return FAILURE;
    }
    printf("Enter the filename:");
    scanf("%s",filename);
   // printf("%s",filename);
    read_and_validate_update(HT,filename);
    return SUCCESS;
}
 







