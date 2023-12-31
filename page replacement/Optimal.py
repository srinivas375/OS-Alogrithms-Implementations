import numpy as np

def find(i,page,n):
    global pages
    for j in range(i+1,n):
        if page == pages[j]:
            return j
    return 9999
    
q = int(input("enter size of the queue :"))
n = int(input("enter the number of pages :"))
print("enter the pages :")
data = input().split()
pages = list(map(int,data))
queue = []
count = []
hit = 0
miss = None
for i in range(n):
    if len(queue)<q:
        if pages[i] not in queue:
            queue.append(pages[i])
            count.append(find(i,pages[i],n))
        else:
            for j in range(q):
                if queue[j] == pages[i]:
                    break
            count[j] = find(i,pages[i],n)
            hit += 1
    else:
        if pages[i] not in queue:
            j = np.argmax(count)
            queue[j] = pages[i]
            count[j] = find(i,pages[i],n)   
        else:
            for j in range(q):
                if queue[j] == pages[i]:
                    break
            count[j] = find(i,pages[i],n)
            hit += 1
    print(queue)
miss = n-hit
print("number of hits are :",hit)
print("number of page faults are :",miss)
print("hit ratio is :",hit/n)
            

