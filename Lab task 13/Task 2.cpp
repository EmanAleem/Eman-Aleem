#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
ofstream textfile("otput.txt");
textfile<<"output file\n";
textfile<<"line 1:writing to the file in c++\n";
textfile<<"line 2:file handling is essential for data manipulation";
textfile.close();
return 0;
}

