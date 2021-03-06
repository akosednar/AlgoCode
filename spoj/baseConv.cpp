/*******************************************************************************
 *  Author      : Kashyap R Puranik ( kashthealien at gmail dot com )
 *  fileName    : dualpal.cpp
 *  description : converts a number from base 10 to base x(input)
 *
 *  date        :12.09.2009 14:20:05
 ******************************************************************************/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// This function converts a number from base 10 to the input base
// String is the output string and base is the base of the number
// num is the input number
string baseConvert( long long int num, int base)
{
    long long int x;                        // A temporary variable
    stack<int> que;                         // A stack for LIFO storage
    string answer;                          // The required string

    while ( num != 0 )
    {
        x = num % base;
        num /= base;
        que.push(char(x<=9?(x+'0'):(x+'A'-10)));
    }
    while(!que.empty()){answer+=que.top();que.pop();}

    return answer;
}

// This function converts a number of given base to base 10 and returns it
// String num is the input string and base is the base of the number
long long int baseUnconvert(string num, int base)
{
    long long int result = 0;                   // The required answer
    long long int pow = 1;                      // pow = base ^ i
    int temp;                                   // temporary number
    int len = num.size();                       // length of input string
    int i;                                      // for loop counter

    for ( i = len - 1 ; i >= 0 ; i -- )
    {
        temp = (num[i]<='9')?(num[i]-'0'):(num[i]-'A'+10);
        result += temp * pow;
        pow *= base;
    }
    return (result);
}

int main()
{
	int t;
	cin >> t;
	while (t -- )
	{
		long long int num;                  // N as in input
		long long int num2;
		string value, value2;

		while(cin >> value >> value2)
		{
			// Convert value to base 10
			num = baseUnconvert( value, 36);
			num2= baseUnconvert( value2, 36);
			// Conver value to the second base
			value = baseConvert( num+num2, 36);
			cout << num << " " << num2 <<endl;
			cout << value << endl;
		}
	}
}
