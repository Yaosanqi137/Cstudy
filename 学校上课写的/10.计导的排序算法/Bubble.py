import random
from time import time

def bubbleSort(array):
    for n in range(0, len(array) - 1):
        for j in range(0, len(array) - n - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

if __name__ == '__main__':
    length = int(input("请问你想要生成多长的数组:"))
    arr = []
    for i in range(length):
        arr.append(random.randint(-10000, 10000))
    start = time()
    bubbleSort(arr)
    end = time()
    print(f"排序完成,耗时:{end - start}s")