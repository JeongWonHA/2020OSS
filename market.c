#include <stdio.h>
#include "product.h"
#include <stdlib.h>
#include <string.h>

Product a;

int main(){
	Product *a[100];
	int menu, count = 0;
	int delete_num;
	#ifdef DEBUG
		printf("DDEBUG[main.c] : call loadProduct()\n");
	#endif
	count = loadProduct(a, count);
	while(1){
		#ifdef DEBUG
			printf("DDEBUG[main.c] : call menuProduct()\n");
		#endif	
		menu = menuProduct();
		if(menu == 0) break;
	
		if(menu != 2 && count == 0) continue;
		
		if(menu == 1){
			#ifdef DEBUG
				printf("DDEBUG[main.c] : call readProduct()\n");
			#endif
			readProduct(a, count);
		}else if(menu == 2){
			a[count] = (Product *)malloc(sizeof(Product));
			#ifdef DEBUG	
				printf("DDEBUG[main.c] : call createProduct()\n");
			#endif
			createProduct(a,count);
			count ++;
		}else if(menu == 3){
			#ifdef DEBUG
				printf("DDEBUG[main.c] : call updateProduct()\n");
			#endif
			updateProduct(a, count);
		}else if(menu == 4){
			#ifdef DEBUG
				printf("DDEBUG[main.c] : call loadProduct()\n");
			#endif
			delete_num = deleteProduct(a, count);
			delete_num--;
			if(delete_num == -1) continue;
			free(a[delete_num]);
			a[delete_num] = NULL;
		}else if(menu == 5){
			#ifdef DEBUG
				printf("DDEBUG[main.c] : call saveProduct()\n");
			#endif
			saveProduct(a,count);
		}else if(menu == 6){
			#ifdef DEBUG
				printf("DDEBUG[main.c] : call searchProduct()\n");
			#endif
			searchProduct(a, count);
		}	
		
	}

	free(a[0]);
return 0;
}
