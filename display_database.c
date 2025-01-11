

#include "inverted.h"

void display_database(hash *HT, int size) 
{
    // Print the header row
    printf("%-10s %-15s %-14s %-15s %-10s\n", "INDEX", "WORD", "FILE COUNT", "FILE NAME", "WORD COUNT");

    int i;
    for (i = 0; i < size; i++) 
    {
        mainnode *temp = HT[i].link;
        if (temp != NULL) {
            while (temp != NULL) 
            {
                // Print the index, word, and file count for the word
                printf("%-10d %-15s %-15d", i,temp->word, temp->filecount);

                sub *temp1 = temp->sub_link;
                int first_file = 1; // Flag to handle alignment for the first file
                
                while (temp1 != NULL) 
                {
                    if (!first_file) 
                    {
                       
                        printf("%-42s", ""); // Spaces for INDEX, WORD, FILE COUNT
                    }
                    
                    // Print file name and word count
                    printf("%-15s %-10d\n", temp1->filename, temp1->wordcount);
                    temp1 = temp1 -> sublink;
                    first_file = 0; // Clear the flag after the first file is printed
                }
                
                temp = temp -> main_link;
            }
        }
    }
}
