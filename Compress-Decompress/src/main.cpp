// Compress-Decompress.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib>
#include "Compression.h"
#include "Decompress.h"
using namespace std;
int main()
{
	string filename= "compress_decompress_1";
	Compression file(filename);
	Decompress file1(file.name);
	string filename2 = "compress_decompress_2";
	Compression file2(filename2);
	Decompress file3(file2.name);
	
}
