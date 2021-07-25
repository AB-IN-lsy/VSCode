def bubble_sort(nums,index):
    for i in range(len(nums) - 1):  
        for j in range(len(nums) - i - 1):  
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
                if j == index:
                    return nums
    return nums
 
print(bubble_sort([54, 26, 93, 17, 77, 20]))