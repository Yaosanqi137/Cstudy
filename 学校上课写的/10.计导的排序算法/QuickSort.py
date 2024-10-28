import random
from time import time

def quickSort(array, left, right):
    if left >= right:
        return # 确认是左比右小，否则退出函数，即排序完成
    key, begin, stop = array[left], left, right
    while left < right :
        while left < right and array[right] >= key:
            right -= 1
        array[left] = array[right]
        while left < right and array[left] <= key:
            left += 1
        array[right] = array[left]
    # 分组
    array[left] = key
    # 归还 key 值
    quickSort(array, begin, left - 1)
    quickSort(array, left + 1, stop)
    # 左右分别递归

if __name__ == '__main__':
    length = int(input("请问你想要生成多长的数组:"))
    arr = []
    for i in range(length):
        arr.append(random.randint(-100000, 100000))
    start = time()
    quickSort(arr, 0, len(arr) - 1)
    end = time()
    print(f"排序完成,耗时:{end - start}s")