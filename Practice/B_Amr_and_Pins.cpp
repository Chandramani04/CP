#include <cmath>
#include <iostream>

int main() {
    double r;
    std::cin >> r;
    double x1, y1, x2, y2;

    std::cin >> x1 >> y1;

    std::cin >> x2 >> y2;

    double dist = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    int ans = std::ceil(dist / (2 * r));

    std::cout << ans << std::endl;

    return 0;
}