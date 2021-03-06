/*
ID: kashthe1
LANG: C++
TASK: palsquare
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: palsquare.cpp
 *	description : solves the problem in usaco by the name palsquare
 *
 *	date 		: 05/09/2009 00:11:31 
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void strrev ( char* cStr )
{
	int len = strlen(cStr);
	int i;
	char temp;
	for ( i = 0 ; i < len / 2 ; i ++ )
	{
		temp = cStr[len - 1 - i];
		cStr[len - 1 - i] = cStr[i];
		cStr[i] = temp;
	}
}

string baseConvert( long long int num, int base, int *isPal )
{
	string value = "";
	long long int x;
	char *cStr, *cStr2;
	while ( num != 0 )
	{
		x = num % base;
		num /= base;
		value += char(x<=9?(x+'0'):(x+'A'-10));
	}
	cStr = new char[value.size()+1];
	cStr2 = new char[value.size()+1];

	strcpy ( cStr, value.c_str());
	strcpy ( cStr2, cStr);
	strrev ( cStr );

	if ( strcmp(cStr, cStr2) == 0)
		*isPal = 1;
	else
		*isPal = 0;
	value = cStr;

	delete []cStr;
	delete []cStr2;

	return value;
}

int main()
{
	FILE *fp =fopen("palsquare.in","r");
	ofstream outFile ("palsquare.out");
	
	int base;							// Base as in input
	int flag;							// equals 1 if number is palin 0 else
	int i;								// loop counter
	string value1, value2;				// The base converted number
	fscanf(fp, "%d", &base);				// Get the flag
	
	// For numbers in the range do,
	for ( i = 1 ; i < 300 ; i ++ )
	{	
		// Convert the base of the square of the number
		value2 = baseConvert( i, base, &flag);
		value1 = baseConvert( i*i, base, &flag);

		if(flag)						// If the number is a palindrome
			outFile << value2 << " " << value1 << endl;	// output the number
	}
	fclose(fp);
}
