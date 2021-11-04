/** 
* @file G181210054
* @description Programınızın açıklaması ne yaptığına dair.
* @course 2-C
* @assignment 1.Odev
* @date Kodu 05.11.2021
* @author Merve Keçeli / merve.keceli@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"
#include <string>
using namespace std;

Dugum::Dugum(string veri){
	this->veri = veri;
	ileri = geri = 0;
}

string Dugum::getirVeri(){
	return this->veri;
}

Dugum::~Dugum(){
	
}