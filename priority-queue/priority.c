#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int queue_hp[MAX];
int queue_lp[MAX];
int rear_hp = -1;
int front_hp = -1;
int rear_lp = -1;
int front_lp = -1;

void insert()
{ // asking user for element to insert and priority
    int item, prio;
    printf("Insert the element in queue : ");
    scanf("%d", &item);
    printf("Insert the priority (0 for low, 1 for high) : ");
    scanf("%d", &prio);
    if (prio == 1)
    {
        if (rear_hp == MAX - 1)
            printf("Queue Overflow \n");
        else
        {
            if (front_hp == -1)
                front_hp = 0;
            queue_hp[++rear_hp] = item;
        }
    }
    else
    {
        if (rear_lp == MAX - 1)
            printf("Queue Overflow \n");
        else
        {
            if (front_lp == -1)
                front_lp = 0;
            queue_lp[++rear_lp] = item;
        }
    }
}

void delete ()
{
    if (front_hp == -1 || front_hp > rear_hp)
    {
        if (front_lp == -1 || front_lp > rear_lp)
        {
            printf("Queue Underflow \n");
            return;
        }
        else
        {
            printf("Element deleted from queue is : %d \n", queue_lp[front_lp++]);
        }
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d \n", queue_hp[front_hp++]);
    }
}

void display()
{
    int i;
    printf("High Priority Queue ");
    if (front_hp == -1 || front_hp > rear_hp)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front_hp; i <= rear_hp; i++)
            printf("%d ", queue_hp[i]);
    }
    printf("Low Priority Queue ");
    if (front_lp == -1 || front_lp > rear_lp)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front_lp; i <= rear_lp; i++)
            printf("%d ", queue_lp[i]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1.Insert element");
        printf("2.Delete element");
        printf("3.Display all elements");
        printf("4.Quit ");
        printf("Enter your choice : \n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice n");
        }
    }
}