// Various methods involving bit manipulation

// Returns the i-th bit value inside num
int getBit(int num, int i)
{
    // Mask creation
    // Using left shift, moves the 1 to the left by i positions,
    // where we have to find the number
    int mask = 1 << i;

    // Apply mask -> everything is set to 0 except for the bit
    // in the i-th position
    int res = num & mask;

    // Check bit value
    return res != 0;
}

// Prints a number in bit representation (assumed 32 bit)
void printNumInBit(int n)
{
    for (int i = 32 - 1; i >= 0; i --)
    {
        // Shift n for i bits to the right, generating new less significant elements,
        // and then checks that the last bit is 1
        std::cout << ((n >> i) & 1);
    }
    std::cout << std::endl;
}

// Sets the i-th bit in n to v, with the new number returned
int setBit(int n, int i, int v)
{
    return n | (v << i);
}

// Sets to 0 the bit in i-th position
int clearBit(int n, int i)
{
    // We want to perform a AND operation in order to overwrite the bit in i-th position
    // Since using shifts, we cannot fill the new created positions with 1s but only 0s
    // Thus, we create a mask and then we reverse it
    int mask = 1; // bit that we want to handle
    mask >>= i; // Put the bit in position
    mask = ~mask;
    return n & mask;
}

// Given two 32bit integers M and N, insert M in N so that M starts at bit i and ends at bit j
// Assumes i < j and m can fit in n
int insertNumberInAnother(int m, int i, int n, int j)
{
    // Creates a 32bit sequence of all 1s. It is the same as unsigned Integer MAX
    int allOnes = ~0;

    // Leaves a list of 1s before position j, then leaves 0 til jless significant bit
    int left = j < 31 ? (allOnes << (j + 1)) : 0;

    // Creates a list of 0s with a list of 1s after position i
    // Explanation: creates a number like 00..00001000000 where there are i 0s after the 1
    // Then it subtracts 1 so that the 1 becomes 0 and all the bits before it become 1
    int right = ((1 << i) - 1);

    int mask = left | right;

    // Sets to 0 bits from i to j in n
    int n_cleared = n & mask;

    // Shifts m so that it is aligned with the empty position of n
    int m_shifted = m << i;

    return n_cleared | m_shifted;
}
