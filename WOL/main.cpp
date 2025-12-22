//WOL - Wake On LAN
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WOL
#define DHCPD

void main()
{
	setlocale(LC_ALL, " ");
#ifdef WOL
	std::ifstream fin("201 RAW.txt");
	std::ofstream fout("201 WOL.txt");
	if (fin.is_open())
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

#endif // WOL

	std::ifstream fin("201 RAW.txt");
	std::ofstream fout("201.dhcpd");
	if (fin.is_open())
	{
		const int IP_BUFFER_SIZE = 16;
		const int MAC_BUFFER_SIZE = 18;
		char sz_IP_buffer[IP_BUFFER_SIZE] = {};
		char sz_MAC_buffer[MAC_BUFFER_SIZE] = {};
		for (int i=1; !fin.eof();i++)
		{
			fin >> sz_IP_buffer >> sz_MAC_buffer;
			if (sz_IP_buffer[0] == 0 || sz_MAC_buffer[0] == 0)continue;
			for (int i = 0; sz_MAC_buffer[i]; i++)
				if (sz_MAC_buffer[i] == '-')sz_MAC_buffer[i] = ':';
			cout << "host-" << i << endl;
			cout << "{\n";
			cout << "\thardware ethernet:\t" << sz_MAC_buffer << ";\n";
			cout << "\tfixed-addaress\t\t" << sz_IP_buffer << ";\n";
			cout << "{\n";
			cout << endl;


			fout << "host-" << i << endl;
			fout << "{\n";
			fout << "\thardware ethernet:\t" << sz_MAC_buffer << ";\n";
			fout << "\tfixed-addaress\t\t" << sz_IP_buffer << ";\n";
			fout << "{\n";
			fout << endl;

		}
	}
	else
	{
		std::cerr << "Error: fole not found" << endl;
	}
	fout.close();
	fin.close();
	system("notepad 201.dhcpd");

}