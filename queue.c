#include<stdio.h>
int first = 0;
int last = -1;
int size = 100;
int arr[100];
int queueisfull()
{
    if(last == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int insert(int n)
{
    if(queueisfull() != 1)
    {
        last++;
        arr[last] = n;
        printf("Element inserted in the queue successfully\n");
        return 1;
    }
    else
    {
        printf("Element cannot be entered queue is full\n");
        return 0;
    }
}
int queueisempty()
{
    if(last == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void delete( )
{
    int n;
    if(queueisempty() != 1)
    {
        n = arr[first];
        first++;
        printf("%d deleted from the queue from the index %d\n",n,first-1);
        
    }
    else{
        printf("Element cannot be deleted queue is empty\n");
        
    }
}
void display()
{
    if(queueisempty() != 1)
    {
        for(int i = first;i <= last;i++)
        {
            printf("%d ",arr[i]);
        }
    }
    else{
        printf("Please insert elements for the display\n");
    }
}
int main()
{
    int choice;
    char ch = 'y';
    int n;
    int nn;
    while(ch == 'y')
    {
        printf("Enter the choice 1)Insert 2)Delete 3)Display 4)End\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element you want to enter in the queue: ");
                scanf("%d",&n);
                nn = insert(n);
                if(nn == 0)
                {
                    char dq;
                    printf("Do you wish to double the size of queue(y/n): ");
                    scanf("%c",&dq);
                    if(dq == 'y')
                    {
                        size = size * 2;
                        printf("Size of the queue is doubled\n");
                    }
                    else{
                        printf("Size of the is not incremented\n");
                    }
                }
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                ch = 'n';
                break;
            default:
                printf("Enter the vaild choice\n");
                break;
        }
    }
}