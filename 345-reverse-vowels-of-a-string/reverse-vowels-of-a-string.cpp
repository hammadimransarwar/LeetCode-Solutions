class Solution {
bool Isvowel(char c){
    c=c&223;
    if(c=='A'||c=='I'||c=='O'||c=='E'||c=='U') return true;
    else return false;
} 
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<s.size()&&j>0&&i<=j){
            if(Isvowel(s[i])==0){
                i++;
                continue;
            }
            if(Isvowel(s[j])==0){
                j--;
                continue;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};