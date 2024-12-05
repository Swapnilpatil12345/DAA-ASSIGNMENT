import threading
import time
import random

def perform_task(id,task):
    print(f"philosopher {id} is {task}ing...")
    time.sleep(random.randint(0,2))

def manage_forks(philosopher_id, action, left_fork, right_fork, forks):
    if(action == "acquire"):
        if(philosopher_id%2==0): #even philosopher
            forks[left_fork].acquire()
            forks[right_fork].acquire()
        else:
            forks[right_fork].acquire()
            forks[left_fork].acquire()
    elif(action=="release"):
        forks[left_fork].release()
        forks[right_fork].release()

    print(f"philosopher {philosopher_id} {action}'d the forks.")

def philosopher_life(philosopher_id,toal_philosophers,forks):
    left_fork = philosopher_id
    right_fork = (philosopher_id+1)%toal_philosophers

    while(True):
        perform_task(philosopher_id, "think")
        manage_forks(philosopher_id,"acquire", left_fork , right_fork,forks)
        perform_task(philosopher_id, "eat")
        manage_forks(philosopher_id,"release", left_fork, right_fork,forks)
        

#number of philosophers 
num_philosophers = 5

forks = [threading.Lock() for i in range(num_philosophers)]

philosophers = []

for i in range(num_philosophers):
    philosopher = threading.Thread(target=philosopher_life , args=(i,num_philosophers,forks))
    philosophers.append(philosopher)
    philosopher.start()

for philospher in philosophers:
    philosopher.join()
