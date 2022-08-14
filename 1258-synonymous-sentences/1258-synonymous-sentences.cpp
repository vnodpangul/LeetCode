class Solution {
    unordered_map<string, vector<string>> adjList;
    vector<string> res;
    set<string> seen;
public:
    
    vector<string> getTokens(string text)
    {
         vector<string> tokens;
        stringstream iss(text); string token="";
        while(getline(iss, token, ' ')) 
        {
            if(token.size()==0) continue;
            tokens.push_back(token);
        }
        return tokens;
    }
    
    string formString(vector<string> tokens) {
        string res = tokens[0];
        for(int i=1; i<tokens.size(); i++)
            res += " " + tokens[i];
        return res;
    }
    
    void helper(string text)
    {
        queue<string> q;
        q.push(text);
        while(!q.empty())
        {
            auto str = q.front(); q.pop();
            seen.insert(str);
            
            vector<string> tokens = getTokens(str);
            for(int i=0; i<tokens.size(); i++)
            {
                if(adjList.find(tokens[i]) == adjList.end()) continue;
                for(auto w : adjList[tokens[i]]) {
                    tokens[i] = w;
                    string newText = formString(tokens);
                    if(seen.count(newText)==0) q.push(newText);
                }
            }
        }
        
        
    }
    
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for(auto entry : synonyms)
        {
            string word1 = entry[0], word2 = entry[1];
            adjList[word1].push_back(word2);
            adjList[word2].push_back(word1);
        }

        helper(text);
        for(auto e: seen) res.push_back(e);
        return res;
    }
};

// synonyms = [["happy","joy"],
//             ["sad","sorrow"],
//             ["joy","cheerful"]], 
// text = "I am happy today but was sad yesterday"
    

// happy --> joy 
// joy   --> cheerful
// sad   --> cheerful

