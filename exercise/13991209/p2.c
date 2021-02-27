#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct product{
	char name[100];
	float price;
	float date_of_production ;
	float expiration_date;
	float discount_rate;
	char description[1000];
	char manufacture[100];
	float weight;
	char color[20];
	int number;

}product;
typedef struct Invoice{
	float customer_number;
	float product_number[];
	int number[];
	float date;

}Invoice;
typedef struct customer{
	char name[50];
	char family[50];
	long int phone;
	int cash;
	int id;

}customer;

//////////////////////////////////////////////////////////////////////////////////////

void menu (product,int,customer,int,Invoice,int);
product add_product (void);
customer add_customer(void);
Invoice add_Invoice(void);
void List_of_products(product[]);
void List_of_customer(customer[]);
void List_of_all_sales(Invoice[]);
void Display_invoice_by_number(void);
void Display_invoice_by_date(void);
void Exit (void);

///////////////////////////////////////////////////////////////////////////////////////
void menu (product pro,int a,customer c,int b,Invoice i,int ii,){
	printf("Enter number ");
	printf("1 for add product\n");
	printf("2 for add customer\n");
	printf("3 for sales\n");
	printf("4 for List of products\n");
	printf("5 for List of customer\n");
	printf("6 for List of all sales\n");
	printf("7 for Display invoice by number\n");
	printf("8 for Display invoice by date\n");
	printf("9 for exit\n");
	int n;
	scanf("%d",&n);
	switch(n){
		case 1:product p;p=add_product();pro[a]=p;a++;
		case 2:customer c;c= add_customer();cus[b]=c;b++;
		case 3:Invoice i; i=add_Invoice();Inv[ii]=i;ii++;
		case 4:List_of_products(pro);
		case 5:List_of_customer(cus);
		case 6:List_of_all_sales(Inv);
		case 7:Display_invoice_by_number();
		case 8:Display_invoice_by_date();
		case 9:exit(0);break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////		
product add_product (void){
	product p;
	printf("enter name:");
	scanf("%s",&p.name);
	printf("enter product number:");
	scanf("%d",&p.number);
	printf("enter purchase price:");
	scanf("%f",&p.price);
	printf("enter date of production ");
	scanf("%f",&p.date_of_production );
	printf("enter expiration date");
	scanf("%f",&p.expiration_date);
	printf("enter discount_rate");
	scanf("%f",&p.discount_rate);
	printf("enter color:");
	scanf("%s",&p.color);
	printf("enter weight");
	scanf("%f",&p.weight);
	printf("enter maker:");
	scanf("%s",&p.manufacture);
	printf("enter information of pruduct:");
	scanf("%s",&p.description);
	return p;
}

customer add_customer(void){
	customer c;
	printf("enter name:");
	scanf("%s",&c.name);
	printf("enter family name:");
	scanf("%s",&c.family);
	printf("enter customer number:");
	scanf("%d",&c.id);
	printf("enter  phone number:");
	scanf("%ld",&c.phone);
	printf("enter  cash:");
	scanf("%d",&c.cash);
	return c;
}
Invoice add_Invoice(void){
	Invoice i;int f=0,p=1;
	printf("enter  customer number:");
	scanf("%f",&i.customer_number);
	printf("enter date of sales");
	scanf("%f",&i.date);
	while(p==1){
		printf("enter product number:");
		scanf("%f",&i.product_number);
		printf("enter  number:");
		scanf("%d",&i.number);
		f++;
		printf("enter product number:");
	}
	
	return i;
}
void List_of_products(product p[]){
	for(int i=0,i++,p[i]!="\0"){
		print ("%s",p[i]);
		print("\n");
	}
}
void List_of_customer(customer c[]){
	for(int i=0,i++,c[i]!="\0"){
		print ("%s",c[i]);
		print("\n");
	}
}
void List_of_all_sales(Invoice i[]){
	for(int ii=0,ii++,i[ii]!="\0"){
		print ("%s",i[ii]);
		print("\n");
	}
}
//////////////////////////////////////////////////////////////////////////////////////
int main(){
	product p[10000];
	customer c[10000];
	Invoice i[10000];
	int a=0,b=0,ii=0;
	menu(p,a,c,b,i,ii);
	return 0;
} 
