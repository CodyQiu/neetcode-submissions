class LRUCache {
public:
    int cap;
    int size = 0;
    vector<int> lru;
    struct ListNode {
       int val;
       int key;
       ListNode *next;
       ListNode *prev;
       ListNode() : val(0), prev(nullptr), next(nullptr) {}
       ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, ListNode*> kp;
    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) {
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attachToEnd(ListNode* node) {
        node->prev = tail->prev;
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }
    
    int get(int key) {
        if (!kp.contains(key)) return -1;
        removeNode(kp[key]);
        attachToEnd(kp[key]);
        return kp[key]->val;
    }
    
    void put(int key, int value) {
        if (kp.contains(key)) {
            removeNode(kp[key]);
            attachToEnd(kp[key]);
            kp[key]->val = value;
            return;
        }
        if (size + 1 <= cap) {
            ListNode* news = new ListNode(value);
            news->key = key;
            kp[key] = news;
            attachToEnd(news);
            size++;
        } else {
            kp.erase(head->next->key);
            removeNode(head->next);

            ListNode* news = new ListNode(value);
            news->key = key;
            kp[key] = news;
            attachToEnd(news);
        }
    }
};
