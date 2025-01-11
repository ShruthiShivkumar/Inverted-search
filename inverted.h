#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct subnode
{
    int wordcount;
    char filename[30];
    struct subnode *sublink;   
}sub;

typedef struct Main_node
{
    int filecount;
    char word[50];
    struct subnode *sub_link;
    struct Main_node *main_link;
}mainnode;

typedef struct hash_table
{
    int key;
    struct Main_node *link;
}hash;

typedef struct filenames
{
    char filename[30];
    struct filenames *link;
}file;

extern file *head;
extern int create;
extern int update;

int read_and_validate(file **head,int argc, char **argv);

int insert_at_last(file **head, char *filename);

void create_HT(hash *HT, int size);

void print_list(file *head);

int find_index(const char *data);

int create_database(file *head,hash *HT);

int read_word(FILE *fptr,hash *HT,char *filename);

int open_files(file *head,hash *HT);

int insert_hash_table(hash *HT,int index,const char *word,char *filename);

void display_database(hash *HT,int size);

int search_database(char word[],hash *HT);

int save_database(hash *HT,char filename[]);

int read_and_validate(file **head,int argc, char **argv);

int open_files_update(hash *HT,char filename[]);

int update_database(hash *HT,char filename[]);

int check_files(char filename[],file **head);

int delete_element(char filename[]);



#endif