/*
��Դ��ţ����
���ӣ�
https://www.nowcoder.com/practice/a632ec91a4524773b8af8694a51109e7
ÿK��һ�鷴ת����
��Ŀ����
����һ������ÿ k ���ڵ�һ����з�ת�������ط�ת�������k ��һ����������
����ֵС�ڻ��������ĳ��ȡ�����ڵ��������� k ������������ô�����ʣ��ڵ㱣��ԭ��˳��

˵����
1. ����Ҫ���ж�������ṹ������������ݱ��浽��������У�
2. �㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
3. ����㷨ֻ��ʹ�ó����Ķ���ռ䡣
��������:
��һ�������������ֵ
�ڶ���������K��ֵ��K�Ǵ��ڻ����1������

������ʽΪ��
1 2 3 4 5
2
�������:
�� k = 2 ʱ��Ӧ�����:
2 1 4 3 5

�� k = 3 ʱ��Ӧ�����:
3 2 1 4 5

��k=6ʱ��Ӧ�������
1 2 3 4 5
ʾ��1
����
����
1 2 3 4 5
2
���
����
2 1 4 3 5
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node
{
    int _val;
    Node* _next;
    Node(int x)
        :_val(x)
        ,_next(nullptr)
    {}
};

Node* createTheList(vector<int> vc)
{
    Node* cur = new Node(vc[0]);
    Node* head = cur;
    
    for(int i = 1; i < vc.size(); ++i)
    {
        cur->_next = new Node(vc[i]);
        cur = cur->_next;
    }
    
    return head;
}
void reverseTheVector(vector<int>& vc, int left, int right, int k)
{
    while(left < vc.size() && right < vc.size())
    {
        reverse(vc.begin() + left, vc.begin() + right + 1);
        left += k;
        right += k;
    }
}
int main()
{
    vector<int> vc;
    int v = 0;
    while(cin >> v)
    {
        vc.push_back(v);
        if(getchar() == '\n')
            break;
    }
    
    int k = 0;
    cin >> k;
    if(k <= vc.size())
        reverseTheVector(vc, 0, k - 1, k);
    
    Node* list = createTheList(vc);
    for(int i = 0; i < vc.size(); ++i)
    {
        cout << list->_val << " ";
        list = list->_next;
    }
    cout << endl;
    
    return 0;
}