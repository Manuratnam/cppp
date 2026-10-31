import random
import time
import matplotlib.pyplot as plt

sizes = [100, 200, 300, 400, 500]
times = []

for size in sizes:

    arr = []

    for i in range(size):
        arr.append(random.randint(1, 100))

    start = time.time()

    n = len(arr)

    for i in range(n):
        for j in range(n - 1):
            if arr[j] > arr[j + 1]:
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp

    end = time.time()

    elapsed = end - start
    times.append(elapsed)

plt.plot(sizes, times, marker='o')
plt.title("Bubble Sort Execution Time")
plt.xlabel("Number of Elements")
plt.ylabel("Time Taken (seconds)")
plt.grid()
plt.show()
