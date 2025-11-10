// #include <iostream>
// #include <map>
// #include <set>
// #include <memory>
// #include <list>
// #include <cmath>
// #include <ctime>
// #include <deque>
// #include <stack>
// #include <limits>
// #include <string>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// #include <unordered_map>
// #include <memory>
// #include <variant>
// #include <optional>
// #include <tuple>
// #include <format>
// #include <cstdint>

// enum class OrderType
// {
//     GoodTillCancel,
//     FillandKill
// };

// enum class Side {
//     Buy,
//     Sell
// };
// //  Alias integers so that the code is cleaner

// using Price = std::int32_t;

// using Quantity = std::uint32_t; // Cant be negative
// using OrdedId = std::uint64_t;

// // When you think of an order book you think of levels
// // Levels are made of price and level

// // 

// struct LevelInfo {
//     Price price_;
//     Quantity Quantity_;
// };


// using LevelInfos = std::vector<LevelInfo>;

// class OrderbookLevelInfos
// {
// public:
//     OrderbooklevelInfos (const levelInfnos& bids, const levelInfos& asks)
//             : bids_ { bids}
//             , asks_ { asks}
//         { }
//         // Let's add public apis
//         const LevelInfos& GetBids() const { return bids_;}
//         const LevelInfos& GetAsks() cosnt { return asks_;}
        

// int main()
// {
//     return 0;
// };