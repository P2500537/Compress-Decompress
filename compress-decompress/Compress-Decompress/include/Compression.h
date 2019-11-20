#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
class Compression
{
private:
	int i;
	int i_thesame;
	
	fstream file;
	fstream saveto;
	string line;
	string s_lineb;
	string s_saveLine;
	string s_saveLineb;
	string s_filename;
	double C_R;
public:
	string name;
	Compression();
	Compression(string filename);
	void CompressionRatio(double a, double b);
	~Compression();
};

