#include<Windows.h>
#include<iostream>
#include<fstream>   //0) Подключаем файловые пот оки 
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE
//#define INPUT_STRINGS

void main()
{
	setlocale(LC_ALL, "");
#ifdef  WRITE_TO_FILE
	// 1) Создаём поток:
	std::ofstream fout;

	//2) Открываем поток:
	fout.open("File.txt", std::ios_base::app); //App - Append, добавить в конец 

	//3) Записываем поток:
	fout << "Hello World!" << endl;

	//4) Закрываем поток:
	fout.close();
	//Behavior is undefined

	system("start notepad File.txt");
	// Функция system() позволяет выполнить любую программу командной строки Windows (cmd.exe)  
#endif //  WRITE_TO_FILE

#ifdef INPUT_STRINGS
	cout << "Введите Ваше имя: ";
	const int SIZE = 256;
	char last_name[SIZE] = {};
	char first_name[SIZE] = {};
	SetConsoleCP(1251);
	cin >> first_name >> last_name;
	SetConsoleCP(866);
	cout << first_name << "\t" << last_name << endl;
#endif // INPUT_STRINGS

	const int SIZE = 256;
	char sz_buffer[SIZE] = {}; //sz - String Zero (NULL - Terminated Line)

	//1) Создаём и открываем поток:
	std::ifstream fin("File.txt"); //Если имя файла указать при создание потока, он сразу же откроется

	//2) Проверяем существование файла:
	if (fin.is_open())
	{
		//3) Читаем файл:
		while (!fin.eof()) //End Of File
		{
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}


	}
	else
	{
		std::cerr << "Error: file not found." << endl;
	}
	
	//?) Закрываем поток:
	fin.close();
}