/** 
* @file G181210054
* @description Programınızın açıklaması ne yaptığına dair.
* @course 2-C
* @assignment 1.Odev
* @date Kodu 05.11.2021
* @author Merve Keçeli / merve.keceli@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream> 
#include "Liste.hpp"

using namespace std;

int main(){
	setlocale(LC_ALL,"Turkish");
	Liste* liste = new Liste();
	
	string satir = "" , temp = "";
	int index = 0, alinanSayi = 0;
	
	ifstream oku("Veri.txt");
	if(oku.is_open()){
		while(getline(oku,satir,'\n')){
			
			char islemDegeri = satir[0];
			
			if(islemDegeri == 'E'){
				for(int i = 2; i < satir.length(); i++){
					if(satir[i] == '#')
					{
						index = i;
						break;
					}
					else
						temp += satir[i];
				}
				alinanSayi = stoi(temp);
				temp = "";
				
				for(int i = index + 1; i < satir.length() - 1; i++){
					temp += satir[i];
				}
				
				if(alinanSayi < liste->dugumSayisiGetir()){
					liste->arayaEkle(temp,alinanSayi);
				}
				else
					liste->ekle(temp);	
				temp = "";
			}
			else{
				for(int i = 2; i < satir.length() - 1; i++){
					temp += satir[i];
				}
				alinanSayi = stoi(temp);
				
				if(alinanSayi < liste->dugumSayisiGetir())
					liste->aradanSil(alinanSayi);
				else
					liste->sil();
				temp = "";
			}
		}
	}
	oku.close();
	liste->yazdir();
	delete liste;
	return 0;
}