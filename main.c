#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include<string.h>


struct Costum costums[100]={
	{1,"Bui Van Hoa","buivana@gmail.com","0123456789"},
	{2,"Nguyen Thi Nhai","nhai1972@gmail.com","0314527431"},
	{3,"Nong Van Manh","manhvan8386@gmail.com","09629472719"},
};
int a = 3;

struct Book books[100]={
	{1,"Mat biec","Nguyen nhat anh", 1014, 49, 1, 12, 1999},
	{2,"De men","To hoai", 1001, 39, 15, 8, 1941},
	{3,"Lao hac","Nam cao", 2001, 19, 20, 5, 1943},	
};
int n=3;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
int choice;
char select;
int nextId=1;
int number;
int pick;
printf("\t\t******Book Management System******\n");
printf("\tCHOSE YOUR LORE\n");
printf("\t========================================\n");
printf("\t[1]Book Management \n");
printf("\t[2]Customer Management\n");
printf("\tEnter the choice: ");
scanf("\t%d", &pick);
if(pick == 1){
	do{
		printMenu();
		printf("\n\tYour Choice: ");
		scanf("%d", &choice);
		if(choice > 7 || choice < 0){
			printf("\tInvalid Selection!!\n");
			continue;
		}	
		switch(choice){
			case 1://in thong tin sach
				printbook(books, n);
				exitProgram(&select);				
		  		break;
		  	case 2://Them thong tin sach 
		  		addbook(books, &n);
		  		saveBook(books, n);
				loadBooksFromFile(books, &n);
				exitProgram(&select);		  		
		  		break;
		  	case 3://Sua thong tin sach
		  		fixbook(books, n);
		  		saveBook(books, n);
		  		exitProgram(&select);
		  		break;
		  	case 4://Xoa sach
		  		deleteBook(books, &n, &nextId);
		  		saveBook(books, n);
		  		exitProgram(&select);
		  		break;
		  	case 5://Tim kiem thong tin sach
		  		searchBook(books, &n);
		  		exitProgram(&select);
		  		break;
		  	case 6://Sap xep sach theo gia tien
		  		sortByPrice(books, n);
		  		exitProgram(&select);
				break;	
			case 7:
				return 1;
		}
	}
	while(choice!=7);
//	return 0;
}else if(pick == 2){
	int luachon;
	do{
		prinMenuCostum();
		printf("\n\tYour Choice: ");
		scanf("%d", &luachon);
		if(luachon > 8 || luachon < 0){
			printf("\tInvalid Selection!!\n");
			continue;
		}
		switch(luachon){
			case 1:
				printListCostum(costums, a);
				exitProgram(&select);
				break;
		}	
	}
	while(luachon!=8);
}

return 0;
}



	
