#include <iostream>
#include <vector>
#include <chrono>

int main() {
    std::cout << "C++ Environment Test\n";
    std::cout << "===================\n";
    
    // Test C++20 features
    std::vector<int> nums = {1, 2, 3, 4, 5};
    
    std::cout << "Vector contents: ";
    for (const auto& n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";
    
    // Test chrono
    auto now = std::chrono::system_clock::now();
    std::cout << "Build successful at: " 
              << std::chrono::system_clock::to_time_t(now) << "\n";
    
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    
    return 0;
}