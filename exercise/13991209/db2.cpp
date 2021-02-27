#include <cstdio>
#include <cstdlib>
/*
typedef struct address{
    char city[50];
    char street[50];
    char alley[50];
    char complex[50];
    int floor;
}Address;
typedef struct producer{
    char city[50];
    char street[50];
    char alley[50];
    char complex[50];
    int floor;
}producer;

*/
struct Customer{
    int code;
    char bday[10];
    int phonenum;
    char first_name[50];
    char last_name[50];
};

struct Good{
    int code;
    int number;
    float price;
    char name[1000];
    char extra_info[1000];

};

struct Sell{
    int code;
    int customer_code;
    int purchase_code[100];
    int purchase_number;
    float final_price;
    char date[10];
};

int main(){

    //X
    char l;
    int req=0;
    int t=1;

    int customer_number=0;
    int goods_number=0;
    int sell_number=0;

    Good good[1000];
    Customer customer[100];
    Sell sell[10];

    while(t){
        printf("1 - Add goods\n");
        printf("2 - Add a customer\n");
        printf("3 - Sales\n");
        printf("4 - List of goods\n");
        printf("5 - List of customers\n");
        printf("6 - Sales list\n");
        printf("7 - Factor information\n");
        printf("8 - Sales information for a specific day\n");
        printf("9 - Exit\n");


        scanf("%d",&req);

        switch (req){

            case 1:
                printf("Add a new good:\n");

                goods_number++;

                printf("Code:");
                good[goods_number].code=goods_number;
                printf("%d\n",goods_number);
                printf("Name:");
                scanf("%s",&good[goods_number].name);
                printf("Price:");
                scanf("%f",&good[goods_number].price);
                printf("Existence:");
                scanf("%d",&good[goods_number].number);
                printf("Extra Information:");
                scanf("%s",&good[goods_number].extra_info);

                printf("DONE!");

                printf("Add a char to exit ");
                scanf("%s",&l);

                break;

            case 2:

                customer_number++;
                printf("Code:");
                customer[customer_number].code=customer_number;
                printf("First Name:");
                scanf("%s",&customer[customer_number].first_name);
                printf("Last Name:");
                scanf("%s",&customer[customer_number].last_name);
                printf("Phone number:");
                scanf("%d",&customer[customer_number].phonenum);
                printf("Birthday:");
                scanf("%s",&customer[customer_number].bday);

                //Address
                printf("DONE!");

                printf("Add a char to exit ");
                scanf("%s",&l);
                break;

            case 3:
                sell_number++;
                int m=0;
                int p=0;
                printf("Sell Code:");
                sell[sell_number].code=sell_number;
                printf("Date:");
                scanf("%s",&sell[sell_number].date);
                printf("Customer code:");
                scanf("%d",&sell[sell_number].customer_code);
                sell[sell_number].final_price=0;
                sell[sell_number].purchase_number=0;
                while(1){
                    printf("Enter the product code / or -1 If the purchase is over:");
                    scanf("%d",&m);
                    if (m == -1) break;
                    else {
                        if(m<=goods_number){
                            if(good[m].number>0){
                                p++;
                                good[m].number--;
                                sell[sell_number].purchase_number++;
                                sell[sell_number].final_price+=good[m].price;
                                sell[sell_number].purchase_code[p]=m;

                            }
                            else printf("this product dose not exist anymore");
                            for (int i=1;i<=goods_number;i++){
                                if (good[i].number==0){
                                    printf("code number%d out of stock",good[i].code);
                                    goods_number--;
                                    for(int j=i;j<=goods_number;j++){
                                        good[i].code=good[i+1].code;
                                        *good[i].extra_info=&good[i+1].extra_info;
                                        *good[i].name=&good[i+1].name;
                                        good[i].number=good[i+1].number;
                                        good[i].price=good[i+1].price;
                                }

                                }
                            }
                        }
                        else printf("this product dose not exist");

                        }


                    }


                //Address
                printf("DONE!");

                printf("Add a char to exit ");
                scanf("%s",&l);

                break;

            case 4:
                printf("List of goods\n");
                for(int i=1;i<=goods_number;i++){
                    printf("%d - Code :%d\n",i,good[i].code);
                    printf("    Name :%s\n",good[i].name);
                    printf("    Extra Information :%s\n",good[i].extra_info);
                    printf("    Price :%f\n",good[i].price);
                    printf("    Existance :%d\n\n",good[i].number);
                }
                printf("Add a char to exit ");
                scanf("%s",&l);

                break;

            case 5:

                printf("List of customers\n");
                for(int i=1;i<=customer_number;i++){
                    printf("%d - First Name :%s\n",i,customer[i].first_name);
                    printf("    Last Name :%s\n",customer[i].last_name);
                    printf("    Birthday :%s\n",customer[i].bday);
                    printf("    Phone number :%d\n",customer[i].phonenum);
                   // Address
                }

                printf("Add a char to exit ");
                scanf("%s",&l);

                break;

            case 6:

                printf("List of Sells\n");
                for(int i=1;i<=sell_number;i++){
                    printf("%d - Code :%d\n",i,sell[i].code);
                    printf("    customer code :%s\n",sell[i].customer_code);
                    printf("    date :%s\n",sell[i].date);
                    printf("    final price :%f\n",sell[i].final_price);
                    printf("Products:");
                    for(int j=1;j<=sell[i].purchase_number;j++){
                        printf("    product code :%d\n",sell[i].purchase_code[j]);

                    }
                }

                printf("Add a char to exit ");
                scanf("%s",&l);

                break;

            case 7:
                system("cls");

                int n=0;
                printf("Which factor information do you want to see? Enter its code");
                scanf("%d",&n);
                if(n<=sell_number){
                    printf("Code :%d\n",sell[n].code);
                    printf("Date :%s\n",sell[n].date);
                    printf("Customer Code :%d\n",sell[n].customer_code);
                    printf("Customer Name :%s %s\n",customer[sell[n].customer_code].first_name,customer[sell[n].customer_code].last_name);

                    for(int i=0;i<sell[n].purchase_number;i++){
                        printf("Product with%dCode Name of Product :%s",sell[n].purchase_code[i],good[sell[n].purchase_code[i]].name);
                    }
                }

                printf("Add a char to exit ");
                scanf("%s",&l);

                break;

            case 8:
                system("cls");
                char s[10];
                printf("Enter date");
                scanf("%s",&s);
                int e=1;
                for(int i =1;i<=sell_number;i++)
                {
                    for(int j =0 ;j<10;j++)
                        if (s[j] != sell[i].date[j])e=0;
                    if (e){
                    printf("Code :%d\n",sell[n].code);
                    printf("Date :%s\n",sell[n].date);
                    printf("Customer Code :%d\n",sell[n].customer_code);
                    printf("Customer Name :%s %s\n",customer[sell[n].customer_code].first_name,customer[sell[n].customer_code].last_name);

                    for(int i=0;i<sell[n].purchase_number;i++){
                        printf("Product with%dCode Name of Product :%s",sell[n].purchase_code[i],good[sell[n].purchase_code[i]].name);
                    }


                    }
                }
                printf("Add a char to exit ");
                scanf("%s",&l);
                break;
            case 9:
                t=0;
                system("cls");
                printf("DONE !");
                break;
            default:
                printf("your request is not valid\n");
                printf("add a char and Try something else ");
                scanf("%s",&l);
                break;

            }

    }
    return 0;

}
/*
13991209$ g++ db2.cpp 
db2.cpp: In function ‘int main()’:
db2.cpp:88:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[1000]’ [-Wformat=]
   88 |                 scanf("%s",&good[goods_number].name);
      |                        ~^  ~~~~~~~~~~~~~~~~~~~~~~~~
      |                         |  |
      |                         |  char (*)[1000]
      |                         char*
db2.cpp:94:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[1000]’ [-Wformat=]
   94 |                 scanf("%s",&good[goods_number].extra_info);
      |                        ~^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                         |  |
      |                         |  char (*)[1000]
      |                         char*
db2.cpp:110:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
  110 |                 scanf("%s",&customer[customer_number].first_name);
      |                        ~^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                         |  |
      |                         |  char (*)[50]
      |                         char*
db2.cpp:112:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
  112 |                 scanf("%s",&customer[customer_number].last_name);
      |                        ~^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                         |  |
      |                         |  char (*)[50]
      |                         char*
db2.cpp:116:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
  116 |                 scanf("%s",&customer[customer_number].bday);
      |                        ~^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                         |  |
      |                         |  char (*)[10]
      |                         char*
db2.cpp:133:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
  133 |                 scanf("%s",&sell[sell_number].date);
      |                        ~^  ~~~~~~~~~~~~~~~~~~~~~~~
      |                         |  |
      |                         |  char (*)[10]
      |                         char*
db2.cpp:159:61: error: invalid conversion from ‘char (*)[1000]’ to ‘char’ [-fpermissive]
  159 |                                         *good[i].extra_info=&good[i+1].extra_info;
      |                                                             ^~~~~~~~~~~~~~~~~~~~~
      |                                                             |
      |                                                             char (*)[1000]
db2.cpp:160:55: error: invalid conversion from ‘char (*)[1000]’ to ‘char’ [-fpermissive]
  160 |                                         *good[i].name=&good[i+1].name;
      |                                                       ^~~~~~~~~~~~~~~
      |                                                       |
      |                                                       char (*)[1000]
db2.cpp:184:18: error: jump to case label
  184 |             case 4:
      |                  ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
db2.cpp:199:18: error: jump to case label
  199 |             case 5:
      |                  ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
db2.cpp:216:18: error: jump to case label
  216 |             case 6:
      |                  ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
db2.cpp:222:49: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘int’ [-Wformat=]
  222 |                     printf("    customer code :%s\n",sell[i].customer_code);
      |                                                ~^    ~~~~~~~~~~~~~~~~~~~~~
      |                                                 |            |
      |                                                 char*        int
      |                                                %d
db2.cpp:237:18: error: jump to case label
  237 |             case 7:
      |                  ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
db2.cpp:259:18: error: jump to case label
  259 |             case 8:
      |                  ^
db2.cpp:240:21: note:   crosses initialization of ‘int n’
  240 |                 int n=0;
      |                     ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
db2.cpp:263:25: warning: format ‘%s’ expects argument of type ‘char*’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
  263 |                 scanf("%s",&s);
      |                        ~^  ~~
      |                         |  |
      |                         |  char (*)[10]
      |                         char*
db2.cpp:285:18: error: jump to case label
  285 |             case 9:
      |                  ^
db2.cpp:264:21: note:   crosses initialization of ‘int e’
  264 |                 int e=1;
      |                     ^
db2.cpp:240:21: note:   crosses initialization of ‘int n’
  240 |                 int n=0;
      |                     ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
db2.cpp:290:13: error: jump to case label
  290 |             default:
      |             ^~~~~~~
db2.cpp:264:21: note:   crosses initialization of ‘int e’
  264 |                 int e=1;
      |                     ^
db2.cpp:240:21: note:   crosses initialization of ‘int n’
  240 |                 int n=0;
      |                     ^
db2.cpp:129:21: note:   crosses initialization of ‘int p’
  129 |                 int p=0;
      |                     ^
db2.cpp:128:21: note:   crosses initialization of ‘int m’
  128 |                 int m=0;
      |                     ^
13991209$ 

 */
