def partion(arr, low, high):
    pivot = arr[low]
    i = low
    j = high

    while i < j:
        while arr[i] <= pivot and i <= high - 1:
            i += 1
        
        while arr[j] > pivot and j >= low:
            j -= 1

        
        if i < j:
           temp = arr[i]
           arr[i] = arr[j]
           arr[j] = temp
        

    temp = arr[j]
    arr[j] = arr[low]
    arr[low] = temp

    return j
        

def quickSort(arr, low, high):
    if low < high:
        pivot = partion(arr, low, high)
        quickSort(arr, low, pivot - 1)
        quickSort(arr, pivot + 1, high)


arr = [80, 70, 40, 50, 90, 92]
size = len(arr)
quickSort(arr, 0, size - 1)
print(arr)

cnt = 0
i = size - 1
while cnt < 5:
    print(arr[i])
    i -= 1
    cnt += 1
