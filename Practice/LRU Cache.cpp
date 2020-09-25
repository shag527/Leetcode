/* Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the 
capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]  */


class doublylist
{
    public:
    int key,val;
    doublylist *left;
    doublylist *right;
    doublylist(int key, int val)
    {
        this->key=key;
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

class LRUCache {
    public:
    int count,cap;
    unordered_map<int,doublylist*>mp;
    doublylist *head=NULL;
    doublylist *tail=NULL;
    LRUCache(int capacity) {
        head=new doublylist(0,0);
        tail=new doublylist(0,0);
        head->right=tail;
        tail->left=head;
        count=0;
        cap=capacity;
    }
    
    void add(int key,int val)
    {
        count++;
        doublylist *temp=new doublylist(key,val);
        mp[key]=temp;
        temp->left=head;
        temp->right=head->right;
        head->right->left=temp;
        head->right=temp;
    }
    
    void del(doublylist *temp)
    {
        count--;
        mp.erase(temp->key);
        temp->left->right=temp->right;
        temp->right->left=temp->left;
        delete temp;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        int val=mp[key]->val;
        del(mp[key]);
        add(key,val);
        return val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            del(mp[key]);
            add(key,value);
        }
        else
        {
            if(count<cap)
                add(key,value);
            else
            {
                del(tail->left);
                add(key,value);
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
