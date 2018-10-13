int main() {
    n |= 1<<i;                          // Set ith bit
    n &= ~(1<<i);                       // Clear ith bit
    n ^= 1<<i;                          // Toggle ith bit
    bool ithBit = n & 1<<i;             // Check if ith bit is 1
    bool isPower2 = n & (n - 1);        // Check if the number is a power of 2
    LSO(i) = i & -i;                    // Least significant bit - AND of number and 1's complement
    
    for(int i = n; i; i = i * (i - 1))  // Count numbes of 1

    return 0;
}