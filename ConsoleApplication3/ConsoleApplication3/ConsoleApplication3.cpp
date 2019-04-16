// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"

// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <vector>
#include <cctype> //tolower
#include <string>
#include  <iterator>
#include  <algorithm>
using namespace std;
vector<string> input(string str);
void updateStr(string& str);
//void removeStr(string& str, int K);
void updateKey(string& str);
void fillingKey(string& key, vector<string>& TablStr);
void print(const string& str);
void printInput(vector<string>& Text);
void printInputM(vector<string>& Text);
void encode(vector<string>& Text, const vector<string> key, const vector<string> key_2);
void dencode(vector<string>& Text, const vector<string> key, const vector<string> key_2);
string fillLetters(string key, string& tmp);




int main()
{
	string str = "IDIOCY OFTEN LOOKS LIKE INTELLIGENCE";
	string key = "WHEATSTONE";
	string tmp = "SON";
	string key_2 = ".WHEATST ONE";
	//string tmp_2 = "TS ON";
	//fillLetters(key, tmp);

	//print(key);
	//print(key_2);

	updateStr(str);

	updateKey(key);
	updateKey(key_2);

	//print(str);
	vector<string> Text;
	vector<string> KeyTable;
	vector<string> KeyTable_2;
	cout << endl;


	Text = input(str);

	fillingKey(key, KeyTable);
	fillingKey(key_2, KeyTable_2);
	/*printInput(KeyTable);
	cout << endl;
	cout << endl;
	printInput(KeyTable_2);*/

	cout << "-------KeyTable------" << endl;
	printInputM(KeyTable);
	cout << endl;
	cout << "-------KeyTable_2------" << endl;
	printInputM(KeyTable_2);

	cout << endl;
	encode(Text, KeyTable, KeyTable_2);
	cout << endl;
	printInput(Text);
	cout << endl;
	cout << "+++++++++++++++++++++++++";
	cout << endl;
	dencode(Text, KeyTable, KeyTable_2);
	cout << endl;
	printInput(Text);
	return 0;
}
vector<string> input(string str)
{

	int size = str.size();
	std::vector<string> v;
	string tmp;
	for (int i = 0; i < size; i = i + 2)
	{

		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				tmp.push_back(str[i]);
			else
				tmp.push_back(str[i + 1]);

			//cout << tmp[j];
		}
		//cout << " ";

		v.push_back(tmp);
		tmp.erase();
		tmp.erase();
	}
	return v;
}

