class Solution {
public:
    void expand(string &s, int left, int right, string &ans){
        
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }

        // step back to valid range
        string temp = s.substr(left + 1, right - left - 1);

        if(temp.length() > ans.length()){
            ans = temp;
        }
    }

    string longestPalindrome(string s) {
        string ans = "";

        for(int i = 0; i < s.length(); i++){
            // odd length
            expand(s, i, i, ans);

            // even length
            expand(s, i, i + 1, ans);
        }

        return ans;
    }
};