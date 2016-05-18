#include "controller.h"
#include <iostream>
#include "functions.h"

using namespace std;

void UIControl()
{

    //UI Controller
    int mode = 0;
    while(mode!=9)
    {
        cout<<""
            <<"1: updateV2() "
            <<"2: lookupV2() "
            <<"3: mergeDatabase() "
            <<'\n';
        cin>>mode;
        cin.ignore();
        switch(mode)
        {
            case 1: updateV2();
            break;
            case 2: lookupV2();
            break;
            case 3: mergeDatabase();
            break;
        }
    }
}
