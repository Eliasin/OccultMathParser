#ifndef GCD
#define GCD

namespace OM {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}

#endif
