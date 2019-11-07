﻿/*
Given a string s and an int k, return an int representing the number of substrings (not unique) 
of s with exactly k distinct characters. 
If the given string doesn't have k distinct characters, return 0.

Example 1:

Input: s = "pqpqs", k = 2
Output: 7
Explanation: ["pq", "pqp", "pqpq", "qp", "qpq", "pq", "qs"]
Example 2:

Input: s = "aabab", k = 3
Output: 0
Constraints:

The input string consists of only lowercase English letters [a-z]
0 ≤ k ≤ 26
*/


#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "pqpqs";
	int k = 2;

	//look at first character in string
	//compare first character with next character 
	//
}