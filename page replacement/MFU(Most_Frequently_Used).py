import numpy as np
q = int(input("enter the size of the queue :"))
n = int(input("enter the number of pages :"))
pages= list(map(int,input("enter the page frames : ").split()))
cache_frames = [-1 for i in range(q)]
frequency = [0 for i in range(q)]
order = [i for i in range(q)]
hit = miss = 0
count = 0
for i in range(n):
    if count<q:
        if pages[i] not in cache_frames:
            cache_frames[count] = pages[i]
            frequency[count] = 1
            count +=1
            print("miss....")
        else:
            for j in range(q):
                if cache_frames[j] == pages[i]:
                    frequency[j] += 1
                    hit += 1
                    print("hit.....")
                    break
    else:
        if pages[i] not in cache_frames:
            min_freq = frequency[0]
            min_order = order[0]
            index = 0
            for j in range(1,q):
                if ((frequency[j] > min_freq) or (frequency[j] == min_freq and order[j] < min_order)):
                    min_freq = frequency[j]
                    min_order = order[j]
                    index = j   
            cache_frames[index] = pages[i]
            frequency[index] = 1
            order[index] = order[q - 1] + 1
            print("miss.....")
        else:
            for j in range(q):
                if cache_frames[j] == pages[i]:
                    frequency[j] += 1
                    hit += 1
                    print("hit....")
                    break
    print(cache_frames)
miss = n-hit
print("number of page hits :",hit)
print("number of page faults :",miss)
print("hit ratio :",hit/n)
        
