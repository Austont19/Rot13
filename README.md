# Introduction
This a simple program that will convert over any text file to ROT13
If you dont know what ROT13 is, its "Rotate by 13 places" so you are able to encrpyt a text file of your choice
You definitely shouldnt use this as any real type of security as it can be easily reversed by going to rot13.com and it will encrpyt or decipher it for you but here i have a
program that will do it offline on your desktop.
## The code
##
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
Firstly
