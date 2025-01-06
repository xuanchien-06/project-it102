#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <string.h>

//in menu
void printMenu(){
	system("cls");
	printf("\t==== Book management system ====\n");
	printf("\tBOOK MENU\n");
	printf("\t===================\n");
	printf("\t[1].Show Book Information\n");
	printf("\t[2].Add Book\n");
	printf("\t[3].edit Book Information\n");
	printf("\t[4].Delete Book\n");
	printf("\t[5].Search Books By Name\n");//theo ten
	printf("\t[6].Sort By Price\n");//theo gia tien
	printf("\t[7].Exit\n");
	printf("\t===================\n");
}

//in sach
void printbook(struct Book books[], int n){
	system("cls");
	printf("|============|===========================|======================|============|============|=================|\n");
    printf("|   ID       |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    printf("|============|===========================|======================|============|============|=================|\n");
    int i;
	for (i = 0; i < n; i++) {
    	printf("| %-10d | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
            books[i].id, 
            books[i].name, 
            books[i].author, 
            books[i].quantity, 
            books[i].price, 
            books[i].publicationDate, 
            books[i].publicationMonth, 
            books[i].publicationYear);
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
    }

}

//them sach
void addbook(struct Book books[],  int *n){
	int number;
	int i, check = 0;
	system("cls");
	getchar(); 
	printf("************ Add A New Book ************\n");
    books[*n].id = *n + 1;
    printf("Enter the ID: ");
    scanf("%d", &books[*n].id);
    fflush(stdin);
    while(1){  //kiem tra id
    	check = 0;
    	for(i=0;i<*n;i++){
		if(books[*n].id == books[i].id || books[*n].id<1 || books[*n].id>1000){
			check = 1;
			break;
			}
		}
		if(check == 0){
			break;
		}else{
			printf("Error: ID already exists or invalid. Please enter a valid ID(1-1000): ");
			scanf("%d", &books[*n].id);
		}
	}
		
		addname:
		printf("Enter the Name: ");
		fgets(books[*n].name, 100, stdin);	
		books[*n].name[strcspn(books[*n].name, "\n")] = '\0'; //xoa ki tu
		for(i = 0; i < strlen(books[*n].name); i++){  //kiem tra name
			//kiem tra neu chua 2 khoang trang
			if(books[*n].name[i] == 32 && books[*n].name[i+1] == 32){
				printf("Error: this Name is not valid\n");
				goto addname;
			}
			// kiem tra neu ky tu khong phai la chu cai hoac khoang trang
        	if (!(isalpha(books[*n].name[i]) || books[*n].name[i] == 32)) {
	            printf("Error: This Name is not valid\n");
	            goto addname;
	        }
		}
		//kiem tra neu ten bat dau bang khoang trang hoac ten trong
		if(books[*n].name[0]==32 || strlen(books[*n].name)<1){
			printf("Error: This Name is not valid\n");
			goto addname;
		}
	
	printf("Enter the Author: ");
	fgets(books[*n].author, 100, stdin);
	books[*n].author[strcspn(books[*n].author, "\n")] = '\0'; 
	printf("Enter the Quantity: ");
    scanf("%d", &books[*n].quantity);
    getchar();
	printf("Enter the Price: \n");
    scanf("%d", &books[*n].price);
    getchar();
    printf("Enter the Date: ");
    scanf("%d", &books[*n].publicationDate);
    getchar();
    printf("Enter the Month: ");
    scanf("%d", &books[*n].publicationMonth);
    getchar();
    printf("Enter the Year: ");
    scanf("%d", &books[*n].publicationYear);
    getchar();
	  
    while(1){
    	check = 0;
    	for(i = 0; i < *n; i++){//kiem tra publication
    		if(	books[*n].publicationDate == books[i].publicationDate &&
				books[*n].publicationMonth == books[i].publicationMonth &&
				books[*n].publicationYear == books[i].publicationYear){
					check = 1;
					break;
				}
		}
		if(check == 0){
			break;
		}else{
		    printf("Enter the Date: ");
		    scanf("%d", &books[*n].publicationDate);
		    getchar();
		    printf("Enter the Month: ");
		    scanf("%d", &books[*n].publicationMonth);
		    getchar();
		    printf("Enter the Year: ");
		    scanf("%d", &books[*n].publicationYear);
		    getchar();  
		}
	}
	(*n)++;  
	printf("Them sach thanh cong!!\n");
}

//sua sach
void fixbook(struct Book books[], int n){
    system("cls");
    int position;
    printf("************ Edit a Book ************\n");
    printf("Enter Book ID to search: ");
    scanf("%d", &position);
    int findIndex = -1;
    int i;
    for(i = 0; i < n; i++) {
        if(books[i].id == position) {
            findIndex = i;
            break;
        }
    }
    
    if(findIndex == -1) {
        printf("Cannot find the book with the given ID!\n");
    } else {
        //In thong tin tai vi tri input
        system("cls");
        printf("One book found for ID: %d\n", books[findIndex].id);
        printf("\nBook Information:\n");
        printf("----------------------\n");
        printf("Id: %d\n", books[findIndex].id);
        printf("Name: %s\n", books[findIndex].name);
        printf("Author: %s\n", books[findIndex].author);
        printf("Quantity: %d\n", books[findIndex].quantity);
        printf("Price: %d\n", books[findIndex].price);
        printf("Publication: %d/%d/%d\n", books[findIndex].publicationDate, books[findIndex].publicationMonth, books[findIndex].publicationYear);
        
        // Cap nhat thong tin sach
        printf("\n************ Update The New Book ************\n");
        getchar(); 
        
        // Cap nhat ten sach
        addname:
        printf("Enter The New Name (0 for skip): ");
        char newName[100];
        fgets(newName, 100, stdin);
        newName[strcspn(newName, "\n")] = '\0';  
        
        // neu khong nhap '0' , kiem tra ten sach
        if (strcmp(newName, "0") != 0) {
            // kiem tra co chua 2 khoang trang khong
            for(i = 0; i < strlen(newName); i++) {
                if (newName[i] == ' ' && newName[i+1] == ' ') {
                    printf("Error: Name contains consecutive spaces.\n");
                    goto addname;
                }
            }
            
            // kiem tra ten sach chua cac ki tu hop le khong
            for(i = 0; i < strlen(newName); i++) {
                if (!((newName[i] >= 'A' && newName[i] <= 'Z') || (newName[i] >= 'a' && newName[i] <= 'z') || newName[i] == ' ')) {
                    printf("Error: Name contains invalid characters. Only letters and spaces are allowed.\n");
                    goto addname;
                }
            }
            
            // kiem tra ten bat dau bang khoang trang va khong duoc trong
            if (newName[0] == ' ' || strlen(newName) < 1) {
                printf("Error: Name cannot start with a space and cannot be empty.\n");
                goto addname;
            }
            
            // Cap nhat ten sach
            strcpy(books[findIndex].name, newName);
        } else {
            printf("Name skipped, no change.\n");
        }
        
        // Cap nhat tac gia
        addauthor:
        printf("Enter The New Author (0 for skip): ");
        char newAuthor[100];
        fgets(newAuthor, 100, stdin);
        newAuthor[strcspn(newAuthor, "\n")] = '\0';  
        
        //neu khong nhap '0' thi kiem tra tac gia
        if (strcmp(newAuthor, "0") != 0) {
            //kiem tra khoang trang
            for(i = 0; i < strlen(newAuthor); i++) {
                if (newAuthor[i] == ' ' && newAuthor[i+1] == ' ') {
                    printf("Error: Author name contains consecutive spaces.\n");
                    goto addauthor;
                }
            }
            
            //kiem tra ki tu co hop le khong
            for(i = 0; i < strlen(newAuthor); i++) {
                if (!((newAuthor[i] >= 'A' && newAuthor[i] <= 'Z') || (newAuthor[i] >= 'a' && newAuthor[i] <= 'z') || newAuthor[i] == ' ')) {
                    printf("Error: Author name contains invalid characters. Only letters and spaces are allowed.\n");
                    goto addauthor;
                }
            }
            
            // cap nhat ten tac gia
            strcpy(books[findIndex].author, newAuthor);
        } else {
            printf("Author skipped, no change.\n");
        }
        
        // Cap nhat so luong sach
        int newQuantity;
        printf("Enter New Quantity (0 for skip): ");
        scanf("%d", &newQuantity);
        if (newQuantity != 0) {
            books[findIndex].quantity = newQuantity;
        } else {
            printf("Quantity skipped, no change.\n");
        }
        
        // Cap nhat gia sach
        getchar();
        int newPrice;
        printf("Enter The New Price (0 for skip): ");
        scanf("%d", &newPrice);
        if (newPrice != 0) {
            books[findIndex].price = newPrice;
        } else {
            printf("Price skipped, no change.\n");
        }
       
        // Cap nhat ngay thang nam
        getchar();
        int newDay, newMonth, newYear;
        printf("Enter new publication date (0 for skip): ");
        scanf("%d", &newDay);
        printf("Enter new publication date (0 for skip): ");
        scanf("%d", &newMonth);
        printf("Enter new publication date (0 for skip): ");
        scanf("%d", &newYear);
        if (newDay != 0 && newMonth != 0 && newYear != 0) {
            books[findIndex].publicationDate = newDay;
            books[findIndex].publicationMonth = newMonth;
            books[findIndex].publicationYear = newYear;
        } else {
            printf("Publication skipped, no change.\n");
        }
    }
}

//xoa sach
void deleteBook(struct Book books[], int *n, int *nextId) {
    system("cls");
    int position;
    int findIndex = -1;

    printf("************ Delete a Book ************\n");
    printf("Enter The Book Id: ");
    scanf("%d", &position);

    // tim kiem sach theo id
    int i;
    for (i = 0; i < *n; i++) {
        if (books[i].id == position) {
            findIndex = i;
            break;
        }
    }
	
	//neu khong tim thay sach thong bao loi
	if (findIndex == -1) {
        printf("Khong tim thay sach voi ID: %d\n", position);
    } else {
        // hien thi thong tin sach can xoa
        system("cls");
        printf("Book Informations\n");
        printf("----------------------\n");
       	printf("Id: %d\n", books[findIndex].id);
        printf("Name: %s\n", books[findIndex].name);
        printf("Author: %s\n", books[findIndex].author);
        printf("Quantity: %d\n", books[findIndex].quantity);
        printf("Price: %d\n", books[findIndex].price);
        printf("Publication: %d/%d/%d\n", books[findIndex].publicationDate, books[findIndex].publicationMonth, books[findIndex].publicationYear);
        
		char check;
        printf("Are you sure want to delete this book? (Y/N): ");
        getchar(); 
        scanf("%c", &check);

        // Neu nguoi dung nhap vao y thi xoa va dich chuyen len 1 vi tri
        if (check == 'y') {
        	int i;
            for (i = findIndex; i < *n - 1; i++) {
                books[i] = books[i + 1]; 
            }
            (*n)--; 
            printf("Book deleted successfully!!");
            // cap nhat lai id cua cac sach con lai
            for (i = 0; i < *n; i++) {
                books[i].id = i + 1;  // cap nhat sach tu 1 den n
            }
        } 
        else {
            printf("Do not delete Books\n");
        }
	}
}

//sap xep theo gia tien
void sortByPrice(struct Book books[], int n){
	system("cls");
	int cull;
	int i,j;
	printf("\t\t\t\t************ Sort By Price ************\n\n");
	// lua chon sap xep tang hoac giam dan
	printf("\t\t\t\tSelect ascending or descending\n");
	printf("\t\t\t\tEnter 1 to sort Ascending\n");
	printf("\t\t\t\tEnter 2 to sort Descending\n");
	printf("\t\t\t\tYour choice: ");
	scanf("%d", &cull);
	if(cull == 1){
		for( i = 0; i < n - 1; i++){
			for( j = 0; j < n - i - 1; j++){
				if(books[j].price > books[j+1].price){
					struct Book temp = books[j];
					books[j] = books[j+1];
					books[j + 1] = temp;
				}	
			}
		}
	}else if(cull == 2){
		for( i = 0; i < n - 1; i++){
			for( j = 0; j < n - i - 1; j++){
				if(books[j].price < books[j+1].price){
					struct Book temp = books[j];
					books[j] = books[j+1];
					books[j + 1] = temp;
				}	
			}
		}
	}	
	printf("\n\t\t\t\t******************************************\n");
	printf("\t\t\t\t******* Sort the list successfully *******\n");
	printf("\t\t\t\t******************************************\n");
	printf("|============|===========================|======================|============|============|=================|\n");
    printf("|   ID       |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    printf("|============|===========================|======================|============|============|=================|\n");
	for (i = 0; i < n; i++) {
    	printf("| %-10d | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
            books[i].id, 
            books[i].name, 
            books[i].author, 
            books[i].quantity, 
            books[i].price, 
            books[i].publicationDate, 
            books[i].publicationMonth, 
            books[i].publicationYear);
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
    }
}

// Tim kiem theo ten
void searchBook(struct Book books[], int *n) {
    system("cls");
    char search[100];
    int found = 0;

    printf("Enter the name you want to search: ");
	getchar();
    fgets(search, 100, stdin);
    search[strcspn(search, "\n")] = '\0';  
    //duyet qua va tim sach 
    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(books[i].name, search) == 0) {
        	printf("|============|===========================|======================|============|============|=================|\n");
    		printf("|   ID       |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    		printf("|============|===========================|======================|============|============|=================|\n");
            // in thong tin sach da tim thay
            printf("| %-10d | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
	            books[i].id, 
	            books[i].name, 
	            books[i].author, 
	            books[i].quantity, 
	            books[i].price, 
	            books[i].publicationDate, 
	            books[i].publicationMonth, 
	            books[i].publicationYear);
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
            found = 1;  // danh dau da tim thay
        }
    }
	// neu khong tim thay sach thong bao khong tim thay
    if(found==0) {
        printf("No books found with the name '%s'.\n", search);
    }
}

//in exit
void printExit(){
	printf("============ Thank You ============\n");
	printf("============ See You Soon ============\n");
}

//Luu du lieu vao file
void saveBook( struct Book books[], int n){
	//Mo file
    FILE *ptr = fopen("books.dat", "wb"); 
    //Thao tac voi file
    if (ptr == NULL) {
        printf("Cannot open file to save books.\n");
        return;
    }
	fwrite(books,sizeof(struct Book),n,ptr);
	printf("\nLuu tru file thanh cong\n");
	fclose(ptr);
}

void loadBooksFromFile(struct Book books[], int *n){
	FILE *ptr = fopen("books.dat","rb");
	if(ptr==NULL){
		printf("Cannot open file to save books\n");
	}
	struct Book readBook[100];
	*n=fread(readBook,sizeof(struct Book),50,ptr);
	printf("|============|===========================|======================|============|============|=================|\n");
    printf("|   ID       |           Name            |        AUTHOR        |  QUANTITY  |    PRICE   |   PUBLICATION   |\n");
    printf("|============|===========================|======================|============|============|=================|\n");
	int i;
	for(i=0;i<*n;i++){
		printf("| %-10d | %-25s | %-20s | %-10d | %-10d | %02d/%02d/%04d      |\n", 
            books[i].id, 
            books[i].name, 
            books[i].author, 
            books[i].quantity, 
            books[i].price, 
            books[i].publicationDate, 
            books[i].publicationMonth, 
            books[i].publicationYear);
        printf("|------------|---------------------------|----------------------|------------|------------|-----------------|\n");
	} 
	printf("Lay du lieu thanh cong\n");
	fclose(ptr);
}

// thoat chuong trinh
void exitProgram(char *select){
	end:
	printf("\nBach:b or Exit:0 ");
	scanf("%s", select);
	fflush(stdin);
	if(strcmp(select,"b") == 0){
		system("cls");
	}else if(strcmp(select,"0") == 0){
		system("cls");
		printExit();
		exit(0);
	}else{
		goto end;
	}
}



//Quan li khach hang
//in menu quan li khach hang
void prinMenuCostum(){
	system("cls");
	printf("\t==== Book management system ====\n");
	printf("\tCOSTUM MENU\n");
	printf("\t===================\n");
	printf("\t[1].Show Customer Information\n");
	printf("\t[2].Add Costum\n");
	printf("\t[3].Edit Customer Information\n");
	printf("\t[4].Lock (Unlock) Customer\n");
	printf("\t[5].Search Customers By Name\n");
	printf("\t[6].Book Lendingn\n");
	printf("\t[7].Returning Borrowed Books\n");
	printf("\t[8].Exit\n");
	printf("\t===================\n");
}

void printListCostum(struct Costum costums[], int a){
	system("cls");
	printf("|============|===========================|=========================|====================|\n");
    printf("|   ID       |           Name            |         EMAIL           |       PHONE        |\n");
    printf("|============|===========================|=========================|====================|\n");

    int i;
	for (i = 0; i < a; i++) {
     	printf("| %-10d | %-25s | %-23s | %-18s |\n", 
                costums[i].id, 
                costums[i].name, 
                costums[i].email, 
                costums[i].phone);
        printf("|------------|---------------------------|-------------------------|--------------------|\n");
    }
}




