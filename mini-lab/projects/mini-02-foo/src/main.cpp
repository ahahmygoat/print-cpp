#include <iostream>

int main(){
  double stockPrice= 99;
  double threshold = 100;

  if (stockPrice > threshold){
    std::cout << "Sell the stock- it's above target price." << std::endl;
  }
  else if (stockPrice == threshold) {
    std::cout << "Hold the stock- it's at threshold" << std::endl;
  }
  else {
    std::cout << "Buy more- it's undervalued!" << std::endl;
  }
  return 0;
}