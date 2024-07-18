#include <functional>
#include <utility>
#include <vector>

// Assuming you need to pass the vector by reference and use it inside the lambda:
auto lambda = [](int row, int col, std::vector<std::pair<int, int>>& carry) -> void {
    // Your code here
};

// Convert to std::function using std::ref for the vector
std::function<void(int, int, std::vector<std::pair<int, int>>&)> func = lambda;