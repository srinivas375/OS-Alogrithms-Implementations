import threading
import time

mutex = threading.Semaphore()
write = threading.Semaphore(1)
read_count = 0
class Reader(threading.Thread):
    def __init__(self,name):
        super().__init__()
        self.name = name
    def run(self):
        global read_count
        mutex.acquire()
        read_count += 1
        if (read_count == 1):
            write.acquire()
        mutex.release()
        #processes can read the file
        print(f"process {self.name} start reading.")
        time.sleep(3)
        print(f"process {self.name} completes reading.")
        mutex.acquire()
        read_count -= 1
        if read_count == 0 :
            write.release()
        mutex.release()

class Writer(threading.Thread):
    def __init__(self,name):
        super().__init__()
        self.name = name
    def run(self):
        write.acquire()
        print(f"process {self.name} starts writing.")
        time.sleep(6)
        print(f"process {self.name} completes writing.")
        write.release()

rr_couont = int(input("enter the reader writer count :"))
print("1.readers are '0'\n2.writers are '1'")
print("enter the readers and writers")
rr = list(map(int,input().split()))


for val in range(rr_couont) :
    if (rr[val] == 0):
        Reader(val+1).start()
    else :
        Writer(val+1).start()