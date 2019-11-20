#include "Compression.h"

Compression::Compression()
{
}
Compression::Compression(string filename)
{
	s_filename = "data/" + filename+".txt";
	file.open(s_filename, ios::in);
	saveto.open("Readme/"+ filename+"CompressionOutput.txt", ios::out | ios::app);
	name = filename + "CompressionOutput";
	if (file.good()==true)
	{
		i = 0;
		i_thesame = 1;
		while (getline(file, line))
		{
			for (int i=0; i < line.length();i++) {
				if (toascii(line[i]) == 32 || toascii(line[i]) >= 48 && toascii(line[i]) <= 57 || toascii(line[i]) >= 65 && toascii(line[i]) <= 90 || toascii(line[i]) >= 97 && toascii(line[i]) <= 122) {
					if (line[i] == char(' '))
					{
						s_saveLine += " ";
					}
					else {
						if (line[i] == line[i + 1])
						{
							i_thesame++;

						}
						else
						{
							if (i_thesame >= 10) {
								s_saveLine += ";";
							}
							s_saveLine += to_string(i_thesame);
							s_saveLine += line[i];
							if (i_thesame >= 10) {
								s_saveLine += ";";
							}
							i_thesame = 1;
						}
					}
				}else
				{
					s_saveLine += line[i];
				}
			}

		saveto << s_saveLine << endl;
		s_saveLineb += s_saveLine;
		s_lineb += line;
		s_saveLine.clear();
		}
		
	}
	else {
		cout << "Compression Error !! Wrong file name!!" << endl;
		exit(0);
	}
	//cout << s_lineb.length() << endl;
	//cout << s_saveLineb.length() << endl;
	CompressionRatio(s_lineb.length(), s_saveLineb.length());
	
	saveto.close();
	file.close();
}
void Compression::CompressionRatio(double a, double b)
{
cout << "Compression Ratio: " << a / b << " Output file: " + name + ".txt" << endl;
}
Compression::~Compression()
{
}
