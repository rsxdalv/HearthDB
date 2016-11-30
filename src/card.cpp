#include "card.h"

Card::Card(std::string name, int value, int dataPoints, int index)
{
    this->name = name;
    this->value = value;
    this->dataPoints = dataPoints;
    this->index = index;
    //    return this;
}

Card::~Card(){};

double Card::getValue()
{
    if (dataPoints)
        return (double)value / dataPoints;
    else
        return value;
}
