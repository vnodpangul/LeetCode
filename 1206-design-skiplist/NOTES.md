}
void add(int num) {
insertPoints.clear();
Node *p = head;
while(p) {
while(p->right and p->right->val < num) p = p->right;
insertPoints.push_back(p);
p = p->down;
}
Node* downNode = NULL;
bool insertUp = true;
while(insertUp and insertPoints.size()) {
Node *ins = insertPoints.back();
insertPoints.pop_back();
ins->right = new Node(ins->right, downNode, num);
downNode = ins->right;
insertUp = (rand() & 1) == 0;
}
if(insertUp) {
head = new Node(new Node(NULL, downNode, num), head, 0);
}
}
vector<Node*> insertPoints;
bool erase(int num) {
Node *p = head;
bool seen = false;
while(p) {
while(p->right and p->right->val < num) p = p->right;
if(!p->right or p->right->val > num) p = p->down;
else {
seen = true;
p->right = p->right->right;
p = p->down;
}
}
return seen;
}
};