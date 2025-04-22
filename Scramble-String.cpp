// jai shree ram
    map<string,bool> mp;
    bool f(string s , string p) {
        // if both string are equal (aab == aab)
        if(s == p) 
        return true;

        if(s.size() != p.size())
        return false;

        string x = s + " " + p;
        
        if(mp.find(x) !=mp.end())
        return mp[x];

        // check is strings differ in characters;
        int arr[26] = {0};
        
        for(auto i : s) {
            arr[i - 'a']++;
        }
        
        for(auto i : p) {
            arr[i - 'a']--;
        }
        for(auto i : arr) {
            if(i != 0)
            return false;
        }
        bool flag = false;
        
        int n = s.size();
        
        for(int i = 1; i <= n-1; i++) {
            bool sw  = f(s.substr(0,i) , p.substr(n-i,i)) && f(s.substr(i,n-i) , p.substr(0,n-i));
            bool nsw = f(s.substr(0,i) , p.substr(0,i)) && f(s.substr(i,n-i) , p.substr(i,n-i));
            if(sw || nsw) {
                flag = true;
                return mp[x] = true;
            }
        }
        return mp[x] = flag;
    }
int Solution::isScramble(const string A, const string B) {
    string s1 = A;
    string s2 = B;
    return f(s1,s2);
}
