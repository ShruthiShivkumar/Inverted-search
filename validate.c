 #include "inverted.h"
#include <string.h>

int read_and_validate(file **head,int argc, char **argv)
{
    //checking if the arguments passed are sufficient
    if(argc <= 1)
    {
        printf("INFO : Insufficient arguments\n");
        printf("Please pass the arguments like ./a.out <txt file>\n");  
        return FAILURE;
    }
    char *ptr;
    int i,count=0;
    FILE *fptr;
    for(i=1;i<argc;i++)
    {
        if(strstr(argv[i],".txt")!=NULL)
        {
            fptr = fopen(argv[i],"r");
            if(fptr!=NULL)
            {
                    
                            fseek(fptr,0,SEEK_END);
                            if(ftell(fptr)!=0)
                            { 
                                
                                fclose(fptr);
                                
                                if(insert_at_last(head,argv[i])==SUCCESS)
                                {
                                    count++; 
                                } 
                                        
                            }
                            
                            else
                            {
                                printf("INFO :%s is empty\n",argv[i]);
                            } 
                                
                    
                    
            }
            
             else
            {
                printf("INFO: %s doesn't exist in the directory\n",argv[i]);
            }
        }
        else
        {
            printf("INFO: %s is not in .txt format\n",argv[i]);
        }
        
    }

    if(count==0)
    {
        printf("INFO: Pass atleast one .txt file\n");
        return FAILURE;
    }  

    return SUCCESS;
}
    



 