#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string *fromStrings=new string[10000];//C++ members
string *toStrings=new string[10000]; // Custom language members
int members=0;                     //  The number of members

/**
 * Loads a language into the arrays.
 * The syntax of the file should be old_new
 * @param filename - The path to the file
 * @param lines - How many lines long the file is. This can be
 input manually or with linec(string filename).
 */
void loadLanguage(string filename,int lines)
{
	string buffer; //Used for parsing individual lines
	members=lines;// How many entries the langdefines has
    int until=0; /*Until is used to determine how many NO_USE characters to use.
                    NO_USE characters show an unwritten line.*/

	ifstream file(filename.c_str());
	for(int index=0; index<10000; index++)
	{
	getline(file,buffer);

	if(buffer.find("_")!=-1){
	toStrings[index]=buffer.substr(0,buffer.find("_"));

	fromStrings[index]=buffer.substr(buffer.find("_")+1,buffer.length());
   }else{
   until=10000-index;//Second bug
   break;
    }

    for(int index=10000-until; index<10000; index++)
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
/**
*Replace all of the strings matching the criteria.
*@param str - The string to replace it in.
*@param from- The string to find and replace.
*@param to  - What to replace the string with
*/
void replaceAll(std::string& str,  std::string& from,  std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
/**
*Splitstr is a very important function.
*This finds text in between two magic characters and removes it from the string.
*
*The translator works on an explicit basis. Every string meeting its criteria will be
*removed. This allows sensitive strings to leave before translation begins. You must place
*the sensitive string in between the two magic characters.
*@param toSplit   - The string to remove sensitive strings from.
*@param magicahar - The character used in the code file to denote a sensitive string. "$" is the standard.
*/
void splitstr(string &toSplit, string magichar){
if(toSplit.find(magichar)!=-1){

    stringstream buffer;

    string copy=toSplit;
    string cnholder="";
    string nope="";


    if(toSplit.find(magichar)!=-1)
    buffer<<copy.substr(0,toSplit.find(magichar));//Before first magichar

    cnholder=buffer.str();

    if(copy.find(magichar)!=-1)
    copy=copy.substr(toSplit.find(magichar)+1,toSplit.length());

    if(copy.find(magichar)!=-1)
    buffer<<copy.substr(copy.find(magichar)+1,copy.length());//Substring of one more than the next magichar and the length.

    toSplit=buffer.str();
}
}
/**
 * Creates a file containing the old text as defined by
 * the langdefines in loadLanguage(filename,lines).
 * If this is being used for code, you must compile it yourself.
 * @param fileName  - The absolute file path to the file.
 * @param lines     - How many lines the file has. Use linec to find this.
 * @param toWriteTo - The name of the file to write the translated code to.
 * @param magichar  - The string that denotes sensitive strings. If you do not have
                    one, use something gibberish. Otherwise, use your magichar. For
                    magichar documentation, see splitstr
 */
void compile(string fileName,int lines,string toWriteTo,string magichar){

    string line[lines];
    ifstream reader(fileName.c_str());

    for(int index=0; index<lines; index++){
        getline(reader, line[index]);
    }

    for(int index=0; index<lines; index++) // Loops through each line
    {
		for(int secInd=0; secInd<members; secInd++)//Performs replacement operations
		{
		    splitstr(line[index],magichar); // splitstr removes protected strings from lines[index] IF they exist.

		    if(fromStrings[secInd]!="/++10x"&&toStrings[secInd]!="/++10x"){
			replaceAll(line[index],fromStrings[secInd],toStrings[secInd]);
		}

    }
    cout << line[index]<<endl;
    reader.close();
}
ofstream writer(toWriteTo.c_str());

for(int index=0; index<lines; index++)//Iterate through the changed lines and write them to a file.
{
writer << line[index]<<endl;
}
writer.close();
}
