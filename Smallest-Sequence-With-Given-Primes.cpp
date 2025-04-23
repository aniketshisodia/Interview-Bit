// jai shree ram
vector<int> Solution::solve(int A, int B, int C, int D) {
    set<long long> s;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    pq.push(1);
    s.insert(1);

    vector<int> primes = {A, B, C};
    vector<int> ans;

    while (ans.size() < D) {
        long long num = pq.top();
        pq.pop();

        for (int i = 0; i < 3; i++) {
            long long next = num * primes[i];
            if (s.find(next) == s.end()) {
                pq.push(next);
                s.insert(next);
            }
        }

        // Skip pushing initial 1, start from generated numbers
        if (num != 1)
            ans.push_back(num);
    }

    return ans;
}
