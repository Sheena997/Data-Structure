/*
来源：牛客网
链接：
https://www.nowcoder.com/practice/a632ec91a4524773b8af8694a51109e7
每K个一组反转链表
题目描述
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。k 是一个正整数，
它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

说明：
1. 你需要自行定义链表结构，将输入的数据保存到你的链表中；
2. 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换；
3. 你的算法只能使用常数的额外空间。
输入描述:
第一行输入是链表的值
第二行输入是K的值，K是大于或等于1的整数

输入形式为：
1 2 3 4 5
2
输出描述:
当 k = 2 时，应当输出:
2 1 4 3 5

当 k = 3 时，应当输出:
3 2 1 4 5

当k=6时，应当输出：
1 2 3 4 5
示例1
输入
复制
1 2 3 4 5
2
输出
复制
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