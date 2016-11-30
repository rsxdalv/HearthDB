#include "database.h"
#include <iostream>

using namespace std;

database::database(char *name)
{
    input = new ifstream(name);
    //output = new ofstream(name);
}

database::~database()
{
    delete input;
    //delete output;
}

void database::write()
{
    ofstream database2("database.txt");
    int sze = cardList.size();
    for (int i = 0; i < sze; i++)
    {
        database2 << cardList[i].name << '\t' << cardList[i].value << '\t' << cardList[i].dataPoints << '\n';
    }
}

void database::read()
{
    string name;
    int value;
    int dataPoints;
    while (input->good())
    {
        char name2[32];
        input->getline(name2, 32, '\t');
        *input >> value;
        *input >> dataPoints;
        input->ignore();
        for (int i = 0; name2[i]; i++)
            name2[i] = tolower(name2[i]);
        Card SpecificCard(name2, value, dataPoints, 0);
        cardList.push_back(SpecificCard);
    }
    cardList.pop_back();
    int sze = cardList.size();
}
