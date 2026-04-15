class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch=t[i];
            if(mp.find(ch)==mp.end()){
                return false;
            }
            if(mp[ch]<=0){
                return false;
            }
            mp[ch]--;
        }
        return true;
    }
};