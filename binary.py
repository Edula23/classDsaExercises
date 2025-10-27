def binarySearch(arr, x):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1
def binary_insertion_sort(nums):
    for i in range(1, len(nums)):
        key = nums[i]
        left = 0
        right = i -1
        while left <= right:
            mid = left + (right-left)//2
            if nums[mid] > key:
                right = mid-1
            else:
                left = mid + 1
        j = i-1
        while j >= left:
            nums[j+1] = nums[j]
            j -= 1
        nums[left] = key
    print(nums)
binary_insertion_sort([5,2,9,1,5,6])