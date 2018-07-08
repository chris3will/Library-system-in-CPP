#pragma once
#include<iostream>
using namespace std;
bool SubSequence(const string &text, const string &pattern ,int loc[]) {
	int tLength = text.Length();
	int pLength = pattern.Length();

	if (pLength > tLength) {
		return false;
	}
	for (int i = 0, j = 0; i < tLength && j < pLength; j++) {
		for ( ;  i<= tLength && text[i]!=pattern[j]; i++){
			if (i > tLength)
				return false;
			else
			{
				loc[j] = i;
			}
		}
	}
	return true;
}