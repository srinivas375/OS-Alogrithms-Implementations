#include <stdio.h>
#include <stdlib.h>

int check(float *bt, int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        if (bt[i] != 0)
            return 1;
    }
    return 0;
}

int minimum(float *at, float *bt, int n, int time)
{
    int index = -1;
    int min = 9999;
    for (int i = 0; i < n; i++)
    {
        if (bt[i] > 0 && bt[i] < min && at[i] <= time)
        {
            min = bt[i];
            index = i;
        }
    }
    return index;
}

int cal(float *bt, int n)
{
    int min = 9999;
    for (int i = 0; i < n; i++)
    {
        if (bt[i] < min && bt[i] != 0)
        {
            min = bt[i];
        }
    }
    return min;
}

int main()
{
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
    float AT[n], BT[n], CT[n], TAT[n], WT[n], CBT[n];
    for (i = 0; i < n; i++)
    {
        P[i] = i + 1;
        CT[i] = TAT[i] = WT[i] = 0;
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

    for (i = 0; i < n; i++)
    {
        CBT[i] = BT[i];
    }
    printf("\nthe gantt chart is :\n");
    printf("\nprocess | start | end |\n");
    float t = 0;
    float track = 0;
    while (check(BT, n))
    {
        int mini = minimum(AT, BT, n, t);
        if (mini == -1)
        {
            t++;
        }
        else
        {
            int data = cal(BT, n);
            if (data == BT[mini])
            {
                t += BT[mini];
                BT[mini] = 0;
            }
            else
            {
                t++;
                BT[mini] -= 1;
            }
            CT[mini] = t;
            printf("%d       | %.2f  |  %.2f\n", P[mini], track, t);
            track = t;
        }
    }
    printf("\npid       BT            AT            CT              TAT          WT\n");

    for (i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - CBT[i];
        printf("%d          %.2f           %.2f          %.2f          %.2f        %.2f\n", P[i], CBT[i], AT[i], CT[i], TAT[i], WT[i]);
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