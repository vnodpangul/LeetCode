class Skiplist {
    struct Node {
        int val;
        Node *next, *down;
        Node(int v, Node *n=nullptr, Node *d=nullptr):
                        val(v), next(n), down(d) {}
    };
    
    Node *head = nullptr;
public:
    Skiplist() {
        head = new Node (0);
    }
    
    bool search(int target) {
        Node *current = head;
        while(current)
        {
            while(current->next && current->next->val<target) current = current->next;
            if(!current->next || current->next->val > target) current = current->down;
            else {
                return true;
            }
        }
        return false;
    }
    
    vector<Node*> pred;
    void add(int num) {
        pred.clear();
        Node *current = head;
        while(current)
        {
            while(current->next && current->next->val<num) current = current->next;
            pred.push_back(current);
            current = current->down;
        }
        
        bool insert = true;
        Node *down = nullptr;
        while(insert && !pred.empty())
        {
            Node *back = pred.back();
            pred.pop_back();
            back->next = new Node(num, back->next, down);
            down = back->next;
            
            insert = (rand()&1)==0;
        }
        if(insert)
        {
            head = new Node(0, new Node(num, nullptr, down), head);
        }
        
    }
    
    bool erase(int num) {
        Node *current = head;
        bool found = false;
        while(current)
        {
            while(current->next && current->next->val < num) current = current->next;
            if(!current->next || current->next->val > num) current = current->down;
            else {
                found = true;
                Node *tmp = current->next;
                current->next = current->next->next;
                delete tmp;
                current = current->down;
            }
        }
        return found;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */