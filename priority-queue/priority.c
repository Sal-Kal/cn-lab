#include <stdio.h>
#include <stdlib.h>

int queue[100], rear = -1, front = 0, size;

void insert();
void display();
void delete ();

void main()
{
    int choice, i;
    printf("Enter the size\n");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
        queue[i] = 0;
    while (1)
    {
        printf("Enter 1 to insert, 2 to delete, 3 to display and 4 to exit\n");
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
            exit(0);
        default:
            printf("Entered wrong choice\n");
        }
    }
}

void insert()
{
    int value, temp, i;
    if (rear == size - 1)
    {
        printf("queue is full\n");
        return;
    }
    printf("Enter the value to be inserted\n");
    scanf("%d", &value);
    if (rear < front)
    {
        queue[++rear] = value;
        return;
    }
    for (i = front; i <= rear; i++)
    {
        if (queue[i] < value)
        {
            temp = queue[i];
            queue[i] = value;
            value = temp;
        }
    }
    rear++;
    queue[rear] = value;
}

void delete ()
{

    if (rear < front)
    {
        printf("queue is empty\n");
        return;
    }
    printf("%d was deleted\n", queue[front]);
    front++;
}

void display()
{
    int i;
    if (rear < front)
    {
        printf("queue is empty\n");
        return;
    }
    for (i = front; i < rear + 1; i++)
    {
        printf("%d \t", queue[i]);
    }
    printf("\n");
}