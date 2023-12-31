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
    for j in range(len(memory_partitions)):
        if (flag[j] == 0 and memory_partitions[j] >= processes[i]):
            memory_partitions[j] -= processes[i]
            result[j] = processes[i]
            flag[j] = 1
            break
print("the processes that are allocated are :\n",result)
print("the remaining spaces in memory paritions are :\n",memory_partitions)
            