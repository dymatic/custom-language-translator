/*
 * Noran Scripting Language.cxx
 *Licensed under the NRPL
 *
 *NOTE: EVERY SINGLE WORD meeting the langdefines WILL be changed
 *by functionallity. This is not a bug. Be safe when writing langdefines.
 *Be especially safe with ints.
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "HEADER/lexic.h"
using namespace std;

int main(int argc, char**argv)
{
    string argv2[6];
    bool interactive=false;

    if(argc<4)
        interactive=true;
    else
        for(int index=1; index<5; index++)
        {
            argv2[index-1]=argv[index];
        }
    if(interactive)
    {

        cout << "What is the total file path to the language definition file?"<<endl<<"$ ";
        cin  >> argv2[0];
        cout << endl;

        cout << "What is the total file path to the code?"<<endl<<"$ ";
        cin  >> argv2[1];
        cout << endl;

        cout << "What is the file path to the output file?"<<endl<<"$ ";
        cin  >> argv2[2];
        cout << endl;

        cout << "What is the magichar? If you do not know, type \"nothing\""<<endl<<"$ ";
        cin  >> argv2[3];
        cout << endl;

        cout << "Would you like the langdefines automatically ordered? y/m "<<endl<<"$ ";
        cin  >> argv2[4];
        cout << endl;
    }
    if(argv2[4].find("y")!=-1)
        orderFile(argv2[0]);

    loadLanguage(argv2[0],linec(argv2[0]));
    compile(argv2[1],linec(argv2[1]),argv2[2],argv2[3]);

    cout << endl;
    return 0;
}
