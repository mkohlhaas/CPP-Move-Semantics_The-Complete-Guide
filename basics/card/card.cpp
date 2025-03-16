#include "card.hpp"
#include <iostream>
#include <print>
#include <string>
#include <vector>

void
print(const Card &c)
{
    using std::string;

    string val{c.getValue()};
    auto   pos1 = val.find("-of-");
    auto   pos2 = pos1 + 4;

    assert(pos1 != std::string::npos);

    std::cout << val.substr(0, pos1) << ' ' << val.substr(pos2) << '\n';
}

int
main()
{
    std::vector<Card> deck;

    for (auto suit : {"clubs", "spades", "hearts", "diamonds"})
    {
        for (auto rank : {"seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"})
        {
            deck.push_back(rank + std::string{"-of-"} + suit);
        }
    }

    int i = 0;
    for (const auto &c : deck)
    {
        std::cout << ++i << " " << c << '\n';
    }

    std::println();
    print(deck[0]);             // passing a valid object; seven clubs
    std::println();

    Card c{std::move(deck[0])}; // deck[0] has invalid state
    // print(deck[0]);          // passing an object with broken invariant -> core dump

    deck[0] = Card{"ace of-hearts"}; // deck[0] is valid again
    print(deck[0]);                  // passing a valid object; ace hearts
}

void
assertValidCard(const std::string &val)
{
    assert(val.find("seven") != std::string::npos         //
           || val.find("eight") != std::string::npos      //
           || val.find("nine") != std::string::npos       //
           || val.find("ten") != std::string::npos        //
           || val.find("jack") != std::string::npos       //
           || val.find("queen") != std::string::npos      //
           || val.find("king") != std::string::npos       //
           || val.find("ace") != std::string::npos);      //

    assert(val.find("clubs") != std::string::npos         //
           || val.find("spades") != std::string::npos     //
           || val.find("hearts") != std::string::npos     //
           || val.find("diamonds") != std::string::npos); //
}
