class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);// convert string into vector of words
        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size())//  if size is not equal return zero
            return false;
        unordered_map<char,string>h;
        unordered_set<string>st;
        for(int i =0;i<pattern.size();i++) // use same logic as isomorphic one map and one hashset 
        {
            if(h.find(pattern[i])!=h.end())
            {
                if(h[pattern[i]]!=words[i])
                 return false;
            }
            else
            {
                if(st.count(words[i]))
                 return false;
                h[pattern[i]]=words[i];
                st.insert(words[i]); 
            }
        }
        return true;
    }
};
