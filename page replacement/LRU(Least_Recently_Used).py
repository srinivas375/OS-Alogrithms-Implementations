import numpy as np
q = int(input("enter the size of the queue :"))
n = int(input("enter the number of pages :"))
hit = 0
miss = None
queue = []
counts = []
count = 0
for i in range(n):
    print("enter the pageframe {} :".format(i+1),end =" ")
    page = int(input())
    if len(queue)<q:
        if page not in queue:
            queue.append(page)
            count +=1
            counts.append(count)
            print("miss....")
        else:
            for j in range(q):
                if queue[j] == page:
                    count+=1
                    counts[j] = count
                    hit += 1
                    print("hit.....")
                    break
    else:
        if page not in queue:
            j = np.argmin(counts)
            count +=1
            queue[j] = page
            counts[j] = count
            print("miss.....")
        else:
            for j in range(q):
                if queue[j] == page:
                    count+=1
                    counts[j] = count
                    hit += 1
                    print("hit.....")
                    break
    print(queue)
miss = n-hit
print("number of page hits :",hit)
print("number of page faults :",miss)
print("hit ratio :",hit/n)
        
