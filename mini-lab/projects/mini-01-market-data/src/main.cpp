// @ahahmygoat

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

int main() {
    std::vector<std::string> symbols = {"AAPL", "GOOGL", "TSLA", "AMZN"};
    std::vector<double> prices = {175.23, 200.20, 400, 444};

    // Le'ts print or stream the data

    std::cout << "Streaming Market Data..." << std::endl;

    for (size_t i = 0; i < symbols.size();++i){
        std::cout << symbols[i] << ": $" << prices[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50000));
    }
    std::cout << "End of Market Stream." << std::endl;
    return 0;
}

