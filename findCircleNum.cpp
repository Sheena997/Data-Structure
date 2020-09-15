/*
547. ����Ȧ
������ N ��ѧ����������Щ�������ѣ���Щ���ǡ����ǵ���������Ǵ����ԡ�
�����֪ A �� B �����ѣ�B �� C �����ѣ���ô���ǿ�����Ϊ A Ҳ�� C �����ѡ�
��ν������Ȧ����ָ�������ѵļ��ϡ�
����һ�� N * N �ľ��� M����ʾ�༶��ѧ��֮������ѹ�ϵ�����M[i][j] = 1��
��ʾ��֪�� i ���� j ��ѧ����Ϊ���ѹ�ϵ������Ϊ��֪����������������ѧ
���е���֪������Ȧ������

ʾ�� 1��
���룺
[[1,1,0],
 [1,1,0],
 [0,0,1]]
�����2 
���ͣ���֪ѧ�� 0 ��ѧ�� 1 ��Ϊ���ѣ�������һ������Ȧ��
��2��ѧ���Լ���һ������Ȧ�����Է��� 2 ��
ʾ�� 2��

���룺
[[1,1,0],
 [1,1,1],
 [0,1,1]]
�����1
���ͣ���֪ѧ�� 0 ��ѧ�� 1 ��Ϊ���ѣ�ѧ�� 1 ��ѧ�� 2 ��Ϊ���ѣ�
����ѧ�� 0 ��ѧ�� 2 Ҳ�����ѣ���������������һ������Ȧ������ 1 ��

��ʾ��

1 <= N <= 200
M[i][i] == 1
M[i][j] == M[j][i]

��Դ��LeetCode
���ӣ�https://leetcode-cn.com/problems/friend-circles/
*/
//���鼯
class UnionFindSet
{
public:
    UnionFindSet(size_t N)
    {
        _vc.resize(N, -1);
    }
    
    int FindRoot(int x)
    {
        while(_vc[x] >= 0)
            x = _vc[x];
        
        return x;
    }
    
    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);
        
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
    int findCircleNum(vector<vector<int>>& M) {
        UnionFindSet ufs(M.size());
        
        for(size_t i = 0; i < M.size(); ++i)
        {
            for(size_t j = 0; j < M[i].size(); ++j)
            {
                if(i == j)
                    break;
                if(M[i][j] == 1)
                    ufs.Union(i, j);
            }
        }
        
        return ufs.GetTheSize();
    }
};