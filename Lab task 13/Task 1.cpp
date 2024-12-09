#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
ofstream myfile("filename.txt");
myfile<<"this is a simple file.\n";
myfile<<"line1: hello world!\n";
myfile<<"line 2: file handling in c++";
myfile.close();
return 0;
}

