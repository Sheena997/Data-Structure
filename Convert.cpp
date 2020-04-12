/*
��Ŀ����
����һ�ö��������������ö���������ת����һ��
�����˫������Ҫ���ܴ����κ��µĽ�㣬ֻ
�ܵ������н��ָ���ָ��

��Դ��LeetCode
���ӣ�https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void _Convert(TreeNode* cur, TreeNode*& prev)
    {
        if(cur == nullptr)
            return;
        
        _Convert(cur -> left, prev);
        
        if(prev)
        {
            prev -> right = cur;
            cur -> left = prev;
        }
        prev = cur;
        
        _Convert(cur -> right, prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        
        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);
        
        TreeNode* head = pRootOfTree;
        while(head -> left)
        {
            head = head -> left;
        }
        
        return head;
    }
};