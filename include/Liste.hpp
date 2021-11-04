#ifndef LISTE_HPP
#define LISTE_HPP

#include "Dugum.hpp"

using namespace std;
class Liste{
	public:
		Liste();
		void ekle(string veri);
		void arayaEkle(string veri, int index);
		void sil();
		void aradanSil(int index);
		void yazdir();
		int dugumSayisiGetir();
		~Liste();
		
	private:
		int dugumSayisi;
		Dugum* basDugum;
		Dugum* dugumGetir(int index);
		Dugum* sondanBirOncekiDugum();
		
};

#endif