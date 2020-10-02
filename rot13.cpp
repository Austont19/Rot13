#include<iostream>
#include<fstream>

using namespace std;


char Rot13(char to_be_translated)
{
if(to_be_translated>='A' && to_be_translated<='Z')
{
return (to_be_translated-'A'+13)%26+'A';
}
else if(to_be_translated>='a' && to_be_translated<='z')
{
return (to_be_translated-'a'+13)%26+'a';
}
return to_be_translated;
}

void WriteTranslatedCharacter(char translated_character, ofstream& output)
{
output << translated_character;
}

int main()
{
string input_file;

cout <<"Enter the name of input file:";
cin >> input_file;
cout << endl;

ifstream infile(input_file.c_str());
ofstream outfile("output.rot13");

char char_from_file = infile.get();
while(!infile.eof())
{
WriteTranslatedCharacter(Rot13(char_from_file), outfile);
char_from_file = infile.get();
}

cout << "File Converted" << endl;
infile.close();
outfile.close();
return 0;
}

