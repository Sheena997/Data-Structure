/*
215. �����еĵ�K�����Ԫ��
��δ������������ҵ��� k ������Ԫ�ء�
��ע�⣬����Ҫ�ҵ������������ĵ� k ��
����Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
ʾ�� 1:
����: [3,2,1,5,6,4] �� k = 2
���: 5
ʾ�� 2:
����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4
˵��:
����Լ��� k ������Ч�ģ��� 1 �� k �� ����ĳ��ȡ�

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
<<<<<<< HEAD
        //����С����
		priority_queue<int, vector<int>, greater<int>> pq;
=======
        priority_queue<int, vector<int>, greater<int>> pq;
>>>>>>> d5090db247ce7a79c76b4ada57f4b2773d4186c7
        
        for(int& e : nums)
        {
            pq.push(e);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};
