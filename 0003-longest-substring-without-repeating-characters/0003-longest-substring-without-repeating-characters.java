class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character>st=new HashSet<>();
        int ans=0;int left=0;
        for(int right=0;right<s.length();right++){
            while(st.contains(s.charAt(right))){
                st.remove(s.charAt(left++));
            }
            st.add(s.charAt(right));
            ans=Math.max(ans,right-left+1);
        }
        return ans;
    }
}