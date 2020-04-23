/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
示例 1:
输入: [1,3,4,2,2]
输出: 2
示例 2:
输入: [3,1,3,4,2]
输出: 3
说明：
不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。

来源：LeetCode
链接：https://leetcode-cn.com/problems/find-the-duplicate-number/
*/
/*
将数组看成链表，val是结点值也是下个节点的地址。
因此这个问题就可以转换成判断链表有环，且找出入
口节点---使用快慢指针
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        int res = 0;
        while(1)
        {
            res = nums[res];
            slow = nums[slow];
            if(res == slow)
                break;
        }
        
        return res;
    }
};