/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: puzzle.cpp
 *	description : solves the problem in oct 09 codechef by the name 'A Puzzle'
 *
 *	date 		: 10/10/2009 15:42:09 
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <map>

#define isPrime(x) ( (x) == 2 || (x) == 3 || (x) == 5 || (x) == 7 || (x) == 11 || (x) == 13 || (x) == 17 )

class array9
{
public:
	int nums[9];
	int height;
	bool operator ==( array9 a) const
	{
		for(int i = 0 ; i < 9 ; i ++ ) if (nums[i]!=a.nums[i]) return 0;
		return 1;		
	}
	bool operator <(const array9 &a) const
	{
		if (nums[0]<a.nums[0]) return 1;
		if (nums[0]>a.nums[0]) return 0;
		if (nums[1]<a.nums[1]) return 1;
		if (nums[1]>a.nums[1]) return 0;
		if (nums[2]<a.nums[2]) return 1;
		if (nums[2]>a.nums[2]) return 0;
		if (nums[3]<a.nums[3]) return 1;
		if (nums[3]>a.nums[3]) return 0;
		if (nums[4]<a.nums[4]) return 1;
		if (nums[4]>a.nums[4]) return 0;
		if (nums[5]<a.nums[5]) return 1;
		if (nums[5]>a.nums[5]) return 0;
		if (nums[6]<a.nums[6]) return 1;
		if (nums[6]>a.nums[6]) return 0;
		if (nums[7]<a.nums[7]) return 1;
		if (nums[7]>a.nums[7]) return 0;
		if (nums[8]<a.nums[8]) return 1;
		if (nums[8]>a.nums[8]) return 0;
		return 0;	
	}
	bool final();
};

bool array9::final()
{
	for ( int i = 0; i < 9 ; i ++ ){ if (nums[i] != i+1){ return 0;}}
	return 1;
}

using namespace std;

queue< array9 > open;
set< array9 > closed;
array9 final;

void swapDig( array9 *array,int x,int y)
{
	int temp;
	temp = array -> nums[x];
	array->nums[x] = array -> nums[y];
	array->nums[y] = temp;
	array->height++;
}
// This implements depth first search
int search()
{
	array9 num;
	array9 temp;
	int i;
	int a, b;

	// If no other move is possible end here
	while(! open.empty())
	{
		// See if the current number is the final number
		num = open.front();
		if (num.final()) 
		{ final.height = num.height; return 1;}
		open.pop();
		
		// If the number was not the required solution
		// generate children and add to the stack and to the closed list
		a=num.nums[0]; b=num.nums[1];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,0,1);
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[1]; b=num.nums[2];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,1,2); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[3]; b=num.nums[4];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,3,4); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[4]; b=num.nums[5];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,4,5); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[6]; b=num.nums[7];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,6,7); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[7]; b=num.nums[8];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,7,8); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[0]; b=num.nums[3];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,0,3); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[3]; b=num.nums[6];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,3,6); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[1]; b=num.nums[4];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,1,4); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[4]; b=num.nums[7];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,4,7); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[2]; b=num.nums[5];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,2,5); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
		a=num.nums[5]; b=num.nums[8];
		if (isPrime(a+b))
		{	temp = num; swapDig(&temp,5,8); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);}}
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while ( t -- )
	{
		int i;							// for loop counter
		array9 num;				// The starting number sequence
		int temp;						// A temporary variable for input
		
		for ( i = 0 ; i < 9 ; i ++ ){
			scanf("%d", &temp);
			num.nums[i] = temp;
			final.nums[i] = i+1;
		}
		num.height = 0;
		final.height = -1;
		// Initialise open and closed		
		while(!open.empty())open.pop();
		closed.clear();
		// Add the initial number to open
		open.push(num);
		// Add it to closed also
		closed.insert(num);
		search();					// Start the depth first search
		printf("%d\n",final.height);
	}
}
