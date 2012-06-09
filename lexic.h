#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string *fromStrings=new string[1000];
string *toStrings=new string[1000];
int members;

/**
 * Loads a language into the arrays.
 * The syntax of the file should be old:new
 * @param filename - The path to the file
 */
void loadLanguage(string filename,int lines)
{
	string buffer;
	members=lines;
    int until=0;

	ifstream file(filename.c_str());
	for(int index=0; index<1000; index++)
	{
	getline(file,buffer);

	if(buffer.find("_")!=-1){
	toStrings[index]=buffer.substr(0,buffer.find("_"));

	fromStrings[index]=buffer.substr(buffer.find("_")+1,buffer.length());//First bug
   }else{
   until=1000-index;//Second bug
   break;
    }

    for(int index=1000-until; index<1000; index++)
    {
       toStrings[index]="/++10x";
       fromStrings[index]="/++10x";
    }
}
}
/**
*Finds the number of lines in a file.
*@param filename - The path to the file
*@return lines - The number of lines in the file
*/
int linec(string filename)
{
    ifstream file(filename.c_str());
    int lines=0;
    string buffer;

    for(;getline(file,buffer);)
    {
        lines++;
    }
    return lines;
}
//!Not my work
void replaceAll(std::string& str,  std::string& from,  std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
void splitstr(string &toSplit){


    stringstream buffer;

    string copy=toSplit;
    string cnholder="";
    string nope="";
    string toSplitOn="$";

    if(cnholder.find("$")!=-1)
    buffer<<copy.substr(0,toSplit.find(toSplitOn)+1);

    cnholder=buffer.str();

    if(cnholder.find("$")!=-1)
    replaceAll(copy,cnholder,nope);
    cout <<"COPY: "<< copy<<endl;

    buffer<<copy.substr(copy.find(toSplitOn)+1,copy.length());
    cnholder=buffer.str();

    if(cnholder.find("$")!=-1)
    replaceAll(cnholder,toSplitOn,nope);
    toSplit=cnholder;
}

/**
 * Compiles the language set up by loadLangauge.
 * It really just places it in a text file in C++.
 * @param fileName - Where to find the file
 * @param lines    - How many lines the file has.
 * @param toWriteTo - The name of the file to write the translated code to.
 */
void compile(string fileName,int lines,string toWriteTo){

    string line[lines];
    ifstream reader(fileName.c_str());

    for(int index=0; index<lines; index++){
        getline(reader, line[index]);
    }

    for(int index=0; index<lines; index++)
    {
		for(int secInd=0; secInd<members; secInd++)
		{
		    splitstr(line[index]);
		    if(fromStrings[secInd]!="/++10x"&&toStrings[secInd]!="/++10x"){
			replaceAll(line[index],fromStrings[secInd],toStrings[secInd]);
		}

    }
    cout << line[index]<<endl;
    reader.close();
}
ofstream writer(toWriteTo.c_str());

for(int index=0; index<lines; index++)
{
writer << line[index]<<endl;
}
writer.close();
}
