// class Solution {
//     public boolean isAnagram(String s, String t) {
//         if(s.length()!=t.length())return false;
//         Map<Character,Integer> mp=new HashMap<>();
//         for(int i=0;i<s.length();i++){
//             int count=mp.getOrDefault(s.charAt(i),0)+1;
//             mp.put(s.charAt(i),count);
//         }
//         for(int i=0;i<t.length();i++){
//             if(!mp.containsKey(t.charAt(i)))return false;
//             int count=mp.get(t.charAt(i))-1;
//             mp.put(t.charAt(i),count);
//         }
//         for(int i=0;i<s.length();i++){
//             if(mp.get(s.charAt(i))!=0)return false;
//         }
//         return true;

//     }
// }

class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length())return false;
        int[] f=new int[26];
        for(int i=0;i<s.length();i++){
            f[s.charAt(i)-'a']++;
            f[t.charAt(i)-'a']--;
        }
        for(int x:f){
            if(x!=0)return false;
        }
        return true;
    }
}