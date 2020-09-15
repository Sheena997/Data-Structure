/*
990. ��ʽ���̵Ŀ�������
����һ���ɱ�ʾ����֮���ϵ���ַ���������ɵ����飬ÿ���ַ�
������ equations[i] �ĳ���Ϊ 4�����������ֲ�ͬ����ʽ֮һ��
"a==b" �� "a!=b"�������a �� b ��Сд��ĸ����һ����ͬ����
��ʾ����ĸ��������
ֻ�е����Խ�������������������Ա��������и����ķ���ʱ�ŷ��� true��
���򷵻� false��  

ʾ�� 1��

���룺["a==b","b!=a"]
�����false
���ͣ��������ָ����a = 1 �� b = 1����ô���������һ�����̣����޷�
����ڶ������̡�û�а취�������ͬʱ�������������̡�

ʾ�� 2��
���룺["b==a","a==b"]
�����true
���ͣ����ǿ���ָ�� a = 1 �� b = 1 �������������������̡�

ʾ�� 3��
���룺["a==b","b==c","a==c"]
�����true

ʾ�� 4��
���룺["a==b","b!=c","c==a"]
�����false

ʾ�� 5��
���룺["c==c","b==d","x!=z"]
�����true
 

��ʾ��
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] �� equations[i][3] ��Сд��ĸ
equations[i][1] Ҫô�� '='��Ҫô�� '!'
equations[i][2] �� '='

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
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