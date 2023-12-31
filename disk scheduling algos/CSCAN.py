ranges = list(map(int,input("enter the range of the disk track (seperated by spaces): ").split()))
head = int(input("enter the head position :"))
requests = list(map(int,input("enter the disk partitions seperated by spaces : ").split()))
print("'1' for right direction.\n'0' for left direction.\n")
dir = int(input("enter the direction of head to be moved : "))
requests.sort()

i = 0
while(head >= requests[i]):
    index = i 
    i += 1

track_moments = 0
if (dir ==1):
    print("the head moment directions are :")
    
    for i in range(index+1,len(requests)):
        track_moments += abs(head - requests[i])
        print(requests[i] ,end ="  ")
        head = requests[i]
        
    track_moments += (ranges[1] - head)
    print(ranges[1], end = "  ")
    track_moments += (ranges[1] - ranges[0])
    head = ranges[0]
    print(head, end = "  ")
    
    for i in range(0,index+1):
        track_moments += abs(head - requests[i])
        print(requests[i],end = "  ")
        head = requests[i]
        
elif (dir == 0):
    print("the head moment directions are :")
    
    for i in range(index,-1,-1):
        print(requests[i], end = "  ")
        track_moments += abs(head - requests[i])
        head = requests[i]
        
    track_moments += abs(head - ranges[0])
    print(ranges[0] ,end = "  ")
    track_moments += abs(ranges[1] - ranges[0])
    head = ranges[1]
    print(head, end = "  ")
    
    for i in range(len(requests)-1,index,-1):
        print(requests[i],end = "  ")
        track_moments += abs(head - requests[i])
        head = requests[i]
        
print("\nthe track moments :",track_moments)