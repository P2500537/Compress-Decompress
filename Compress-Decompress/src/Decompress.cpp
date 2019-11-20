#include "Decompress.h"


Decompress::Decompress(string filename)
{
	c = false;
	s_filename = "Readme/" + filename+".txt";
	file.open(s_filename, ios::in);
	saveto.open("Readme/" + filename + "DecompressionOutput.txt", ios::out | ios::app);
	if (file.good() == true)
	{
		while (getline(file, line))
		{
			for (int i = 0; i <= line.length()-1; i++) {
				if (toascii(line[i]) == 32 || toascii(line[i]) >= 48 && toascii(line[i]) <= 57 || toascii(line[i]) >= 65 && toascii(line[i]) <= 90 || toascii(line[i]) >= 97 && toascii(line[i]) <= 122) {
					if(toascii(line[i]) == 32){
						s_saveLine += ' ';
				}
				else {
					i_st = toascii(line[i]) - 48;
					i++;
					while (i_st-- >= 1)
					{
						s_saveLine += line[i];
					}
				}
				}
				else
				{
					if (line[i] == ';')
					{
						i++;
						i_bignum = 0;
						while (line[i] != ';')
						{	
							if (line[i + 1] == ';')
							{
								i++;
							}else{
							i_bignum = i_bignum * 10 + line[i]-'0';
							i++;
							cout << i_bignum<<endl;
							}
						}

						while (i_bignum-- > 0)
						{
							s_saveLine += line[i-1];
						}
					}else{
					s_saveLine += line[i];
					}
				}
				
				
			}
			saveto << s_saveLine << endl;
			s_saveLineb += s_saveLine;
			s_lineb += line;
			s_saveLine.clear();
		}

	}
	else {
		cout << "Decompression Error !! Wrong file name!!" << endl;
		exit(0);
	}
	cout << s_lineb.length() << endl;
	cout << s_saveLineb.length() << endl;
	CompressionRatio(s_lineb.length(), s_saveLineb.length());

	saveto.close();
	file.close();
}
void Decompress::CompressionRatio(double a, double b)
{
	cout << "Compression Ratio: " << b / a << endl;
}

Decompress::~Decompress()
{
}
