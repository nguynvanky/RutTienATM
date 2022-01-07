#pragma once
#ifndef Header_h
#define Header_h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string>
struct ATM {
	int value, quantum;
	int out = 0;
};
struct STK {
	char STK[10];
	long int SoDu;
};
extern int N,nTaiKhoan; // loai tien
extern ATM* Tien_ATM;
extern STK* Cac_TaiKhoan;
extern int x_Cursor, y_Cursor;
extern int TongTien_ATM;

using namespace std;
#define MAX			1000
#define key_Up		72
#define key_Down	80
#define key_Enter	13
#define key_ESC		27

void Chon(int x, int y, int &chon);
void Label(int time);
void stk_atm();
void in_STK();
long int money_atm();
void in_Money();
void in_Tien();
void clear_input(int x,int y);
int check_TaiKhoan(char So_TaiKhoan[]);
void in_Option();
void in_Login(char *s);
void clear_Option();
void in_Option_RutTien();
void QuickSort_GiamDan(ATM ds[], int left, int right);
void QuickSort_TangDan(ATM ds[], int left, int right);
void in_TienRut(ATM ds[], int N, int TienRut);
void RutTien_ItToTienNhat(ATM TienATM[], int TienCanRut, long int& SoDu);
void RutTien_NhieuToTienNhat(ATM TienATM[], int TienCanRut, long int& SoDu);
int chon(int TienCanRut, int SoLuong, int GiaTri);
void RutUuTienTTNN(ATM TienATM[], int n, int TienCanRut,long int& SoDu);
void XapXepSLBangNhau(ATM ds[], int n);
void QuickSortSL(ATM ds[], int left, int right);
void backup();
#pragma region SetUpRegion
void gotoXY(int column, int line);
int whereX();
int whereY();
void TextColor(int color);
void ShowCur(bool CursorVisibility);
void SetWindowSize(SHORT width, SHORT height);

#pragma endregion

#endif