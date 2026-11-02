import random
import time
import matplotlib.pyplot as plt

sizes = [100, 200, 300, 400, 500]
times = []

for size in sizes:      #This loop takes each value from sizes, one at a time.

    arr = []

    for i in range(size):     #Repeats the loop according to the current value of size.
        arr.append(random.randint(1, 100))   #random.randint(1, 100) generates a random integer between 1 and 100.
                                             #append() adds that number to the array.

    start = time.time()

    n = len(arr)   #calculates no. of elements in array

    for i in range(n):        #Outer loop (i) – controls the number of passes.
        for j in range(n - 1):   #Inner loop (j) – compares adjacent elements.
            if arr[j] > arr[j + 1]:
                temp = arr[j]        #Suppose the values are 5 and 2.,temp = arr[j] → stores 5 temporarily.
                arr[j] = arr[j + 1]  #arr[j] = arr[j + 1] → replaces 5 with 2.
                arr[j + 1] = temp    #arr[j + 1] = temp → puts 5 in the next position.

    end = time.time()  #records the ending time. 

    elapsed = end - start  #calculates the time taken.
    times.append(elapsed)   #stores that time in the times list.

plt.plot(sizes, times, marker='o')
plt.title("Bubble Sort Execution Time")
plt.xlabel("Number of Elements")
plt.ylabel("Time Taken (seconds)")
plt.grid()
plt.show()
