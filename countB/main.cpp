#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;

int getCount(string str)
{
	int count = 0;
	char *buffer = new char[str.length() + 1]; //������������ � ������
	strcpy(buffer, str.c_str());
	char *c = strstr(buffer," ")+sizeof(char);  //���� ������ ��������� ������� (�� ���� ������ ������ �����)
	char *tmp = buffer;
	if(c!=NULL) //���� �� ������ ������
	{
		do //���� �� ����� �� ����� ������
		{		
			for(char *i = tmp; i<c;i++) //��������� �����
				if(i[0]=='b')
				{
					count++;
					break;
				}
			tmp = c;
			if(strlen(c)==1) //���� �������� ���� �����
				break;
			c = strstr(tmp+sizeof(char)*(strlen(tmp)-strlen(c))," "); //���� ������ ���������� �������
			if(c!=NULL) //���� �� ����� �� �����, �� �������� � ������ �����
				c+=+sizeof(char);	
			else //����� �� ��������� �������
				c = tmp+sizeof(char)*(strlen(tmp)-1);
		}
		while(c!=NULL);
	}
	else
	{
		for(int i=0;i<str.length();i++) //��������� ���� �����
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
	{ //��������� ���� �� �������
		file.getline(buffer,1024);
		countWord+=getCount(buffer);
	}
	if(countWord>0)
		cout << "���������� ���� � ������� ���� ����� b = " << countWord << endl;
	else
		cout << "���� � ������ b � ������ ���"<< endl;
	file.close();
	getch();
}