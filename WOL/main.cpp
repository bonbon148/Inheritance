//WOL - Wake On LAN
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, " ");
	std::ifstream fin("201 RAW.txt");
	std::ofstream fout("201 WOL.txt"); 
	if(fin.is_open())
	{
		const int IP_BUFFER_SIZE = 16;
		const int MAC_BUFFER_SIZE = 18;
		//NULL-Terminated Line (sz - String Zero)
		char sz_IP_buffer[IP_BUFFER_SIZE] = {};
		char sz_MAC_buffer[MAC_BUFFER_SIZE] = {};
		while (!fin.eof())
		{
			fin >> sz_IP_buffer >> sz_MAC_buffer;
			cout << sz_MAC_buffer << "\t" << sz_IP_buffer << endl;
			fout << sz_MAC_buffer << "\t" << sz_IP_buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
		//cerr - Console Errors
	}
	fout.close();
	fin.close();
	system("notepad 201 WOL.txt");
	
	
}