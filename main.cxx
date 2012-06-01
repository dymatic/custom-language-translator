/*
 * Noran Scripting Language.cxx
 *Licensed under the NRPL
 *
 *See EDITORS for author information.
 *By standard, append the name of langdefines
 *files with .ldf if your operating system allows it.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "HEADER/lexic.h"
using namespace std;

int main(int argc, char**argv)
{
    string argv2[6];
    bool interactive=false;

    if(argc<2)
        interactive=true;
    else
        for(int index=1; index<5; index++)
        {
            argv2[index-1]=argv[index];
        }
    if(interactive)
    {
        char choice='a';
        cout << "What is the total file path to the language definition file?"<<endl<<"$ ";
        cin  >> argv2[0];
        cout << endl;

        cout << "Would you like the langdefines automatically ordered? y or n "<<endl<<"$ ";
        cin  >> argv2[4];
        cout << endl;

        cout << "Are you using a Noran Make File? y/n"<<endl<<"$ ";
        cin  >> choice;
        cout << endl;

        if(choice=='y')
            {
                if(argv2[4].find("Y")!=-1)
                    orderFile(argv2[0],true);

                string filename;
                cout << "What is the path to the Noran Make File?"<<endl<<"$ ";
                cin  >> filename;
                cout << endl;

                iCompile(filename);
            }else{
        cout << "What is the total file path to the code?"<<endl<<"$ ";
        cin  >> argv2[1];
        cout << endl;

        cout << "What is the file path to the output file?"<<endl<<"$ ";
        cin  >> argv2[2];
        cout << endl;

        cout << "What is the magichar? If you do not know, type \"nothing\""<<endl<<"$ ";
        cin  >> argv2[3];
        cout << endl;

    }
    if(argv2[4].find("y")!=-1)
        orderFile(argv2[0],true);

    loadLanguage(argv2[0],linec(argv2[0]));
    compile(argv2[1],linec(argv2[1]),argv2[2],argv2[3]);
    }//END Noran Make File else
    cout << endl;
    return 0;
}
