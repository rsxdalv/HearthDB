#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <vector>
#include "card.h"
#include "cardList.h"

//This is a lowly ad-hoc type database, fully integrated.
class database
{
    public:
    std::ifstream *input;
    std::ofstream *output;

    CardList cardList;

    database(char * name);
    ~database();
    void read();
    void write();
};

#endif // DATABASE_H
