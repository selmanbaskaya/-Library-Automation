#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Kitap
{
	public:

		string KitapAdi;
		string KitapYazariAdi;
		string KitapYazariSoyadi;
		string KitapYay�mevi;
		int	   KitapBasimYili;
		int    KitapAdeti;

		void KitapBilgi();
		void KitapYazdir();
		void KitapListele();
};

void Kitap::KitapBilgi()
{
	setlocale(LC_ALL, "Turkish");
	cout.setf(ios::right);

	cout<<""<<endl;

	cout<<setw(15)<<" ""Kitap Ad�n� Giriniz: ";
	cin>>KitapAdi;

	cout<<setw(15)<<" ""Kitab�n Yazar�n�n Ad�n� Giriniz: ";
	cin>>KitapYazariAdi;

	cout<<setw(15)<<" ""Kitab�n Yazar�n�n Soyad�n� Giriniz: ";
	cin>>KitapYazariSoyadi;

	cout<<setw(15)<<" ""Kitab�n Yay�mevini Giriniz: ";
	cin>>KitapYay�mevi;

	cout<<setw(15)<<" ""Kitab�n Bas�m Y�l�n� Giriniz: ";
	cin>>KitapBasimYili;

	cout<<setw(15)<<" ""Kitab�n Adetini Giriniz: ";
	cin>>KitapAdeti;
}

void Kitap::KitapYazdir()
{
	setlocale(LC_ALL, "Turkish");
	cout.setf(ios::right);

	cout<<setw(15)<<"Kitab�n Ad�: "<<KitapAdi<<endl;

	cout<<setw(15)<<"Kitab�n Yazar�n�n Ad�: "<<KitapYazariAdi<<endl;

	cout<<setw(15)<<"Kitab�n Yazar�n�n Soyad�: "<<KitapYazariSoyadi<<endl;

	cout<<setw(15)<<"Kitab�n Yay�mevi: "<<KitapYay�mevi<<endl;

	cout<<setw(15)<<"Kitab�n Bas�m Y�l�: "<<KitapBasimYili<<endl;

	cout<<setw(15)<<"Kitab�n Adeti: "<<KitapAdeti<<endl;
}

class Kutuphane
{
	public:
		Kitap Kitaplar[200];

		int KitapSayisi;

		fstream dosya;

		Kutuphane()
		{
			KitapSayisi=0;

			dosya.open("Du_Kutuphane.txt", ios::out|ios::in|ios::app);

			dosya.setf(ios::left);
		}

		void KitapEkle()
		{
			Kitaplar[KitapSayisi].KitapBilgi();

			//Kullan�m� k�saltmak i�in "Kitaplar[KitapSayisi]"'n� bir ba�ka de�i�kene yollayaca��m.

			Kitap x =Kitaplar[KitapSayisi];

			dosya<<setw(15)<<x.KitapAdi
				<<setw(15)<<x.KitapYazariAdi
				<<setw(15)<<x.KitapYazariSoyadi
				<<setw(15)<<x.KitapYay�mevi
				<<setw(15)<<x.KitapBasimYili
				<<setw(15)<<x.KitapAdeti<<endl;
		}

		void KitapBul(string KitapAdi)
		{
			fstream dosya;

			dosya.open("Du_Kutuphane.txt", ios::out|ios::in|ios::app);

			Kitap x;

			while (dosya.eof()!=true)
			{
				cout<<""<<endl;

				dosya>>x.KitapAdi;

				dosya>>x.KitapYazariAdi;

				dosya>>x.KitapYazariSoyadi;

				dosya>>x.KitapYay�mevi;

				dosya>>x.KitapBasimYili;

				dosya>>x.KitapAdeti;

				if (x.KitapAdi==KitapAdi)
				{
					x.KitapYazdir();
				}
			}

			dosya.close();

		}

