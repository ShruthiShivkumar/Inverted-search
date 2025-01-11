#include "inverted.h"
#include <string.h>

int search_database(char word[],hash *HT)
{
    //finding index
    int index = find_index(word);

    mainnode *temp = HT[index].link;

    //searching for the file
    while(temp!=NULL)
    {
        if(strcmp(temp -> word,word)==0)
        {
            printf("%s is present in %d files\n",temp->word,temp->filecount);
            sub *temp1=temp->sub_link;
            while(temp1!=NULL)
            {
                printf("In file %s : %d times\n",temp1->filename,temp1->wordcount);
                temp1 = temp1 -> sublink;
            }
            return SUCCESS;
        }
        temp = temp -> main_link;
    }

    printf("INFO: Word is not found in the database\n");
    return FAILURE;


}