// jai shree ram
int Solution::solve(int A) {
    int left = 0 , c = 0;
    while(!(A & (1 << left))) {
        c++;
        left++;
    }
    return c;
}
