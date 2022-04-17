class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.push_back(Node(row1,col1,row2,col2, newValue));
    }
    
    int getValue(int row, int col) {
        for(int i=history.size()-1; i>=0; i--) {
            Node n = history[i];
            if(row>=n.x1 && col >=n.y1 && row<=n.x2 && col<=n.y2) {
                return n.val;
            }
           
        }
         return rect[row][col];
    }
    private:
    struct Node {
        int x1,y1,x2,y2;
        int val;
        Node (int _x1, int _y1, int _x2, int _y2, int _val) : x1(_x1), y1(_y1), x2(_x2), y2(_y2), val(_val) {}; 
    };
    vector<vector<int>> rect;
    vector<Node> history;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
