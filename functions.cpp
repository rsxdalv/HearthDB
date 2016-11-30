#include "functions.h"
#include <string.h>

void updateV2()
{
    database db("database.txt");
    db.read();
    int selection = 0, selectValue = 0;
    while(selection!=-1)
    {
        selection = selectCard(db.cardList);
        if(selection == -1) break;
        cout<< "Value difference: ";
        cin >> selectValue;
        cin.ignore();
        // Update value
        cout<< "New value: "<<db.cardList[selection].addValue(selectValue)<<'\n';
    }
    db.write();
    //db.writeDatabase(cardList);
}

void lookupV2()
{
    database db("database.txt");
    db.read();
    int selections[3] = {};
    int selection = 0;
    while(1){
        for(int j=0;j<3;j++)
        {
            selection = selectCard(db.cardList);
            if(selection == -1) {
                selections[j] = 0;
                break;}
            else
                selections[j] = selection;

        } // End of selection loop.

        for(int i=0;i<3;i++)
        {
            cout<<db.cardList[selections[i]].name<<' '<<db.cardList[selections[i]].getValue()<<'\t';
        }
        cout<<'\n';

    }// Super-while loop
    db.write();
}

int selectCard(CardList cardList)
{
    int sze = cardList.size();
    char * selectName = new char[32];
    int duplicates[600]={}; // UNSAFE

    cout<<"Enter card name:";
    cin.getline(selectName,32);

    if(!selectName[0]) return -1;

    int result = 0, length = strlen(selectName), duples = 0;
    for(int i=0;i<sze;i++)
    {
        result=cardList[i].name.compare(0,length,selectName);
        if(result==0)
        {
            while(!result)
            {
                duplicates[0+duples] = i+duples;
                duples++;
                if((duples + i >= sze)) break;
                result = cardList[i+duples].name.compare(0,length,selectName);
            }
        }
        if(result>0) break;
    }

    int choice = 1;
    if(duples>1)
    {
        for(int i=0;i<duples;i++)
        {
            cout << i+1 << ":" << cardList[duplicates[i]].name << '\n';
        }
        cin >> choice;
        cin.ignore();
    }
    choice--;
    cout<<"Selection :"<<cardList[duplicates[choice]].name<<'\n';
    return duplicates[choice];
}

void mergeDatabase()
{
    database db("database.txt");
    db.read();
    ifstream input("mergeDB.txt");
    CardList cardList;
    string name;
    //int value;
    //int dataPoints;
    while(input.good())
    {
        char name2[32];
        input.getline(name2,32, '\n');
        //*input>>value;
        //*input>>dataPoints;
        //input.ignore();
        for(int i=0;name2[i];i++) name2[i]=tolower(name2[i]);
        Card SpecificCard(name2, 0, 0, 0);
        cardList.push_back(SpecificCard);
    }
    cardList.pop_back();
    int sze = cardList.size();

    int sourceIndex=0;
    for(int i=0;i<sze;i++)
    {
        //cout<<"Match at i:"<<i<<" and sI:"<<sourceIndex<<'\n';
        if(cardList[i].name == db.cardList[sourceIndex].name)
        {
            cout<<"Match at i:"<<cardList[i].name<<" and sI:"<<db.cardList[sourceIndex].name<<'\n';
            cardList[i].value = db.cardList[sourceIndex].value;
            cardList[i].dataPoints = db.cardList[sourceIndex].dataPoints;
            sourceIndex++;
        }

    }
    db.cardList = cardList;
    db.write();

    cin.get();
}
