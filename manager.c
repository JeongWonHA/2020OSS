#include <stdio.h>
#include "product.h"
#include <stdlib.h>
#include <string.h>

Product a;

int menuProduct(){
        int menu;
        printf("\n*** 과자 관리 ***\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 저장\n");
        printf("6. 검색\n");
        printf("0. 종료\n");

        printf("\n=> 원하는 메뉴는? " );
        scanf("%d", &menu);

        printf("\n");
        return menu;
}

void readProduct(Product *a[], int count ){
        for( int i = 0; i < count; i++){
	if(a[i] == NULL){
		continue;
	}
        a[i]->std_price = a[i]->price / a[i]->gram;
        printf("\n---------------------\n");
	printf("%d.\n",i+1);
        printf("이름 : %s\n",a[i]->name);
        printf("무게 : %dg\n",a[i]->gram);
        printf("가격 : %d원\n",a[i]->price);
        printf("표준가격 : 10g 당 %d원\n",a[i]->std_price);
        printf("평점 : %d\n",a[i]->star);

	}
}

int createProduct(Product *a[],int count){
        getchar();
        printf("이름은? ");
        scanf("%[^\n]s",a[count]->name);
        printf("무게는? ");
        scanf("%d",&a[count]->gram);
        printf("가격은? ");
        scanf("%d",&a[count]->price);
        printf("평점은? ");
        scanf("%d",&a[count]->star);

        return 1;
}

int updateProduct(Product *a[], int count){
	int choose;
	readProduct(a, count);
	
	printf("수정하고 싶은 제품번호?(0: 취소)");
	scanf("%d", &choose);
	if(choose == 0) return 0;
        choose--;
	getchar();
        printf("이름은? ");
        scanf("%[^\n]s",a[choose]->name);
        printf("무게는? ");
        scanf("%d",&a[choose]->gram);
        printf("가격은? ");
        scanf("%d",&a[choose]->price);
        printf("평점은? ");
        scanf("%d",&a[choose]->star);
        printf("=> 수정됨!\n");

        return 1;
}

int deleteProduct(Product *a[], int count){
	int choose;
	readProduct(a, count);
	printf("삭제하고 싶은 제품번호?(0: 취소)");
	scanf("%d",&choose);
	if(choose == 0)
		 return 0;
	else
		return choose-1;
}

int saveProduct(Product *a[], int count){
        FILE *fp;
        fp = fopen("Product.txt","wt");
	for(int i=0; i < count; i++){
	if(a[i] == NULL){
		count ++;
		continue;
	}
        fprintf(fp,"%s\n",a[i]->name);
        fprintf(fp,"%d\n",a[i]->gram);
        fprintf(fp,"%d\n",a[i]->price);
        fprintf(fp,"%d\n",a[i]->std_price);
        fprintf(fp,"%d\n",a[i]->star);
	}
        fclose(fp);
        printf("=> 저장됨!\n");
        return 1;
}

int loadProduct(Product *a[], int count){
	int i=0;
        FILE *fp;
        fp = fopen("Product.txt","rt");
        if(fp == NULL){
                printf("=>파일없음!\n");
                return 0;
        }
	while(1){
	a[i] = (Product *)malloc(sizeof(Product));
        fscanf(fp,"%[^\n]s\n",a[i]->name);
        fscanf(fp,"%d\n",&a[i]->gram);
        fscanf(fp,"%d\n",&a[i]->price);
        fscanf(fp,"%d\n",&a[i]->std_price);
        fscanf(fp,"%d\n",&a[i]->star);
	i++;
	if(feof(fp)) break;
        }
	fclose(fp);
        printf("=>로딩성공!\n");
        return i;
}

int searchProduct(Product *a[], int count){
        int choose;
        printf("1. 이름 검색\n");
        printf("2. 가격 검색\n");
        printf("3. 평점 검색\n");
        printf("검색 종류 : ");
        scanf("%d",&choose);

        switch(choose){

        case 1:
        searchName(a,count);
        break;

        case 2:
        searchPrice(a,count);
        break;

        case 3:
        searchStar(a,count);
        break;

        default : break;
        }
}
void searchPrint(Product *a[], int x){
        printf("이름: %s\n무게: %dg\n가격: %d원\n표준가격: 10g 당%d원\n 평점: %d\n", a[x]->name, a[x]->gram, a[x]->price, a[x]->std_price, a[x]->star);
}

void searchName(Product *a[], int count ){
        char name[30];
        char *ptr;
        int z = 0;
        printf("원하는 이름 : ");
        getchar();
        scanf("%[^\n]s",name);
        printf("\n-----------------\n");
        for(int x=0; x < count; x++){
                ptr = strstr(name, a[x]->name);
                if(ptr == NULL){
                        continue;
                }
                if(ptr != NULL){
                        z++;
                        searchPrint(a,x);
                }
        }
        if(z == 0) printf("=> 검색된 결과 없음!\n");
}

void searchPrice(Product *a[], int count){
        int price;
	int z=0;
        printf("원하는 가격 : ");
        scanf("%d", &price);
        printf("\n-----------------\n");
        for(int x=0; x < count; x++){
        	if(price == a[x]->price){
		z++;
                searchPrint(a,x);
		}
	}
	if(z == 0) printf("=> 검색된 결과 없음!\n");
}

void searchStar(Product *a[], int count){
        int star;
	int z=0;
        printf("원하는 별점  : ");
        scanf("%d", &star);
        printf("\n-----------------\n");
        for(int x=0; x < count; x++){
        if(star == a[x]->star){
		z++;
                searchPrint(a,x);
		}
        }
	if(z == 0) printf("=> 검색된 결과 없음!\n");
}
