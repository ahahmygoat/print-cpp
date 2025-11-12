// @ahahmygoat
// Stock.h

/* 

Object-Oriented Design in Financial Systems

Encapsulation: 
Protecting data in financial objects

Encapsulation is the principle of bundling data (variables) and operations (functions)
that act on that data in a singal unit - a class - while keeping internal details hidden

bank vault: clients can deposit or withdrawl money (through methods) but they cant access the valuts interna
mech

*/ 

#pragma once

#include <string>

class Stock {

  private:
    std::string ticker;
    double price;

  public:
    Stock(const std::string& symbol, double initalPrice)
      :ticker(symbol), price(initalPrice){}
      void setPrice(double newPrice) {
        price = newPrice;
      }
      double getPrice() const {
        return price;
      }
      std::string getTicker() const {
        return ticker;
      }
};


// Private members hide sensitive internal data (price)
// public methods provide controlled access (getters and setters)
// You can add setPrice() without breaking external code