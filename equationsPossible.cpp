/*
990. 等式方程的可满足性
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符
串方程 equations[i] 的长度为 4，并采用两种不同的形式之一：
"a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），
表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，
否则返回 false。  

示例 1：

输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法
满足第二个方程。没有办法分配变量同时满足这两个方程。

示例 2：
输入：["b==a","a==b"]
输出：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

示例 3：
输入：["a==b","b==c","a==c"]
输出：true

示例 4：
输入：["a==b","b!=c","c==a"]
输出：false

示例 5：
输入：["c==c","b==d","x!=z"]
输出：true
 

提示：
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='

来源：LeetCode
链接：https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
*/
class UnionFindSet
{
public:
    UnionFindSet(size_t N)
    {
        _vc.resize(N, -1);
    }
    
    int FindTheRoot(int x)
    {
        while(_vc[x] >= 0)
            x = _vc[x];
        
        return x;
    }
    
    void Union(int x1, int x2)
    {
        int root1 = FindTheRoot(x1);
        int root2 = FindTheRoot(x2);
        
        if(root1 != root2)
        {
            _vc[root1] += _vc[root2];
            _vc[root2] = root1;
        }
    }
    
    size_t GetTheSize()
    {
        size_t n = 0;
        for(auto e : _vc)
        {
            if(e < 0)
                ++n;
        }
        
        return n;
    }
private:
    vector<int> _vc;
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFindSet ufs(26);
        
        for(auto& str : equations)
        {
            if(str[1] == '=')
            {
                char ch1 = str[0];
                char ch2 = str[3];
                
                ufs.Union(ch1 - 'a', ch2 - 'a');
            }
        }
        
        for(auto& str : equations)
        {
            if(str[1] == '!')
            {
                char ch1 = str[0];
                char ch2 = str[3];
                
                int root1 = ufs.FindTheRoot(ch1 - 'a');
                int root2 = ufs.FindTheRoot(ch2 - 'a');
                
                if(root1 == root2)
                    return false;
            }
        }
        
        return true;
    }
};