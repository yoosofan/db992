#include <cstdio>
#include <cstdlib>

struct product
{
  int code_of_product;
  char product_name[50];
  int popularity;
  int ext;
  int price_one;
  int whole_sale;
  int available_number;
  int produce_date;
  int remaining;

};

struct sale
{
  int customer_id;
  long code_of_product;
  int number;
  int date;
  int factor_number;

};
struct customer
{
  char name[50];
  int id;
  int Number_of_times_purchased;
  char address[200];
  char phone_number[20];

};

struct product p_t[200];
struct customer c_t[200];
struct sale s_t[200];
static int counter_p = 0;
static int counter_c = 0;
static int counter_s = 0;

void Add_goods ()
{
  printf ("enter code of product\n");
  scanf ("%d", &p_t[counter_p].code_of_product);

  printf ("enter Name Of Product\n");
  scanf ("%s", p_t[counter_p].product_name);

  printf ("enter Popularity\n");
  scanf ("%d", &p_t[counter_p].popularity);

  printf ("enter Expiration date\n");
  scanf ("%d", &p_t[counter_p].ext);

  printf ("enter single price \n");
  scanf ("%f", &p_t[counter_p].price_one);

  printf ("enter wholesale price\n");
  scanf ("%f", &p_t[counter_p].whole_sale);

  printf ("enter Available Number\n");
  scanf ("%d", &p_t[counter_p].available_number);

  printf ("enter Compony_name  \n");
  scanf ("%c", &p_t[counter_p].producer_compony);

  printf ("enter Date of produce\n");
  scanf ("%d", &p_t[counter_p].produce_date);

  printf ("enter Number of remaining \n");
  scanf ("%d", &p_t[counter_p].remaining);
  counter_p++;
  menu ();

}

void Add_customer ()
{
  printf ("enter Name\n");
  scanf ("%s", c_t[counter_c].name);

  printf ("enter Id \n");
  scanf ("%d", &c_t[counter_c].id);

  c_t[counter_c].Number_of_times_purchased = 0;

  printf ("enter address of customer\n");
  scanf ("%s", c_t[counter_c].address);


  printf ("enter phone_number\n");
  scanf ("%s", c_t[counter_c].phone_number);

  counter_c++;
  menu ();
}

void sele_process ()
{
  printf ("enter customer_id\n");
  scanf ("%d", &s_t[counter_s].customer_id);
  
  printf ("enter code_of_product\n");
  scanf ("%d", &s_t[counter_s].code_of_product);
  
  printf ("enter number \n");
  scanf ("%d", &s_t[counter_s].number);
  
  printf ("enter Date\n");
  scanf ("%d", &s_t[counter_s].date);
  
  printf ("enter factor_number\n");
  scanf ("%d", &s_t[counter_s].factor_number);
  counter_s ++;
  menu();
}

void show_list_goods ()
{
  printf ("hello");
  for (int i = 0; i <= counter_p; i++)
    {
      printf ("%d", &p_t[i].code_of_product);
      printf ("%s",p_t[i].product_name);
      printf ("%d", &p_t[i].popularity);
      printf ("%d", &p_t[i].ext);
      printf ("%d", &p_t[i].produce_date);
      printf ("%d", &p_t[i].price_one);
      printf ("%d", &p_t[i].whole_sale);
      printf ("%d", &p_t[i].remaining);
      printf ("%d", &p_t[i].available_number);
      printf (p_t[i].producer_compony);
      printf("______________________");
    }

}
void show_list_customer()
{
    for (int i =0 ; i <= counter_c; i++)
    {
      printf("%s",c_t[i].name);
      printf("%d",c_t[i].id);  
      printf("%d",c_t[i].Number_of_times_purchased);  
      printf("%s",c_t[i].address);
      printf("%s",c_t[i].phone_number);  
      printf("______________________");
        
    }
    menu();
}


void show_list_sales()
{
    for (int i =0 ; i <= counter_s; i++)
    {
      printf ("%d\n",s_t[i].customer_id);
      printf ("%d\n ",s_t[i].code_of_product);  
      printf ("%d\n",s_t[i].number);  
      printf ("%d\n",s_t[i].date);
      printf ("%d\n",s_t[i].factor_number);  
      printf("______________________");
        
    }
    menu();
    
}

void show_factor_of_id()
{
    int fact=0;
    printf("enter factor number:");
    scanf("%d",&fact);
    for (int i =0 ; i <=counter_s; i++)
    {
        if(s_t[i].factor_number==fact)
        {
            printf ("%d\n",s_t[i].customer_id);
            printf ("%d\n ",s_t[i].code_of_product);  
            printf ("%d\n",s_t[i].number);  
            printf ("%d\n",s_t[i].date);
            printf ("%d\n",s_t[i].factor_number);  
            printf("______________________");
        
        }
    }
    menu();
}

void show_list_sales_today()
{
    int special_date=0;
    printf("enter Datee:");
    scanf("%d",&special_date);
    
    for (int i =0;i<=counter_s;i++)
    {
        if(s_t[i].date==special_date)
        {
            printf ("%d\n",s_t[i].customer_id);
            printf ("%d\n ",s_t[i].code_of_product);  
            printf ("%d\n",s_t[i].number);  
            printf ("%d\n",s_t[i].date);
            printf ("%d\n",s_t[i].factor_number);  
            printf("______________________");
        
        }
    }
    menu();
}

