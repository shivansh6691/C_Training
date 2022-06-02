#include <stdio.h>

void displayBook();
int autoIncrement();
void addBook();
void writeToFile();
int main()
{ 
    int user_choice;
    int n=1;
    while(n){
        addBook();
        
        printf("Do you want to add more Books \nEnter 1 to add\n");
        scanf("%d",&user_choice);
        
        
        if(user_choice!=1)
        {
            n=0;
        }
            
    }
    displayBook();
    writeToFile();
    printf("\nhello world here i am");
    return 0;
}
