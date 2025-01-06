#include "datatype.h"
// nguyen mau ham
void printMenu();
void prinbook(struct Book books[], int n);//In sach
void addbook(struct Book books[],  int *n);//Them sach
void fixbook(struct Book books[], int n);//Sua sach
void exitProgram(char *select);//Thoat hoac quay lai
void printExit();
void deleteBook(struct Book books[], int *n, int *nextId);//Xoa sach
void sortByPrice(struct Book books[], int n);//Sap xep theo gia
void searchBook(struct Book books[], int *n);//Tim kiem theo ten
void saveBook( struct Book books[], int n);//Luu file
void loadBooksFromFile(struct Book books[], int *n);//Doc file

//Quan li khach hang
void prinMenuCostum();
void printListCostum(struct Costum costums[], int a);
