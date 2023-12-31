head_pos = int(input("Enter the head position :"))
data = input("Enter the disk partitions seperated by spaces : ")
print("the head moments are : ")
partitions = list(map(int,data.split()))
disk_moments = 0
for i in partitions:
    if head_pos <= i:
        disk_moments += (i - head_pos)
    else :
        disk_moments += (head_pos - i)
    print(head_pos ,end = "  ")
    head_pos = i
print(head_pos)
print("total overhead moments is : ",disk_moments)