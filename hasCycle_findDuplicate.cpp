/*
287. Ѱ���ظ���
����һ������ n + 1 ������������ nums�������ֶ��� 1 �� n ֮�䣨���� 1 �� n����
��֪���ٴ���һ���ظ�������������ֻ��һ���ظ����������ҳ�����ظ�������
ʾ�� 1:
����: [1,3,4,2,2]
���: 2
ʾ�� 2:
����: [3,1,3,4,2]
���: 3
˵����
���ܸ���ԭ���飨����������ֻ���ģ���
ֻ��ʹ�ö���� O(1) �Ŀռ䡣
ʱ�临�Ӷ�С�� O(n2) ��
������ֻ��һ���ظ������֣��������ܲ�ֹ�ظ�����һ�Ρ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/find-the-duplicate-number/
*/
/*
�����鿴������val�ǽ��ֵҲ���¸��ڵ�ĵ�ַ��
����������Ϳ���ת�����ж������л������ҳ���
�ڽڵ�---ʹ�ÿ���ָ��
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