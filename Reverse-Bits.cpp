// jai shree ram
unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long reverse = 0;
    long long n = A;
    for(long long i = 0 ; i < 32; i++) {
        if((1 << i) & n) {
            reverse = reverse ^ (1 << (31-i));
        }
    }
    return reverse;
}
