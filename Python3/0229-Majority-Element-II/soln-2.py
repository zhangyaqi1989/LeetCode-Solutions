class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cnt1, cnt2 = 0, 0
        num1, num2 = None, None
        for num in nums:
            if num1 == num:
                cnt1 += 1
            elif num2 == num:
                cnt2 += 1
            elif cnt1 == 0:
                num1 = num
                cnt1 = 1
            elif cnt2 == 0:
                num2 = num
                cnt2 = 1
            else:
                cnt1 -= 1
                cnt2 -= 1
        ans = []
        if nums.count(num1) > len(nums) // 3:
            ans.append(num1)
        if nums.count(num2) > len(nums) // 3:
            ans.append(num2)
        return ans
