/******** time complexity O(n *l logl)********/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>vs;
        unordered_map<string,int>h;
        int k =0;
        for(int i =0;i<strs.size();i++) //create a map with sorted string and index for vector and push it accordingly 
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(h.find(temp)==h.end())
            {
                h[temp] = k++;
                vs.push_back({}); // create a new vector inside vector of strings
            }
             int j = h[temp];
             vs[j].push_back(strs[i]);
        }
        return vs;
        
    }
};
/*****optimized method O(n*l)********/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>vs;
        unordered_map<double,int>h;
        int k =0;
        for(int i =0;i<strs.size();i++) //get hash value and check if it is present not push to the same anagram group
        {
         
            double val = gethash(strs[i]);
            if(h.find(val)==h.end())
            {
                h[val] = k++;
                vs.push_back({}); // create a new vector inside vector of strings
            }
             int j = h[val];
             vs[j].push_back(strs[i]);
        }
        return vs;
        
    }

     private:
     double gethash(string str) // insted of sorting create unique valuenfor each string using prime numbers(these are multipicatively unique)
     {
        int prime[26]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
                          41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        double h  = 1;
        for(char s :str)
        {
            h *=prime[s-'a'];
        } 
        return h;                 
     }   
};   
    
 