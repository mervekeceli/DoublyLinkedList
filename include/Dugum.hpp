#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>

using namespace std;
class Dugum{
	public: 
		string veri;
		Dugum* ileri;
		Dugum* geri;
		
		Dugum(string veri);
		string getirVeri();
		~Dugum();
};

#endif