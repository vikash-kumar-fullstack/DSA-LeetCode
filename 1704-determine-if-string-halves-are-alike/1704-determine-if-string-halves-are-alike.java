class Solution {
    public boolean halvesAreAlike(String s) {
        int first=0;
        int sec=0;
        int n=s.length()/2;
        s=s.toLowerCase();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='a' || s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u') first++;
            if(s.charAt(n+i)=='a' || s.charAt(n+i)=='e' || s.charAt(n+i)=='i' || s.charAt(n+i)=='o' || s.charAt(n+i)=='u')sec++;
        }
        return first==sec;
    }
}