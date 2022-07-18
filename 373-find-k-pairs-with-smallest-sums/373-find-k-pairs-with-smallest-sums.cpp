class Solution {
    struct Node {
      int n1, n2, idx;
      Node(int _n1, int _n2, int _idx): n1(_n1), n2(_n2), idx(_idx) {}
    };
    struct comp {
      bool operator()(const Node &lh, const Node &rh)
      {
          return (lh.n1+lh.n2) > (rh.n1+rh.n2);
      }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k==0) return res;
        
        priority_queue<Node, vector<Node>, comp> minHeap;
        for(int i=0; i<nums1.size(); i++)
        {
            minHeap.push(Node(nums1[i], nums2[0], 0));
        }
        
        while(k>0 && !minHeap.empty())
        {
            auto node = minHeap.top(); minHeap.pop();
            res.push_back({node.n1, node.n2});
            k--;
            
            if(node.idx==nums2.size()-1) continue; // End to iterate over next elements;
            
            
            minHeap.push( Node(node.n1, nums2[node.idx+1], node.idx+1) );
           
        }
        
        return res;
        
    }
};