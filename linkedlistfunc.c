#include <stdio.h>
#include <malloc.h>
struct list
{
    int info;
    struct list *next;
};
typedef struct list node;
node *start = NULL, *newnode, *prev = NULL;
int nnode = 0;
void clearbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void create(int num)
{
    clearbuffer();
    start = (node *)malloc(sizeof(node));
    start->info = num;
    start->next = NULL;
    printf("Linked List Created\n");
    printf("Number entered \n");
    prev = start;
    nnode = nnode + 1;
}
void insert(int num)
{
    clearbuffer();
    newnode = (node *)malloc(sizeof(node));
    newnode->info = num;
    newnode->next = NULL;
    prev->next = newnode;
    prev = newnode;
    nnode = nnode + 1;
    printf("The number entered \n");
}
void sort()
{
    if (start == NULL)
    {
        printf("List not created \n");
    }
    else
    {
        node *tempi, *tempj;
        int temp;
        for (tempi = start; tempi->next != NULL; tempi = tempi->next)
        {
            for (tempj = tempi->next; tempj != NULL; tempj = tempj->next)
            {
                if (tempi->info > tempj->info)
                {
                    temp = tempi->info;
                    tempi->info = tempj->info;
                    tempj->info = temp;
                }
            }
        }
    }
}
void display()
{
    if (start == NULL)
    {
        printf("List is not Created\n");
    }
    else
    {
        for (node *temp = start; temp != NULL; temp = temp->next)
        {
            printf("%d ", temp->info);
        }
    }
}
void search(int num)
{
    if (start == NULL)
    {
        printf(":ist not created \n");
    }
    else
    {
        int flag = 0, index = 0;
        node *temp = NULL;
        while (temp != NULL)
        {
            if (temp->info == num)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
            index += 1;
        }
        if (flag == 1)
        {
            printf("%d found at position %d\n", num, index);
        }
        else
        {
            printf("Element not found\n");
        }
    }
}
void insertatrandom(int num, int pos)
{
    if (start == NULL)
    {
        create(num);
    }
    else if (pos == 1)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->info = num;
        newnode->next = start;
        start = newnode;
        nnode += 1;
    }
    else
    {
        if (nnode < pos)
        {
            insert(num);
        }
        else
        {
            int nodenumber = 0;
            node *newnode = (node *)malloc(sizeof(node));
            newnode->info = num;
            newnode->next = NULL;
            for (node *temp = start; temp != NULL; temp = temp->next)
            {
                if (nodenumber == pos - 1)
                {
                    newnode->next = temp->next;
                    temp->next = newnode;
                    break;
                }
                nodenumber += 1;
            }
        }
    }
}
void freememory()
{
    for (node *temp = start; temp != NULL; temp = temp->next)
    {
        free(temp);
    }
}
int main()
{
    int num;
    int choice;
    int pos;
    char another = 'y';
    while (another == 'y')
    {
        printf("Enter the choice : \n 1.) Insert element in the list \n 2.)Display the list \n 3.) Sort the list \n 4.) Searcb the number in list: \n5.) Insert the number at specific position\n 6.)End the list \n Choice-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &num);
            if (start == NULL)
            {
                create(num);
            }
            else
            {
                insert(num);
            }
            break;
        case 2:
            display();
            break;
        case 3:
            sort();
            break;
        case 4:
            printf("Enter the number : ");
            scanf("%d", &num);
            search(num);
            break;
        case 5:
            printf("Enter the number : ");
            scanf("%d", &num);
            printf("Enter the position : ");
            scanf("%d", &pos);
            insertatrandom(num, pos);
            break;
        case 6:
            freememory();
            another = 'n';
            break;
        default:
            printf("Enter the Corrent Choice\n ");
        }
    }
}