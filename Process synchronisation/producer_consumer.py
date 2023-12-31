import threading
import time

# buffer size
buffer_size = 5
buffer = [-1 for i in range(buffer_size)]
in_index = 0
out_index = 0

# using semaphores

mutex = threading.Semaphore()
empty = threading.Semaphore(buffer_size)
full = threading.Semaphore(0)

# producer thread
class Producer(threading.Thread):
    
    def run(self):
        global in_index,out_index,buffer,buffer_size
        global mutex,empty,full
        
        item_count = 0
        item = 0
        while(item_count < 7):
            item += 1
            empty.acquire()
            mutex.acquire()
            
            buffer[in_index] = item
            in_index = (in_index+1)%buffer_size
            
            print("prodecer produced :",item )
            full.release()
            mutex.release()
            
            item_count += 1
            time.sleep(1)
    
class Consumer(threading.Thread):
    
    def run(self):
        global in_index,out_index,buffer,buffer_size
        global mutex,empty,full
        
        item_consumed = 0
        
        while(item_consumed < 7) :
            full.acquire()
            mutex.acquire()
            
            item = buffer[out_index]
            out_index = (out_index + 1) % buffer_size
            print("consumer consumed item :",item)
            
            empty.release()
            mutex.release()
            
            item_consumed += 1
            time.sleep(2.5)

# threads
producer = Producer()
consumer = Consumer()

# starting threads
producer.start()
consumer.start()

# waiting for threads
producer.join()
consumer.join()