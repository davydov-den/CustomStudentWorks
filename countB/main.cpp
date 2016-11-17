#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;

int getCount(string str)
{
	int count = 0;
	char *buffer = new char[str.length() + 1]; //переписываем в массив
	strcpy(buffer, str.c_str());
	char *c = strstr(buffer," ")+sizeof(char);  //ищем первое вхождение пробела (то есть начало нового слова)
	char *tmp = buffer;
	if(c!=NULL) //если бы найден пробел
	{
		do //пока не дошли до конца строки
		{		
			for(char *i = tmp; i<c;i++) //проверяем слово
				if(i[0]=='b')
				{
					count++;
					break;
				}
			tmp = c;
			if(strlen(c)==1) //если осталась одна буква
				break;
			c = strstr(tmp+sizeof(char)*(strlen(tmp)-strlen(c))," "); //ищем начало следующего пробела
			if(c!=NULL) //если не дошли до конца, то сдвигаем в начало слова
				c+=+sizeof(char);	
			else //иначе на последний элемент
				c = tmp+sizeof(char)*(strlen(tmp)-1);
		}
		while(c!=NULL);
	}
	else
	{
		for(int i=0;i<str.length();i++) //проверяем одно слово
			if(str[i]=='b')
				return 1;
		return 0;
	}
	return count;
}

void main()
{
	setlocale(LC_CTYPE,"Russian");
	ifstream file("text.txt");
	char buffer[1024];
	int countWord=0;
	while(!file.eof())
	{ //считываем файл по строчно
		file.getline(buffer,1024);
		countWord+=getCount(buffer);
	}
	if(countWord>0)
		cout << "Количество слов в которых есть буква b = " << countWord << endl;
	else
		cout << "СЛов с буквой b в тексте нет"<< endl;
	file.close();
	getch();
}