/*
面试题 16.25. LRU缓存
设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。
缓存应该从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时
指定最大容量。当缓存被填满时，它应该删除最近最少使用的项目。
它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，
它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

来源：LeetCode
链接：https://leetcode-cn.com/problems/lru-cache-lcci/
*/
class LRUCache {
public:
    LRUCache(int capacity) 
        :_capacity(capacity)
    {}
    
    int get(int key) {
        auto ht_it = _ht.find(key);
        if(ht_it == _ht.end())
        {
            //没有找到
            return -1;
        }
        else
        {
            //找到了，要将其变成第一个
            auto lt_it = ht_it->second;
            pair<int, int> kv = *(lt_it);
            
            _lru_lst.erase(lt_it);
            _lru_lst.push_front(kv);
            _ht[key] = _lru_lst.begin();
            
            return kv.second;
        }
    }
    
    void put(int key, int value) {
        auto ht_it = _ht.find(key);
        if(ht_it == _ht.end())
        {
            //不在，则插入
            //满了，则删掉最近最少未使用的
            if(_lru_lst.size() == _capacity)
            {
                _ht.erase(_lru_lst.back().first);
                _lru_lst.pop_back();
            }
            //插入数据
            _lru_lst.push_front(make_pair(key, value));
            _ht[key] = _lru_lst.begin();
        }
        else
        {
            //在，则更新
            _lru_lst.erase(ht_it->second);
            _lru_lst.push_front(make_pair(key, value));
            _ht[key] = _lru_lst.begin();
        }
    }
    
private:
    list<pair<int, int>> _lru_lst;
    unordered_map<int, list<pair<int, int>>::iterator> _ht;
    int _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */