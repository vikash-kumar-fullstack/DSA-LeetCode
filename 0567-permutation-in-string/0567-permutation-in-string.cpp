class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(char ch:s1){
            freq1[ch-'a']++;
        }
        for(int i=0;i<s1.length();i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2){
            return true;
        }
        int len=s1.length();
        for(int i=s1.length();i<s2.length();i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-len]-'a']--;
            if(freq1==freq2)return true;
        }
        return false;
    }
};