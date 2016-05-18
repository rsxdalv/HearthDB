#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
    public:
    int value;
    std::string name;
    int dataPoints;
    int index;

    Card(std::string CardName, int CardValue, int dataPoints, int index);
    ~Card();
    double getValue();
    void incrementValue() {value++;}
    int addValue(int valueDifference) {dataPoints++; return (value+=valueDifference)/dataPoints;}
};

#endif // CARD_H
