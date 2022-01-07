

#include "Header.h"
int main()
{
#pragma region setup
	SetConsoleTitle(L"Rút tiền ATM");
	// ẩn con trỏ
	ShowCur(false);
	system("mode con: cols=250 lines=65");
	// để in ra được kí tự trong txt
	SetConsoleOutputCP(65001);
	system("cls");
#pragma endregion
#pragma region location
#pragma endregion
	printf("Xin hay mo full screen!\n");
	system("pause");
	system("cls");
	int x_input, y_input;
	char So_TK[11];
	long int Tien_Rut;
	x_input = 67;
	y_input = 56;
	int chon = -1;
	int vitri = -1;
	stk_atm();
	Label(1);
	in_Money();
	//in_Tien();
	do {
		in_Option();
		Chon(x_Cursor, y_Cursor, chon);
		switch (chon)
		{
		case 1:
			vitri = -1;
			gotoXY(x_input, y_input);
			do {
				printf("Nhap so tai khoan: ");
				gets_s(So_TK);
				vitri = check_TaiKhoan(So_TK);
				if (vitri == -1)
				{
					clear_input(x_input, y_input);
					printf("So tai khoan khong ton tai, moi nhap lai!");
					getch();
					clear_input(x_input, y_input);
				}
				else
				{
					clear_input(x_input, y_input);
					printf("Dang nhap thanh cong, moi ban rut tien");
					in_Login(Cac_TaiKhoan[vitri].STK);
					getch();
					clear_input(x_input, y_input);
				}
			} while (vitri == -1);
			break;
		case 2:
			if (vitri == -1)
			{
				clear_input(x_input, y_input);
				printf("Xin hay dang nhap truoc!");
				getch();
				clear_input(x_input, y_input);

				break;
			}

			gotoXY(x_input, y_input);
			if (Cac_TaiKhoan[vitri].SoDu == 0)
			{
				clear_input(x_input, y_input);
				printf("So tien trong tai khoan cua ban da het");
				getch();
				clear_input(x_input, y_input);
				break;
			}
			else if (TongTien_ATM == 0)
			{
				clear_input(x_input, y_input);
				printf("So tien trong ATM da het");
				getch();
				clear_input(x_input, y_input);
				break;
			}
			do {
				
				clear_input(x_input, y_input);
				printf("Nhap so tien muon rut: ");
				scanf_s("%ld", &Tien_Rut);
				if (Tien_Rut > TongTien_ATM) // Tiền rút lớn hơn tiền trong atm
				{
					clear_input(x_input, y_input);
					printf("So tien rut hon Tong Tien ATM, moi nhap lai");
					getch();
					clear_input(x_input, y_input);
				}
				else if (Tien_Rut % 50000 != 0) // Số nhập vào phải là bội số của 50.000
				{
					clear_input(x_input, y_input);
					printf("Xin hay nhap tien co boi so 50000, moi nhap lai");
					getch();
					clear_input(x_input, y_input);
				}
				else if (Tien_Rut > Cac_TaiKhoan[vitri].SoDu) // Tiền rút lớn hơn số dư của tài khoản
				{
					clear_input(x_input, y_input);
					printf("Tien rut ban nhap > hon tien co trong tai khoan, moi nhap lai");
					getch();
					clear_input(x_input, y_input);
				}
				else if (Tien_Rut > 5000000) // Không được rút quá 5 triệu
				{
					clear_input(x_input, y_input);
					printf("Ban khong duoc rut qua 5 trieu, moi nhap lai");
					getch();
					clear_input(x_input, y_input);
				}
				else if (Tien_Rut == Cac_TaiKhoan[vitri].SoDu)
				{
					clear_input(x_input, y_input);
					printf("Ban khong duoc rut het tien trong tai khoan");
					getch();
					clear_input(x_input, y_input);
				}
			} while (Tien_Rut > TongTien_ATM || Tien_Rut % 50000 != 0 || Tien_Rut > Cac_TaiKhoan[vitri].SoDu || Tien_Rut > 5000000 || Tien_Rut == Cac_TaiKhoan[vitri].SoDu);
			clear_Option();
			in_Option_RutTien();
			Chon(x_Cursor, y_Cursor, chon);
			switch (chon)
			{
			case 1:
				QuickSort_GiamDan(Tien_ATM, 0, N - 1);
				RutTien_ItToTienNhat(Tien_ATM, Tien_Rut,Cac_TaiKhoan[vitri].SoDu);
				in_Money();
				in_STK();
				in_Tien();
				break;
			case 2:
				QuickSortSL(Tien_ATM, 0, N - 1);
				XapXepSLBangNhau(Tien_ATM, N);
				RutUuTienTTNN(Tien_ATM, N, Tien_Rut, Cac_TaiKhoan[vitri].SoDu);
				in_Money();
				in_STK();
				in_Tien();
				break;
			case 3:
				QuickSort_TangDan(Tien_ATM, 0, N - 1);
				RutTien_NhieuToTienNhat(Tien_ATM, Tien_Rut, Cac_TaiKhoan[vitri].SoDu);
				in_Money();
				in_STK();
				in_Tien();
				chon = 1;
				break;
			}
			clear_input(x_input, y_input);
			clear_Option();
			cin.ignore();
			break;
		case 3:
			backup();
			system("cls");
			break;
		default:
			break;
		}

	} while (chon != 3);
	_getch();
	return 0;
}