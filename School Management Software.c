//Added the secret
	/*DEVELOPED FOR THE COMPLETION OF THE PROJECT ASSIGNMENT*/  /*	Version 3.1 */
#include<stdio.h>
#include<conio.h>        //ADDED DATE
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>
#include<math.h>
//void startup(void);
void add(void);   //Add Record
void view(void);  //View Record
void search(int c); //Search the records
void edit(int c,int roll);  //Edit the Record
void del(int c,int roll);  //Delete the Records
void info(void);           //Displays the information About Programmers
void add2(int c);          //Add function used in class with no records
void head(void);           //Contains the heading of the program
int login(int s);          //Allows the user to pass only if username and password are correct
void ww(void);             //Displays the students scoring above 80%
void search2(int c,int roll);//Displays the searched students information if the authorization for deletion fails
void details(void);        //Displays the details stored in the program
void view2(int c);        //Acts as BACK function in view	//Logout the user
void forgot(void);        //DISPLAYS THE USERNAMES and PASSWORDS if administrator password is correct
void validate(void);     //Allow Only Numbers to be typed
void add_user(void);	//Add New User
void last_add(void);
char k[20];
int aaa;
struct std
{
	int roll,clas;
	char name[30];
	struct mark
	{
		int a,b,f,g,h;
	}m;
	float per;
}s[50],s1;
struct data
{
	char user[45],pass[45];
}q12;
void main()
{
	int a,b,z=0,l,p;
	struct data d;
      //	startup();
      for( ; ; )
	{
			b=login(1);
			if(b==1)
			{
			printf("\n\t\tAccess Granted !!");
			delay(500);
			break;
			}
			else
			{
				z++;
				printf("\n\t\tPassword Or Username Wrong\n");
				delay(400);
				if(z==4)
				{
					printf("\t\tMaximum trial Reached.\n");
					printf("Press 1 to recover Password , any other key to Exit\n");
					switch(getch())
					{
				      /*	printf("Exitting. ");
					delay(40);
					printf(". ");
					delay(40);
					printf(". ");
					delay(40);
					printf(". ");
					delay(40);
					printf(". ");
					exit(0);  */
					case '1':
						forgot();
						break;
					default:
					exit(1);
				      }
				}

			}
	}
	while(1)
	{
		head();
		printf("\t\t\tLogged In as %s\n",k);
		printf("\n\n----------|1.Add Record\n");
		//printf("-------------------------------------------------------|");
		printf("----------|2.View Records\t\t\n");
	       //	printf("-------------------------------------------------------|");
		printf("----------|3.Display records of students according to percentage %\n");
	       //	printf("-------------------------------------------------------|");
		printf("----------|4.Last Updated\n");
		printf("----------|5.View Details\n");

		printf("----------|6.About us\n");
		printf("----------|7.Add New user\n");
		printf("----------|8.Logout\n");
		printf("----------|Press any other Key to exit. . .\n\n\n\t");
	       //	gotoxy(70,25);
		gotoxy(40,18);
		getdate(&d);
		printf("15-03-15 22:38");
		gotoxy(12,18);
		printf("Your Choice:\t");
	      //	scanf("%c",&a);
		validate();
		a=aaa;
		printf("\n");
		switch(a)
		{
			case 1:
				delay(300);
				clrscr();
				add();
				break;
			case 2:
				delay(301);
				clrscr();
				view();
				break;

			case 3:
				ww();
				break;
			case 5:
				details();
				break;
			case 6:
				info();
				break;
			case 7:
				add_user();
				break;
			case 4:
				last_add();
				break;
			case 8:
				printf("Do you want To Logout(Y/N):\t");
				l=getch();
				if(l=='y' || l=='Y')
				{
					printf("\nLogging out.");
					for(p=0;p<10;p++)
					{
						printf(" .");
						delay(120);
					}
				main();
				}
				else
				break;
			default:
				delay(200);
				clrscr();
				gotoxy(20,15);
				printf("Thank You For Using This Program...\n");
				printf("Exitting.");

				delay(230);
				printf(".");
				delay(300);
				printf(".");
				delay(340);
				printf(".");
				delay(300);
				printf(".");
				delay(340);printf(".");
				delay(300);
				printf(".");
				delay(340);
				clrscr();
				exit(0);

		}
	}
}
void add(void)
{
	FILE *fp,*fpp;
	int t=0,o,l,p;
	head();
       //	fp=fopen("26.txt","a");
	printf("Enter the students Information. . \n");
	printf("Name : \t");
	scanf("%s",&s[0].name);
	s[0].name[0]=toupper(s[0].name[0]);
//	printf("Roll: \t");
 //	scanf("%d",&s[0].roll);
	printf("Class: \t");
//	scanf("%d",&s[0].clas);
	validate();
	s[0].clas=aaa;
	printf("\n");
	for( ; ; )
	{
		l=0;
		printf("Roll:\t");
		validate();
		s[0].roll=aaa;
		printf("\n");
		fp=fopen("45.txt","r");
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
			if((s[0].roll==s1.roll) && (s[0].clas==s1.clas))
			l++;
		}
		fclose(fp);
		if(l!=0)
			printf("Error : Roll Repeated !!.Please input another Roll\n");
		else
		break;
	}
	printf("Marks: \n");
	for( ; ; )
	{
    //	fflush(stdin);
	printf("Marks in English(100) : \t");
	validate();
	s[0].m.a=aaa;
	printf("\n");
	if(!(s[0].m.a<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Mathmetics(100) : \t");
       //	scanf("%d",&s[0].m.b);
	validate();
	s[0].m.b=aaa;
	printf("\n");
	if(!(s[0].m.b<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Computer(100) : \t");
       //	scanf("%d",&s[0].m.f);
	validate();
	s[0].m.f=aaa;
	printf("\n");
	if(!(s[0].m.f<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Business(100) : \t");
      //	scanf("%d",&s[0].m.g);
	validate();
	s[0].m.g=aaa;
	printf("\n");
	if(!(s[0].m.g<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Account(100) : \t");
       //	scanf("%d",&s[0].m.h);
	validate();
	s[0].m.h=aaa;
	printf("\n");
	if(!(s[0].m.h<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
      /*	if(s[0].m.a>100 || s[0].m.b>100 || s[0].m.g>100 || s[0].m.f>100 || s[0].m.h>100)
	{
	printf("Marks Cannot Be greater than 100 !!\n");
	getch();
	}
	else
	{     */
	s[0].per=(s[0].m.a+s[0].m.b+s[0].m.f+s[0].m.g+s[0].m.h)/(5.00);
	fp=fopen("45.txt","r");
	while(fread(&s1,sizeof(s1),1,fp)==1)
	{
		if((s[0].roll==s1.roll) && (s[0].clas==s1.clas))
		t++;
	}
	fclose(fp);
	fp=fopen("45.txt","a");
	fpp=fopen("last.dat","w");
	if(t==0)
	{
		fwrite(&s[0],sizeof(s[0]),1,fp);
		fwrite(&s[0],sizeof(s[0]),1,fpp);
		printf("Record Added !!");
	}
	else
		printf("Roll Number Repeated !!");

	fclose(fp);
	fclose(fpp);
	delay(1000);
}
void view(void)
{
	FILE *fp;
	int cls,t=0;
	head();
	fp=fopen("45.txt","r");
	printf("Class:\t");
       //	scanf("%d",&cls);
	validate();
	cls=aaa;
	clrscr();
	printf("Student's Information of class %d \n",cls);
	printf("Name\tRoll\tPercentage\tRemarks\t\t\n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if(cls==s[0].clas)
		{
			printf("%s\t%d\t%0.2f\t\t",s[0].name,s[0].roll,s[0].per);
			if(s[0].per>=75 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Distinction !!\t");
			else if(s[0].per>=60 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("First Division\t");
			else if(s[0].per>=45 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Second Division\t");
			else if(s[0].per>=35 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Third Division\t");
			else
				printf("Fail\t\t");
			printf("\n");
			printf("---------------------------------------------------------|\n");
			delay(450);
			t++;
		}
	}
	fclose(fp);
	delay(300);
	if(t!=0)
		search(cls);
	else
	{
		printf("No Record Found\n");
		delay(1000);
		add2(cls);
	}
}
void search(int c)
{
	FILE *fp;
	int roll,choice,t=0;
	char dd;
	printf("Enter The Roll number you want to view :\t");
       //	scanf("%d",&roll);
	validate();
	roll=aaa;
	fp=fopen("45.txt","r");
	delay(200);
	clrscr();
	head();
	printf("\n\n");
      //	printf("Name\tRoll\tPercentage\tRemarks\t\tMarks: \n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if(c==s[0].clas && roll==s[0].roll)
		{
		      //	printf("%s\t%d\t%0.2f\t\t",s[0].name,s[0].roll,s[0].per);
			printf("The Marks obtained by %s,",s[0].name);
			printf("Roll : %d of Class: %d are given below:\n\n",s[0].roll,s[0].clas);
			printf("Subjects \t\t Full Marks\tPass Marks\t Obtained Marks   Remark\n");
			printf("______________________________________________________________________________\n");
			printf("English \t\t     100    \t    35    \t       %d  ",s[0].m.a);
			if(s[0].m.a<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Math    \t\t     100    \t    35    \t       %d  ",s[0].m.b);
			if(s[0].m.b<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Computer\t\t     100    \t    35    \t       %d  ",s[0].m.f);
			if(s[0].m.f<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Business\t\t     100    \t    35    \t       %d  ",s[0].m.g);
			if(s[0].m.g<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Account \t\t     100    \t    35    \t       %d  ",s[0].m.h);
			if(s[0].m.h<35)
			printf("          *\n");
			else
			printf("\n");
		       //	printf("_________________________________________________________________\n");
			printf("______________________________________________________________________________\n");
			printf("Total   \t\t     500    \t   175    \t       %d\n",s[0].m.a+s[0].m.b+s[0].m.g+s[0].m.f+s[0].m.h);
			printf("______________________________________________________________________________\n");
		       //	printf("_________________________________________________________________\n");
			printf("Total Marks Secured : %d\t",s[0].m.a+s[0].m.b+s[0].m.g+s[0].m.f+s[0].m.h);
			printf("Percentage: %0.2f %\t",s[0].per);
			printf("Division: ");
			if(s[0].per>=75 && s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				{
					printf("Distinction !!\n");
					if(s[0].roll%2==0)
					printf("Comments : Excellent!!\n");
					else if(s[0].roll<10)
					printf("Comments : Marvellous !!\n");
					else
					printf("Comments : Brilliant!!\n");
				}
			else if(s[0].per>=60 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
			{
				printf("First Division\n");
					if(s[0].roll%2==0)
					printf("Comments : Good!!\n");
					else if(s[0].roll<10)
					printf("Comments : Keep up !!\n");
					else
					printf("Comments : Superb!!\n");
				}
			else if(s[0].per>=45 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
			{
				printf("Second Division\n");
					if(s[0].roll%2==0)
					printf("Comments : Try Harder!!\n");
					else if(s[0].roll<10)
					printf("Comments : Not Good Enough !!\n");
					else
					printf("Comments : Read Harder!!\n");
				}
			else if(s[0].per>=35 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
			{
				printf("Third Division\n");
				if(s[0].roll%2==0)
				printf("Comments : Study Harder!!\n");
				else if(s[0].roll<10)
				printf("Comments : Poor marks!!\n");
				else
				printf("Comments : Not Good Enough!!\n");
				}
			else
			{
				printf("Fail\n");
				if(s[0].roll%2==0)
				printf("Comments : Very Bad!!\n");
				else if(s[0].roll<10)
				printf("Comments : Try Harder to Pass !!\n");
				else
				printf("Comments : Improve Yourself!!\n");
			}
			printf("\t//*************************************************************//\n");
			printf("\t\tPress 1 To EDIT record , Press 2 To DELETE record \n");
			printf("\t//*************************************************************//\n\t");
			printf("Press 3 to go back , any other key to go back to Main menu\n");
			choice=getch();
			if(choice=='1')
			{
				edit(c,roll);
			}
			else if(choice=='2')
			{
				printf("Are you Sure You want to DELETE the record(y\\n): \t");
				dd=getch();
				if(dd=='y' || dd=='Y')
				if(login(0)==1)
				del(c,roll);
				else
				{
					printf("\nUsername or Password wrong. Deletion Aborted\n");
					delay(541);
					search2(c,roll);
				}

			}
			else if(choice=='3')
				view2(c);
			else
			printf("Wrong Command !!");
			t++;
		}
	}
	if(t==0)
	printf("Roll not Found !!");
	delay(1000);
	fclose(fp);
}
void edit(int c,int roll)
{
	FILE *fp,*fpp,*fp2;
       //	head();
	fp=fopen("45.txt","r");
	fpp=fopen("abc.txt","w");
	fp2=fopen("Last.dat","w");
	printf("Enter New Information: \n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if((c == s[0].clas) && (roll == s[0].roll))
		{
			printf("Name : \t");
			fflush(stdin);
			scanf("%s",&s[0].name);
			fflush(stdin);
			printf("Marks:\n ");
			fflush(stdin);
			printf("Marks: \n");
			for( ; ; )
			{
	 //	fflush(stdin);
			printf("Marks in English(100) : \t");
			validate();
			s[0].m.a=aaa;
			printf("\n");
			if(!(s[0].m.a<=100))
			printf("Error : Marks cannot be greater than 100!!\n");
			else
			break;
			}
			for( ; ; )
			{
			printf("Marks in Mathmetics(100) : \t");
       //	scanf("%d",&s[0].m.b);
			validate();
			s[0].m.b=aaa;
			printf("\n");
			if(!(s[0].m.b<=100))
			printf("Error : Marks cannot be greater than 100!!\n");
			else
			break;
			}
			for( ; ; )
			{
			printf("Marks in Computer(100) : \t");
       //	scanf("%d",&s[0].m.f);
			validate();
			s[0].m.f=aaa;
			printf("\n");
			if(!(s[0].m.f<=100))
			printf("Error : Marks cannot be greater than 100!!\n");
			else
			break;
			}
			for( ; ; )
			{
			printf("Marks in Business(100) : \t");
		    //	scanf("%d",&s[0].m.g);
			validate();
			s[0].m.g=aaa;
			printf("\n");
			if(!(s[0].m.g<=100))
			printf("Error : Marks cannot be greater than 100!!\n");
			else
			break;
			}
			for( ; ; )
			{
			printf("Marks in Account(100) : \t");
	    //	scanf("%d",&s[0].m.h);
			validate();
			s[0].m.h=aaa;
			printf("\n");
			if(!(s[0].m.h<=100))
			printf("Error : Marks cannot be greater than 100!!\n");
			else
			break;
			}


			s[0].per=(s[0].m.a+s[0].m.b+s[0].m.f+s[0].m.g+s[0].m.h)/(5.00);
			fwrite(&s[0],sizeof(s[0]),1,fpp);
			fwrite(&s[0],sizeof(s[0]),1,fp2);
		}
		else
		{
			fwrite(&s[0],sizeof(s[0]),1,fpp);
		}
	}
	delay(230);
	printf("The Information has been Updated !!\n");
	delay(340);
	clrscr();
	fclose(fp);
	fclose(fpp);
	fclose(fp2);
	remove("45.txt");
	rename("abc.txt","45.txt");
}
void del(int c,int roll)
{
	FILE *fp,*fpp;
	fp=fopen("45.txt","r");
	fpp=fopen("abc.txt","w");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if((c == s[0].clas) && (roll == s[0].roll))
		{
		       printf("\nDeleting. .");
		       delay(340);
		       printf(".");
		       delay(340);
		       printf(" .");
		       delay(340);
		       printf(" .");
		       delay(340);
		       printf(" .\n");
		}
		else
		{
			fwrite(&s[0],sizeof(s[0]),1,fpp);
		}
	}
	delay(230);
	printf("The Information has been Deleted !!\n");
	delay(340);
	clrscr();
	fclose(fp);
	fclose(fpp);
	remove("45.txt");
	rename("abc.txt","45.txt");
}                     /*
void startup(void)
{
	int gd=DETECT,gm,i,j;
	initgraph(&gd,&gm,"c:\\TurboC3\\BGI");
	settextstyle(1,0,4);
	outtextxy(10,10,"STUDENT INFO MANAGEMENT SYSTEM");
	printf("\t\t\t\tSIMS\n");
	delay(2000);
	closegraph();
}
			*/
void info(void)
{
	clrscr();
	head();
	printf("\t\t\tABOUT US\n");
	printf("\t\t\t--------\n");
	printf("Name\t\tAddress\t\tSymbol\tPhone Number\n");
	printf("-----------------------------------------------------------------|\n");
	printf("Ashish Pradhan\tPhikkal\t\t310190\t9842658018\n");
	printf("-----------------------------------------------------------------|\n");
	delay(1300);
	printf("Asmita Ghimire\tBirtamode\t310192\t9844605656\n");
	printf("-----------------------------------------------------------------|\n");
	delay(1300);
	printf("Usha Giri\tSanischare\t310206\t9842747309\n");
	printf("-----------------------------------------------------------------|\n");
	delay(1300);
	printf("Rajkumar Adhikari\tLaxmipur\t310195\t9862680413\n");
	printf("-----------------------------------------------------------------|\n");
	delay(200);
	printf("Press any Key. . ");
	getch();
}
void add2(int c)
{
	FILE *fp,*fpp;
	int a,l;
	printf("\n\n");
	printf("\t//*************************************************************//\n");
	printf("\t\tPress 1 to Add record , Any other key To exit \n");
	printf("\t//*************************************************************//\n\t");
	a=getch();
	if(a=='1')
	{
	fp=fopen("45.txt","a");
	printf("Name : \t");
	scanf("%s",&s[0].name);
      //	printf("\tRoll: \t");
       //	scanf("%d",&s[0].roll);
	s[0].clas=c;
	for( ; ; )
	{
		l=0;
		printf("Roll:\t");
	       //	scanf("%d",&s[0].roll);
		validate();
		s[0].roll=aaa;
		fp=fopen("45.txt","r");
		while(fread(&s1,sizeof(s1),1,fp)==1)
		{
		if((s[0].roll==s1.roll) && (s[0].clas==s1.clas))
		l++;
		}
		fclose(fp);
		if(l!=0)
		printf("Error : Roll Repeated !!.Please Input another Roll\n");
		else
		break;
	}
	printf("\nMarks: \n");
	for( ; ; )
	{
    //	fflush(stdin);
	printf("Marks in English(100) : \t");
	validate();
	s[0].m.a=aaa;
	printf("\n");
	if(!(s[0].m.a<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Mathmetics(100) : \t");
       //	scanf("%d",&s[0].m.b);
	validate();
	s[0].m.b=aaa;
	printf("\n");
	if(!(s[0].m.b<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Computer(100) : \t");
       //	scanf("%d",&s[0].m.f);
	validate();
	s[0].m.f=aaa;
	printf("\n");
	if(!(s[0].m.f<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Business(100) : \t");
      //	scanf("%d",&s[0].m.g);
	validate();
	s[0].m.g=aaa;
	printf("\n");
	if(!(s[0].m.g<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}
	for( ; ; )
	{
	printf("Marks in Account(100) : \t");
       //	scanf("%d",&s[0].m.h);
	validate();
	s[0].m.h=aaa;
	printf("\n");
	if(!(s[0].m.h<=100))
	printf("Error : Marks cannot be greater than 100!!\n");
	else
	break;
	}

	fp=fopen("45.txt","a");
	fpp=fopen("Last.dat","w");
	s[0].per=(s[0].m.a+s[0].m.b+s[0].m.f+s[0].m.g+s[0].m.h)/(5.00);
	fwrite(&s[0],sizeof(s[0]),1,fp);
	fwrite(&s[0],sizeof(s[0]),1,fpp);
	printf("Record Added !!");
	delay(450);
	fclose(fp);
	fclose(fpp);
	}
}
void head(void)
{
	printf("//*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*//\n");
	printf("//****************-STUDENT INFORMATION MANAGEMENT SYSTEM-**************//\n");
	printf("\\\\*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\\\\\n");
	delay(500);
}
int login(int s)
{
	char a[20],b[]="simran",v,usrname[]="Rehmat",u1[]="Aaces",p1[]="mandira",u2[]="sweet_asmi2",p2[]="pro.c",p3[]="lalala",u3[]="Usha";
     //	char z[20];
	int i,t=0;
	FILE *fp;
	fp=fopen("User.txt","r");
	clrscr();
	printf("\t\tEnter the following to Proceed\n");
	if(s==1)
	printf("\t\t<<USE\"exit\"in username to exit>>\n");
	printf("__________________________________________________________________\n");
	printf("\t\tUsername : \t");
	scanf("%s",&k);
	if(s==1)
	{
		if(strcmp(k,"exit")==0)
		{
			exit(0);
			printf("Exitting . . .");
			delay(340);
		}
	}
	printf("\t\tPassword : \t");
	for(i=0; ; )
	{
		v=getch();
		if(v=='\r')
		break;
		else if(v=='\b')
		{
			if(i!=0)
			{
			printf("\b");
			printf(" ");
			printf("\b");
		      //	printf("*");
			i=i-1;
			}
		}
		else
		{
			printf("*");
			a[i]=v;
			i++;
		}
	}
	a[i]='\0';
	if(strcmp(a,b)==0 && strcmp(usrname,k)==0)
	t=1;
	else
	{
		while(fread(&q12,sizeof(q12),1,fp)==1)
		{
		if(strcmp(a,q12.pass)==0 && strcmp(k,q12.user)==0)
		t=1;
		}
	}
	if(t==1)
	return 1;
	else
	return 0;
}
void ww(void)
{
	FILE *fp;
	int jjj;
	fp=fopen("45.txt","r");

	clrscr();
	head();
    //	printf("[Only the integer part, example : 20 , 45, 88 but not decimal part..example: 34.6,67.6\n");
	printf("Enter the percentage boundary :\t");
	validate();
	jjj=aaa;
	printf("\n");
	printf("Students scoring above %d %\n",jjj);
	printf("__________________________________________\n");
       //	printf("Name \t Roll \t Class\n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if(s[0].per>=jjj && s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
		{
		printf("Name: %s \tRoll: %d \tClass: %d\n",s[0].name,s[0].roll,s[0].clas);
		printf("-------------------------------------------------|\n");
		}
		delay(400);
	}
	getch();
}

void search2(int c,int roll)
{
	FILE *fp;
	int choice,t=0,j=0;
	char dd;
      //	printf("Enter The Roll number you want to view :\t");
       //	scanf("%d",&roll);
	fp=fopen("45.txt","r");
	delay(200);
	clrscr();
	head();
	printf("\n\n");
      //	printf("Name\tRoll\tPercentage\tRemarks\t\tMarks: \n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if(c==s[0].clas && roll==s[0].roll)
		{
			j++;
			printf("The Marks obtained by %s,",s[0].name);
			printf("Roll : %d of Class: %d are given below:\n\n",s[0].roll,s[0].clas);
			printf("Subjects \t\t Full Marks\tPass Marks\t Obtained Marks   Remark\n");
			printf("______________________________________________________________________________\n");
			printf("English \t\t     100    \t    35    \t       %d  ",s[0].m.a);
			if(s[0].m.a<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Math    \t\t     100    \t    35    \t       %d  ",s[0].m.b);
			if(s[0].m.b<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Computer\t\t     100    \t    35    \t       %d  ",s[0].m.f);
			if(s[0].m.f<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Business\t\t     100    \t    35    \t       %d  ",s[0].m.g);
			if(s[0].m.g<35)
			printf("          *\n");
			else
			printf("\n");
			printf("Account \t\t     100    \t    35    \t       %d  ",s[0].m.h);
			if(s[0].m.h<35)
			printf("          *\n");
			else
			printf("\n");
		       //	printf("_________________________________________________________________\n");
			printf("______________________________________________________________________________\n");
			printf("Total   \t\t     500    \t   175    \t       %d\n",s[0].m.a+s[0].m.b+s[0].m.g+s[0].m.f+s[0].m.h);
			printf("______________________________________________________________________________\n");
		       //	printf("_________________________________________________________________\n");
			printf("Total Marks Secured : %d\t",s[0].m.a+s[0].m.b+s[0].m.g+s[0].m.f+s[0].m.h);
			printf("Percentage: %0.2f %\t",s[0].per);
			printf("Division: ");
			if(s[0].per>=75 && s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				{
					printf("Distinction !!\n");
					if(s[0].roll%2==0)
					printf("Comments : Excellent!!\n");
					else if(s[0].roll<10)
					printf("Comments : Marvellous !!\n");
					else
					printf("Comments : Brilliant!!\n");
				}
			else if(s[0].per>=60 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
			{
				printf("First Division\n");
					if(s[0].roll%2==0)
					printf("Comments : Good!!\n");
					else if(s[0].roll<10)
					printf("Comments : Keep up !!\n");
					else
					printf("Comments : Superb!!\n");
				}
			else if(s[0].per>=45 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
			{
				printf("Second Division\n");
					if(s[0].roll%2==0)
					printf("Comments : Try Harder!!\n");
					else if(s[0].roll<10)
					printf("Comments : Not Good Enough !!\n");
					else
					printf("Comments : Read Harder!!\n");
				}
			else if(s[0].per>=35 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
			{
				printf("Third Division\n");
				if(s[0].roll%2==0)
				printf("Comments : Study Harder!!\n");
				else if(s[0].roll<10)
				printf("Comments : Poor marks!!\n");
				else
				printf("Comments : Not Good Enough!!\n");
				}
			else
			{
				printf("Fail\n");
				if(s[0].roll%2==0)
				printf("Comments : Very Bad!!\n");
				else if(s[0].roll<10)
				printf("Comments : Try Harder to Pass !!\n");
				else
				printf("Comments : Improve Yourself!!\n");
			}
			printf("\t//*************************************************************//\n");
			printf("\t\tPress 1 To EDIT record , Press 2 To DELETE record \n");
			printf("\t//*************************************************************//\n\t");
			printf("Press any other key to go back to Main menu\n");
			choice=getch();
			if(choice=='1')
			{
				edit(c,roll);
			}
			else if(choice=='2')
			{
				printf("Are you Sure You want to DELETE the record(y\\n): \t");
				dd=getch();
				if(dd=='y' || dd=='Y')
				if(login(0)==1)
				del(c,roll);
				else
				{
					printf("Wrong Username or Password. Please Try again later.");
					delay(540);
					search2(c,roll);
				}

			}
			else
			printf("Wrong Command !!");
			t++;
		}
	}
	if(j==0)
	{
		printf("No Data To Display....\n");
		delay(400);
		printf("The Data Is Probably Deleted....");
		delay(1000);
	}
}
void details(void)
{
	FILE *fp;
	int t=0,d=0,f=0,s=0,tt=0,fa=0;
	clrscr();
    //	int t,d,f,s,tt,fa;
	fp=fopen("45.txt","r");
	while(fread(&s1,sizeof(s1),1,fp)==1)
	{
		t++;
       //	while(fread(&s1,sizeof(s1),1,fp)==1)
       //	{
		if(s1.per>=75 && s1.m.a>=35 && s1.m.b>=35 && s1.m.g>=35 && s1.m.f>=35 && s1.m.h>=35)
		d++;
		else if(s1.per>=60 && s1.m.a>=35 && s1.m.b>=35 && s1.m.g>=35 && s1.m.f>=35 && s1.m.h>=35)
		f++;
		else if(s1.per>=45 && s1.m.a>=35 && s1.m.b>=35 && s1.m.g>=35 && s1.m.f>=35 && s1.m.h>=35)
		s++;
		else if(s1.per>=35 && s1.m.a>=35 && s1.m.b>=35 && s1.m.g>=35 && s1.m.f>=35 && s1.m.h>=35)
		tt++;
		else
		fa++;
	}
	fclose(fp);
	printf("\t\tDetails of the Project \n");
	printf("_____________________________________________________\n");
	printf("Total Students : %d\n",t);
	printf("----------------------------------------------------|\n");
	delay(230);
	printf("Total students scoring Distinction %d\n",d);
	printf("----------------------------------------------------|\n");
	delay(230);
	printf("Total students scoring First division %d\n",f);
	printf("----------------------------------------------------|\n");
	delay(230);
	printf("Total students scoring Second division %d\n",s);
	printf("----------------------------------------------------|\n");
	delay(230);
	printf("Total students scoring Third division %d\n",tt);
	printf("----------------------------------------------------|\n");
	delay(230);
	printf("Total number of failed Students %d\n",fa);
	printf("----------------------------------------------------|\n");
	delay(20);
	printf("Press Any key to go to Main Menu. . . ");
	getch();
}

void view2(int c)
{
	FILE *fp;
	int cls,t=0;
	head();
	fp=fopen("45.txt","r");
//	printf("Class:\t");
  //	scanf("%d",&cls);
	clrscr();
	printf("Student's Information of class %d \n",cls);
	printf("Name\tRoll\tPercentage\tRemarks\t\t\n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
		if(cls==s[0].clas)
		{
			printf("%s\t%d\t%0.2f\t\t",s[0].name,s[0].roll,s[0].per);
			if(s[0].per>=75 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Distinction !!\t");
			else if(s[0].per>=60 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("First Division\t");
			else if(s[0].per>=45 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Second Division\t");
			else if(s[0].per>=35 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Third Division\t");
			else
				printf("Fail\t\t");
			printf("\n");
			printf("---------------------------------------------------------|\n");
			delay(450);
			t++;
		}
	}
	fclose(fp);
	delay(300);
	if(t!=0)
		search(cls);
	else
	{
		printf("No Record Found\n");
		delay(1000);
		add2(cls);
	}
}
void logout(void)
{
	main();
}
void forgot(void)
{
	char a[20],b[]="simran",v,usrname[]="Rehmat",u1[]="Aaces",p1[]="mandira",u2[]="sweet_asmi2",p2[]="pro.c",p3[]="lalala",u3[]="Usha";
	char z[20];
	char admin[]="JARVIS",ap[]="don";
	int i,t=0;
	FILE *fp;
	clrscr();
	printf("\t\tEnter the Admin Password to Get the user password\n");
	printf("\t\tEnter the following to Proceed\n");
       //	if(s==1)
	printf("\t\t<<USE\"exit\"in Admin to exit>>\n");
	printf("__________________________________________________________________\n");
	printf("\t\tAdmin : \t");
	scanf("%s",&z);
	if(s==1)
	{
		if(strcmp(z,"exit")==0)
		{
			exit(0);
			printf("Exitting . . .");
			delay(340);
		}
	}
	printf("\t\tPassword : \t");
	for(i=0; ; )
	{
		v=getch();
		if(v=='\r')
		break;
		else if(v=='\b')
		{
			if(i!=0)
			{
			printf("\b");
			printf(" ");
			printf("\b");
		      //	printf("*");
			i=i-1;
			}
		}
		else
		{
			printf("*");
			a[i]=v;
			i++;
		}
	}
	a[i]='\0';
	if(((strcmp(z,admin)==0) && (strcmp(a,ap)==0)))
	t=1;
	fp=fopen("User.txt","r");
	if(t==1)
	{
		printf("\nUsernames\t\tPasswords\n");
		printf("___________________________________________________\n");
		printf("%s\t\t\t%s\n",usrname,strrev(b));
		printf("--------------------------------------------------|\n");
		delay(20);
		while(fread(&q12,sizeof(q12),1,fp)==1)
		{
			printf("%s\t\t\t%s\n",q12.user,strrev(q12.pass));
			delay(200);
			printf("--------------------------------------------------|\n");
		}
		delay(20);
		fclose(fp);
		fp=fopen("User.txt","r");
		printf("Press any key . . .\n");      //This Launches A Secret
		if(getch()=='r' || getch()=='R')        //                    Falcon
		if(getch()=='e' || getch()=='E')          //           Cap'
		if(getch()=='h' || getch()=='H')            //            Iron
		if(getch()=='m' || getch()=='M')          //         Banner
		if(getch()=='a' || getch()=='A')        //                 Hawkeye
		if(getch()=='t' || getch()=='T')       //    Star Lord
		{
			printf("\nUsernames\t\tPasswords\n");
			printf("___________________________________________________\n");
			printf("%s\t\t\t%s\n",usrname,b);
			printf("--------------------------------------------------|\n");
			delay(20);
			while(fread(&q12,sizeof(q12),1,fp)==1)
			{
				printf("%s\t\t\t%s\n",q12.user,q12.pass);
				delay(200);
				printf("--------------------------------------------------|\n");
			}
		delay(20);
		fclose(fp);
		printf("Press Any Key .....");
		getch();
		}
		main();
	}
	else
	{
		printf("\n\t\tError : Admin Username or Password Wrong\n");
		delay(1300);
		main();
	}
}
void validate(void)
{
	char a[9],v;
	int z=0,i,c,t=0,b[20],x,l=0;
       //	printf("ENTRE\n");
	i=0;
	for( ; ; )
	{
		a[i]=getch();
		if(!(i==0 && (a[i]=='\r' && i<=0 || a[i]=='\b')))
		{
		if(a[i]!='\r' && !(a[i]<='9' && a[i]>='0') && a[i]!='\b')
		{
			sound(5*24);
			delay(100);
			nosound();
			i=i-1;
		}
		else
		{
		     //	sound(6*50);
		      //	delay(100);
		      //	nosound();
			if(a[i]=='\r')
			break;
			else if(a[i]=='\b')
			{
			printf("\b \b");
			i=i-2;
			}
			else
			{
			b[i]=a[i];
			printf("%c",a[i]);
			}
		}
		i++;
		}
	}
	a[i]='\0';
       //	printf("\n%s\n",a);
	for(i=0;a[i]!='\0';i++)
		t++;
	c=t;
       for(i=0;i<t;i++)
	{
		x=b[i]-48;
		z=z+(pow(10,c-1)*x);
		c--;
	}
	aaa=z;
}
void add_user(void)
{
	FILE *fp;
	int i;
	char v;
	for( ; ; )
	{
	printf("Enter Username : \t");
	scanf("%s",&q12.user);
	if(strcmp(q12.user,"exit")==0)
	printf("Error : Cannot Use \"exit\" as username ..\n");
	else
	break;
	}
	printf("Password : \t");
	for(i=0; ; )
	{
		v=getch();
		if(v=='\r')
		break;
		else if(v=='\b')
		{
			if(i!=0)
			{
			printf("\b");
			printf(" ");
			printf("\b");
		      //	printf("*");
			i=i-1;
			}
		}
		else
		{
			printf("*");
			q12.pass[i]=v;
			i++;
		}
	}
	q12.pass[i]='\0';
	fp=fopen("User.txt","a");
	fwrite(&q12,sizeof(q12),1,fp);
	delay(800);
	printf("\nUser Added !!");
	delay(400);
	printf("\nRestart the program to apply the changes.\n");
	printf("\nPress Any key to continue. . .");
	getch();
}
void last_add(void)
{
	FILE *fp;
	int cls,t=0;
	clrscr();
	head();
	fp=fopen("last.dat","r");
	printf("Class:\t");
       //	scanf("%d",&cls);
  //	validate();
    //	cls=aaa;
	clrscr();
	printf("Last Updated \n");
	printf("Name\tRoll\tPercentage\tRemarks\t\t\n");
	while(fread(&s[0],sizeof(s[0]),1,fp)==1)
	{
	    //	if(cls==s[0].clas)
	      //	{
			printf("%s\t%d\t%0.2f\t\t",s[0].name,s[0].roll,s[0].per);
			if(s[0].per>=75 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Distinction !!\t");
			else if(s[0].per>=60 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("First Division\t");
			else if(s[0].per>=45 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Second Division\t");
			else if(s[0].per>=35 &&  s[0].m.a>=35 && s[0].m.b>=35 && s[0].m.g>=35 && s[0].m.f>=35 && s[0].m.h>=35)
				printf("Third Division\t");
			else
				printf("Fail\t\t");
			printf("\n");
			printf("---------------------------------------------------------|\n");
			delay(450);
			t++;
	       //	}
	}
	fclose(fp);
	if(t==0)
	{
		printf("No Data To Display...");
		delay(400);
	}
	else
	{

	delay(300);
	printf("Press ENTER to view .....\n");
	printf("Any other key to go to main menu.....\n");
	switch(getch())
	{
		case 13:
		search2(s[0].clas,s[0].roll);
		break;
	}
	}
       //	getch();
}

