#include "inverted.h"
#include <string.h>
#include <stdlib.h>

int save_database(hash *HT,char filename[])
{
    //checking if extension is .txt
   if(strstr(filename,".txt")==NULL)
   {
      printf("INFO: Pass the filename in .txt format\n");
      return FAILURE;
   }

   FILE *fptr;
   fptr = fopen(filename,"w");

    int i;
    for (i = 0; i < 28; i++) 
    {
        mainnode *temp = HT[i].link;
        if (temp != NULL) 
        {
            while (temp != NULL) 
            {
                // Print the index, word, and file count for the word
                fprintf(fptr,"#%d;%s;%d;", i ,temp->word, temp->filecount);

                sub *temp1 = temp->sub_link;
                
                while (temp1 != NULL) 
                {
                    //print filename and wordcount
                    fprintf(fptr,"%s;%d;",temp1->filename, temp1->wordcount);
                    temp1 = temp1 -> sublink;
                }
                fprintf(fptr,"#\n");
                temp = temp -> main_link;
            }
            
        }
    }
   fclose(fptr);
   printf("INFO: Database saved successfully\n");
   return SUCCESS; 
}