void updateStr(string& str)
{
	int size = str.size();
	size = str.size();
	print(str);
	for (int i = 0; i < size; i = i + 2)
	{
		if (str[i] == str[i + 1])
			str.insert(i + 1, "X");
	}
	if (str.size() % 2 != 0)
		str.push_back('X');
}
void print(const string& str)
{
	cout << "-----------" << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
	cout << "-----------" << endl;

}
void printInput(vector<string>& Text)
{
	for (int i = 0; i < Text.size(); i++)
	{
		for (int j = 0; j < Text.at(i).size(); j++)
			cout << Text.at(i)[j];
		cout << " ";
	}
}
void encode(vector<string>& Text, const vector<string> key, const vector<string> key_2)
{
	//on one line
	//on one column
	//on different rows and columns
	int column = 0;
	int line = 0;
	int Case;
	bool stop = false;
	for (int i = 0; i < Text.size(); i++)
	{

		for (int j = 0; j < 2; j++)
		{
			//cout << Text.at(i)[j];
			for (int k = 0; k < key.size(); k++)
			{
				for (int y = 0; y < key.size(); y++)
				{
					if ((j == 0))
					{
						if (Text.at(i)[j] == key.at(k)[y])
						{
							column = y;
							line = k;
						}
					}if ((j == 1))
					{
						if (Text.at(i)[j] == key_2.at(k)[y])
						{

							if (column == y && line != k)
								Case = 0;
							if (column != y && line == k)
								Case = 1;
							if (column != y && line != k)
								Case = 2;

							switch (Case)
							{
								//on one column
							case 0:
								if (k != 5 && line != 5)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k + 1)[y];
									Text.at(i)[0] = key.at(line + 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (line == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k + 1)[y];
									Text.at(i)[0] = key.at(0)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (k == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(0)[y];
									Text.at(i)[0] = key.at(line + 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
								//on one line
							case 1:
								if (y != 4 && column != 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k)[y + 1];
									Text.at(i)[0] = key.at(line)[column + 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (column == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k)[y + 1];
									Text.at(i)[0] = key.at(line)[0];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (y == 4)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k)[0];
									Text.at(i)[0] = key.at(line)[column + 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
								//on different rows and columns
							case 2:
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << "	";
								Text.at(i)[1] = key_2.at(line)[y];
								Text.at(i)[0] = key.at(k)[column];
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << endl;

								stop = true;
								break;
							default:
								stop = true;
								break;
							}

						}
					}
					if (stop == true)
						break;
				}
				if (stop == true)
				{
					stop = false;
					break;
				}
			}
		}
	}
}
void dencode(vector<string>& Text, const vector<string> key, const vector<string> key_2)
{
	//on one line
//on one column
//on different rows and columns
	int column = 0;
	int line = 0;
	int Case;
	bool stop = false;
	for (int i = 0; i < Text.size(); i++)
	{

		for (int j = 0; j < 2; j++)
		{
			//cout << Text.at(i)[j];
			for (int k = 0; k < key.size(); k++)
			{
				for (int y = 0; y < key.size(); y++)
				{
					if ((j == 0))
					{
						if (Text.at(i)[j] == key.at(k)[y])
						{
							column = y;
							line = k;
						}
					}if ((j == 1))
					{
						if (Text.at(i)[j] == key_2.at(k)[y])
						{

							if (column == y && line != k)
								Case = 0;
							if (column != y && line == k)
								Case = 1;
							if (column != y && line != k)
								Case = 2;

							switch (Case)
							{
								//on one column
							case 0:
								if (k != 0 && line != 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k - 1)[y];
									Text.at(i)[0] = key.at(line - 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (line == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k - 1)[y];
									Text.at(i)[0] = key.at(5)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (k == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(5)[y];
									Text.at(i)[0] = key.at(line - 1)[column];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
								//on one line
							case 1:
								if (y != 0 && column != 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k)[y - 1];
									Text.at(i)[0] = key.at(line)[column - 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (column == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k)[y - 1];
									Text.at(i)[0] = key.at(line)[4];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								if (y == 0)
								{
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << "	";
									Text.at(i)[1] = key_2.at(k)[4];
									Text.at(i)[0] = key.at(line)[column - 1];
									cout << Text.at(i)[0];
									cout << Text.at(i)[1];
									cout << endl;
								}
								stop = true;
								break;
								//on different rows and columns
							case 2:
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << " ---- ";
								Text.at(i)[1] = key_2.at(line)[y];
								Text.at(i)[0] = key.at(k)[column];
								cout << Text.at(i)[0];
								cout << Text.at(i)[1];
								cout << endl;

								stop = true;
								break;
							default:
								stop = true;
								break;
							}

						}
					}
					if (stop == true)
						break;
				}
				if (stop == true)
				{
					stop = false;
					break;
				}
			}
		}
	}
}
string fillLetters(string key, string& tmp)
{
	string tmp_2;
	bool duplicateCharacter = 0;
	bool spaceCharacter = 0;
	bool pointCharacter = 0;
	bool twoPointCharacter = 0;
	bool commaCharacter = 0;
	int Symbol = 65;
	int sizeKey = key.size();
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < sizeKey; j++)
		{
			if (Symbol == 90)
				break;
			if (key[j] == Symbol)
			{
				duplicateCharacter = 1;
			}
			if (key[j] == 32)
				spaceCharacter = 1;
			if (key[j] == 46)
				pointCharacter = 1;
			if (key[j] == 58)
				twoPointCharacter = 1;
			if (key[j] == 44)
				commaCharacter = 1;
		}
		if (duplicateCharacter == 0)
		{
			tmp_2.push_back(Symbol);
		}

		duplicateCharacter = 0;
		Symbol++;
	}
	if (commaCharacter == 0)
	{
		tmp_2.insert(5, ",");
	}
	if (spaceCharacter == 0)
	{
		tmp_2.insert(8, " ");
	}
	if (pointCharacter == 0)
	{
		tmp_2.insert(0, ".");
	}
	if (twoPointCharacter == 0)
	{
		tmp_2.insert(16, ":");
	}
	//print(key);
	//print(tmp_2);
	tmp_2 = tmp + tmp_2;

	return tmp_2;
}
void updateKey(string& str)
{
	int size = str.size();

	string tmp;


	//	Remove duplicate characters from string
	std::string::iterator iter = str.begin();
	std::copy_if(str.begin(), str.end(), back_inserter(tmp),
		[&](char c) { return !std::count(str.begin(), iter++, c); });
	//print(tmp);
	str = tmp;
}
void fillingKey(string& key, vector<string>& TablStr)
{
	int SizeKey = key.size() - 1;
	int remainderOfDivision = key.size() % 5;
	string tmp_2;
	string tmp = key;
	//fill the rest of the letters
	tmp = fillLetters(key, tmp);
	int tmpSize = 0;
	bool stop = 0;
	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < 5; j++, SizeKey--)
		{
			tmp_2.push_back(tmp[j + i * 5]);
		}

		TablStr.push_back(tmp_2);
		//print(tmp_2);
		tmp_2.clear();
	}

}
void printInputM(vector<string>& Text)
{
	for (int i = 0; i < Text.size(); i++)
	{
		for (int j = 0; j < Text.at(i).size(); j++)
			cout << Text.at(i)[j];
		cout << endl;
	}
}
