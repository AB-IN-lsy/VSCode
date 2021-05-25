def selection_sort(nums):
    for i in range(len(nums)-1, 0, -1):
        nums[i] , nums[nums.index(max(nums[:i+1]))] = nums[nums.index(max(nums[:i+1]))] , nums[i]
        print(nums)
    return nums

def bubble_sort(nums):
    for i in range(len(nums) - 1):  
        for j in range(len(nums) - i - 1):  
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
    return nums

def insertion_sort(nums):
    for i in range(1, len(nums)): 
        for j in range(i, 0, -1):
            if nums[j] < nums[j - 1]:
                nums[j], nums[j - 1] = nums[j - 1], nums[j]  
        print(nums)
    return nums

insertion_sort([9,3,6,5,3])