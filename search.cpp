/*
二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(left <= right && nums[mid] < target)
                left = mid + 1;
            else if(left <= right && nums[mid] > target)
                right = mid - 1;
            else if(target == nums[mid])
                return mid;        
        }
        return -1;
    }
};
