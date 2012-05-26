/*
 * Noran Scripting Language.cxx
 *
 * Copyright 2012 Norton Jenkins <nate@Phoenix>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
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

int main(){

string argv[6];

cout << "What is the total file path to the language definition file?"<<endl<<"$ ";
cin  >> argv[0];
cout << endl;

cout << "What is the total file path to the code?"<<endl<<"$ ";
cin  >> argv[1];
cout << endl;

cout << "What is the file path to the output file?"<<endl<<"$ ";
cin  >> argv[2];
cout << endl;

cout << "What is the magichar? If you do not know, type \"nothing\""<<endl<<"$ ";
cin  >> argv[5];
cout << endl;
	loadLanguage(argv[0],linec(argv[0]));
	compile(argv[1],linec(argv[1]),argv[2],argv[5]);
cout << endl;
	return 0;
}
