#include <stdio.h>
#include <stdlib.h>

void takematrixinput(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

void takearrayinput(int rows, int array[rows])
{
    for (int i = 0; i < rows; i++)
    {
        scanf("%d", &array[i]);
    }
}

void safe_search(int processes, int resources, int allocated[processes][resources], int available[resources], int need[processes][resources])
{

    int finish[processes], flag, i, j;
    int work[resources];
    for (i = 0; i < resources; i++)
        work[i] = available[i];
    int safe_seq[processes], k = 0;
    for (i = 0; i < processes; i++)
    {
        finish[i] = 0;
    }
    for (i = 0; i < processes; i++)
    {
        flag = 0;
        if (finish[i] == 0)
        {
            for (j = 0; j < resources; j++)
            {
                if (need[i][j] > work[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                safe_seq[k++] = i;
                for (j = 0; j < resources; j++)
                {
                    work[j] += allocated[i][j];
                }
                finish[i] = 1;
                i = -1;
            }
        }
    }
    flag = 0;
    for (i = 0; i < processes; i++)
    {
        if (finish[i] != 1)
        {
            printf("the system is in deadlock\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("the processes executed successfully.\n");
        printf("the safe sequence is : ");
        for (i = 0; i < processes; i++)
        {
            printf("%d  ", safe_seq[i]);
        }
        printf("\n");
    }
}

int main()
{
    int processes, resources, i, j;

    printf("number of processes : ");
    scanf("%d", &processes);
    printf("number of resource types :");
    scanf("%d", &resources);

    int max[processes][resources];
    printf("maximum instances needed for each process :\n");
    takematrixinput(processes, resources, max);

    int allocated[processes][resources];
    printf("allocated instances for processes :\n");
    takematrixinput(processes, resources, allocated);

    int need[processes][resources];
    for (i = 0; i < processes; i++)
    {
        for (j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }

    printf("the availabe resources : ");
    int available[resources];
    takearrayinput(resources, available);

    safe_search(processes, resources, allocated, available, need);

    printf("do you have any request : ");
    int get;
    scanf("%d", &get);
    if (get)
    {
        printf("which process want request :");
        int process, flag;
        scanf("%d", &process);
        int request[resources];
        printf("enter the request : ");
        takearrayinput(resources, request);
        for (i = 0; i < resources; i++)
        {
            flag = 1;
            if (request[i] > max[process][i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            printf("there is a error in request \n");
        }
        else
        {
            flag = 1;
            for (i = 0; i < resources; i++)
            {
                if (request[i] > available[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("the resources are not suffiecient to handle the request .\n");
            }
            else
            {
                for (i = 0; i < resources; i++)
                {
                    available[i] -= request[i];
                    allocated[process][i] += request[i];
                    need[process][i] -= request[i];
                }
                printf("the request is taken and checking :\n");
                safe_search(processes, resources, allocated, available, need);
            }
        }
    }
    return 0;
}