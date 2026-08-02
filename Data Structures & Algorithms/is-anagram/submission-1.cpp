class Solution {
public:
    bool isAnagram(string s, string t) {
        // ist edge case length is same
        // can we apply the map data structure
        if(s.length()!=t.length())
        return false;

        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        // now mpp contains the element 
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
        }

        for(auto it:mpp){
            if(it.second!=0)
            return false;
        }
        
        return true;
    }
};
