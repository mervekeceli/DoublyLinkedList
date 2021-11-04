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
	
	ifstream oku("Veri.txt");
	string satir = "";
	string temp = "";
	int index = 0;
	if(oku.is_open()){
		while(getline(oku,satir,'\n')){
			
			char islemDegeri = satir[0];
			// 0 ın ascii karşılığı 48 dir ve sayıların değerlerini bulmak için de ascii değerlerinden 0 değerlerini çıkardım.
			int index = satir[2] - 48;
			if(islemDegeri == 'E'){
				for(int i = 4; i < satir.length() - 1; i++){
					temp += satir[i];
				}
				
				if(index < liste->dugumSayisiGetir()){
					liste->arayaEkle(temp,index);
				}
				else
					liste->ekle(temp);	
				temp = "";
			}
			else{
				if(index < liste->dugumSayisiGetir())
					liste->aradanSil(index);
				else
					liste->sil();
				temp = "";
			}
			
		}
		oku.close();
		
		liste->yazdir();
	}
	return 0;
}