/** 
* @file G181210054
* @description Programınızın açıklaması ne yaptığına dair.
* @course 2-C
* @assignment 1.Odev
* @date Kodu 05.11.2021
* @author Merve Keçeli / merve.keceli@ogr.sakarya.edu.tr
*/

#include "Liste.hpp"
#include <iostream>
#include <string>

using namespace std;

Liste::Liste(){
	basDugum = 0;
	dugumSayisi = 0;
}

void Liste::ekle(string veri){
	Dugum* yeni = new Dugum(veri);
	
	if(basDugum == 0){
		basDugum = yeni;
	}
	else{
		Dugum* temp = basDugum;
		while(temp->ileri != 0){
			temp = temp->ileri;
		}
		temp->ileri = yeni;
		yeni->geri = temp;
	}
	dugumSayisi++;
}

void Liste::arayaEkle(string veri, int index){
	if(index == 0 && basDugum == 0){
		basDugum = new Dugum(veri);
	}
	else{
		Dugum* secilenDugum = dugumGetir(index);
		
		if(secilenDugum == 0) return;
		
		Dugum* yeni = new Dugum(veri);
		Dugum* oncekiDugum = secilenDugum->geri;
		
		secilenDugum->geri = yeni;
		yeni->ileri = secilenDugum;
		yeni->geri = oncekiDugum;
		
		if(oncekiDugum)
			oncekiDugum->ileri = yeni;
		else
			basDugum = yeni;
	}
	dugumSayisi++;
}

void Liste::sil(){
	if(basDugum == 0) return;
	if(basDugum->ileri == 0){
		delete basDugum;
		basDugum = 0;
	}
	else{
		Dugum* temp = sondanBirOncekiDugum();
		delete temp->ileri;
		temp->ileri = 0;
	}
	dugumSayisi--;
}

void Liste::aradanSil(int index){
	Dugum* silinecek = dugumGetir(index);
	if(silinecek == 0) return;
	
	Dugum* prev = silinecek->geri;
	Dugum* next = silinecek->ileri;
	
	delete silinecek;
	
	if(next)
		next->geri = prev;
	if(prev)
		prev->ileri = next;
	else
		basDugum = next;
	dugumSayisi--;
}

void Liste::yazdir(){
	Dugum* temp = basDugum;
	while(temp->ileri != 0){
		cout<<temp->getirVeri()<<" <-> ";
		temp= temp->ileri;
	}
	cout<<temp->getirVeri();
}

int Liste::dugumSayisiGetir(){
	return dugumSayisi;
}

Dugum* Liste::dugumGetir(int index){
	if(index < 0 || index > dugumSayisi)
		return 0;
	
	Dugum* temp = basDugum;
	for(int i = 0; i < index; i++)
		temp = temp->ileri;
	return temp;
}

Dugum* Liste::sondanBirOncekiDugum(){
	if(basDugum == 0) return 0;
	if(basDugum->ileri == 0) return basDugum;
	
	Dugum* temp = basDugum;
	while(temp->ileri->ileri != 0){
		temp = temp->ileri;
	}
	return temp;
}

Liste::~Liste(){
	Dugum* temp = basDugum;
	while(temp != 0){
		Dugum* silinecek = temp;
		temp = temp->ileri;
		
		delete silinecek;
	}
}