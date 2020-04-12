/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个
排序的双向链表。要求不能创建任何新的结点，只
能调整树中结点指针的指向。

来源：LeetCode
链接：https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
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