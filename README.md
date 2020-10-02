# Introduction
This a simple program that will convert over any text file to ROT13
If you dont know what ROT13 is, its "Rotate by 13 places" so you are able to encrpyt a text file of your choice
You definitely shouldnt use this as any real type of security as it can be easily reversed by going to rot13.com and it will encrpyt or decipher it for you but here i have a
program that will do it offline on your desktop. This a great little fun tool as a gag or joke to send over messages or just ruin someones essay and let them try and figure out how to decode it.
## The code
The first part i had trouble with but eventually fixed was the loop to encrypt any letters but then adding the file i/o and connecting the translator to then output that onto the text file was easier. Other than that the code is pretty simple and acheives what is needs to do in a lightweight file so it is very portable. Which makes it practical if you want to throw it onto a flash drive and be a secret file you can hide within some random folders.
####
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

## File i/o
Here i was able to to use any named file that the user desired and allowed for them to then input it and the program would accept it and use the above code to encrpyt the file.
####
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

## Future plans
My plans with this program is to add a little gui or application window to it so that you can drag and drop the file into it rather than having to have the files in the same directory.

## Technologies 
This project was created with C++ with Dev++

## Setup
To use this program simply all you have to do it download the provided exe file and then run it and you will be prompted to input the file, just have your prepared text file on hand in the same folder or drive and youll be good to encrpyt some files.
