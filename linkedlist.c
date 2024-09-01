#include<stdio.h>
#include<malloc.h>
struct list
{
    int data;
    struct list *next;
};
typedef struct list node;
node *start = NULL,*newnode,*prev,*temp;
void clearbuffer()
{
    int c;
    while(( c = getchar())!= '\n' && c != EOF);
}
int main()
{
    
    int num;
    char another = 'y';
    while(another == 'y')
    {
        printf("Enter the number: ");
        scanf("%d",&num);
        newnode = (node*) malloc(sizeof(node));
        newnode->data = num;
        newnode->next = NULL;
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            prev->next = newnode;
        }
        prev = newnode;
        clearbuffer();
        printf("Do you wish to continue(Y/N): ");
        scanf("%c",&another);
        clearbuffer();
    }
    temp = start;
    while(temp != NULL)
    {
        printf("%d \n",temp->data);
        temp = temp->next;
    }
}
