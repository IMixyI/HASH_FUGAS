#include <filesystem>
#include <fstream>
#include <iostream>
#include <direct.h>
#include "streebog.hpp"
#include "utils.hpp"
#include <string>
int main() 
{
	setlocale(0, "");
	std::string path = "C:\\Users\\merzl\\source\\repos\\file.txt";
	Streebog hash ,hash1,hash2,hash3,hash4;
	hash.init();
	hash1.init();
	hash2.init();
	hash3.init();
	hash4.init();
	std::string s = "";
	std::string chit;
		std::ifstream file(path);
		if (file.is_open()) 
		{
			while(getline(file,chit))
			{
				s += chit;
			}
			int del = s.length() / 4;
			std::string s1 = "";
			std::string s2 = "";
			std::string s3 = "";
			std::string s4 = "";
			for (int i = 0; i < del; i++)
			{
				s1 += s[i];
			}
			for (int i = del; i < 2*del; i++)
			{
				s2 += s[i];
			}
			for (int i = 2 * del; i < 3*del; i++)
			{
				s3 += s[i];
			}
			for (int i = 3 * del; i < s.length(); i++)
			{
				s4 += s[i];
			}
			std::ofstream file1("C:\\Users\\merzl\\source\\repos\\file1.txt");
			file1 << s1 << '\n';
			file1.close();
			std::ofstream file2("C:\\Users\\merzl\\source\\repos\\file2.txt");
			file2 << s2 << '\n';
			file2.close();
			std::ofstream file3("C:\\Users\\merzl\\source\\repos\\file3.txt");
			file3 << s3 << '\n';
			file3.close();
			std::ofstream file4("C:\\Users\\merzl\\source\\repos\\file4.txt");
			file4 << s4 << '\n';
			file4.close();
			std::ifstream file1r("C:\\Users\\merzl\\source\\repos\\file1.txt");
			if (file1r.is_open())
			{
				std::ifstream copy_file1("C:\\Users\\merzl\\source\\repos\\file1.txt");
				hash.update(file1r);
				hash1.update(copy_file1);
				file1r.close();
				copy_file1.close();
			}
			std::ifstream file2r("C:\\Users\\merzl\\source\\repos\\file2.txt");
			if (file2r.is_open())
			{
				std::ifstream copy_file2("C:\\Users\\merzl\\source\\repos\\file2.txt");
				hash.update(file2r);
				hash2.update(copy_file2);
				file2r.close();
				copy_file2.close();
			}
			std::ifstream file3r("C:\\Users\\merzl\\source\\repos\\file3.txt");
			if (file3r.is_open())
			{
				std::ifstream copy_file3("C:\\Users\\merzl\\source\\repos\\file3.txt");
				hash.update(file3r);
				hash3.update(copy_file3);
				file3r.close();
				copy_file3.close();
			}
			std::ifstream file4r("C:\\Users\\merzl\\source\\repos\\file4.txt");
			if (file4r.is_open())
			{
				std::ifstream copy_file4("C:\\Users\\merzl\\source\\repos\\file4.txt");
				hash.update(file4r);
				hash4.update(copy_file4);
				file4r.close();
				copy_file4.close();
			}
			file.close();
		}
	std::cout << "1 хеш-сумма: " << bytesToHexString(hash1.digest()) << '\n';
	std::cout << "2 хеш-сумма: " << bytesToHexString(hash2.digest()) << '\n';
	std::cout << "3 хеш-сумма: " << bytesToHexString(hash3.digest()) << '\n';
	std::cout << "4 хеш-сумма: " << bytesToHexString(hash4.digest()) << '\n';
	std::cout <<"Общая хеш-сумма: " << bytesToHexString(hash.digest()) << '\n';
	return 0;
}