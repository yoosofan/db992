#include<cstdio>
#include<cstdlib>
#include<cstring>

struct product{
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

};

struct Invoice{
	float customer_number;
	float product_number[100];
	int number[100];
	float date;
};

struct customer{
	char name[50];
	char family[50];
	long int phone;
	int cash;
	int id;
};

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
void menu (product pro,int a,customer c,int b,Invoice i,int ii){
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

/*
3991209$ g++ p2.cpp 
p2.cpp:48:64: error: expected identifier before ‘)’ token
   48 | void menu (product pro,int a,customer c,int b,Invoice i,int ii,){
      |                                                                ^
p2.cpp: In function ‘void menu(product, int, customer, int, Invoice, int, int)’:
p2.cpp:62:39: error: no match for ‘operator[]’ (operand types are ‘product’ and ‘int’)
   62 |   case 1:product p;p=add_product();pro[a]=p;a++;
      |                                       ^
p2.cpp:63:39: error: ‘cus’ was not declared in this scope
   63 |   case 2:customer c;c= add_customer();cus[b]=c;b++;
      |                                       ^~~
p2.cpp:64:37: error: ‘Inv’ was not declared in this scope
   64 |   case 3:Invoice i; i=add_Invoice();Inv[ii]=i;ii++;
      |                                     ^~~
p2.cpp:65:27: error: cannot convert ‘product’ to ‘product*’
   65 |   case 4:List_of_products(pro);
      |                           ^~~
      |                           |
      |                           product
p2.cpp:40:23: note:   initializing argument 1 of ‘void List_of_products(product*)’
   40 | void List_of_products(product[]);
      |                       ^~~~~~~~~
p2.cpp: In function ‘product add_product()’:
p2.cpp:77:10: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   77 |  scanf("%s",&p.name);
      |         ~^  ~~~~~~~
      |          |  |
      |          |  char (*)[100]
      |          char*
p2.cpp:89:10: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[20]’ [-Wformat=]
   89 |  scanf("%s",&p.color);
      |         ~^  ~~~~~~~~
      |          |  |
      |          |  char (*)[20]
      |          char*
p2.cpp:93:10: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   93 |  scanf("%s",&p.manufacture);
      |         ~^  ~~~~~~~~~~~~~~
      |          |  |
      |          |  char (*)[100]
      |          char*
p2.cpp:95:10: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[1000]’ [-Wformat=]
   95 |  scanf("%s",&p.description);
      |         ~^  ~~~~~~~~~~~~~~
      |          |  |
      |          |  char (*)[1000]
      |          char*
p2.cpp: In function ‘customer add_customer()’:
p2.cpp:102:10: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
  102 |  scanf("%s",&c.name);
      |         ~^  ~~~~~~~
      |          |  |
      |          |  char (*)[50]
      |          char*
p2.cpp:104:10: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
  104 |  scanf("%s",&c.family);
      |         ~^  ~~~~~~~~~
      |          |  |
      |          |  char (*)[50]
      |          char*
p2.cpp: In function ‘Invoice add_Invoice()’:
p2.cpp:121:11: warning: format ‘%f’ expects argument of type ‘float*’, but argument 2 has type ‘float (*)[100]’ [-Wformat=]
  121 |   scanf("%f",&i.product_number);
      |          ~^  ~~~~~~~~~~~~~~~~~
      |           |  |
      |           |  float (*)[100]
      |           float*
p2.cpp:123:11: warning: format ‘%d’ expects argument of type ‘int*’, but argument 2 has type ‘int (*)[100]’ [-Wformat=]
  123 |   scanf("%d",&i.number);
      |          ~^  ~~~~~~~~~
      |           |  |
      |           |  int (*)[100]
      |           int*
p2.cpp: In function ‘void List_of_products(product*)’:
p2.cpp:131:15: error: expected ‘;’ before ‘++’ token
  131 |  for(int i=0,i++,p[i]!="\0"){
      |               ^~
      |               ;
p2.cpp:131:17: error: expected primary-expression before ‘,’ token
  131 |  for(int i=0,i++,p[i]!="\0"){
      |                 ^
p2.cpp:131:22: error: no match for ‘operator!=’ (operand types are ‘product’ and ‘const char [2]’)
  131 |  for(int i=0,i++,p[i]!="\0"){
      |                  ~~~~^~~~~~
      |                     |  |
      |                     |  const char [2]
      |                     product
p2.cpp:131:28: error: expected ‘;’ before ‘)’ token
  131 |  for(int i=0,i++,p[i]!="\0"){
      |                            ^
      |                            ;
p2.cpp:132:3: error: ‘print’ was not declared in this scope; did you mean ‘printf’?
  132 |   print ("%s",p[i]);
      |   ^~~~~
      |   printf
p2.cpp: In function ‘void List_of_customer(customer*)’:
p2.cpp:137:15: error: expected ‘;’ before ‘++’ token
  137 |  for(int i=0,i++,c[i]!="\0"){
      |               ^~
      |               ;
p2.cpp:137:17: error: expected primary-expression before ‘,’ token
  137 |  for(int i=0,i++,c[i]!="\0"){
      |                 ^
p2.cpp:137:22: error: no match for ‘operator!=’ (operand types are ‘customer’ and ‘const char [2]’)
  137 |  for(int i=0,i++,c[i]!="\0"){
      |                  ~~~~^~~~~~
      |                     |  |
      |                     |  const char [2]
      |                     customer
p2.cpp:137:28: error: expected ‘;’ before ‘)’ token
  137 |  for(int i=0,i++,c[i]!="\0"){
      |                            ^
      |                            ;
p2.cpp:138:3: error: ‘print’ was not declared in this scope; did you mean ‘printf’?
  138 |   print ("%s",c[i]);
      |   ^~~~~
      |   printf
p2.cpp: In function ‘void List_of_all_sales(Invoice*)’:
p2.cpp:143:17: error: expected ‘;’ before ‘++’ token
  143 |  for(int ii=0,ii++,i[ii]!="\0"){
      |                 ^~
      |                 ;
p2.cpp:143:19: error: expected primary-expression before ‘,’ token
  143 |  for(int ii=0,ii++,i[ii]!="\0"){
      |                   ^
p2.cpp:143:25: error: no match for ‘operator!=’ (operand types are ‘Invoice’ and ‘const char [2]’)
  143 |  for(int ii=0,ii++,i[ii]!="\0"){
      |                    ~~~~~^~~~~~
      |                        |  |
      |                        |  const char [2]
      |                        Invoice
p2.cpp:143:31: error: expected ‘;’ before ‘)’ token
  143 |  for(int ii=0,ii++,i[ii]!="\0"){
      |                               ^
      |                               ;
p2.cpp:144:3: error: ‘print’ was not declared in this scope; did you mean ‘printf’?
  144 |   print ("%s",i[ii]);
      |   ^~~~~
      |   printf
p2.cpp: In function ‘int main()’:
p2.cpp:154:19: error: no matching function for call to ‘menu(product [10000], int&, customer [10000], int&, Invoice [10000], int&)’
  154 |  menu(p,a,c,b,i,ii);
      |                   ^
p2.cpp:36:6: note: candidate: ‘void menu(product, int, customer, int, Invoice, int)’
   36 | void menu (product,int,customer,int,Invoice,int);
      |      ^~~~
p2.cpp:36:12: note:   no known conversion for argument 1 from ‘product [10000]’ to ‘product’
   36 | void menu (product,int,customer,int,Invoice,int);
      |            ^~~~~~~
p2.cpp:48:6: note: candidate: ‘void menu(product, int, customer, int, Invoice, int, int)’
   48 | void menu (product pro,int a,customer c,int b,Invoice i,int ii,){
      |      ^~~~
p2.cpp:48:6: note:   candidate expects 7 arguments, 6 provided
13991209$ 



*/
