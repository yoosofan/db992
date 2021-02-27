
int main()
{
    int goods[10000];
    int customers[10000];
    int sells[10000];

};
struct customer{
    char first_name[50];
    char last_name[50];
    int phone_number;
    char email_address[50];
    float balance;

};
struct goods{
    char name[60];
    float prices;
    char manufactor_name[60];
    int g_number;
    int goods_produce_date;
    int goods_Expiration_date;


};
struct sell_information{
    int customer_phone_number;
    int Single_good_number;
    float good_prices;

};
struct goods_date{
    int day; month; year;

};




#include <stdio.h>
goods adding_goods(void);
goods adding_goods(void){
    struct goods g1;
    struct goods_date g2;
    printf("please enter your name");
    scanf("%s",&g1.name);
    printf("enter a goods price's");
    scanf("%f",&g1.prices);
    printf("what is mf name? ");
    scanf("%s",&g1.manufactor_name);
    printf("please enter a goods number");
    scanf("%d",&g1.g_number);
    printf("enter produce date: ");
    scanf("%d%d%d",&g2.day,&g2.month,%g2.year);
    printf("enter Expriation date: ");
    scanf("5d%d%d",&g2.day,%g2.month,&g2.year);
    return g1;

}
customer adding_customer(void);
customer adding_customer(void){
    struct customer c1;
    printf("enter customer name & last name: ");
    scanf("%s%s",&c1.first_name,%c1.last_name);
    printf("enter customer phone number");
    scanf("%d",&c1.phone_number);
    printf("enter .... balance");
    scanf("%f",&c1.balance);

    return c1;


}
sell_information sell;
sell_information sell(int x){
    struct sell_information s1;
    int customer_number;
    int goods_number;
    float good_prices;
    int g=1;
    int h,j;
    printf("enter a customer number");
    scanf("%d",&s1.customer_phone_number);
    printf("enter a goods number");
    scanf("%d",&s1.single_good_number);
    printf("enter a prices of goods");
    scanf("%f",&s1.good_prices);
    while()





}
void goods_list();
void goods_list(void){
    int i=0;
    int c=1
    while(goods[i]!="\0"){
        i=i+1;
        c=c+1
        printf("goods list %d:  &d \n",c,goods[i]);
    }
void customers_list();
void customers_list(void){
    int j=0;
    int t=1;
    while(customers[j]!="\0"){
        j=j+1;
        t=t+1;
        printf("goods list %d:  &d \n",t,customers[j]);
    }
void all_sells_list();
void all_sells_list(void){
    int k=0;
    while(sells[k]!="\0"){
        k=k+1;
        p=p+1;
        printf("%d%d \n",p,sells[k]);
    }

}
}


}



void menu(void){
    printf("1_\n add goods");
    printf("2_\n add customer");
    printf("3_\n add ");
    printf("4_\n sell&buy");
    printf("5_\n Customer list");
    printf("6_\n all_sells list");
    printf("7_\n show factor informatin");
    printf("8_\n show one day sells information");
int n;
struct goods g11;
struct customer c11;
printf("please enter a number");
scanf("%d",&n);
switch(n){
    case 1:
        g11=goods adding_goods();
        goods[i]=g11;
        i=i+1;

    case 2:
        c11=customer adding_customer();
        customer[j]=c11;
        j=j+1;
    case 3:




}

}
