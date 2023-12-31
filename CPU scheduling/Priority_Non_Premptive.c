#include <stdio.h>
#include <stdlib.h>

int flag[100];


int min(float *pr, int n)
{
    int min = 9999;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (pr[i] < min && flag[i] != 1)
        {
            min = pr[i];
            index = i;
        }
    }
    return index;
}

int counting(int k, float *at, int n)
{
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (k >= at[j])
            count++;
    }
    return count;
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
    float AT[n], BT[n], CT[n], TAT[n], WT[n], PR[n];
    for (i = 0; i < n; i++)
    {
        P[i] = i + 1;
        flag[i] = 0;
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
    printf("\nenter the priorities of processes :\n");
    for (i = 0; i < n; i++)
    {
        if (scanf("%f", &PR[i]) != 1 || PR[i] < 0)
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
                temp = PR[j];
                PR[j] = PR[j + 1];
                PR[j + 1] = temp;
            }
        }
    }
    printf("\nthe gantt chart is :\n");
    printf("\nprocess | start | end |\n");
    float t = 0;
    float time = 0;
    for (i = 0; i < n; i++)
    {
        int count;
        count = counting(time, AT, n);
        if (count == 0)
        {
            time++;
            i = -1;
            continue;
        }
        else
        {
            int d = min(PR, count);
            time += BT[d];
            CT[d] = time;
            printf("%d       | %.2f  |  %.2f\n", P[d], t, CT[d]);
            t = CT[d];
            TAT[d] = CT[d] - AT[d];
            WT[d] = TAT[d] - BT[d];
            flag[d] = 1;
        }
    }
    printf("\npointer       BT           AT          PR           CT            TAT            WT\n");

    for (i = 0; i < n; i++)
    {
        printf("%d          %.2f           %.2f          %.2f          %.2f          %.2f         %.2f\n", P[i], BT[i], AT[i], PR[i], CT[i], TAT[i], WT[i]);
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
