#include <stdio.h>

typedef struct{
    char name[30];
    int gram;
    int price;
    int std_price;
    int star;
}Product;

int menuProduct();
int createProduct(Product *a[], int count);
void readProduct(Product *a[], int count);
int updateProduct(Product *a[], int count);
int deleteProduct(Product *a[], int count);

void searchName(Product *a[],int count);
void searchPrice(Product *a[], int count);
void searchStar(Product *a[], int count);
void searchPrint(Product *a[], int count);
int searchProduct(Product *a[], int count);

int saveProduct(Product *a[], int count);
int loadProduct(Product *a[], int count);
