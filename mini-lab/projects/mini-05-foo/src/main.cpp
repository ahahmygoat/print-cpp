#include <iostream>

#include "Stock.h"

int main (){

  // Instantiate one object and print
  // I will set it to a diff price
  Stock stock =  Stock("AAPL", 200);
  std::cout << "AAPl's price: " << stock.getPrice() << std::endl;
  // I will set it to a diff price
  stock.setPrice(400);
  if (stock.getPrice() > 250) {
    std::cout << "The price is at: " << stock.getPrice() << std::endl;
    std::cout << "Massive JUMP! Maybe Earnings???" << std::endl;
  }

  return 0;
}