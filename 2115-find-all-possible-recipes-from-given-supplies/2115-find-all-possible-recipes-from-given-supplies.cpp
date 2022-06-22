class Solution {
    set<string> R, S;
    unordered_map<string, vector<string>> adjList;
    unordered_map<string, int> inD;
    vector<string> res;
public:
    
   vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Create a set of Supplies
        for(auto s: supplies)
            S.insert(s);
       //Mark all Recipes with 0 inDegree
        for(auto r : recipes)
            inD[r] = 0;
       
        for(int i=0; i<recipes.size(); i++) {
            auto recipe = recipes[i];
            cout<<recipe<<endl;
            for(int j=0; j<ingredients[i].size(); j++) {
                auto item = ingredients[i][j];
                if(!S.count(item)) {
                    adjList[item].push_back(recipe);
                    inD[recipe]++;
                }
            }
        }
       
       cout<<"-----\n";
       queue<string> q;
       for(auto item : inD) {
           if(item.second==0) {
               cout<<item.first<<endl;
               q.push(item.first);
           }
       }
       cout<<"-----\n";
       while(!q.empty()) {
           auto r = q.front(); q.pop();
           res.push_back(r);
           for(auto item : adjList[r]) {
                  inD[item]--;
                 cout<<item<<":"<<inD[item]<<endl;
                  if(inD[item]==0) {
                      q.push(item);
                  }
              
           }
       }
       return res;
        
    }
};


/*
// Initial Approach
class Solution {
    set<string> R, S;
    unordered_map<string, int> RtoIdxMap;
    vector<string> res;
    unordered_map<string, bool> memo;
public:
    
    bool DFS(int idx, vector<vector<string>>& Ing, vector<string>& sup, set<string> &visited)
    {
        
        auto ing = Ing[idx];
        bool rc = true;
        for(auto item : ing) {
            // cout<<item<<S.count(item)<<":"<<RtoIdxMap.count(item)<<endl;
            
            if(S.count(item)<=0 && RtoIdxMap.count(item)<=0)
                rc &=false;
            else if(memo.count(item))
                rc &= memo[item];
            else if(S.count(item)<=0 && RtoIdxMap.count(item)>1)  {
                visited.insert(item);
                memo[item] = DFS(RtoIdxMap[item], Ing, sup, visited);
                rc &= memo[item];
            }
        }
        return rc;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(int i=0; i<recipes.size(); i++)
            RtoIdxMap[recipes[i]] = i;
        for(auto s : supplies)
            S.insert(s);

        set<string> visited;
        for(auto r : recipes) {
            // cout<<"Recipe: "<<r<<endl;
            
            if(DFS(RtoIdxMap[r], ingredients, supplies, visited)) {
                res.push_back(r);
            }
            visited.clear();
        }
        return res;
    }
};
*/

/*
recipes = ["bread","sandwich"], 
ingredients = [["yeast","flour"],["bread","meat"]], 
supplies = ["yeast","flour","meat"]

|| RtoIdxMap ||
    bread - 0
    sand  - 1

bread--> ( 0 ) --> ["yeast","flour"]
     --> ingred[0] --> ["yeast","flour"] 
     --> ingred[1] --> ingred[0] --> true, meat
bread--> ( 1 ) --> ["bread","meat"]
            ---> ( 0 ) --> ["yeast","flour"]
     --> ingred[0] --> ["yeast","flour"] 
     --> ingred[1] --> ingred[0] --> true, meat
<bread, 
*/
/*
["ju","fzjnm","x","e","zpmcz","h","q"]

[
 ["d"],
 ["hveml","f","cpivl"],
 ["cpivl","zpmcz","h","e","fzjnm","ju"],
 ["cpivl","hveml","zpmcz","ju","h"],
 ["h","fzjnm","e","q","x"],
 ["d","hveml","cpivl","q","zpmcz","ju","e","x"],
 ["f","hveml","cpivl"]]
Supp: 
["f","hveml","cpivl","d"]
*/
