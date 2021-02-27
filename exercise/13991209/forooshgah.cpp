#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

void menu(void);
void addCustomer(void);
void addProduct(void);
void addsale(void);
void listProduct(void);
void listCustomer(void);
void listSale(void);
void specificInvoice(void);
void oneDaySales(void);

struct customer{
    int id;
    char name[10];
    char phoneNumber[11];
};
struct product{
    int id;
    char name[10];
    int price;
    int discount;
};
struct sale{
    int factorNum;
    int customerId;
    int productId;
    int number;
    char date[10];
};


static int ctrCustomer = 0;
static int ctrProduct = 0;
static int ctrSale = 0;

struct product proarr[50];
struct customer custarr[50];
struct sale salearr[50];

int main()
{
    menu();
}

void menu(void){
    int select;
    printf("1.Add product\n2.Add customer\n3.Add sale\n4.List of products\n5.List of customers\n6.Sales list\n7.Information of a specific invoice\n8.One day sales information");
    printf("\nEnter your selection : ");
    scanf("%d",&select);
    if(select == 1){
        addProduct();
    }
    else if(select == 2){
        addCustomer();
    }
    else if(select == 3){
        addsale();
    }
    else if(select == 4){
        listProduct();
    }
    else if(select == 5){
        listCustomer();
    }
    else if(select == 6){
        listSale();
    }
    else if(select == 7){
        specificInvoice();
    }
    else if(select == 8){
        oneDaySales();
    }

}

void addCustomer(){
    struct customer newC;
    printf("Enter customer id : ");
    scanf("%d",&newC.id);
    printf("Enter customer name : ");
    scanf("%s",newC.name);
    printf("Enter customer phone number : ");
    scanf("%s",newC.phoneNumber);
    custarr[ctrCustomer] = newC;
    ctrCustomer += 1;
    menu();
}

void addProduct(){
    struct product newP;
    printf("Enter product id : ");
    scanf("%d",&newP.id);
    printf("Enter product name : ");
    scanf("%s",newP.name);
    printf("Enter product price : ");
    scanf("%d",&newP.price);
    printf("Enter product discount : ");
    scanf("%2d",&newP.discount);
    proarr[ctrProduct] = newP;
    ctrProduct += 1;
    menu();
}

void addsale(){
    struct sale newS;
    printf("Enter sale factorNum : ");
    scanf("%d",&newS.factorNum);
    printf("Enter sale customerId : ");
    scanf("%d",&newS.customerId);
    printf("Enter sale productId : ");
    scanf("%d",&newS.productId);
    printf("Enter sale number : ");
    scanf("%d",&newS.number);
    printf("Enter sale date [****/**/**]: ");
    scanf("%s",newS.date);
    salearr[ctrSale] = newS;
    ctrSale += 1;
    menu();
}

void listProduct(){
    for(int i=0;i<ctrProduct;i++){
        printf("Product id : %d\n",proarr[i].id);
        printf("Product name : %s\n",proarr[i].name);
        printf("Product price : %d\n",proarr[i].price);
        printf("Product discount : %d\n",proarr[i].discount);
        printf("*******************\n");
    }
    menu();
}

void listCustomer(){
    for(int i=0;i<ctrCustomer;i++){
        printf("Customer id : %d\n",custarr[i].id);
        printf("Customer name : %s\n",custarr[i].name);
        printf("Customer phone number : %s\n",custarr[i].phoneNumber);
        printf("*******************\n");
    }
    menu();
}

void listSale(){
    for(int i=0;i<ctrSale;i++){
        printf("sale factor number : %d\n",salearr[i].factorNum);
        printf("sale customer id : %d\n",salearr[i].customerId);
        printf("sale product id : %d\n",salearr[i].productId);
        printf("sale number : %d\n",salearr[i].number);
        printf("sale date : %s\n",salearr[i].date);
        printf("*******************\n");
    }
    menu();
}

void specificInvoice(){
    int fn;
    printf("Enter factor number : ");
    scanf("%d",&fn);
    for(int i=0;i<ctrSale;i++){
            if(fn == salearr[i].factorNum){
                printf("sale factor number : %d\n",salearr[i].factorNum);
                printf("sale customer id : %d\n",salearr[i].customerId);
                printf("sale product id : %d\n",salearr[i].productId);
                printf("sale number : %d\n",salearr[i].number);
                printf("sale date : %s\n",salearr[i].date);
                printf("*******************\n");
            }
    }
    menu();
}

void oneDaySales(){
    char onedate[10];
    printf("Enter date : ");
    scanf("%s",onedate);
    for(int i=0;i<ctrSale;i++){
        if(strcmp(onedate,salearr[i].date) == 0){
            printf("sale factor number : %d\n",salearr[i].factorNum);
            printf("sale customer id : %d\n",salearr[i].customerId);
            printf("sale product id : %d\n",salearr[i].productId);
            printf("sale number : %d\n",salearr[i].number);
            printf("sale date : %s\n",salearr[i].date);
            printf("*******************\n");
        }
    }
    menu();
}
