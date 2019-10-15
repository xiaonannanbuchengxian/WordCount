
#include<iostream>
#include<fstream>
#include<string>

#include "stdio.h"
#include "string.h"
#pragma warning(disable:4996)

using namespace std;
int sum;

bool isnum_str(char str)  //判断是否是字符或数字
{
	if ((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9'))
		return true;
	else
		return false;
}

void count(fstream &outfile, int *cnt)  //统计函数
{
	char str[100000];
	while (outfile.getline(str, 100000))
	{
		int tmp = 0;

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')//统计单词数
				cnt[1]++;            

			if (isnum_str(str[i]))   //统计字符数
			{
				cnt[0]++;   
				tmp++;    //tmp局部变量用来区分是不是一个空行
			}    
		}

		if (tmp != 0)
			cnt[2]++;                 //统计行数
		tmp = 0;
	}

	return;
}




struct word

{

	char str[30];    

	int num;       //单词出现的次数

}A[100000];






void frequency(char s[])                      //统计单词频率并排序

{

	int i, j;

	int flag = 0;  

	for (i = 0; i <= sum; i++)   //单词频率统计

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

	for (i = 0; i<sum; i++)   //单词频率排序

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

	cout << "please input your filename:" << endl; //输入需要统计的文本的路径
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

		printf("此文件不存在！\n");

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

			frequency(s);//调用frequency函数统计单词频率并排序

		}

	}

	for (i = 0; i < 10; i++)
		cout << A[i].str << ":" << A[i].num<<endl;

	outfile.close();
	system("pause");
	return 0;

}


