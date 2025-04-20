// jai shree ram
int Solution::isValid(string A) {
    stack<char> s;
    for(int i = 0 ; i < A.size(); i++) {
        char ch = A[i];
        if(ch == '{' || ch == '(' || ch == '[') {
            s.push(ch);
        }
        else {
            if(!s.size()) return 0;
            
            if(ch == '}') {
                if(s.top() == '{') {
                    s.pop();
                }
                else return 0;
            }
            
            if(ch == ']') {
                if(s.top() == '[') {
                    s.pop();
                }
                else return 0;
            }
            if(ch == ')') {
                if(s.top() == '(') {
                    s.pop();
                }
                else return 0;
            } 
        }
    }
    if(s.size()) return 0;
    return 1;
}
