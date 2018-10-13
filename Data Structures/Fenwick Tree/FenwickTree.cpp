

/*
    Fenwick Tree - Binary Indexed Tree
    - 1994
    - Dynamic Cumulative Frequency Tables

    LSO - Least Significant One - i & (-i)

    LSO(6)  = LSO(0110) = 0010
    LSO(4)  = LSO(0100) = 0100
    LSO(9)  = LSO(0101) = 0001
    LSO(14) = LSO(1110) = 0010

    FT[i] = [ i - LSO(i) + 1 ... i]

    FT[6]  = [ 6 - 2 + 1 ... 6]  = [5 ... 6]
    FT[4]  = [ 4 - 4 + 1 ... 4]  = [1 ... 4]
    FT[9]  = [ 9 - 1 + 1 ... 9]  = [9]
    FT[14] = [ 14 - 2 + 1 ... 9] = [13 ... 14]

    Generalize:

    a) Odd:             FT[i] = [i]
    b) Even != 2^k:     FT[i] = [sum 2^k ... i]
    c) Even 2^k:        FT[i] = [1 ... 2^k]

    rsq(a) = FT[a] + FT[a - LSO(a)] + FT[a' - LSO(a')] + ...
    rsq(i,j) = rsq(j) - rsq(i - 1)

    rsq(a)    - O(log n)
    rsq(i, j) - O(log n)


    IDEA: a number can be contructed by powers of 2:
    6 = 4 + 2           => 2 elements
    4 = 4               => 4 elements
    9 = 8 + 1           => 1 element
    14 = 8 + 4 + 2      => 2 elemnents

    Query  - O(log n)
    Update - O(log n)
    Build  - O(n log n)
*/
class FenwickTree {
    public:   
        FenwickTree(vector<int> v, int n) {
            ft.assign(n, 0); N = n;
            for(int i = 1; i < n; i++) update(i, v[i]);
        }
        int query(int i, int j) { return rsq(j) - rsq(i-1); }
        void update(int i, int x) { for(int j =  i; j < N; j += LSO(j)) ft[j] += x; }

    private:
        vector<int> ft;
        int N;

        int LSO(int i) { return i & (-i); }
        int rsq(int i) {
            int rsq = 0;
            for(; i > 0; i = i - LSO(i)) rsq += ft[i];
            return rsq;
        }
}