import threading
import time

phil_count = int(input("enter number of philosophers :"))
ch_sticks = [threading.Semaphore(1) for i in range(phil_count)]

class Philoshopher(threading.Thread):
    def __init__(self,phil_id):
        super().__init__()
        self.phil_id = phil_id
    
    def run(self):
        for i in range(2): # each one eats 3 times
            self.think()
            self.eat()
    
    def think(self):
        print(f"philosopher {self.phil_id} is thinking")
        time.sleep(5)
    
    def eat(self):
        left_ch = ch_sticks[self.phil_id]
        right_ch = ch_sticks[(self.phil_id + 1)%phil_count]
        
        left_ch.acquire()
        right_ch.acquire()
        #eating
        print(f"philosopher {self.phil_id} starts eating.")
        time.sleep(4)
        print(f"philosopher {self.phil_id} completed eating.")
        left_ch.release()
        right_ch.release()

philosophers = [Philoshopher(i) for i in range(phil_count)]

for philosopher in philosophers:
    philosopher.start()
    
for philoshopher in philosophers :
    philosopher.join()
        