#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    float pr;
    printf("enter the number of processes :"); //for validation 
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
    float AT[n], BT[n], CT[n], TAT[n], WT[n];
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
    printf("the gantt chart is :\n");
    printf("process | start | end |\n");
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
    float t = AT[0];
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (AT[i] == 0)
                CT[i] = BT[i] + AT[i];
        }
        else if (i > 0)
        {
            if (AT[i] < CT[i - 1])
            {
                CT[i] = BT[i] + CT[i - 1];
            }
            else
            {
                CT[i] = (AT[i] - CT[i - 1]) + BT[i] + CT[i - 1];
            }
        }
        printf("%d       | %.2f  |  %.2f\n", P[i], t, CT[i]);
        t = CT[i];
    }
    printf("pointer       BT       AT        CT          TAT            WT\n");
    for (i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        printf("%d          %.2f           %.2f          %.2f          %.2f          %.2f\n", P[i], BT[i], AT[i], CT[i], TAT[i], WT[i]);
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
