// jai shree ram
string Solution::solve(string A, int B) {
    string maxStr = A;

    function<void(string, int, int)> backtrack = [&](string s, int b, int index) {
        if (b == 0 || index == s.length()) {
            if (s > maxStr)
                maxStr = s;
            return;
        }

        char maxChar = *max_element(s.begin() + index, s.end());

        if (s[index] != maxChar) {
            for (int i = s.length() - 1; i > index; --i) {
                if (s[i] == maxChar) {
                    swap(s[i], s[index]);
                    backtrack(s, b - 1, index + 1);
                    // no need to backtrack since s is passed by value
                    swap(s[i] , s[index]);
                }
            }
        } else {
            backtrack(s, b, index + 1);
        }
    };

    backtrack(A, B, 0);
    return maxStr;
}