void menu ()
{
  printf
    ("1)Add goods \n2)Add customer \n3)seles \n4)list of goods \n5)list of costumer \n6)sales list \n7)show special factor \n8)show history of special date");
  int k;
  scanf ("%d", &k);
  switch (k)
    {
    case 1:
      Add_goods ();
      break;
    case 2:
      Add_customer ();
      break;

    case 3:
      sele_process ();
      break;

    case 4:
      show_list_goods ();
      break;

    case 5:
        show_list_customer();
        break;

    case 6:
        show_list_sales();
        break;

    case 7:
        show_factor_of_id();
        break;
         
    case 8:
        show_list_sales_today();
        break;
       

    default:
      break;
    }


}

int
main ()
{
  menu ();

}
/*
2.cpp: In function ‘void Add_goods()’:
t2.cpp:60:12: warning: format ‘%f’ expects argument of type ‘float*’, but argument 2 has type ‘int*’ [-Wformat=]
   60 |   scanf ("%f", &p_t[counter_p].price_one);
      |           ~^   ~~~~~~~~~~~~~~~~~~~~~~~~~
      |            |   |
      |            |   int*
      |            float*
      |           %d
t2.cpp:63:12: warning: format ‘%f’ expects argument of type ‘float*’, but argument 2 has type ‘int*’ [-Wformat=]
   63 |   scanf ("%f", &p_t[counter_p].whole_sale);
      |           ~^   ~~~~~~~~~~~~~~~~~~~~~~~~~~
      |            |   |
      |            |   int*
      |            float*
      |           %d
t2.cpp:69:12: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘int’ [-Wformat=]
   69 |   scanf ("%s", p_t[counter_p].producer_compony);
      |           ~^   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |            |                  |
      |            char*              int
t2.cpp:77:3: error: ‘menu’ was not declared in this scope
   77 |   menu ();
      |   ^~~~
t2.cpp: In function ‘void Add_customer()’:
t2.cpp:99:3: error: ‘menu’ was not declared in this scope
   99 |   menu ();
      |   ^~~~
t2.cpp: In function ‘void sele_process()’:
t2.cpp:108:12: warning: format ‘%d’ expects argument of type ‘int*’, but argument 2 has type ‘long int*’ [-Wformat=]
  108 |   scanf ("%d", &s_t[counter_s].code_of_product);
      |           ~^   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |            |   |
      |            |   long int*
      |            int*
      |           %ld
t2.cpp:119:3: error: ‘menu’ was not declared in this scope
  119 |   menu();
      |   ^~~~
t2.cpp: In function ‘void show_list_goods()’:
t2.cpp:127:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  127 |       printf ("%d", &p_t[i].code_of_product);
      |                ~^   ~~~~~~~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:129:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  129 |       printf ("%d", &p_t[i].popularity);
      |                ~^   ~~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:130:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  130 |       printf ("%d", &p_t[i].ext);
      |                ~^   ~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:131:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  131 |       printf ("%d", &p_t[i].produce_date);
      |                ~^   ~~~~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:132:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  132 |       printf ("%d", &p_t[i].price_one);
      |                ~^   ~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:133:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  133 |       printf ("%d", &p_t[i].whole_sale);
      |                ~^   ~~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:134:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  134 |       printf ("%d", &p_t[i].remaining);
      |                ~^   ~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:135:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘int*’ [-Wformat=]
  135 |       printf ("%d", &p_t[i].available_number);
      |                ~^   ~~~~~~~~~~~~~~~~~~~~~~~~
      |                 |   |
      |                 int int*
      |                %n
t2.cpp:136:22: error: invalid conversion from ‘char’ to ‘const char*’ [-fpermissive]
  136 |       printf (p_t[i].producer_compony);
      |               ~~~~~~~^~~~~~~~~~~~~~~~
      |                      |
      |                      char
In file included from /usr/include/c++/9/cstdio:42,
                 from t2.cpp:1:
/usr/include/stdio.h:332:43: note:   initializing argument 1 of ‘int printf(const char*, ...)’
  332 | extern int printf (const char *__restrict __format, ...);
      |                    ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~
t2.cpp:136:38: warning: format not a string literal and no format arguments [-Wformat-security]
  136 |       printf (p_t[i].producer_compony);
      |                                      ^
t2.cpp: In function ‘void show_list_customer()’:
t2.cpp:153:5: error: ‘menu’ was not declared in this scope
  153 |     menu();
      |     ^~~~
t2.cpp: In function ‘void show_list_sales()’:
t2.cpp:162:17: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
  162 |       printf ("%d\n ",s_t[i].code_of_product);
      |                ~^     ~~~~~~~~~~~~~~~~~~~~~~
      |                 |            |
      |                 int          long int
      |                %ld
t2.cpp:169:5: error: ‘menu’ was not declared in this scope
  169 |     menu();
      |     ^~~~
t2.cpp: In function ‘void show_factor_of_id()’:
t2.cpp:183:23: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
  183 |             printf ("%d\n ",s_t[i].code_of_product);
      |                      ~^     ~~~~~~~~~~~~~~~~~~~~~~
      |                       |            |
      |                       int          long int
      |                      %ld
t2.cpp:191:5: error: ‘menu’ was not declared in this scope
  191 |     menu();
      |     ^~~~
t2.cpp: In function ‘void show_list_sales_today()’:
t2.cpp:205:23: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
  205 |             printf ("%d\n ",s_t[i].code_of_product);
      |                      ~^     ~~~~~~~~~~~~~~~~~~~~~~
      |                       |            |
      |                       int          long int
      |                      %ld
t2.cpp:213:5: error: ‘menu’ was not declared in this scope
  213 |     menu();
      |     ^~~~
13991209$ 

*/
