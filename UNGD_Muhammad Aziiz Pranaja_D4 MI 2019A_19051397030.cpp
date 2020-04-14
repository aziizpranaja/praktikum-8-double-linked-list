#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



typedef struct node

{

	string password;

	node* next;

	node* prev;

}*list;



list head;

list tail;

int batas;



void initData()

{

	head = NULL;

	tail = NULL;

}



int cekHead()

{

	return (head == NULL) ? 1 : 0;

}



void tampilList()

{

	list bantu;

	bantu = head;

	if (cekHead() == 1)

	{

		cout << "Password Masih Kosong";

	}

	else

	{

		for (int x = 1; x <= batas; x++)

		{

			cout << "Karakter Ke-" << x << " : " << bantu->password << endl;

			bantu = bantu->next;

		}

	}

}



void tampilListBaru()

{

	list bantu;

	bantu = head;

	if (cekHead() == 1)

	{

		cout << "Password Masih Kosong";

	}

	else

	{

		for (int x = 1; x <= batas; x++)

		{

			cout << bantu->password;

			bantu = bantu->next;

		}

	}

}






void hapusSemua()

{

	list bantu;

	list hapus;

	if (cekHead() == 1)

	{

		system("cls");

		cout << "Password Masih Kosong\n\n";

		system("pause");

		system("cls");

	}

	else

	{

		bantu = head;

		while (bantu != tail)

		{

			hapus = bantu;

			bantu = bantu->next;

			delete hapus;

		}

		head = NULL;

		tail = NULL;

		batas = 0;

		delete bantu;

		system("cls");

		cout << "Password Telah Terhapus\n\n";

		system("pause");

		system("cls");

	}

}



void gantiData(list insert, int nomor)

{

	list bantu;

	if (cekHead() == 1)

	{

		system("cls");

		cout << "Password Masih Kosong\n\n";

		system("pause");

		system("cls");

	}

	else

	{

		if (nomor == 1)

		{

			bantu = head;

			insert->next = bantu->next;

			bantu->next->prev = insert;

			insert->prev = tail;

			tail->next = insert;

			head = insert;

			delete bantu;

			system("cls");

			cout << "Karakter Ke-" << nomor << " Telah Diganti\n\n";

			system("pause");

			system("cls");

		}

		else if (nomor == batas)

		{

			bantu = tail;

			bantu->prev->next = insert;

			insert->prev = bantu->prev;

			insert->next = head;

			head->prev = insert;

			tail = insert;

			delete bantu;

			system("cls");

			cout << "Karakter Ke-" << nomor << " Telah Diganti\n\n";

			system("pause");

			system("cls");

		}

		else if ((nomor > batas) || (nomor < 0))

		{

			system("cls");

			cout << "No Urutan Tidak Ditemukan\n\n";

			system("pause");

			system("cls");

		}

		else

		{

			bantu = head;

			for (int x = 1; x < nomor; x++)

			{

				bantu = bantu->next;

			}

			bantu->prev->next = insert;

			insert->prev = bantu->prev;

			insert->next = bantu->next;

			bantu->next->prev = insert;

			delete bantu;

			system("cls");

			cout << "Karakter Ke-" << nomor << " Telah Diganti\n\n";

			system("pause");

			system("cls");

		}

	}

}

void Enkripsi()

{

	list bantu, tempat;

	char random;

	bantu = head;

	for (int x = 1; x <= batas; x++)

	{

		if (x == batas - 2)

		{

			bantu->prev->next = NULL;

			bantu->prev = NULL;

			head = bantu;

		}

		else

		{

			bantu = bantu->next;

		}

	}



	bantu = head;

	do

	{

		bantu = bantu->next;

	} while (bantu->next != NULL);

	tail = bantu;

	head->prev = tail;

	tail->next = head;



	int jarak, a, b, hasil;

	jarak = 33 - 47;

	a = rand();

	b = a % jarak;

	hasil = b + 33;

	random = hasil;



	tempat = new node;

	tempat->password = random;

	bantu = head;

	for (int x = 1; x <= 3; x++)

	{

		bantu = bantu->next;

	}

	bantu->prev->next = tempat;

	tempat->prev = bantu->prev;

	tempat->next = bantu;

	bantu->prev = tempat;

	batas++;

}



void Deskripsi()

{

	list bantu, hapus;

	hapus = bantu = head;

	for (int x = 1; x <= 3; x++)

	{

		hapus = hapus->next;

	}

	hapus->prev->next = hapus->next;

	hapus->next->prev = hapus->prev;

	delete hapus;

	batas--;



	for (int x = 1; x <= 3; x++)

	{

		bantu = bantu->next;

	}

	bantu->prev->next = NULL;

	bantu->prev = NULL;

	head = bantu;



	bantu = head;

	do

	{

		bantu = bantu->next;

	} while (bantu->next != NULL);

	tail = bantu;

	head->prev = tail;

	tail->next = head;

}



