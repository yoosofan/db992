/*Arian Seyfi*/
/*9721160023*/

#include <stdio.h>

struct product {
   char title[100];
   float price;
   int number;                  /*Number of products available*/
   char productionDate[10];     /*The date the product expires*/
   char expirationDate[10];     /*The date the product was produced*/
   float weight;                /*Based on Grams*/
   float size;                  /*Square centimeters*/
   char company[20]             /*Name of the producer*/
   char mainCategory[100];      /*the category that this product is in*/
   int numberSold;              /*number sold till now*/
   int numberPurchased;         /*number purchased till now*/
   float discountRate;          /*Discount for the product*/
   char ingredients[1000];      /*Materials of which the product is composed*/
   char appleHealth[1000];      /*Apple Health Information*/
};

struct storage{
   product cellar[1000];
   int size = 1000;
   int numFullHouse = 0;      /*number of full houses in storage*/
};

struct customer{
   char name[50];
   int phoneNumber;
};

struct customerlist{
   customer client[1000];
   int size = 1000;
   int numFullHouse = 0;      /*number of full houses in the list*/
};

struct salecart{
   customer person;            /*The Buyer*/
   int indexOfObjects[100];    /*indexes of products he/she is buying*/
   char time[5];
   char date[10];
   float wholePrice;
};

struct salelist
{
   salecart allCarts[1000];
   int size = 1000;
   int numFullHouse = 0;      /*number of full houses in the list*/
};



/* function declaration */
void panel(void);
void addingProduct(storage store);
void addingCustomers(customerlist personlist);
void addingSaleCart(customerlist personlist, storage store, salelist sale);
void showingProducts(storage store);
void showingCustomers(customerlist personlist);
void showingAcartDetails(salelist sale,int index,storage store);
void showingAllCarts(salelist sale,storage store);
void showingADayAllCarts(salelist sale,storage store, char dateGiven[]);

int main(){
   storage store;
   customerlist personlist;
   salelist sale;
   panel(store,personlist,sale);
   return 0;
}

void panel(storage store, customerlist personlist, salelist sale;){
   int loopVAR == 1;
   int input;
   int indexConsumed;
   char thisDate[10];
   do{
      printf("1. Add product\n");
      printf("2. Add customer\n");
      printf("3. Sell\n");
      printf("4. List of products\n");
      printf("5. List of customers\n");
      printf("6. List of Sales\n");
      printf("7. Display information of a specific Sale\n");
      printf("8. Display day sales information\n");
      printf("0. exit\n\n");
      printf("Please enter a number:");
      scanf("%d", &input);
      printf("\n\n\n");

      if(input==1){
         addingProduct(store);
      }
      else if(input==2){
         addingCustomers(personlist)
      }
      else if(input==3){
         addingSaleCart(personlist, store, sale);
      }
      else if(input==4){
         showingProducts(store);
      }
      else if(input==5){
         showingCustomers(personlist);
      }
      else if(input==6){
         showingAllCarts(sale,store);
      }
      else if(input==7){
         printf("please enter the index of your sale cart:");
         scanf("%d", &indexConsumed );
         showingAcartDetails(sale,indexConsumed,store);
      }
      else if(input==8){
         printf("please enter the date: ");
         gets( thisDate );
         showingADayAllCarts(sale,store,thisDate[]);
      }
      else if(input==0){
          loopVAR = 0;
      }
   }while(loopVAR == 1);
}

void addingProduct(storage store){
   if(store.size == store.numFullHouse){
      printf("storage is full! Sorry.\n");
   }
   else{
      printf( "\nEnter title :");
      gets( store.cellar[store.numFullHouse].title );
      printf( "\nEnter price :");
      scanf("%d", &store.cellar[store.numFullHouse].price);
      printf( "\nHow many do you want to add? :");
      scanf("%d", &store.cellar[store.numFullHouse].number);
      printf( "\nEnter Production Date :");
      gets( store.cellar[store.numFullHouse].productionDate );
      printf( "\nEnter Expiration Date:");
      gets( store.cellar[store.numFullHouse].expirationDate );
      printf( "\nEnter Weight :");
      scanf("%d", &store.cellar[store.numFullHouse].weight);
      printf( "\nEnter Size :");
      scanf("%d", &store.cellar[store.numFullHouse].size);
      printf( "\nEnter Company :");
      gets( store.cellar[store.numFullHouse].company );
      printf( "\nEnter Main Category :");
      gets( store.cellar[store.numFullHouse].mainCategory );
      printf( "\nEnter Number sold :");
      scanf("%d", &store.cellar[store.numFullHouse].numberSold);
      printf( "\nEnter Number purchased :");
      scanf("%d", &store.cellar[store.numFullHouse].numberPurchased);
      printf( "\nEnter Discount rate :");
      scanf("%d", &store.cellar[store.numFullHouse].discountRate);
      printf( "\nEnter Ingredients :");
      gets( store.cellar[store.numFullHouse].ingredients );
      printf( "\nEnter Apple Health details:");
      gets( store.cellar[store.numFullHouse].appleHealth );
      store.numFullHouse++;
   }
}

