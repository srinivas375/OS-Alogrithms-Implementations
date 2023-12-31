page = list(map(int,input("enter pages :").split()))
q = int(input("enter the mm size :"))
hit = miss = 0
count = -1
queue = []
for i in range(len(page)):
    if len(queue) < q:
        if page[i] not in queue:
            queue.append(page[i])
            print('miss...')
            count +=1
        else :
            hit +=1
            print('hit...')
    else :
        if page[i] not in queue:
            count = (count+1)%len(queue)
            queue[count] = page[i]
            print("miss...")
        else:
            hit += 1
            print("hit...")
    print(queue)
            
miss = len(page)-hit
print("number of page hits :",hit)
print("number of page faults :",miss)
print("hit ratio :",hit/len(page))
                    
