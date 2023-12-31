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
    
    for i in range(len(requests)-1,index,-1):
        print(requests[i],end = "  ")
        track_moments += abs(head - requests[i])
        head = requests[i]
        
print("\nthe track moments :",track_moments)