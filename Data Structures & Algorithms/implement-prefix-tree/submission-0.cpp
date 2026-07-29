class PrefixTree {
public:

    struct Node {
        char val;
        unordered_map<char, Node*> next;
        Node(): next() {}
        Node(char c): val(c), next() {}
    };
    Node* start;
    unordered_set<Node*> valid;
    PrefixTree() {
        start = new Node();
    }
    
    void insert(string word) {
        Node* curr = start;
        for (char c: word) {
            if (!curr->next.contains(c)) {
                Node* temp = new Node(c);
                curr->next[c] = temp;
                curr = temp;
            } else curr = curr->next[c];
        }
        valid.insert(curr);
    }
    
    bool search(string word) {
        Node* curr = start;
        for (char c: word) {
            if (curr->next.contains(c)) curr = curr->next[c];
            else return false;
        }
        if (valid.contains(curr)) return true;
        else return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = start;

        for (char c: prefix) {
            if (curr->next.contains(c)) curr = curr->next[c];
            else return false;
        }
        return true;
    }
};
