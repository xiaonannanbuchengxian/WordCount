
#include<iostream>
#include<fstream>
#include<string>

#include "stdio.h"
#include "string.h"
#pragma warning(disable:4996)

using namespace std;
int sum;

bool isnum_str(char str)  //�ж��Ƿ����ַ�������
{
	if ((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9'))
		return true;
	else
		return false;
}

void count(fstream &outfile, int *cnt)  //ͳ�ƺ���
{
	char str[100000];
	while (outfile.getline(str, 100000))
	{
		int tmp = 0;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')//ͳ�Ƶ�����
				cnt[1]++;            

			if (isnum_str(str[i]))   //ͳ���ַ���
			{
				cnt[0]++;   
				tmp++;    //tmp�ֲ��������������ǲ���һ������
			}    
		}

		if (tmp != 0)
			cnt[2]++;                 //ͳ������
		tmp = 0;
	}

	return;
}




struct word

{

	char str[30];    

	int num;       //���ʳ��ֵĴ���

}A[100000];






void frequency(char s[])                      //ͳ�Ƶ���Ƶ�ʲ�����

{

	int i, j;

	int flag = 0;  

	for (i = 0; i <= sum; i++)   //����Ƶ��ͳ��

	{

		if (strcmp(A[i].str, s) == 0)

		{

			A[i].num++;

			flag = 1;

			sum++;

		}

	}

	if (flag == 0)

	{

		for (j = 0; j<30; j++)

			A[sum].str[j] = s[j];

		A[sum].num++;

		sum++;

	}


	struct word a;

	for (i = 0; i<sum; i++)   //����Ƶ������

	{

		for (j = i + 1; j<sum; j++)

			if (A[i].num<A[j].num)

			{

				a = A[j];

				A[j] = A[i];

				A[i] = a;

			}

	}


}




int main()
{
	char filename[100000];
	int i, flag = 0;
	int cnt[3] = { 0 };
	char ch, s[30];

	cout << "please input your filename:" << endl; //������Ҫͳ�Ƶ��ı���·��
	cin.getline(filename, 100000);

	fstream outfile(filename, ios::in);
	count(outfile, cnt);
	cout << "characters: " << cnt[0] << endl;
	cout << "words:" << cnt[1] << endl;
	cout << "lines:" << cnt[2] << endl;
	

	FILE *fp;
	fp = fopen(filename, "r");
	
	if (fp == NULL)

	{

		printf("���ļ������ڣ�\n");

	}
	sum = 0;

	ch = NULL;

	for (i = 0; i<1000; i++)

		A[i].num = 0;

	while (ch != -1)

	{

		for (i = 0; i<30; i++)

			s[i] = '\0';

		ch = fgetc(fp);

		if ((65 <= ch&&ch <= 90) || (ch >= 97 && ch <= 122))

		{

			for (i = 0;; i++)

			{

				s[i] = ch;

				ch = fgetc(fp);

				if ((65 <= ch&&ch <= 90) || (ch >= 97 && ch <= 122))continue;

				else break;

			}

			frequency(s);//����frequency����ͳ�Ƶ���Ƶ�ʲ�����

		}

	}

	for (i = 0; i < 10; i++)
		cout << A[i].str << ":" << A[i].num<<endl;

	outfile.close();
	system("pause");
	return 0;

}


