head_pos = int(input("Enter the head position :"))
data = input("Enter the disk partitions seperated by spaces : ")
print("the head moments are : \n")
partitions = list(map(int,data.split()))
disk_moments = 0
flag = []
for i in range(len(partitions)):
    flag.append(0)
for i in range(len(partitions)):
    min = 9999
    index = 0
    for j in range(len(partitions)):
        if (flag[j] == 0):
            val = abs(head_pos - partitions[j])
            if (val < min):
                min = val
                index = j
    disk_moments += min
    print(head_pos ,end ="  ")
    head_pos = partitions[index]
    flag[index] = 1
print("\nthe track moments : ",disk_moments)
        
        
    