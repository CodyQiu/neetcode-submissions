class LRUCache {
private:
    struct Node{
        int val;
        int keyy;
        Node* prev;
        Node* next;

        Node() {
            next = nullptr;
            prev = nullptr;
        }
    };
    int _capacity;
    int _size;
    Node* _head;
    Node* _curr;
    unordered_map<int, Node*> findNode;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        _curr = nullptr;
        _head = nullptr;
    }
    
    int get(int key) {
        if (findNode.find(key) == findNode.end()) return -1;

        int final = findNode[key]->val;
        Node* temp = findNode[key];
        if (_curr == temp) return final;
        if (_head == temp) _head = temp->next;
        if (temp->prev != nullptr) temp->prev->next = temp->next;
        if (temp->next != nullptr) temp->next->prev = temp->prev;
        _curr->next = temp;
        temp->prev = _curr;
        _curr = temp;
        _curr->next = nullptr;

        return final;
    }
    
    void put(int key, int value) {
        if (findNode.find(key) != findNode.end()) {
            findNode[key]->val = value;
            Node* temp = findNode[key];
            if (_curr == temp) return;
            if (_head == temp) _head = temp->next;
            if (temp->prev != nullptr) temp->prev->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = temp->prev;
            _curr->next = temp;
            temp->prev = _curr;
            _curr = temp;
            _curr->next = nullptr;
            return;
        }
        if (_size == _capacity) {
            Node* temp = _head->next;
            if (temp != nullptr) {
                _head->next->prev = _head->prev;
            }
            findNode.erase(_head->keyy);
            delete _head;
            _head = temp;
            _size--;
        }


        Node* temp = new Node;
        temp->keyy = key;
        temp->val = value;
        findNode[key] = temp;
        if (_size == 0) {
            _head = temp;
            _curr = temp;
        }
        else {
            _curr->next = temp;
            temp->prev = _curr;
            _curr = _curr->next;
        }
        _size++;
    }
};
