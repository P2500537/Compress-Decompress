#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
class Decompress
{
private:
	int i_bignum;
	int i_st;
	bool c;
	string::size_type sz;
	fstream file;
	fstream saveto;
	string line;
	string s_lineb;
	string s_saveLine;
	string s_saveLineb;
	string s_filename;
	string s_bignum;
	double C_R;
public:
	Decompress(string filename);
	void CompressionRatio(double a, double b);
	~Decompress();
};

