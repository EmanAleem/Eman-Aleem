#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
ofstream file("userlog.txt",ios::app);
file<<"user'John' logged in.\n";
file<<"user'Jane'acessed the dashboard.\n";
file<<"user'Bob'performed a file operation.\n";
file.close();
ifstream myfile("userlog.txt");
cout<<"user activation log:\n";
string line;
while(getline(myfile, line)){
cout<<line<<endl;
}
}