void SalahMemasukkan()

{

	system("cls");

	cout << "Anda Salah Memasukkan Input\n\n";

	system("pause");

}



void KeluarProgram()

{

	system("cls");

	cout << "Anda Keluar Program \n\n";

	system("pause");

}



int main()

{

	initData();

	list n;

	list bantu;

	bantu = new node;

	do

	{

		unsigned short int pilihan, urutan, count = 0;

		string data;

		system("cls");

		cout << "Program Enkripsi dan Deskripsi Password\n\n";

		system("pause"); system("cls");

		cout << "Pilih Yes untuk Memulai Program Enkripsi dan Deskripsi  \n1. Yes\n2. No\n\nPilihan: ";

		cin >> pilihan;

		switch (pilihan)

		{

		case 1:

			system("cls");

			cout << "Masukkan Panjang Password: ";

			cin >> batas;

			if (batas < 6)

			{

				system("cls");

				cout << "Panjang Password Harus Lebih Besar Sama Dengan 6!! \n\n";

				system("pause");

				system("cls");

				break;

			}

			else

			{

				system("cls");

				for (int x = 1; x <= batas; x++)

				{

					if (x == 1)

					{

						cout << "Masukkan Karakter Ke-" << x << " : ";

						cin >> data;

						n = new node;

						n->password = data;

						n->prev = tail;

						head = n;

						bantu = n;

					}

					else if (x == batas)

					{

						cout << "Masukkan Karakter Ke-" << x << " : ";

						cin >> data;

						n = new node;

						n->password = data;

						bantu->next = n;

						n->prev = bantu;

						n->next = head;

						tail = n;

						head->prev = tail;

						bantu = head;

						cout << "Password Telah Masuk Ke Data Store\n\n";

						system("pause");

						system("cls");

					}

					else

					{

						cout << "Masukkan Karakter Ke-" << x << " : ";

						cin >> data;

						n = new node;

						n->password = data;

						bantu->next = n;

						n->prev = bantu;

						bantu = bantu->next;

					}

				}

				do

				{

					system("cls");

					cout << "Pengoperasian Password "<<endl;
					cout<<"1. Tampilkan Data"<<endl;
					cout<<"2. Enkripsi Password"<<endl;
					cout<<"3. Deskripsi Password"<<endl;
					cout<<"4. Hapus Semua Data"<<endl;
					cout<<"5. Ganti Data"<<endl;
					cout<<"6. Keluar Program\n\nPilihan: ";

					cin >> pilihan;

					switch (pilihan)

					{

					case 1:

						system("cls");

						tampilList();

						cout << endl << endl;

						system("pause");

						system("cls");

						break;

					case 2:

						switch (count)

						{

						case 0:

							system("cls");

							cout << "Password Asli: ";

							tampilListBaru();

							Enkripsi();

							cout << "\nPassword Setelah Di Enkripsi: ";

							tampilListBaru();

							cout << endl << endl;

							system("pause");

							system("cls");

							count++;

							break;

						default:

							system("cls");

							cout << "Password Sudah Di Enkripsi\n\n";

							cout << endl << endl;

							system("pause");

							system("cls");

							break;

						}

						break;

					case 3:

						switch (count)

						{

						case 1:

							system("cls");

							cout << "Password Sebelum Di Deskripsi: ";

							tampilListBaru();

							Deskripsi();

							cout << "\nPassword Setelah Di Deskripsi: ";

							tampilListBaru();

							cout << endl << endl;

							system("pause");

							system("cls");

							count--;

							break;

						default:

							system("cls");

							cout << "Password Sudah Di Deskripsi\n\n";

							cout << endl << endl;

							system("pause");

							system("cls");

							break;

						}

						break;

				
					case 4:

						system("cls");

						hapusSemua();

						break;

					case 5:

						system("cls");

						tampilList();

						cout << endl << endl;

						cout << "Masukkan Nomor Urutan: ";

						cin >> urutan;

						cout << "Masukkan Karakter Baru: ";

						cin >> data;

						n = new node;

						n->password = data;

						gantiData(n, urutan);

						break;

					case 6:

						KeluarProgram();

						return 0;

						break;

					default:

						SalahMemasukkan();

						return 0;

						break;

					}

				} while (true);

			}

			

		case 2:

			KeluarProgram();

			return 0;

		default:

			SalahMemasukkan();

			return 0;

		}

	} while (true);

}
