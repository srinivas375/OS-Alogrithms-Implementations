data = input("enter the memory partitions separated by spaces :")
memory_partitions = list(map(int,data.split()))
data = input("enter the processes seperated by spaces :")
processes = list(map(int,data.split()))
n = len(memory_partitions)
flag = []
result = []
for i in range(n):
    flag.append(0)
    result.append(-1)
for i in range(len(processes)):
    index = -1
    max = 99999
    for j in range(len(memory_partitions)):
        if (flag[j] == 0 and memory_partitions[j] >= processes[i] and memory_partitions[j] < max):
            max = memory_partitions[j]
            index = j
    if (index != -1):
        memory_partitions[index] -= processes[i]
        result[index] = processes[i]
        flag[index] = 1
    
print("the processes that are allocated are :\n",result)
print("the remaining spaces in memory paritions are :\n",memory_partitions)
            