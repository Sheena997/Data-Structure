/*
655. 输出二叉树
在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：

行数 m 应当等于给定二叉树的高度。
列数 n 应当总是奇数。
根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。
根节点所在的行与列会将剩余空间划分为两部分（左下部分和右下部分）。
你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部
分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的
子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果
两个子树都为空则不需要为它们留出任何空间。
每个未使用的空间应包含一个空的字符串""。
使用相同的规则输出子树。
示例 1:

输入:
     1
    /
   2
输出:
[["", "1", ""],
 ["2", "", ""]]
示例 2:

输入:
     1
    / \
   2   3
    \
     4
输出:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
示例 3:

输入:
      1
     / \
    2   5
   / 
  3 
 / 
4 
输出:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
注意: 二叉树的高度在范围 [1, 10] 中。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getTheDepth(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int leftLen = getTheDepth(root->left);
        int rightLen = getTheDepth(root->right);
        
        return 1 + ((leftLen > rightLen) ? leftLen : rightLen);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == nullptr)
            return {};
        int depth = getTheDepth(root), length = 1;
        for(int i = 1; i < depth; ++i)
            length = 1 + (length << 1);
        
        vector<vector<string>> res(depth, vector<string>(length, ""));
        
        queue<pair<TreeNode*, int>> q;
        int len = length/2;
        q.push(make_pair(root, len));
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();
            len /= 2;
            while(size--)
            {
                auto kv = q.front();
                q.pop();
                TreeNode* cur = kv.first;
                int index = kv.second;
                res[level][index] = to_string(cur->val);
                if(cur->left)
                    q.push(make_pair(cur->left, index - len - 1));
                if(cur->right)
                    q.push(make_pair(cur->right, index + len + 1));
            }
            ++level;
        }
        
        return res;
    }
};