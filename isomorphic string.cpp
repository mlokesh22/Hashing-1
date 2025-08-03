class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
        return false;
        unordered_map<char,char>h;
        unordered_set<char>st;
        for(int i =0;i<s.size();i++)
        {
            if(h.find(s[i])!=h.end())
            {
                if(h[s[i]]!=t[i])
                 return false;
            }
            else
            {
                if(st.count(t[i]))
                 return false;
                h[s[i]]=t[i];
                st.insert(t[i]);
            }
        }

      return true;
    }
};
/******space optimized using fixed sixe array for s and t stings (95 printable characters) */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
        return false;
        if(s.empty()&& t.empty())
        return true;

        char smap[95]={};//printable character range 
        char tmap[95]={};//2 maps to check s->t and t->s
        for(int i =0;i<t.size();i++)
        {

            char schar=s[i];
            char tchar=t[i];
            if(smap[schar - ' ']!=0)
            {
                if(smap[schar - ' ']!=tchar)
                return false;
             
            }
            else
            {
               smap[schar-' '] =tchar;  
            }
            if(tmap[tchar - ' ']!=0)
            {
                if(tmap[tchar - ' ']!=schar)
                return false;
             
            }
            else
            {
               tmap[tchar-' '] =schar;  
            }
        }
        return true;
    }
};