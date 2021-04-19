# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)
    i = 0
    j = 0
    count = 0
    while nums[i] != nil
        if nums[i] == nums[j]
            j += 1
            count += 1
        elsif
            if count > 2
                (count-2).times do |_|
                    nums.delete_at(i)
                    j -= 1
                end
                i = j
                count = 0
            elsif
                i = j
                count = 0
            end
        end
    end
    return nums.size
end

p remove_duplicates([1,1,1,2,2,2,3,3])