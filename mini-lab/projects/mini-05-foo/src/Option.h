#include <string>
#include <cmath>
#pragma once

class Option {
  private:
      std::string underlying;
      double strikePrice;
      std::string optionType;
      std::string expirationDate;
      double premium;
      std::int16_t contractSize;
};
