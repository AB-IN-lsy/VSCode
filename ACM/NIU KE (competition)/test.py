def my_selection_sort(data):
    for index in range(len(data)-1, 0, -1):
        tmp = data[data.index(max(data[:index+1]))]
        data[index] , tmp = tmp , data[index]

def bubble_sort(nums,index):
    for i in range(len(nums) - 1):  
        for j in range(len(nums) - i - 1):  
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
    return nums
