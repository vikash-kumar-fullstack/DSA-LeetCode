class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder ss=new StringBuilder();
        for(int i=0;i<s.length();i++){
            char ch=Character.toLowerCase(s.charAt(i));
            if(Character.isLetterOrDigit(ch)){
                ss.append(ch);
            }
            

        }
            String ori=ss.toString();
            String rev=ss.reverse().toString();
            return ori.equals(rev);
    }
}