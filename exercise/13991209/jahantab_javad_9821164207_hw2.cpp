#include <stdio.h>
#include<windows.h>
void menu();
struct person addMember();
struct kala addKala();
struct Buy addBuy();
void showKala(struct kala k[]);
void showMember(struct person p[]);
void showBuy(struct Buy b[]);
struct person {
	char name[20];
	char fname[20];
	double balance;
	int age;
	int num;
};
struct kala {
	char name[20];
	double price;
	int num;
};
struct Buy {
	int numFactor;l
	int numPerson;
	int numKala;
	double price;
	int moth;
	int day;
};
int main(){
	menu();
}
void menu() {
	int x,ik=-1,ip=-1,ib=-1;
	struct kala k[100];
	struct person p[100];
	struct Buy b[100];
    system("cls");
	printf("\n\n\t\t\t  MENU\t\t\n\n");
	printf("A)Mangement of Memberships info\n1- Add a New Kala\n2- Add a New Member\n3- Add Buy\n4-Show Kala list\n5-Show Member list\n6-Show Buy list");
	printf ("\n enter order : ");
	scanf("%d",&x);
    if(x==1)  {
    	k[++ik]=addKala();
    	menu();
	}
    else if(x==2)  {
    	p[++ip]=addMember();
    	menu();
	}
	else if(x==3) {
    	b[++ib]=addBuy();
    	menu();
	}
	else if(x==4) showKala(k);
    else if(x==5) showMember(p);
    else if(x==6) showBuy(b);
    else{
            system("cls");
            printf("\nEnter 1 to 6 only");
            printf("\n Enter any key");
			menu();
	}
}
struct person addMember(){
	system("cls");
    struct person p;
    printf("\n Enter sharing number ");
	scanf("%d",&p.num);
    printf("\nEnter name: ");
    scanf("%s",p.name);
    printf("\nEnter family name: ");
    scanf("%s",p.fname);
    printf("\nEnter balance acount: ");
    scanf("%d",&p.balance);
    printf("\nrecord saved");
    printf("\n\nEnter any key");
    system("cls");
    return p;
}
struct kala addKala(){
	system("cls");
    struct kala k;
    printf("\n Enter Kala number ");
	scanf("%d",&k.num);
    printf("\nEnter  kala name: ");
    scanf("%s",k.name);
    printf("\nEnter Price :  ");
    scanf("%d",&k.price);
    printf("\nrecord saved");
    printf("\n\nEnter any key");
    system("cls");
    return k;
}
struct Buy addBuy(){
	system("cls");
    struct Buy b;
    printf("\n Enter factor number ");
	scanf("%d",&b.numFactor);
    printf("\n Enter Kala number ");
	scanf("%d",&b.numKala);
	printf("\n Enter person number ");
	scanf("%d",&b.numPerson);
    printf("\nEnter Price :  ");
    scanf("%d",&b.price);
    printf("\nEnter moth :  ");
    scanf("%d",&b.moth);
    printf("\nEnter day :  ");
    scanf("%d",&b.moth);
    printf("\nrecord saved");
    printf("\n\nEnter any key");
    system("cls");
    return b;
}
void showMember(struct person p[]) {
	system("cls");
	while(p[i]!=null)
	{
  		printf("\n\n\n YOUR RECORD IS\n\n ");
   		printf("\nsharing number : %s\nName : %s\nFamily name=%s\nmoney : %d\nage : %d",p[i].num,p[i].name,p[i].fname,p[i].money,p[i].age);
		system("cls");
		i++;
	}
	printf("\n Enter any key");
    system("cls");
	menu();
}
void showKala(struct kala k[]) {
	system("cls");
	while(k[i]!=null)
	{
  		printf("\n\n\n YOUR RECORD IS\n\n ");
   		printf("\nkala number : %s\nName : %s\nprice :%d",k[i].num,k[i].name,k[i].price);
		system("cls");
		i++;
	}
	printf("\n Enter any key");
    system("cls");
	menu();
}
void showKala(struct buy b[]) {
	system("cls");
	while(b[i]!=null)
	{
  		printf("\n\n\n YOUR RECORD IS\n\n ");
   		printf("\nfactor number : %d\nkala number : %d\nBuyer number : %d\nprice :%d \nmoth : %d \nyear : ",b[i].numFactor,b[i].numKala,b[i].numPerson,b[i].price,b[i].moth,b[i].year);
		system("cls");
		i++;
	}
	printf("\n Enter any key");
    system("cls");
	menu();
}