		void KitapListele()
			{
				ifstream dosya;
				dosya.open("DU_Kutuphane.txt");
				char veri;
				while(!dosya.eof())
				{
					dosya.get(veri);
					cout<<veri;
				}
					dosya.close();
			}


		void KitapSil(string KitapAd)
                {
                        Kitap kitap;
                        char veri;
                        fstream dosya;
                        dosya.open("Du_Kutuphane.txt", ios::in | ios::app);
                        fstream dosya0;
                        dosya.open("Du_Kutuphane0.txt", ios::in | ios::out | ios::app);

                        while (dosya>>kitap.KitapAdi>>kitap.KitapYazariAdi
                                   >>kitap.KitapYazariSoyadi
                                   >>kitap.KitapYay�mevi
                                   >>kitap.KitapBasimYili
                                   >>kitap.KitapAdeti)
                        {
                                if (KitapAd != kitap.KitapAdi)
                                {
                                        Kitap x =Kitaplar[KitapSayisi];

                                        dosya0<<setw(15)<<x.KitapAdi
                                        <<setw(15)<<x.KitapYazariAdi
                                        <<setw(15)<<x.KitapYazariSoyadi
                                        <<setw(15)<<x.KitapYay�mevi
                                        <<setw(15)<<x.KitapBasimYili
                                        <<setw(15)<<x.KitapAdeti<<endl;
                                }
                        }

                        dosya.close();

                        remove("Du_Kutuphane.txt");

                        dosya0.close();

                        rename("Du_Kutuphane0.txt","Du_Kutuphane.txt");
                }
};



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Turkish");

	int secim;
	char karar;
	string ara;

	Kutuphane DU;

	do
	{   cout<<endl<<"	   			      ""D�zce �niversitesi K�t�phane Bilgi Sistemi"<<endl<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<"               ""MEN�"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<" * ""Rafa Kitap Eklemek ��in     -> 1"<<endl;
		cout<<" * ""Raftaki Kitab� Bulmak ��in  -> 2"<<endl;
		cout<<" * ""Raftan Kitap Silmek ��in    -> 3"<<endl;
		cout<<" * ""Sistemden ��kmak ��in       -> 4"<<endl;
		cout<<"------------------------------------"<<endl;
		cout<<" ""Hangi ��lemi Yapmak �stiyorsunuz? : ";
		cin>>secim;

		if (secim==1)
		{
			DU.KitapEkle();

			cout<<endl<<"Kitab�n�z Rafa Ba�ar�yla Eklenmi�tir.";
		}
	
		else if (secim==2)
		{
			cout<<""<<endl;

			cout<<"         ""Raftaki Kitaplar�m�z"<<endl;;
			cout<<"---------------------------------------"<<endl;
			
			DU.KitapListele();

			cout<<endl<<" ""Aramak �stedi�iniz Kitab�n Ad�n� Giriniz: ";
			cin>>ara;		

			DU.KitapBul(ara);

		}

		else if (secim==3)
		{
			cout<<endl<<"   ""Sistemimiz Size Daha �yi Hizmet Verebilmek ��in Yenileniliyor."
				<<endl<<"   ""Anlay���n�z ��in Te�ekk�r Ederiz."<<endl;
		}

		else if (secim==4)
		{
			exit (1);
		}

		else
		{
			cout<<endl<<"   ""Yanl�� Bir Se�im Yapt�n�z."<<endl; 

			cout<<endl<<"   ""Tekrar Se�im Yapmak �ster Misiniz? (E / e) : ";
  			cin >> karar; 

  			if (karar == 'E' || karar=='e') 
			{
				continue; 
			}
  			
  			else 
			{
				break; 
			}	
		}

  		cout<<endl<<"   ""Ba�ka i�lem Yapmak �ster Misiniz? (E / e) : ";
  		cin >> karar; 

  		if (karar == 'E' || karar=='e') 
		{
			continue; 
		}
  			
  		else 
		{
			break; 
		}	

	} while (1);


	system("pause");
	return 0;
}