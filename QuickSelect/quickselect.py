def quickselect(arr, k):
    if not arr:
        return None
    if k < 0 or k >= len(arr):
        return None
    return quickselect_helper(arr, 0, len(arr) - 1, k)

def quickselect_helper(arr, left, right, k):
    if left == right:
        return arr[left]
    pivot_index = partition(arr, left, right)
    if k == pivot_index:
        return arr[k]
    elif k < pivot_index:
        return quickselect_helper(arr, left, pivot_index - 1, k)
    else:
        return quickselect_helper(arr, pivot_index + 1, right, k)

def partition(arr, left, right):
    pivot = arr[left]
    i, j = left, right
    while i < j:
        while i < j and arr[j] >= pivot:
            j -= 1
        arr[i] = arr[j]
        while i < j and arr[i] <= pivot:
            i += 1
        arr[j] = arr[i]
    
