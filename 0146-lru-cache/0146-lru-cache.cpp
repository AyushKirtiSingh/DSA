class LRUCache {
public:
    class Node {       //Overall Time Complexity : O(1)
    public:
        Node* next;
        Node* prev;
        int key,val;

        Node(int k, int v){
            key = k;
            val = v;
            next = prev = NULL;
        }    
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    void addnode(Node* newnode){    //O(1)
        Node* oldnext = head->next;
        head->next = newnode;
        oldnext->prev = newnode;
        newnode->next = oldnext;
        newnode->prev = head;
    }

    void delnode(Node* oldnode){    //O(1)
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    unordered_map<int,Node*> m;
    int limit = 0;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {   //O(1)
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansnode = m[key];
        int ans = ansnode->val;

        delnode(ansnode);
        m.erase(key);
        addnode(ansnode);
        m[key] = ansnode;

        return ans;
    }
    
    void put(int key, int value) {    //O(1)
        if(m.find(key) != m.end()){
            Node* oldnode = m[key];
            delnode(oldnode);
            m.erase(key);
        }

        if(m.size()==limit){
            //delete LRU data
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }

        Node* newnode = new Node(key,value);
        addnode(newnode);
        m[key] = newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */