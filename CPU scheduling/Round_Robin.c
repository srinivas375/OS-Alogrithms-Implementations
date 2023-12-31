
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    float data;
    struct node *next;
} node;

node *head = NULL, *new, *temp;

void enqueue(int x)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = x;
        head->next = NULL;
    }
    else
    {
        new = (node *)malloc(sizeof(node));
        new->data = x;
        new->next = NULL;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

float dequeue()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        temp = head;
        head = head->next;
        float data = temp->data;
        free(temp);
        return data;
    }
}

int empty()
{
    if (head == NULL)
        return 1;
    return 0;
}

int main()
{
    float tq;
    int n, i, j;
    float pr;
    printf("enter the number of processes :");
    if (scanf("%f", &pr) != 1)
    {
        printf("you entered invalid input.\n");
        exit(1);
    }
    else
    {
        n = pr;
        if (n < 0 || (pr - n) != 0)
        {
            printf("enter only integer value.\n");
            exit(1);
        }
    }
    int P[n];
    float AT[n], BT[n], CT[n], TAT[n], WT[n], CBT[n], flag[n];
    for (i = 0; i < n; i++)
    {
        P[i] = i + 1;
        CT[i] = TAT[i] = WT[i] = flag[i] = 0;
    }
    printf("enter the process id's :\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &P[i]) != 1 || P[i] < 0)
        {
            printf("you entered invalid input.\n");
            exit(1);
        }
    }
    printf("enter the AT's of processes :\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%f", &AT[i]) != 1 || AT[i] < 0)
        {
            printf("you entered invalid input.\n");
            exit(1);
        }
    }
    printf("enter the BT's of processes :\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%f", &BT[i]) != 1 || BT[i] < 0)
        {
            printf("you entered invalid input.\n");
            exit(1);
        }
    }
    printf("enter the TQ value : ");
    if (scanf("%f", &tq) != 1 || tq < 1)
    {
        printf("you entered invalid input.\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (AT[j] > AT[j + 1])
            {
                float temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;
                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }
    float t = 0;
    float track = 0;
    int min = 9999;
    for (i = 0; i < n; i++)
    {
        if (AT[i] < min)
        {
            min = AT[i];
        }
    }
    t = min;
    track = t;
    for (i = 0; i < n; i++)
    {
        if (AT[i] == t)
        {
            enqueue(BT[i]);
            enqueue(i);
            flag[i] = 1;
        }
        CBT[i] = BT[i];
    }

    printf("\nthe gannt chart is :\n");
    printf("process | start | end |\n");
    while (!empty()) // Continue scheduling until all processes are completed
    {

        float d = dequeue();
        i = dequeue();
        if (d <= tq)
        {
            t += d;
            CT[i] = t;
            BT[i] = 0;
            printf("%d       | %.2f  |  %.2f\n", P[i], track, t);
            track = t;
        }
        else
        {
            t += tq;
            CT[i] = t;
            BT[i] -= tq;
            printf("%d       | %.2f  |  %.2f\n", P[i], track, t);
            track = t;
            for (int j = 0; j < n; j++)
            {
                if (AT[j] <= CT[i] && flag[j] == 0)
                {
                    enqueue(BT[j]);
                    enqueue(j);
                    flag[j] = 1;
                }
            }
            enqueue(BT[i]);
            enqueue(i);
        }
    }

    printf("\npointer       BT          AT           CT              TAT             WT\n");

    for (i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - CBT[i];
        printf("%d          %.2f           %.2f          %.2f          %.2f          %.2f\n", P[i], CBT[i], AT[i], CT[i], TAT[i], WT[i]);
    }
    float sum = 0;
    float sum2 = 0;
    for (i = 0; i < n; i++)
    {
        sum += WT[i];
        sum2 += TAT[i];
    }
    float avg = (float)sum / n;
    float avg2 = (float)sum2 / n;
    printf("the average turn around time is : %.4f\n", avg2);

    printf("the average waiting time is : %.4f\n", avg);

    return 0;
}