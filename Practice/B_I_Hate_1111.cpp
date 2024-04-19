#include <algorithm>
#include <iostream>

// Function to check if the target can be expressed as a combination of a and b
// Using the Chicken McNugget Theorem

bool canMakeTarget(int a, int b, int target) {
    // Ensure a is the smaller number
    if (b < a) std::swap(a, b);

    // Calculate the largest number that cannot be expressed as a combination of a and b
    int largestNonExpressible = a * b - (a + b);

    // If the target is larger than this number, it can be expressed as a combination of a and b
    if (target > largestNonExpressible) return true;

    // If the target is a multiple of a, it can be expressed as a combination of a and b
    if (target % a == 0) return true;

    // Otherwise, check if the target can be expressed as a combination of a and b
    for (int i = 0; i * a <= target; ++i) {
        if ((target - i * a) % b == 0) return true;
    }

    // If none of the above conditions are met, the target cannot be expressed as a combination of a and b
    return false;
}

int main() {
    int tt;
    std::cin >> tt;
    int a = 11, b = 111, target;
    while (tt--) {
        std::cin >> target;
        std::cout << (canMakeTarget(a, b, target) ? "YES" : "NO") << std::endl;
    }
    return 0;
}