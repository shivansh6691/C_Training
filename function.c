#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef struct Books{
    int book_id;
    char book_name[20];
    char book_author[20];
    int book_quantity;
    
    struct Books *next;
}Books;

Books *head_book=NULL, *current_book=NULL;


int autoIncrement(){
    int id=0;
    for(current_book=head_book;current_book;current_book=current_book->next)
        id=current_book->book_id;
    return id+1; 
}

void addBook()
{
    Books b, *node;
    printf("Enter Book Name : ");
    scanf("%s",b.book_name);
    
    printf("Enter Book Author : ");
    scanf("%s",b.book_author);
    
    printf("Enter Book Quantity : ");
    scanf("%d",&b.book_quantity);
    
    node = (Books*)malloc(sizeof(Books));
    node->book_id=autoIncrement();
    strcpy(node->book_name, b.book_name);
    strcpy(node->book_author, b.book_author);
    node->book_quantity=b.book_quantity;
    
    node->next=NULL;
    
    if (head_book==NULL)
    {
        head_book=node;
    }
    else
    {
        current_book=head_book;
        while(current_book->next!=NULL)
            current_book=current_book->next;
        current_book->next=node;
    }
    
    
}


void displayBook()
{
    printf("\n%-5s%-20s%-20s%5s\n","Id","BOOK NAME","BOOK AUTHOR","BOOK QUANTITY");
    printf("-------------------------------------------------------------------\n");
    for(current_book=head_book;current_book;current_book=current_book->next)
        printf("%-5d%-20s%-20s%5d\n",current_book->book_id,current_book->book_name,current_book->book_author,current_book->book_quantity);
    printf("-------------------------------------------------------------------\n\n\n");
    // system("pause");
}
void writeToFile(){
    FILE *fp =fopen("Books.txt","a+");
    
    for(current_book=head_book;current_book;current_book=current_book->next){
        fprintf(fp,"%d,%s,%s,%d\n",current_book->book_id,current_book->book_name,current_book->book_author,current_book->book_quantity);
    }
    fclose(fp);
}	