void addingCustomers(customerlist personlist){
   if(personlist.size == personlist.numFullHouse){
      printf("list is full! Sorry.\n");
   }
   else{
      printf( "\nEnter Name :");
      gets( personlist.client[personlist.numFullHouse].name );
      printf( "\nEnter phone number :");
      scanf("%d", &personlist.client[personlist.numFullHouse].phoneNumber );
      personlist.numFullHouse++;
   }
}

void addingSaleCart(customerlist personlist, storage store, salelist sale){
   int phone;
   float fullPrice=0;
   int a,x,sizeConsumed=0;
   int indexes[100];
   if(sale.size == sale.numFullHouse){
      printf("list is full! Sorry.\n");
   }
   else{
      printf( "\nEnter Phone number :");
      scanf("%d", &phone );
      for( a = 0 ; a < personlist.numFullHouse; a = a + 1 ){
         if(phone == personlist.client[a].phoneNumber){
            sale.allCarts[sale.numFullHouse].person.phoneNumber = phone;
         }
         else{
            printf( "\nphone not found");
         }
      }
      printf( "\nEnter Time :");
      gets( sale.allCarts[sale.numFullHouse].time );
      printf( "\nEnter Date :");
      gets( sale.allCarts[sale.numFullHouse].date );
      showingProducts(store);
      printf( "\nHow many products you want? :");
      scanf("%d", &sizeConsumed );
      printf( "\nEnter indexes of products you want :");
      for( x = 0; x < sizeConsumed; x = x + 1 ){
         scanf("%d", &sale.allCarts[sale.numFullHouse].indexOfObjects[x] );
         fullPrice = fullPrice + store.cellar[sale.allCarts[sale.numFullHouse].indexOfObjects[x]].price;
         sale.allCarts[sale.numFullHouse].wholePrice = fullPrice;
      }
      sale.numFullHouse++;
   }
}

void showingProducts(storage store){
   int a;
   printf( "\n\nlist of products --->\n");
   for( a = 0; a < store.numFullHouse; a = a + 1 ){
      printf( "%d . %s\n", a, store.cellar[a].title);
   }
}

void showingCustomers(customerlist personlist){
   int a;
   printf( "\n\nlist of customers --->\n");
   for( a = 0; a < personlist.numFullHouse; a = a + 1 ){
      printf( "%d . %s\n", a, personlist.client[a].name);
   }
}

void showingAllCarts(salelist sale,storage store){
   int a;
   printf( "\n\nlist of sales --->\n");
   for( a = 0; a < sale.numFullHouse; a = a + 1 ){
      showingAcartDetails(sale,a,store);
      printf("\n_______________\n");
   }
}

void showingAcartDetails(salelist sale,int index,storage store){
   int a;
   printf( "\n\nDetails ---> # %d #\n",index);
   printf( "%s\n", sale.allCarts[index].person);
   printf( "%s\n", sale.allCarts[index].time);
   printf( "%s\n", sale.allCarts[index].date);
   while(sale.allCarts[index].indexOfObjects[a] != NULL){
      printf( "%d . %s : %s toman\n", a, store.cellar[sale.allCarts[index].indexOfObjects[a]].title, store.cellar[sale.allCarts[index].indexOfObjects[a]].price);
   }
   printf( "all price is %s toman\n", sale.allCarts[index].wholePrice);
}

void showingADayAllCarts(salelist sale,storage store, char dateGiven[]){
   int a;
   if (strcmp(namet2, nameIt2) != 0)
   for( a = 0; a < sale.numFullHouse; a = a + 1 ){
      if (strcmp(dateGiven, sale.allCarts[a].date) == 0){
         showingAcartDetails(sale,a,store);
      }
   }
}
