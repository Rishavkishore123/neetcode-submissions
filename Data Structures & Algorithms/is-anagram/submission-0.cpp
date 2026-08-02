class Solution {
public:
    bool isAnagram(string s, string t) {
        // ist edge case length is same
        // can we apply the map data structure
        if(s.length()!=t.length())
        return false;

        unordered_map<char,int>mpp;
        for(auto ch:s)
        mpp[ch]++;

        // now mpp contains the element 
        for(auto ch:t)
        mpp[ch]--;

        for(auto it:mpp){
            if(it.second!=0)
            return false;
        }
        
        return true;
    }
};
