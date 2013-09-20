/**************************PROJECT**************************
***********************LIC DATA MANAGEMENT******************

*******************MADE BY**********************************
**************************ROHIT AGGARWAL*******************/


/*----------------------------------------------------------
  HEADER FILES DECLERATION
----------------------------------------------------------*/

#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdlib.h>


/*----------------------------------------------------------
  GLOBAL MULTI-USE VARAIBLES AND STRUCTURES
----------------------------------------------------------*/

int i,j,k;

struct day
{
 int date,month,year;
};

struct address
{
 int house_no,sector;
 char block[10],area[15],state[15],pin_code[10];
};

struct nominee
{
 char name3[25],relation[15];
 int age;
 day date_of_birth1;
};

struct policy
{
 char table_term[10],policy_no[15],mode_of_pay[10],premium[6],branch[10];
 char agent_name[25];
 unsigned long sum_assured;
 day risk_date;
};

struct family
{
 char father_name[25],mother_name[25],wife_name[25],son_name[5][25];
 char daughter_name[5][25],brother_name[5][25],sister_name[5][25];
 int father_age,mother_age,wife_age,son_age[5],daughter_age[5];
 int brother_age[5],sister_age[5];
};

struct policy_holder
{
 char name2[25],ph_no1[2][15],edu_qua[50],annual_income[10],birth_place[20];
 int age1;
 day date_of_birth2,risk_date;
 address add1;
 nominee n;
 family f;
 policy p;
};


/*----------------------------------------------------------
  DATA MEMBER AND MEMBER FUNCTION OF CLASS AGENT_DATA
  ie. TO STORE AGENT'S DATA
----------------------------------------------------------*/

class agent_data
{
 char name1[50],agent_code[15],branch[10],ph_no2[2][15],do_name[50];
 char do_code[15];
 int age2;
 day date_of_birth3;
 address add2;
 public:
 void initial_agent_data();
 void alter_agent_data();
 void display_agent_data();
};


/*----------------------------------------------------------
  DATA MEMBER AND MEMBER FUNCTION OF CLASS PREM_INFO
  ie. TO STORE PREMIUM INFORMATION
----------------------------------------------------------*/

class prem_info
{
 char pol_name[25],prem[6],pol_no[15],mode[10];
 day risk;
 public:
 void pol_data();
 void alter_pol_data();
 void delete_pol_data(char []);
 void print_data();
 int get_month()
   {
    return(risk.month);
   }
 int get_year()
   {
    return(risk.year);
   }
 char* get_mode()
   {
    return(mode);
   }
}ob;


/*----------------------------------------------------------
  DATA MEMBER AND MEMBER FUNCTION OF CLASS POLICY_PERSON
  ie. TO STORE POLICY HOLDER'S INFORMATION
----------------------------------------------------------*/

class policy_person
{
 int nob,nos,nod,non;
 char choice4;
 policy_holder per;
 public:
 int count;
 char store_policy_no[15];
 void create_person(int &);
 void alter_person();
 void display_person();
 void delete_person(char p_no1[]);
 void medical_report();
 friend void check_person();
 friend void prem_info::pol_data();
 friend void prem_info::alter_pol_data();
 friend void prem_info::delete_pol_data(char []);
 char* get_p_no()
    {
     return(per.p.policy_no);
    }
}person;


/*----------------------------------------------------------
  DATA MEMBER AND MEMBER FUNCTIONS OF CLASS
  POLICY_AVAILABLE ie. TO STORE INFORMATION OF DIFFERENT
  POLICIES
----------------------------------------------------------*/

class policy_available
{
 char policy_name[50];
 int age2,table_no,term;
 unsigned long sum_assured2[4],premium2[16];
 public:
 void store_policy();
 void display_policy();
 void delete_policy(int);
 int get_table_no()
   {
    return(table_no);
   }
 int get_age()
   {
    return(age2);
   }
 int get_term()
   {
    return(term);
   }
 char* get_policy_name()
   {
    return(policy_name);
   }
}ob1;


/*----------------------------------------------------------
  FUNCTION TO ASK FOR CHANGE OF DATA
----------------------------------------------------------*/

char change_option()
{
 char change_choice;
 cout<<"\t\tWant to change(y/n):";
 cin>>change_choice;
 return(change_choice);
}


/*----------------------------------------------------------
  FUNCTION TO STORE AGENT'S DATA
----------------------------------------------------------*/

void agent_data::initial_agent_data()
{
 char ans1;
 day check;
 struct date v;
 getdate(&v);
 check.date=v.da_day;
 check.month=v.da_mon;
 check.year=v.da_year;
 cout<<"\n\t\t\t\tAGENT'S DATA";
 cout<<"\n\nEnter agent's name:";
 gets(name1);
 cout<<"\nEnter agent's code:";
 gets(agent_code);
 cout<<"\nEnter agent's branch code:";
 gets(branch);
 label20:
 cout<<"\nEnter agent's date of birth(dd/mm/yy):";
 cin>>date_of_birth3.date;
 cout<<"\t\t\t\t     :";
 cin>>date_of_birth3.month;
 cout<<"\t\t\t\t     :";
 cin>>date_of_birth3.year;
 if(date_of_birth3.year>check.year)
   {
    cout<<"\n\t\t\t\tINVALID DATE";
    cout<<"\n\t\t\tPlease, re-enter the date\n";
    goto label20;
   }
 else
   {
    if(date_of_birth3.month>12)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label20;
      }
    else
      {
       if(date_of_birth3.date>31)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label20;
	 }
       else if(date_of_birth3.month==2)
	 {
	  if(date_of_birth3.date>29)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label20;
	    }
	  else if((date_of_birth3.year%4!=0)&&(date_of_birth3.date>28))
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label20;
	    }
	 }
       switch(date_of_birth3.month)
	 {
	  case 4:
	  case 6:
	  case 9:
	  case 11:if(date_of_birth3.date>30)
		  {
		   cout<<"\n\t\t\t\tINVALID DATE";
		   cout<<"\n\t\t\tPlease, re-enter the date\n";
		   goto label20;
		  }
	 }
      }
   }
 cout<<"\nEnter agent's age:";
 cin>>age2;
 cout<<"\nEnter agent's address(Block):";
 gets(add2.block);
 cout<<"\t\t (House no.):";
 cin>>add2.house_no;
 cout<<"\t\t    (Sector):";
 cin>>add2.sector;
 cout<<"\t\t      (Area):";
 gets(add2.area);
 cout<<"\t\t     (State):";
 gets(add2.state);
 cout<<"\t\t  (Pin code):";
 gets(add2.pin_code);
 cout<<"\nEnter agent's phone number(landline):";
 gets(ph_no2[0]);
 cout<<"\nDoes agent has a mobile phone(y/n):";
 cin>>ans1;
 if(ans1=='y'||ans1=='Y')
   {
    cout<<"Enter agent's mobile number:";
    gets(ph_no2[1]);
   }
 else
   strcpy(ph_no2[1],"0");
 cout<<"\nEnter development officer's(d.o.) name:";
 gets(do_name);
 cout<<"\nEnter d.o.'s code:";
 gets(do_code);
}


/*----------------------------------------------------------
  FUNCTION TO ALTER AGENT'S DATA
----------------------------------------------------------*/

void agent_data::alter_agent_data()
{
 day d3,check;
 address ad2;
 char correct;
 int a2;
 struct date v;
 getdate(&v);
 check.date=v.da_day;
 check.month=v.da_mon;
 check.year=v.da_year;
 char n1[50],a_c1[15],b[10],p_n2[2][15],d_n[50],d_c[15];
 cout<<"\n\nName:";
 puts(name1);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nName:";
    gets(n1);
    strcpy(name1,n1);
   }
 cout<<"\nCode:";
 puts(agent_code);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nCode:";
    gets(a_c1);
    strcpy(agent_code,a_c1);
   }
 cout<<"\nBranch code:";
 puts(branch);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nBranch code:";
    gets(b);
    strcpy(branch,b);
   }
 label21:
 cout<<"\nDate of birth:"<<date_of_birth3.date<<"\\"<<date_of_birth3.month
     <<"\\"<<date_of_birth3.year<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nDate of birth(dd/mm/yy):";
    cin>>d3.date;
    date_of_birth3.date=d3.date;
    cout<<"\t\t\t\b:";
    cin>>d3.month;
    date_of_birth3.month=d3.month;
    cout<<"\t\t\t\b:";
    cin>>d3.year;
    date_of_birth3.year=d3.year;
    if(d3.year>check.year)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label21;
      }
    else
      {
       if(d3.month>12)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label21;
	 }
       else
	 {
	  if(d3.date>31)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label21;
	    }
	  else if(d3.month==2)
	    {
	     if(d3.date>29)
	       {
		cout<<"\n\t\t\t\tINVALID DATE";
		cout<<"\n\t\t\tPlease, re-enter the date\n";
		goto label21;
	       }
	     else if((d3.year%4!=0)&&(d3.date>28))
	       {
		cout<<"\n\t\t\t\tINVALID DATE";
		cout<<"\n\t\t\tPlease, re-enter the date\n";
		goto label21;
	       }
	    }
	  switch(d3.month)
	    {
	     case 4:
	     case 6:
	     case 9:
	     case 11:if(d3.date>30)
		       {
			cout<<"\n\t\t\t\tINVALID DATE";
			cout<<"\n\t\t\tPlease, re-enter the date\n";
			goto label21;
		       }
	    }
	 }
      }
   }
 cout<<"\nAge:"<<age2<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAge:";
    cin>>a2;
    age2=a2;
   }
 cout<<"\nAddress:"<<add2.block<<"\\"<<add2.house_no<<","<<add2.sector
     <<",\n\t"<<add2.area<<","<<add2.state<<"-";
 puts(add2.pin_code);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAddress(Block):";
    gets(ad2.block);
    strcpy(add2.block,ad2.block);
    cout<<"   (House no.):";
    cin>>ad2.house_no;
    add2.house_no=ad2.house_no;
    cout<<"      (Sector):";
    cin>>ad2.sector;
    add2.sector=ad2.sector;
    cout<<"\t(Area):";
    gets(ad2.area);
    strcpy(add2.area,ad2.area);
    cout<<"\t\b(State):";
    gets(ad2.state);
    strcpy(add2.state,ad2.state);
    cout<<"    (Pin code):";
    gets(ad2.pin_code);
    strcpy(add2.pin_code,ad2.pin_code);
   }
 cout<<"\nPhone number(Landline):"<<ph_no2[0]<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nPhone number(Landline):";
    gets(p_n2[0]);
    strcpy(ph_no2[0],p_n2[0]);
   }
 cout<<"\n\t      (Mobile):";
 if(strcmp(ph_no2[1],"0"))
   puts(ph_no2[1]);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\n\t      (Mobile):";
    gets(p_n2[1]);
    strcpy(ph_no2[1],p_n2[1]);
   }
 cout<<"\nDevelopment officer's(D.O.) name:";
 puts(do_name);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nD.O.'s Name:";
    gets(d_n);
    strcpy(do_name,d_n);
   }
 cout<<"\nD.O.'s code:";
 puts(do_code);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nD.O.'s Code:";
    gets(d_c);
    strcpy(do_code,d_c);
   }
}


/*----------------------------------------------------------
  FUNCTION TO DISPLAY AGENT'S DATA
----------------------------------------------------------*/

void agent_data::display_agent_data()
{
 char ch;
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 1";
 gotoxy(1,1);
 cout<<"\n\t\t\t\tAGENT'S DETAILS";
 cout<<"\n\n\tName:";
 puts(name1);
 cout<<"\n\tCode:";
 puts(agent_code);
 cout<<"\n\tBranch code:";
 puts(branch);
 cout<<"\n\tDate of birth:"<<date_of_birth3.date<<"\\"<<date_of_birth3.month
     <<"\\"<<date_of_birth3.year;
 cout<<"\n\n\tAge:"<<age2;
 cout<<"\n\n\tAddress:"<<add2.block<<"\\"<<add2.house_no<<","<<add2.sector
     <<",\n\t\t"<<add2.area<<","<<add2.state<<"-";
 puts(add2.pin_code);
 cout<<"\n\tPhone number(Landline):"<<ph_no2[0];
 cout<<"\n\t\t      (Mobile):";
 if(strcmp(ph_no2[1],"0"))
   puts(ph_no2[1]);
 gotoxy(20,22);
 cout<<"Press any key to go to next page";
 getch();
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 2";
 gotoxy(1,1);
 cout<<"\n\n\tDevelopment officer's(D.O.) name:";
 puts(do_name);
 cout<<"\n\tD.O.'s code:";
 puts(do_code);
 gotoxy(20,22);
 cout<<"Press any key to return";
 getch();
}

/*----------------------------------------------------------
  FUNCTION TO STORE POLICY HOLDER'S DATA
----------------------------------------------------------*/

void policy_person::create_person(int &y)
{
 char ans2;
 day check;
 struct date v;
 getdate(&v);
 check.date=v.da_day;
 check.month=v.da_mon;
 check.year=v.da_year;
 cout<<"\t\t\t\tPOLICY HOLDER "<<++y;
 count=y;
 cout<<"\n\nEnter policy holder's name:";
 gets(per.name2);
 cout<<"\nEnter policy holder's father's name:";
 gets(per.f.father_name);
 cout<<"\nEnter policy holder's mother's name:";
 gets(per.f.mother_name);
 label22:
 cout<<"\nEnter policy holder's date of birth(dd/mm/yy):";
 cin>>per.date_of_birth2.date;
 cout<<"\t\t\t\t\t\t\b\b\b:";
 cin>>per.date_of_birth2.month;
 cout<<"\t\t\t\t\t\t\b\b\b:";
 cin>>per.date_of_birth2.year;
 if(per.date_of_birth2.year>check.year)
   {
    cout<<"\n\t\t\t\tINVALID DATE";
    cout<<"\n\t\t\tPlease, re-enter the date\n";
    goto label22;
   }
 else
   {
    if(per.date_of_birth2.month>12)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label22;
      }
    else
      {
       if(per.date_of_birth2.date>31)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label22;
	 }
       else if(per.date_of_birth2.month==2)
	 {
	  if(per.date_of_birth2.date>29)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label22;
	    }
	  else if((per.date_of_birth2.year%4!=0)&&(per.date_of_birth2.date>28))
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label22;
	    }
	 }
       switch(per.date_of_birth2.month)
	 {
	  case 4:
	  case 6:
	  case 9:
	  case 11:if(per.date_of_birth2.date>30)
		  {
		   cout<<"\n\t\t\t\tINVALID DATE";
		   cout<<"\n\t\t\tPlease, re-enter the date\n";
		   goto label22;
		  }
	 }
      }
   }
 cout<<"\nEnter policy holder's age:";
 cin>>per.age1;
 cout<<"\nEnter policy holder's birth place:";
 gets(per.birth_place);
 cout<<"\nEnter policy holder's address(Block):";
 gets(per.add1.block);
 cout<<"\t\t\t (House No.):";
 cin>>per.add1.house_no;
 cout<<"\t\t\t    (Sector):";
 cin>>per.add1.sector;
 cout<<"\t\t\t      (Area):";
 gets(per.add1.area);
 cout<<"\t\t\t     (State):";
 gets(per.add1.state);
 cout<<"\t\t\t  (Pin code):";
 gets(per.add1.pin_code);
 cout<<"\nEnter policy holder's phone no.(landline):";
 gets(per.ph_no1[0]);
 cout<<"\nDoes policy holder has a mobile phone(y/n):";
 cin>>ans2;
 if(ans2=='y'||ans2=='Y')
   {
    cout<<"Enter policy holder's mobile number:";
    gets(per.ph_no1[1]);
   }
 else
   strcpy(per.ph_no1[1],"0");
 cout<<"\nEnter policy holder's annual income(in Rs.):";
 gets(per.annual_income);
 cout<<"\nEnter policy holder's educational Qualification:";
 gets(per.edu_qua);
 cout<<"\n\n\nEnter the POLICY DETAILS:";
 cout<<"\n\nAgent's name:";
 gets(per.p.agent_name);
 cout<<"\nBranch code:";
 gets(per.p.branch);
 cout<<"\nTable term:";
 gets(per.p.table_term);
 cout<<"\nSum assured:";
 cin>>per.p.sum_assured;
 cout<<"\nPolicy number:";
 gets(per.p.policy_no);
 cout<<"\nPremium:";
 gets(per.p.premium);
 cout<<"\nMode of payment:";
 gets(per.p.mode_of_pay);
 label23:
 cout<<"\nRisk date(dd/mm/yy):";
 cin>>per.p.risk_date.date;
 cout<<"\t\t   :";
 cin>>per.p.risk_date.month;
 cout<<"\t\t   :";
 cin>>per.p.risk_date.year;
 if(per.p.risk_date.year>check.year)
   {
    cout<<"\n\t\t\t\tINVALID DATE";
    cout<<"\n\t\t\tPlease, re-enter the date\n";
    goto label23;
   }
 else
   {
    if(per.p.risk_date.month>check.month)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label23;
      }
    else
      {
       if(per.p.risk_date.date>check.date)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label23;
	 }
      }
   }
 policy_person::medical_report();
 cout<<"\n\n\nEnter the details of the NOMINEE:";
 cout<<"\n\nName:";
 gets(per.n.name3);
 cout<<"\nRelation with policy holder:";
 gets(per.n.relation);
 label24:
 cout<<"\nDate of birth(dd/mm/yy):";
 cin>>per.n.date_of_birth1.date;
 cout<<"\t\t\t\b:";
 cin>>per.n.date_of_birth1.month;
 cout<<"\t\t\t\b:";
 cin>>per.n.date_of_birth1.year;
 if(per.n.date_of_birth1.year>check.year)
   {
    cout<<"\n\t\t\t\tINVALID DATE";
    cout<<"\n\t\t\tPlease, re-enter the date\n";
    goto label24;
   }
 else
   {
    if(per.n.date_of_birth1.month>12)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label24;
      }
    else
      {
       if(per.n.date_of_birth1.date>31)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label24;
	 }
       else if(per.n.date_of_birth1.month==2)
	 {
	  if(per.n.date_of_birth1.date>29)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label24;
	    }
	  else if((per.n.date_of_birth1.year%4!=0)&&
		  (per.n.date_of_birth1.date>28))
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label24;
	    }
	 }
       switch(per.n.date_of_birth1.month)
	 {
	  case 4:
	  case 6:
	  case 9:
	  case 11:if(per.n.date_of_birth1.date>30)
		  {
		   cout<<"\n\t\t\t\tINVALID DATE";
		   cout<<"\n\t\t\tPlease, re-enter the date\n";
		   goto label24;
		  }
	 }
      }
   }
 cout<<"\nAge:";
 cin>>per.n.age;
 cout<<"\n\n\nEnter the details of the FAMILY MEMBERS:";
 cout<<"\n\nFather's Name:";
 gets(per.f.father_name);
 cout<<"\nFather's age(If died, age at death):";
 cin>>per.f.father_age;
 cout<<"\nMother's Name:";
 gets(per.f.mother_name);
 cout<<"\nMother's age(If died, age at death):";
 cin>>per.f.mother_age;
 cout<<"\nNo. of brother's of policy holder:";
 cin>>nob;
 for(j=0;j<nob;j++)
   {
    cout<<"\nBrother's Name:";
    gets(per.f.brother_name[j]);
    cout<<"Brother's age(If died, age at death):";
    cin>>per.f.brother_age[j];
   }
 cout<<"\nNo. of sister's of policy holder:";
 cin>>nos;
 for(j=0;j<nos;j++)
   {
    cout<<"\nSister's Name:";
    gets(per.f.sister_name[j]);
    cout<<"Sister's age(If died, age at death):";
    cin>>per.f.sister_age[j];
   }
 cout<<"\nIs the policy holder married(y/n):";
 cin>>choice4;
 if(choice4=='y'||choice4=='Y')
   {
    cout<<"\nWife's Name:";
    gets(per.f.wife_name);
    cout<<"Wife's age:";
    cin>>per.f.wife_age;
    cout<<"\nNo. of son's of policy holder:";
    cin>>non;
    for(j=0;j<non;j++)
      {
       cout<<"\nSon's Name:";
       gets(per.f.son_name[j]);
       cout<<"Son's age:";
       cin>>per.f.son_age[j];
      }
    cout<<"\nNo. of daughter's of policy holder:";
    cin>>nod;
    for(j=0;j<nod;j++)
      {
       cout<<"\nDaughter's Name:";
       gets(per.f.daughter_name[j]);
       cout<<"Daughter's age:";
       cin>>per.f.daughter_age[j];
      }
   }
 ob.prem_info::pol_data();
}


/*----------------------------------------------------------
  FUNCTION TO ALTER POLICY HOLDER'S DATA
----------------------------------------------------------*/

void policy_person::alter_person()
{
 char choice41,ans3,correct;
 int nob1,nos1,non1,nod1;
 policy_holder per1;
 day check;
 struct date v;
 getdate(&v);
 check.date=v.da_day;
 check.month=v.da_mon;
 check.year=v.da_year;
 strcpy(store_policy_no,per.p.policy_no);
 cout<<"\n\nName:";
 puts(per.name2);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nName:";
    gets(per1.name2);
    strcpy(per.name2,per1.name2);
   }
 label25:
 cout<<"\nDate of birth(dd/mm/yy):"<<per.date_of_birth2.date<<"\\"
     <<per.date_of_birth2.month<<"\\"<<per.date_of_birth2.year<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nDate of birth(dd/mm/yy):";
    cin>>per1.date_of_birth2.date;
    per.date_of_birth2.date=per1.date_of_birth2.date;
    cout<<"\t\t\t\b:";
    cin>>per1.date_of_birth2.month;
    per.date_of_birth2.month=per1.date_of_birth2.month;
    cout<<"\t\t\t\b:";
    cin>>per1.date_of_birth2.year;
    per.date_of_birth2.year=per1.date_of_birth2.year;
    if(per1.date_of_birth2.year>check.year)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label25;
      }
    else
      {
       if(per1.date_of_birth2.month>12)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label25;
	 }
       else
	 {
	  if(per1.date_of_birth2.date>31)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label25;
	    }
	  else if(per1.date_of_birth2.month==2)
	    {
	     if(per1.date_of_birth2.date>29)
	       {
		cout<<"\n\t\t\t\tINVALID DATE";
		cout<<"\n\t\t\tPlease, re-enter the date\n";
		goto label25;
	       }
	     else if((per1.date_of_birth2.year%4!=0)&&
		     (per1.date_of_birth2.date>28))
	       {
		cout<<"\n\t\t\t\tINVALID DATE";
		cout<<"\n\t\t\tPlease, re-enter the date\n";
		goto label25;
	       }
	    }
	  switch(per1.date_of_birth2.month)
	    {
	     case 4:
	     case 6:
	     case 9:
	     case 11:if(per1.date_of_birth2.date>30)
		       {
			cout<<"\n\t\t\t\tINVALID DATE";
			cout<<"\n\t\t\tPlease, re-enter the date\n";
			goto label25;
		       }
	    }
	 }
      }
   }
 cout<<"\n\nAge:"<<per.age1<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAge:";
    cin>>per1.age1;
    per.age1=per1.age1;
   }
 cout<<"\n\nBirth place:";
 puts(per.birth_place);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nBirth place:";
    gets(per1.birth_place);
    strcpy(per.birth_place,per1.birth_place);
   }
 cout<<"\nAddress:";
 cout<<per.add1.block<<"\\"<<per.add1.house_no<<","<<per.add1.sector
     <<",\n\t\t"<<per.add1.area<<","<<per.add1.state<<"-";
 puts(per.add1.pin_code);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAddress(Block):";
    gets(per1.add1.block);
    strcpy(per.add1.block,per1.add1.block);
    cout<<"   (House No.):";
    cin>>per1.add1.house_no;
    per.add1.house_no=per1.add1.house_no;
    cout<<"      (Sector):";
    cin>>per1.add1.sector;
    per.add1.sector=per1.add1.sector;
    cout<<"\t(Area):";
    gets(per1.add1.area);
    strcpy(per.add1.area,per1.add1.area);
    cout<<"\t\b(State):";
    gets(per1.add1.state);
    strcpy(per.add1.state,per1.add1.state);
    cout<<"    (Pin Code):";
    gets(per1.add1.pin_code);
    strcpy(per.add1.pin_code,per1.add1.pin_code);
   }
 cout<<"\nPhone no.(Landline):";
 puts(per.ph_no1[0]);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nPhone no.(Landline):";
    gets(per1.ph_no1[0]);
    strcpy(per.ph_no1[0],per1.ph_no1[0]);
   }
 cout<<"\t      (Mobile):";
 if(strcmp(per.ph_no1[1],"0"))
   puts(per.ph_no1[1]);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\n\t      (Mobile):";
    gets(per1.ph_no1[1]);
    strcpy(per.ph_no1[1],per1.ph_no1[1]);
   }
 cout<<"\nAnnual income(in Rs.):";
 puts(per.annual_income);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAnnual income:";
    gets(per1.annual_income);
    strcpy(per.annual_income,per1.annual_income);
   }
 cout<<"\nEducational Qualification:";
 puts(per.edu_qua);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nEducational Qualification:";
    gets(per1.edu_qua);
    strcpy(per.edu_qua,per1.edu_qua);
   }
 cout<<"\n\t\t\t\tPOLICY'S DETAILS";
 cout<<"\n\nAgent's name:";
 puts(per.p.agent_name);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAgent's Name:";
    gets(per1.p.agent_name);
    strcpy(per.p.agent_name,per1.p.agent_name);
   }
 cout<<"\nBranch code:";
 puts(per.p.branch);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nBranch Code:";
    gets(per1.p.branch);
    strcpy(per.p.branch,per1.p.branch);
   }
 cout<<"\nTable term:";
 puts(per.p.table_term);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nTable term:";
    gets(per1.p.table_term);
    strcpy(per.p.table_term,per1.p.table_term);
   }
 cout<<"\nSum assured:"<<per.p.sum_assured<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nSum assured:";
    cin>>per1.p.sum_assured;
    per.p.sum_assured=per1.p.sum_assured;
   }
 cout<<"\nPolicy number:";
 puts(per.p.policy_no);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nPolicy number:";
    gets(per1.p.policy_no);
    strcpy(per.p.policy_no,per1.p.policy_no);
   }
 cout<<"\nPremium:";
 puts(per.p.premium);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nPremium:";
    gets(per1.p.premium);
    strcpy(per.p.premium,per1.p.premium);
   }
 cout<<"\nMode of payment:";
 puts(per.p.mode_of_pay);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nMode of payment:";
    gets(per1.p.mode_of_pay);
    strcpy(per.p.mode_of_pay,per1.p.mode_of_pay);
   }
 label26:
 cout<<"\nRisk date(dd/mm/yy):"<<per.p.risk_date.date<<"\\"
     <<per.p.risk_date.month<<"\\"<<per.p.risk_date.year<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nRisk date(dd/mm/yy):";
    cin>>per1.p.risk_date.date;
    per.p.risk_date.date=per1.p.risk_date.date;
    cout<<"\t\t   :";
    cin>>per1.p.risk_date.month;
    per.p.risk_date.month=per1.p.risk_date.month;
    cout<<"\t\t   :";
    cin>>per1.p.risk_date.year;
    per.p.risk_date.year=per1.p.risk_date.year;
    if(per1.p.risk_date.year>check.year)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label26;
      }
    else
      {
       if(per1.p.risk_date.month>check.month)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label26;
	 }
       else
	 {
	  if(per1.p.risk_date.date>check.date)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label26;
	    }
	 }
      }
   }
 cout<<"\n\t\t\t\tNOMINEE'S DETAILS";
 cout<<"\n\nName:";
 puts(per.n.name3);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nName:";
    gets(per1.n.name3);
    strcpy(per.n.name3,per1.n.name3);
   }
 cout<<"\nRelation:";
 puts(per.n.relation);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nRelation:";
    gets(per1.n.relation);
    strcpy(per.n.relation,per1.n.relation);
   }
 label27:
 cout<<"\nDate of birth(dd/mm/yy):";
 cout<<per.n.date_of_birth1.date<<"\\"<<per.n.date_of_birth1.month
     <<"\\"<<per.n.date_of_birth1.year<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nDate of birth(dd/mm/yy):";
    cin>>per1.n.date_of_birth1.date;
    per.n.date_of_birth1.date=per1.n.date_of_birth1.date;
    cout<<"\t\t\t\b:";
    cin>>per1.n.date_of_birth1.month;
    per.n.date_of_birth1.month=per1.n.date_of_birth1.month;
    cout<<"\t\t\t\b:";
    cin>>per1.n.date_of_birth1.year;
    per.n.date_of_birth1.year=per1.n.date_of_birth1.year;
    if(per1.n.date_of_birth1.year>check.year)
      {
       cout<<"\n\t\t\t\tINVALID DATE";
       cout<<"\n\t\t\tPlease, re-enter the date\n";
       goto label27;
      }
    else
      {
       if(per1.n.date_of_birth1.month>12)
	 {
	  cout<<"\n\t\t\t\tINVALID DATE";
	  cout<<"\n\t\t\tPlease, re-enter the date\n";
	  goto label27;
	 }
       else
	 {
	  if(per1.n.date_of_birth1.date>31)
	    {
	     cout<<"\n\t\t\t\tINVALID DATE";
	     cout<<"\n\t\t\tPlease, re-enter the date\n";
	     goto label27;
	    }
	  else if(per1.n.date_of_birth1.month==2)
	    {
	     if(per1.n.date_of_birth1.date>29)
	       {
		cout<<"\n\t\t\t\tINVALID DATE";
		cout<<"\n\t\t\tPlease, re-enter the date\n";
		goto label27;
	       }
	     else if((per1.n.date_of_birth1.year%4!=0)&&
		     (per1.n.date_of_birth1.date>28))
	       {
		cout<<"\n\t\t\t\tINVALID DATE";
		cout<<"\n\t\t\tPlease, re-enter the date\n";
		goto label27;
	       }
	    }
	  switch(per1.n.date_of_birth1.month)
	    {
	     case 4:
	     case 6:
	     case 9:
	     case 11:if(per1.n.date_of_birth1.date>30)
		       {
			cout<<"\n\t\t\t\tINVALID DATE";
			cout<<"\n\t\t\tPlease, re-enter the date\n";
			goto label27;
		       }
	    }
	 }
      }
   }
 cout<<"\nAge:"<<per.n.age<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nAge:";
    cin>>per1.n.age;
    per.n.age=per1.n.age;
   }
 cout<<"\n\t\t\t\tFAMILY'S DETAILS";
 cout<<"\n\nFather's Name:";
 puts(per.f.father_name);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nFather's Name:";
    gets(per1.f.father_name);
    strcpy(per.f.father_name,per1.f.father_name);
   }
 cout<<"\nFather's age(If died, age at death):"<<per.f.father_age<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nFather's age:";
    cin>>per1.f.father_age;
    per.f.father_age=per1.f.father_age;
   }
 cout<<"\n\nMother's Name:";
 puts(per.f.mother_name);
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nMother's Name:";
    gets(per1.f.mother_name);
    strcpy(per.f.mother_name,per1.f.mother_name);
   }
 cout<<"\nMother's age(If died, age at death):"<<per.f.mother_age<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nMother's Age:";
    cin>>per1.f.mother_age;
    per.f.mother_age=per1.f.mother_age;
   }
 cout<<"\nNo. of Brother(s):"<<nob<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nNo. of brother(s):";
    cin>>nob1;
   }
 else
   nob1=nob;
 for(j=0;j<nob1;j++)
   {
    cout<<"\nBrother's Name:";
    puts(per.f.brother_name[j]);
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nBrother's Name:";
       gets(per1.f.brother_name[j]);
       strcpy(per.f.brother_name[j],per1.f.brother_name[j]);
      }
    cout<<"\nBrother's age(If died, age at death):"<<per.f.brother_age[j]<<"\n";
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nBrother's age:";
       cin>>per1.f.brother_age[j];
       per.f.brother_age[j]=per1.f.brother_age[j];
      }
   }
 cout<<"\nNo. of Sister(s):"<<nos<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nNo. of sister(s):";
    cin>>nos1;
   }
 else
   nos1=nos;
 for(j=0;j<nos1;j++)
   {
    cout<<"\nSister's Name:";
    puts(per.f.sister_name[j]);
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nSister's Name:";
       gets(per1.f.sister_name[j]);
       strcpy(per.f.sister_name[j],per1.f.sister_name[j]);
      }
    cout<<"\nSister's age(If died, age at death):"<<per.f.sister_age[j]<<"\n";
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nSister's age:";
       cin>>per1.f.sister_age[j];
       per.f.sister_age[j]=per1.f.sister_age[j];
      }
   }
 cout<<"\nMarried:"<<choice4<<"\n";
 correct=change_option();
 if(correct=='y'||correct=='Y')
   {
    cout<<"\nMarried:";
    cin>>choice41;
   }
 else
   choice41=choice4;
 if(choice41=='y'||choice41=='Y')
   {
    cout<<"\nWife's Name:";
    puts(per.f.wife_name);
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nWife's Name:";
       gets(per1.f.wife_name);
       strcpy(per.f.wife_name,per1.f.wife_name);
      }
    cout<<"\nWife's age:"<<per.f.wife_age<<"\n";
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nWife's age:";
       cin>>per1.f.wife_age;
       per.f.wife_age=per1.f.wife_age;
      }
    cout<<"\nNo. of son(s):"<<non<<"\n";
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nNo. of son(s):";
       cin>>non1;
      }
    else
      non1=non;
    for(j=0;j<non1;j++)
      {
       cout<<"\nSon's Name:";
       puts(per.f.son_name[j]);
       correct=change_option();
       if(correct=='y'||correct=='Y')
	 {
	  cout<<"\nSon's Name:";
	  gets(per1.f.son_name[j]);
	  strcpy(per.f.son_name[j],per1.f.son_name[j]);
	 }
       cout<<"\nSon's age:"<<per.f.son_age[j]<<"\n";
       correct=change_option();
       if(correct=='y'||correct=='Y')
	 {
	  cout<<"\nSon's age:";
	  cin>>per1.f.son_age[j];
	  per.f.son_age[j]=per1.f.son_age[j];
	 }
      }
    cout<<"\nNo. of daughter(s):"<<nod<<"\n";
    correct=change_option();
    if(correct=='y'||correct=='Y')
      {
       cout<<"\nNo. of daughter(s):";
       cin>>nod1;
      }
    else
      nod1=nod;
    for(j=0;j<nod1;j++)
      {
       cout<<"\nDaughter's Name:";
       puts(per.f.daughter_name[j]);
       correct=change_option();
       if(correct=='y'||correct=='Y')
	 {
	  cout<<"\nDaughter's Name:";
	  gets(per1.f.daughter_name[j]);
	  strcpy(per.f.daughter_name[j],per1.f.daughter_name[j]);
	 }
       cout<<"\nDaughter's age:"<<per.f.daughter_age[j]<<"\n";
       correct=change_option();
       if(correct=='y'||correct=='Y')
	 {
	  cout<<"\nDaughter's age:";
	  cin>>per1.f.daughter_age[j];
	  per.f.daughter_age[j]=per1.f.daughter_age[j];
	 }
      }
   }
 ob.prem_info::alter_pol_data();
}


/*----------------------------------------------------------
  FUNCTION TO DISPLAY POLICY HOLDER'S DATA
----------------------------------------------------------*/

void policy_person::display_person()
{
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 1";
 gotoxy(1,1);
 cout<<"\n\t\t\t\tPOLICY HOLDER'S DETAILS";
 cout<<"\n\n\tName:";
 puts(per.name2);
 cout<<"\n\tDate of birth(dd/mm/yy):"<<per.date_of_birth2.date<<"\\"
     <<per.date_of_birth2.month<<"\\"<<per.date_of_birth2.year;
 cout<<"\n\n\tAge:"<<per.age1;
 cout<<"\n\n\tBirth place:";
 puts(per.birth_place);
 cout<<"\n\tAddress:";
 cout<<per.add1.block<<"\\"<<per.add1.house_no<<","<<per.add1.sector
     <<",\n\t\t"<<per.add1.area<<","<<per.add1.state<<"-";
 puts(per.add1.pin_code);
 cout<<"\n\tPhone no.(landline):";
 puts(per.ph_no1[0]);
 cout<<"\t\t   (Mobile):";
 if(strcmp(per.ph_no1[1],"0"))
   puts(per.ph_no1[1]);
 cout<<"\n\tAnnual income(in Rs.):";
 puts(per.annual_income);
 cout<<"\n\tEducational Qualification:";
 puts(per.edu_qua);
 gotoxy(20,22);
 cout<<"Press any key to go to next page";
 getch();
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 2";
 gotoxy(1,1);
 cout<<"\n\t\t\t\tPOLICY'S DETAILS";
 cout<<"\n\n\tAgent's name:";
 puts(per.p.agent_name);
 cout<<"\n\tBranch code:";
 puts(per.p.branch);
 cout<<"\n\tTable term:";
 puts(per.p.table_term);
 cout<<"\n\tSum assured:";
 cout<<per.p.sum_assured;
 cout<<"\n\tPolicy number:";
 puts(per.p.policy_no);
 cout<<"\n\tPremium:";
 puts(per.p.premium);
 cout<<"\n\tMode of payment:";
 puts(per.p.mode_of_pay);
 cout<<"\n\tRisk date(dd/mm/yy):"<<per.p.risk_date.date<<"\\"
     <<per.p.risk_date.month<<"\\"<<per.p.risk_date.year;
 gotoxy(20,22);
 cout<<"Press any key to go to next page";
 getch();
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 3";
 gotoxy(1,1);
 cout<<"\n\t\t\tMEDICAL REPORTS REQUIRED";
 policy_person::medical_report();
 gotoxy(20,22);
 cout<<"Press any key to go to next page";
 getch();
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 4";
 gotoxy(1,1);
 cout<<"\n\t\t\t\tNOMINEE'S DETAILS";
 cout<<"\n\n\tName:";
 puts(per.n.name3);
 cout<<"\n\tRelation:";
 puts(per.n.relation);
 cout<<"\n\tDate of birth(dd/mm/yy):";
 cout<<per.n.date_of_birth1.date<<"\\"<<per.n.date_of_birth1.month
     <<"\\"<<per.n.date_of_birth1.year;
 cout<<"\n\n\tAge:"<<per.n.age;
 gotoxy(20,22);
 cout<<"Press any key to go to next page";
 getch();
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 5";
 gotoxy(1,1);
 cout<<"\n\t\t\t\tFAMILY'S DETAILS";
 cout<<"\n\n\tFather's Name:";
 puts(per.f.father_name);
 cout<<"\n\tFather's age(If died, age at death):"<<per.f.father_age;
 cout<<"\n\n\tMother's Name:";
 puts(per.f.mother_name);
 cout<<"\n\tMother's age(If died, age at death):"<<per.f.mother_age;
 for(j=0;j<nob;j++)
   {
    cout<<"\n\n\tBrother's Name:";
    puts(per.f.brother_name[j]);
    cout<<"\tBrother's age(If died, age at death):"<<per.f.brother_age[j];
    delay(1000);
   }
 for(j=0;j<nos;j++)
   {
    cout<<"\n\n\tSister's Name:";
    puts(per.f.sister_name[j]);
    cout<<"\tSister's age(If died, age at death):"<<per.f.sister_age[j];
    delay(1000);
   }
 if(choice4=='y'||choice4=='Y')
   {
    cout<<"\n\n\n\tWife's Name:";
    puts(per.f.wife_name);
    cout<<"\tWife's age:"<<per.f.wife_age<<"\n";
    for(j=0;j<non;j++)
      {
       cout<<"\n\n\tSon's Name:";
       puts(per.f.son_name[j]);
       cout<<"\tSon's age:"<<per.f.son_age[j];
       delay(1000);
      }
    for(j=0;j<nod;j++)
      {
       cout<<"\n\n\tDaughter's Name:";
       puts(per.f.daughter_name[j]);
       cout<<"\tDaughter's age:"<<per.f.daughter_age[j];
       delay(1000);
      }
   }
 cout<<"\n\n\n\n\t\tPress any key to return";
 getch();
}


/*----------------------------------------------------------
  FUNCTION TO DISPLAY MEDICAL REPORTS TO BE SUBMITTED
  BY POLICY HOLDER
----------------------------------------------------------*/

void policy_person::medical_report()
{
 char ecg[]="Electrocardiogram",cbc[]="Complete Blood Count Report";
 char bst[]="Blood Sugar Tolerance Report",sch[]="Serum Cholestrol Report";
 char tm[]="Treadmill Exercises",esr[]="Erythrocyte Sedimentation Rate";
 char tele[]="Teleroentgenogram";
 char sma12[12][25]={"Fasting Blood Sugar","Serum Creatinine","SGOT","SGPT",
		     "Serum Cholestrol","Serum Triglyceride","Serum Calcium",
		     "Serum Uric Acids","Serum Patassium","Serum Protein",
		     "Serum Alkaline Phosphatse","Serum Bilirubin"};
 char sma27[27][35]={"Fasting Blood Sugar","Serum Creatinine","SGOT","SGPT",
		     "Serum Cholestrol","Serum Triglyceride","Serum Calcium",
		     "Serum Chloride","Serum Patassium","Serum Protein",
		     "Serum Alkaline Phosphatse","Serum Sodium","LDH","SGP",
		     "Serum Phosphorus","Serum Test","Blood Urea Nitrogen",
		     "Serum Gobulin","Serum Albumin","HDL Cholestrol","HBDH",
		     "Serum Unconjugated Bilirubin","Glucose Blood Sugar",
		     "Serum conjugated Bilirubin","Serum Total Bilirubm",
		     "Serum CPK","Serum Albumin Globulin Ratio"};
 if(per.p.sum_assured<=50000)
   cout<<"\n\nNo, medical tests required";
 else if(per.p.sum_assured>50000&&per.p.sum_assured<=100000)
   {
    if(per.age1<=59)
      cout<<"\n\nNo, medical tests are required";
    else
      cout<<"\n\n"<<ecg<<" is required";
   }
 else if(per.p.sum_assured>100000&&per.p.sum_assured<=200000)
   {
    if(per.age1<=35)
      cout<<"\n\nNo, medical tests are required";
    else if(per.age1>=36&&per.age1<=59)
      cout<<"\n\n"<<ecg<<" is required";
    else
      cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	  <<tele<<"\n\t3."<<bst<<"\n\t4."<<cbc<<"\n\t5."<<esr<<"\n\t6."<<sch;
   }
 else if(per.p.sum_assured>200000&&per.p.sum_assured<=600000)
   {
    if(per.age1<=35)
      cout<<"\n\nNo, medical tests are required";
    else if(per.age1>=36&&per.age1<=50)
      cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	  <<bst<<"\n\t3."<<sch;
    else if(per.age1>=51&&per.age1<=59)
      cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	  <<bst<<"\n\t3."<<sch<<"\n\t4."<<tele;
    else
      cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	  <<bst<<"\n\t3."<<sch<<"\n\t4."<<tele<<"\n\t5."<<cbc<<"\n\t6."<<esr;
   }
 else if(per.p.sum_assured>600000&&per.p.sum_assured<=1500000)
   {
    if(per.age1<=35)
      cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	  <<cbc<<"\n\t3."<<esr;
    else if(per.age1>=36&&per.age1<=50)
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	   <<bst<<"\n\t3."<<cbc<<"\n\t4."<<esr;
       for(k=1;k<=12;k++)
	 cout<<"\n\t"<<k+4<<"."<<sma12[k-1];
      }
    else if(per.age1>=51&&per.age1<=59)
      cout<<"\n\nFollowing medical tests are required:\n\t1.";
    else
      cout<<"\n\nFollowing medical tests are required:\n\t1."<<tm;
   }
 else if(per.p.sum_assured>1500000&&per.p.sum_assured<2500000)
   {
    if(per.age1<=35)
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	   <<cbc<<"\n\t3."<<esr;
       for(k=1;k<=12;k++)
	 cout<<"\n\t"<<k+3<<"."<<sma12[k-1];
      }
    else if(per.age1>=36&&per.age1<=50)
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	   <<bst<<"\n\t3."<<cbc<<"\n\t4."<<esr;
       for(k=1;k<=12;k++)
	 cout<<"\n\t"<<k+4<<"."<<sma12[k-1];
      }
    else
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<tm<<"\n\t2."
	   <<ecg<<"\n\t3."<<tele<<"\n\t4."<<cbc<<"\n\t5."<<esr<<"\n\t6.RUA"
	   <<"\n\t7.SPQ001";
       for(k=1;k<=12;k++)
	  cout<<"\n\t"<<k+7<<"."<<sma12[k-1];
      }
   }
 else if(per.p.sum_assured>=2500000&&per.p.sum_assured<10000000)
   {
    if(per.age1<=35)
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<"Elisa"
	   <<"\n\t2."<<ecg<<"\n\t3."<<tele<<"\n\t4."<<cbc<<"\n\t5."<<esr
	   <<"\n\t6.RUA\n\t7.SPQ001";
       for(k=1;k<=12;k++)
	  cout<<"\n\t"<<k+7<<"."<<sma12[k-1];
      }
    else if(per.age1>=36&&per.age1<=45)
      {
			 cout<<"\n\nFollowing medical tests are required:\n\t1."<<"Elisa"
	   <<"\n\t2."<<ecg<<"\n\t3."<<tele<<"\n\t4."<<cbc<<"\n\t5."<<esr
	   <<"\n\t6.RUA\n\t7.SPQ001";
       for(k=1;k<=12;k++)
	  cout<<"\n\t"<<k+7<<"."<<sma12[k-1];
      }
    else if(per.age1>=46&&per.age1<=50)
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<"Elisa\n\t2."
	   <<tm<<"\n\t3.TMT"<<"\n\t4."<<ecg<<"\n\t5."<<tele<<"\n\t6."<<cbc
	   <<"\n\t7."<<esr<<"\n\t8.RUA\n\t9.SPQ001";
       for(k=1;k<=12;k++)
	  cout<<"\n\t"<<k+9<<"."<<sma12[k-1];
			}
    else
      {
       cout<<"\n\nFollowing medical tests are required:\n\t1."<<"Elisa\n\t2."
	   <<tm<<"\n\t3."<<ecg<<"\n\t4."<<tele<<"\n\t5."<<cbc<<"\n\t6."<<esr
	   <<"\n\t7.RUA\n\t8.SPQ001";
       for(k=1;k<=12;k++)
	  cout<<"\n\t"<<k+8<<"."<<sma12[k-1];
      }
   }
 else
   {
    cout<<"\n\nFollowing medical tests are required:\n\t1."<<ecg<<"\n\t2."
	<<tm<<"\n\t3."<<tele<<"\n\t4."<<cbc<<"\n\t5."<<esr<<"\n\t6.RUA\n\t7."
	<<"SPQ001\n\t8.S.Amylase\n\t9.Acid Phosphate Australian Antigen Test"
	<<"\n\t10.Elisa VDRL";
    for(k=1;k<=27;k++)
	 cout<<"\n\t"<<k+10<<"."<<sma27[k-1];
   }
}


/*----------------------------------------------------------
  FUNCTION TO DELETE POLICY HOLDER'S DATA
----------------------------------------------------------*/

void policy_person::delete_person(char p_no1[])
{
 fstream file2,file_del;
 file2.open("Holder.dat",ios::in|ios::out);
 file_del.open("Temp.dat",ios::out|ios::in);
 while(!file2.eof())
   {
    file2.read((char*)&person,sizeof(policy_person));
    if(strcmp(p_no1,per.p.policy_no)!=0)
      {
       file_del.write((char*)&person,sizeof(policy_person));
      }
   }
 file2.close();
 file_del.close();
 remove("Holder.dat");
 rename("Temp.dat","Holder.dat");
 ob.prem_info::delete_pol_data(p_no1);
}


/*----------------------------------------------------------
  FUNCTION TO STORE PREMIUM INFORMAION
----------------------------------------------------------*/

void prem_info::pol_data()
{
 fstream file3;
 file3.open("Premium.dat",ios::app|ios::in|ios::out);
 file3.seekp(0,ios::end);
 strcpy(pol_name,person.per.name2);
 strcpy(pol_no,person.per.p.policy_no);
 strcpy(prem,person.per.p.premium);
 strcpy(mode,person.per.p.mode_of_pay);
 risk=person.per.p.risk_date;
 file3.write((char*)&ob,sizeof(prem_info));
 file3.close();
}


/*----------------------------------------------------------
  FUNCTION TO ALTER PREMIUM INFORMATION
----------------------------------------------------------*/

void prem_info::alter_pol_data()
{
 fstream file3;
 file3.open("Premium.dat",ios::out|ios::in);
 while(!file3.eof())
   {
    file3.read((char*)&ob,sizeof(prem_info));
    if(strcmp(person.store_policy_no,person.per.p.policy_no)==0)
      {
       if(strcmp(pol_name,person.per.name2)!=0)
	 strcpy(pol_name,person.per.name2);
       if(strcmp(pol_no,person.per.p.policy_no)!=0)
	 strcpy(pol_no,person.per.p.policy_no);
       if(strcmp(prem,person.per.p.premium)!=0)
	 strcpy(prem,person.per.p.premium);
       if(strcmp(mode,person.per.p.mode_of_pay)!=0)
	 strcpy(mode,person.per.p.mode_of_pay);
       if(risk.date!=person.per.p.risk_date.date)
	 risk.date=person.per.p.risk_date.date;
       if(risk.month!=person.per.p.risk_date.month)
	 risk.month=person.per.p.risk_date.month;
       if(risk.year!=person.per.p.risk_date.year)
	 risk.year=person.per.p.risk_date.year;
      }
   }
 file3.close();
}


/*----------------------------------------------------------
  FUNCTION TO DISPLAY PREMIUM INFORMATION
----------------------------------------------------------*/

void prem_info::print_data()
{
 cout<<"\nName:"<<pol_name;
 cout<<"\t\t\tPremium:"<<prem;
 cout<<"\nPolicy Number:"<<pol_no;
 cout<<"\nRisk date:"<<risk.date<<"\\"<<risk.month<<"\\"<<risk.year<<"\n";
}


/*----------------------------------------------------------
  FUNCTION TO DELETE PREMIUM INFORMATION
----------------------------------------------------------*/

void prem_info::delete_pol_data(char p_no1[])
{
 fstream file3,file_del;
 file3.open("Premium.dat",ios::in|ios::out);
 file_del.open("Temp.dat",ios::in|ios::out);
 while(!file3.eof())
   {
    file3.read((char*)&ob,sizeof(prem_info));
    if(strcmp(p_no1,person.per.p.policy_no)==0)
      {
       file_del.write((char*)&ob,sizeof(prem_info));
      }
   }
 file3.close();
 file_del.close();
 remove("Premium.dat");
 rename("Temp.dat","Premium.dat");
}


/*----------------------------------------------------------
  FUNCTION TO STORE POLICY'S DATA
----------------------------------------------------------*/

void policy_available::store_policy()
{
 int a,b,c,d;
 cout<<"\n\n\tEnter the table no. of the policy:";
 cin>>ob1.table_no;
 cout<<"\n\tEnter the name of the policy:";
 gets(ob1.policy_name);
 cout<<"\n\tEnter the term of the policy:";
 cin>>ob1.term;
 cout<<"\n\tEnter the age of the policy holder:";
 cin>>ob1.age2;
 cout<<"\n\tEnter the four basic premium\n";
 for(i=0;i<4;i++)
   {
    cout<<"\t\t\t\t    :";
    cin>>ob1.sum_assured2[i];
   }
 clrscr();
 cout<<"\n\t\t\t\t";
 puts(ob1.policy_name);
 cout<<"\t\t\t\t    Age: "<<ob1.age2;
 cout<<"\n\t\t\t\tTable Term: "<<table_no<<"-"<<term;
 a=7;
 c=0;
 for(i=0;i<2;i++,a+=10)
   {
    b=20;
    for(j=0;j<2;j++,b+=40,c++)
      {
       gotoxy(b,a);
       cout<<ob1.sum_assured2[c];
      }
   }
 a=10;
 for(i=0;i<2;i++,a+=10)
   {
    b=5;
    for(j=0;j<2;j++,b+=40)
      {
       gotoxy(b,a);
       cout<<"Yly        Hly        Qly        Sss";
      }
   }
 a=13;
 c=0;
 for(i=0;i<2;i++,a+=10)
   {
    b=5;
    for(j=0;j<2;j++,b+=40)
      {
       d=0;
       for(k=0;k<4;k++,c++,d+=8)
	 {
	  gotoxy(b+d,a);
	  cin>>ob1.premium2[c];
	 }
      }
   }
}


/*----------------------------------------------------------
  FUNCTION TO DISPLAY POLICY'S DATA
----------------------------------------------------------*/

void policy_available::display_policy()
{
 clrscr();
 int a,b,c,d;
 cout<<"\n\t\t\t\t";
 puts(ob1.policy_name);
 cout<<"\t\t\t\t    Age: "<<ob1.age2;
 cout<<"\n\t\t\t\tTable Term: "<<table_no<<"-"<<term;
 a=7;
 c=0;
 for(i=0;i<2;i++,a+=10)
   {
    b=20;
    for(j=0;j<2;j++,b+=40,c++)
      {
       gotoxy(b,a);
       cout<<ob1.sum_assured2[c];
      }
   }
 a=10;
 for(i=0;i<2;i++,a+=10)
   {
    b=5;
    for(j=0;j<2;j++,b+=40)
      {
       gotoxy(b,a);
       cout<<"Yly        Hly        Qly        Sss";
      }
   }
 a=13;
 c=0;
 for(i=0;i<2;i++,a+=10)
   {
    b=5;
    for(j=0;j<2;j++,b+=40)
      {
       d=0;
       for(k=0;k<4;k++,c++,d+=8)
	 {
	  gotoxy(b+d,a);
	  cout<<ob1.premium2[c];
	 }
      }
   }
}


/*----------------------------------------------------------
  FUNCTION TO DELETE POLICY'S DATA
----------------------------------------------------------*/

void policy_available::delete_policy(int t_no)
{
 fstream file4,file_del;
 file4.open("Policy.dat",ios::in|ios::out);
 file_del.open("Temp.dat",ios::in|ios::out);
 while(!file4.eof())
   {
    file4.read((char*)&ob1,sizeof(policy_available));
    if(t_no!=table_no)
      {
       file_del.write((char*)&ob1,sizeof(policy_available));
      }
   }
 file4.close();
 file_del.close();
 remove("Policy.dat");
 rename("Temp.dat","Policy.dat");
}


/*----------------------------------------------------------
  FUNCTION TO CHECK THE VALIDITY OF THE POLICY NUMBER OF A
  PERSON(POLICY HOLDER)
----------------------------------------------------------*/

void check_person()
{
 cout<<"\n\nName:";
 puts(person.per.name2);
 cout<<"Policy number:";
 puts(person.per.p.policy_no);
 cout<<"\n\t\t\t(y/n):";
}


/*----------------------------------------------------------
  FUNCTION TO CHECK THE PASSWORD ENTERED BY THE USER TO
  OPEN THE PROGRAM
----------------------------------------------------------*/

int password()
{
 char password[10],pass[10],pass2[10]="Rohit",ch='r';
 fstream file5;
 file5.open("Password.dat",ios::out|ios::in);
 if(file5.eof())
   {
    file5.seekp(ios::beg);
    file5<<pass2<<"\t";
   }
 i=0;
 gotoxy(20,19);
 cout<<"Enter the password:";
 while(ch!=' ')
   {
    ch=getche();
    if(ch!=' ')
      {
       cout<<"\b*";
       pass[i]=ch;
       i++;
      }
   }
 pass[i]='\0';
 file5>>password;
 if(strcmp(pass,password)==0)
   {
    file5.close();
    return(1);
   }
 else
   {
    file5.close();
    return(0);
   }
}


/*----------------------------------------------------------
  FUNCTION TO CHANGE THE PASSWORD ENTERED BY THE USER TO
  OPEN THE PROGRAM
----------------------------------------------------------*/

int change_password()
{
 labelp:
 clrscr();
 char pass1[10],pass2[10],pass3[10],pass4[10],ch1,ch2,ch3;
 fstream file5;
 file5.open("Password.dat",ios::in|ios::out);
 file5.seekg(ios::beg);
 file5>>pass1;
 i=0;
 gotoxy(20,6);
 cout<<"Enter the old password:";
 while(ch1!=' ')
   {
    ch1=getche();
    if(ch1!=' ')
      {
       cout<<"\b*";
       pass2[i]=ch1;
       i++;
      }
   }
 pass2[i]='\0';
 if(strcmp(pass1,pass2)==0)
   {
    i=0;
    gotoxy(20,11);
    cout<<"Enter the new password(<10):";
    while(ch2!=' ')
      {
       ch2=getche();
       if(ch2!=' ')
	 {
	  cout<<"\b*";
	  pass3[i]=ch2;
	  i++;
	 }
      }
    pass3[i]='\0';
    i=0;
    gotoxy(20,15);
    cout<<"Confirm the new password(<10):";
    while(ch3!=' ')
      {
       ch3=getche();
       if(ch3!=' ')
	 {
	  cout<<"\b*";
	  pass4[i]=ch3;
	  i++;
	 }
      }
    pass4[i]='\0';
    if(strcmp(pass3,pass4)==0)
      {
       file5.seekp(ios::beg);
       file5<<pass3<<"\t";
       file5.close();
       return(1);
      }
    else
      {
       gotoxy(25,17);
       cout<<"Please, Enter same password both time";
       file5.close();
       goto labelp;
      }
   }
 else
   {
    gotoxy(25,10);
    cout<<"Old password entered is wrong";
    file5.close();
    return(0);
   }
}


/*----------------------------------------------------------
  FUNCTION TO END UP THE PROGRAM BY EXITING
----------------------------------------------------------*/

void exit()
{
 k=0;
 clrscr();
 for(i=4;i<10;i++)
   {
    gotoxy(35,i);
    cout<<"THANKS";
    gotoxy(35,i-1);
    for(j=0;j<20;j++)
      cout<<" ";
    delay(100);
   }
 gotoxy(60,20);
 cout<<"Made By:";
 gotoxy(57,22);
 cout<<"ROHIT AGGARWAL";
 gotoxy(60,24);
 cout<<"XII - E";
 getch();
}


/*----------------------------------------------------------
  FUNCTION TO PRODUCE SOUND DURING PROGRAM RUN
----------------------------------------------------------*/

void sound()
{
 sound(256);
 delay(300);
 nosound();
 sound(280);
 delay(300);
 nosound();
 sound(320);
 delay(300);
 nosound();
 sound(341.3);
 delay(300);
 nosound();
 sound(384);
 delay(300);
 nosound();
 sound(426.6);
 delay(300);
 nosound();
 sound(480);
 delay(300);
 nosound();
 sound(512);
 delay(300);
 nosound();
}


/*----------------------------------------------------------
  FUNCTION TO EXIT A GIVEN CHOICE ON SELECTING EXIT OPTION
----------------------------------------------------------*/

void choose_exit()
{
 gotoxy(25,24);
 cout<<"EXITING TO MAIN MENU";
 for(i=0;i<10;i++)
   {
    cout<<".";
    delay(100);
   }
 sound();
}


/*----------------------------------------------------------
  FUNCTION TO EXIT A GIVEN CHOICE ON GIVING A WRONG CHOICE
  AS THE OPTION
----------------------------------------------------------*/

void default_exit()
{
 gotoxy(20,23);
 cout<<"WRONG CHOICE";
 gotoxy(25,25);
 cout<<"EXITING TO MAIN MENU";
 for(i=0;i<10;i++)
   {
    cout<<".";
    delay(100);
   }
}


/*----------------------------------------------------------
  FUNCTION TO DISPLAY THE HISTORY OF L.I.C.
----------------------------------------------------------*/

void history_of_lic()
{
 gotoxy(73,25);
 cout<<"PAGE 1";
 gotoxy(20,2);
 cout<<"LIFE INSURANCE COOPERATION LTD. (L.I.C.)";
 gotoxy(19,3);
 cout<<"------------------------------------------";
 gotoxy(5,6);
 cout<<"L.I.C of INDIA is a corporate autonomous body.It has been established";
 gotoxy(5,7);
 cout<<"by an act i.e. L.I.C Act 1956.";
 gotoxy(19,8);
 cout<<"----------------";
 gotoxy(5,10);
 cout<<"The insurance business was nationalised with an object to spread the";
 gotoxy(5,11);
 cout<<"message of insurance to every corner of the country aiming absolute";
 gotoxy(5,12);
 cout<<"security of the money contributed by the public ,cheaper premium rates ,";
 gotoxy(5,13);
 cout<<"dependable service.";
 gotoxy(5,16);
 cout<<"The corporation has it's Central Office at MUMBAI with seven zonal";
 gotoxy(5,17);
 cout<<"offices and 100 divisional offices.It has 2700 Branches spread in every";
 gotoxy(5,18);
 cout<<"part of the country.";
 gotoxy(20,22);
 cout<<"Press any key to go to next page";
 getch();
 clrscr();
 gotoxy(73,25);
 cout<<"PAGE 2";
 gotoxy(20,2);
 cout<<"LIFE INSURANCE COOPERATION LTD. (L.I.C.)";
 gotoxy(19,3);
 cout<<"------------------------------------------";
 gotoxy(5,7);
 cout<<"BENEFITS OF LIFE INSURANCE";
 gotoxy(4,8);
 cout<<"----------------------------";
 gotoxy(5,10);
 cout<<"1. Financial security and periodical payments.";
 gotoxy(5,12);
 cout<<"2. Better than ordinary savings scheme.";
 gotoxy(5,14);
 cout<<"3. Gives security against creditors.";
 gotoxy(5,16);
 cout<<"4. Income tax relief to arise.";
 gotoxy(5,18);
 cout<<"5. Loan can be raised on the security of the policy.";
 gotoxy(10,21);
 cout<<"Press any key to return";
 getch();
}

void main()
{
 clrscr();

 // DECLARING DIFFERENT VARIABLES AND FILES

 char ch,ch1,p_no[15],ch2,ch3,mode_data[10],choice,choice1,choice2,choice3;
 char month_name[13][20]={"0","January","February","March","April","May",
			  "June","July","August","September","October",
			  "November","December"};
 char choice4,choice41,choice42,choice43;
 int set,pos,count1,month_data,year_data,flag,flag1,age_check,term_check;
 int t_p_no,access,change,check_year;
 agent_data agent;
 fstream file1,file2,file3,file4;

 //DEFINING THE OPENING PAGE

 _setcursortype(_NOCURSOR);
 for(i=0;i<40;i++)
   {
    cout<<"* ";
    delay(50);
   }
 for(i=2;i<24;i++)
   {
    cout<<"*";
    delay(50);
    gotoxy(79,i);
    cout<<"*\n";
    delay(50);
   }
 for(i=0;i<40;i++)
   {
    cout<<"* ";
    delay(50);
   }
 delay(500);
 gotoxy(33,6);
 cout<<"A PROJECT ON";
 delay(1000);
 gotoxy(28,8);
 cout<<"LIC DATABASE MANAGEMENT";
 delay(1000);
 gotoxy(16,4);
 for(i=0;i<24;i++)
   {
    cout<<"* ";
    delay(50);
   }
 for(i=5;i<10;i++)
   {
    gotoxy(16,i);
    cout<<"*";
    delay(50);
    gotoxy(62,i);
    cout<<"*";
    delay(50);
   }
 gotoxy(16,10);
 for(i=0;i<24;i++)
   {
    cout<<"* ";
    delay(50);
   }
 delay(500);
 gotoxy(26,12);
 cout<<"WELCOME TO THE DATABASE OF";
 delay(1000);
 gotoxy(22,14);
 cout<<"LIFE INSURANCE COOPERATION (L.I.C.)";
 for(i=11;i<16;i++)
   {
    gotoxy(16,i);
    cout<<"*";
    delay(50);
    gotoxy(62,i);
    cout<<"*";
    delay(50);
   }
 gotoxy(16,16);
 for(i=0;i<24;i++)
   {
    cout<<"* ";
    delay(50);
   }

 //CHECKING PASSWORD FOR ACCESSING PROGRAM

 access=password();
 if(access==1)
   {
    gotoxy(40,22);
    cout<<"ACCESS GRANTED";
    getch();
   }
 else
   {
    gotoxy(40,22);
    cout<<"ACCESS NOT GRANTED";
    getch();
    exit(1);
   }

 //DEFINING OPENING MENU

 label:
 clrscr();
 for(i=1,j=1;i<=5;i++,j+=2)
   {
    gotoxy(j,i);
    cout<<"*";
    gotoxy(80-j,i);
    cout<<"*";
    gotoxy(j,26-i);
    cout<<"*";
    gotoxy(80-j,26-i);
    cout<<"*";
   }
 gotoxy(10,5);
 for(i=0;i<31;i++)
   cout<<" *";
 for(i=6;i<21;i++)
   {
    gotoxy(9,i);
    cout<<"*";
    gotoxy(71,i);
    cout<<"*";
   }
 gotoxy(10,21);
 for(i=0;i<31;i++)
   cout<<" *";
 gotoxy(25,2);
 cout<<"LIFE INSURANCE COOPERATION (L.I.C.)";
 gotoxy(35,4);
 cout<<"OPENING MENU";
 gotoxy(15,9);
 cout<<"1.AGENT'S INFORMATION";
 gotoxy(15,10);
 cout<<"2.POLICY HOLDER";
 gotoxy(15,11);
 cout<<"3.PREMIUM INFORMATION";
 gotoxy(15,12);
 cout<<"4.POLICIES AVAILABLE";
 gotoxy(15,13);
 cout<<"5.HISTORY OF L.I.C.";
 gotoxy(15,14);
 cout<<"6.CHANGE ACCESSING PASSWORD";
 gotoxy(15,15);
 cout<<"7.EXIT";
 gotoxy(30,19);
 cout<<"ENTER YOUR CHOICE(1-7):";
 choice=getch();
 switch(choice)
   {
    case '1':
	     //DEFINING FIRST OPTION :- AGENT'S INFORMATION

	     label1:
	     clrscr();
	     for(i=1,j=1;i<=5;i++,j+=2)
	       {
		gotoxy(j,i);
		cout<<"*";
		gotoxy(80-j,i);
		cout<<"*";
		gotoxy(j,26-i);
		cout<<"*";
		gotoxy(80-j,26-i);
		cout<<"*";
	       }
	     gotoxy(10,5);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     for(i=6;i<21;i++)
	       {
		gotoxy(9,i);
		cout<<"*";
		gotoxy(71,i);
		cout<<"*";
	       }
	     gotoxy(10,21);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     gotoxy(25,2);
	     cout<<"LIFE INSURANCE COOPERATION (L.I.C.)";
	     gotoxy(33,4);
	     cout<<"AGENT'S INFORMATION";
	     gotoxy(15,9);
	     cout<<"1.CREATE";
	     gotoxy(15,10);
	     cout<<"2.ALTER";
	     gotoxy(15,11);
	     cout<<"3.DISPLAY";
	     gotoxy(15,12);
	     cout<<"4.MAIN MENU";
	     gotoxy(30,19);
	     cout<<"ENTER YOUR CHOICE(1-4):";
	     choice1=getch();
	     switch(choice1)
	       {
		case '1':
			 //STORING AGENT'S INFORMATION

			 clrscr();
			 file1.open("Agent.dat",ios::out|ios::in);
			 agent.initial_agent_data();
			 file1.seekp(ios::beg);
			 file1.write((char*)&agent,sizeof(agent_data));
			 file1.close();
			 goto label1;
		case '2':
			 //ALTERING AGENT'S INFORMATION

			 clrscr();
			 file1.open("Agent.dat",ios::out|ios::in);
			 file1.seekg(ios::beg);
			 if(file1.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\t\tFirst run the CREATE option";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    file1.read((char*)&agent,sizeof(agent_data));
			    agent.alter_agent_data();
			    file1.seekp(ios::beg);
			    file1.write((char*)&agent,sizeof(agent_data));
			    cout<<"\n\n\t\t\t\tRECORD HAS BEEN ALTERED";
			    cout<<"\n\n\tPress any key to return";
			    getch();
			   }
			 file1.close();
			 goto label1;
		case '3':
			 //DISPLAYING AGENT'S INFORMATION

			 clrscr();
			 file1.open("Agent.dat",ios::out|ios::in);
			 file1.seekg(ios::beg);
			 if(file1.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\t\tFirst run the CREATE option";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    file1.read((char*)&agent,sizeof(agent_data));
			    agent.display_agent_data();
			   }
			 file1.close();
			 goto label1;
		case '4':
			 //CHOOSING EXIT OPTION

			 choose_exit();
			 goto label;
		default:
			//EXITING ON ENTERING WRONG VALUE

			default_exit();
			goto label;
	       }
    case '2':
	     //DEFINING SECOND OPTION :- POLICY HOLDER

	     label2:
	     clrscr();
	     for(i=1,j=1;i<=5;i++,j+=2)
	       {
		gotoxy(j,i);
		cout<<"*";
		gotoxy(80-j,i);
		cout<<"*";
		gotoxy(j,26-i);
		cout<<"*";
		gotoxy(80-j,26-i);
		cout<<"*";
	       }
	     gotoxy(10,5);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     for(i=6;i<21;i++)
	       {
		gotoxy(9,i);
		cout<<"*";
		gotoxy(71,i);
		cout<<"*";
	       }
	     gotoxy(10,21);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     gotoxy(25,2);
	     cout<<"LIFE INSURANCE COOPERATION (L.I.C.)";
	     gotoxy(35,4);
	     cout<<"POLICY HOLDER";
	     gotoxy(15,9);
	     cout<<"1.CREATE";
	     gotoxy(15,10);
	     cout<<"2.ALTER";
	     gotoxy(15,11);
	     cout<<"3.DISPLAY";
	     gotoxy(15,12);
	     cout<<"4.DELETE";
	     gotoxy(15,13);
	     cout<<"5.MAIN MENU";
	     gotoxy(30,19);
	     cout<<"ENTER YOUR CHOICE(1-5):";
	     choice2=getch();
	     switch(choice2)
	       {
		case '1':
			 //STORING POLICY HOLDER'S INFORMATION

			 file2.open("Holder.dat",ios::out|ios::in);
			 file2.seekg(ios::beg);
			 if(file2.eof())
			   count1=0;
			 else
			   {
			    count1=0;
			    while(!file2.eof())
			      {
			       file2.read((char*)&person,sizeof(policy_person));
			       if(person.count>count1)
				 count1=person.count;
			      }
			   }
			 file2.close();
			 file2.open("Holder.dat",ios::out|ios::in|ios::app);
			 do
			   {
			    clrscr();
			    person.create_person(count1);
			    file2.seekp(0,ios::end);
			    file2.write((char*)&person,sizeof(policy_person));
			    cout<<"\n\n\nWant to create another POLICY HOLDER"
				<<"(y/n):";
			    cin>>ch1;
			   }while(ch1=='y'||ch1=='Y');
			 file2.close();
			 goto label2;
		case '2':
			 //ALTERING POLICY HOLDER'S INFORMATION

			 label6:
			 file2.open("Holder.dat",ios::out|ios::in);
			 file2.seekg(ios::beg);
			 if(file2.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\t\tFirst run the CREATE option";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    cout<<"\n\tEnter the policy number of the policy "
				<<"to be altered:";
			    gets(p_no);
			    while(!file2.eof())
			      {
			       file2.read((char*)&person,sizeof(policy_person));
			       if(strcmp(person.get_p_no(),p_no)==0)

				       //checking the validity of policy number

				 {
				  cout<<"\n\n\nWant to alter the policy of:\n\t";
				  check_person();
				  cin>>ch3;
				  if(ch3=='y'||ch3=='Y')
				    {
				     clrscr();
				     person.alter_person();
				     count1=person.count;
				     pos=((count1-1)*sizeof(policy_person));
				     file2.seekp(pos,ios::beg);
				     file2.write((char*)&person,sizeof(policy_person));
				     cout<<"\n\n\t\t\t\tPOLICY HAS BEEN ALTERED";
				     cout<<"\n\n\tPress any key to return";
				     getch();
				    }
				  else
				    cout<<"\n\n\n\tCheck the policy number entered";
				  goto label5;
				 }
			      }
			    cout<<"\n\n\t\tNo such Policy number exist";
			    label5:
			    cout<<"\n\n\nWant to alter record of any other "
				<<"policy(y/n):";
			    cin>>ch2;
			    if(ch2=='y'||ch2=='Y')
			      {
			       file2.close();
			       goto label6;
			      }
			   }
			 file2.close();
			 goto label2;
		case '3':
			 //DISPLAYING POLICY HOLDER'S INFORMATION

			 label8:
			 file2.open("Holder.dat",ios::out|ios::in);
			 file2.seekg(ios::beg);
			 if(file2.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\t\tFirst run the CREATE option";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    cout<<"\n\tEnter the policy number whose details are "
				<<"to be displayed:";
			    gets(p_no);
			    while(!file2.eof())
			      {
			       file2.read((char*)&person,sizeof(policy_person));
			       if(strcmp(person.get_p_no(),p_no)==0)

				       //checking the validity of policy number

				 {
				  cout<<"\n\n\nWant to display the policy of:\n";
				  check_person();
				  cin>>ch3;
				  if(ch3=='y'||ch3=='Y')
				    person.display_person();
				  else
				    cout<<"\n\n\n\tCheck the policy number entered";
				  goto label7;
				 }
			      }
			    cout<<"\n\n\t\tNo such Policy number exist";
			    label7:
			    cout<<"\n\n\n\t\tWant to display any other policy(y/n):";
			    cin>>ch2;
			    if(ch2=='y'||ch2=='Y')
			      {
			       file2.close();
			       goto label8;
			      }
			   }
			 file2.close();
			 goto label2;
		case '4':
			 //DELETING POLICY HOLDER'S INFORMATION

			 label10:
			 file2.open("Holder.dat",ios::out|ios::in);
			 file2.seekg(ios::beg);
			 if(file2.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\t\tFirst run the CREATE option";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    cout<<"\n\tEnter the policy number of the policy "
				<<"to be deleted:";
			    gets(p_no);
			    while(!file2.eof())
			      {
			       file2.read((char*)&person,sizeof(policy_person));
			       if(strcmp(person.get_p_no(),p_no)==0)

				       //checking the validity of policy number

				 {
				  cout<<"\n\n\nWant to delete the policy of:\n\t";
				  check_person();
				  cin>>ch3;
				  if(ch3=='y'||ch3=='Y')
				    {
				     person.delete_person(p_no);
				     cout<<"\n\n\t\t\t\tPOLICY HAS BEEN DELETED";
				     cout<<"\n\n\tPress any key to return";
				     getch();
				    }
				  else
				    cout<<"\n\n\n\tCheck the policy number entered";
				  goto label9;
				 }
			      }
			    cout<<"\n\n\t\tNo such policy number exist";
			    label9:
			    cout<<"\n\n\nWant to delete any other policy(y/n):";
			    cin>>ch2;
			    if(ch2=='y'||ch2=='Y')
			      {
			       file2.close();
			       goto label10;
			      }
			   }
			 file2.close();
			 goto label2;
		case '5':
			 //CHOOSING EXIT OPTION

			 choose_exit();
			 goto label;
		default:
			//EXITING ON ENTERING WRONG VALUE

			default_exit();
			goto label;
	       }
    case '3':
	     //DEFINING THIRD OPTION :- PREMIUM INFORMATION

	     label3:
	     clrscr();
	     for(i=1,j=1;i<=5;i++,j+=2)
	       {
		gotoxy(j,i);
		cout<<"*";
		gotoxy(80-j,i);
		cout<<"*";
		gotoxy(j,26-i);
		cout<<"*";
		gotoxy(80-j,26-i);
		cout<<"*";
	       }
	     gotoxy(10,5);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     for(i=6;i<21;i++)
	       {
		gotoxy(9,i);
		cout<<"*";
		gotoxy(71,i);
		cout<<"*";
	       }
	     gotoxy(10,21);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     gotoxy(25,2);
	     cout<<"LIFE INSURANCE COOPERATION (L.I.C.)";
	     gotoxy(33,4);
	     cout<<"PREMIUM INFORMATION";
	     gotoxy(15,9);
	     cout<<"1.MONTH WISE DETAILS";
	     gotoxy(15,10);
	     cout<<"2.YEAR WISE DETAILS";
	     gotoxy(15,11);
	     cout<<"3.MODE WISE DETAILS";
	     gotoxy(15,12);
	     cout<<"4.MAIN MENU";
	     gotoxy(30,19);
	     cout<<"ENTER YOUR CHOICE(1-4):";
	     choice3=getch();
	     switch(choice3)
	       {
		case '1':
			 //DISPLAY PREMIUM INFORMATION AS PER MONTH

			 label11:
			 file3.open("Premium.dat",ios::out|ios::in);
			 file3.seekg(ios::beg);
			 if(file3.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\tFirst run the CREATE option of "
				<<"POLICY HOLDER ";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    cout<<"\n\tEnter the month for which details have "
				<<"to be printed(in number):";
			    cin>>month_data;
			    flag1=1;
			    flag=0;
			    if(month_data>12)

				       //checking the validity of month

			      {
			       cout<<"\n\n\tThere is no "<<month_data<<" month in"
				   <<" the year";
			       flag=1;
			      }
			    k=0;
			    gotoxy(73,25);
			    cout<<"PAGE 1";
			    gotoxy(1,5);
			    while(!file3.eof())
			      {
			       file3.read((char*)&ob,sizeof(prem_info));
			       if(ob.get_month()==month_data)
				 {
				  flag1++;
				  if(flag1<5)
				    ob.print_data();
				  else
				    {
				     cout<<"\n\n\tPress any key to go to the "
					 <<"next page";
				     getch();
				     clrscr();
				     k++;
				     gotoxy(73,25);
				     cout<<"PAGE "<<k;
				     gotoxy(1,5);
				     flag1=1;
				     ob.print_data();
				    }
				  flag=1;
				 }
			      }
			    if(flag==0)
			      cout<<"\n\n\n\tThere is no policy in the month of "
				  <<month_name[month_data];
			    cout<<"\n\n\tWant to display premium details for any "
				<<"other month(y/n):";
			    cin>>ch2;
			    if(ch2=='y'||ch2=='Y')
			      {
			       file3.close();
			       goto label11;
			      }
			   }
			 file3.close();
			 goto label3;
		case '2':
			 //DISPLAY PREMIUM INFORMATION AS PER YEAR

			 label12:
			 file3.open("Premium.dat",ios::out|ios::in);
			 file3.seekg(ios::beg);
			 if(file3.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\tFirst run the CREATE option of "
				<<"POLICY HOLDER ";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    cout<<"\n\tEnter the year for which details have "
				<<"to be printed:";
			    cin>>year_data;
			    struct date v;
			    getdate(&v);
			    check_year=v.da_year;
			    if(year_data>check_year)

				       //checking the validity of year

			       {
				cout<<"\n\n\tYear "<<year_data<<" has not yet arrived";
			       }
			    flag1=1;
			    flag=0;
			    k=0;
			    gotoxy(73,25);
			    cout<<"PAGE 1";
			    gotoxy(1,5);
			    while(!file3.eof())
			      {
			       file3.read((char*)&ob,sizeof(prem_info));
			       if(ob.get_year()==year_data)
				 {
				  flag1++;
				  if(flag1<5)
				    ob.print_data();
				  else
				    {
				     cout<<"\n\n\tPress any key to go to the "
					 <<"next page";
				     getch();
				     clrscr();
				     k++;
				     gotoxy(73,25);
				     cout<<"PAGE "<<k;
				     gotoxy(1,5);
				     flag1=1;
				     ob.print_data();
				    }
				  flag=1;
				 }
			      }
			    if(flag==0)
			      cout<<"\n\n\n\tThere is no policy in the year of "
				  <<year_data;
			    cout<<"\n\n\tWant to display premium details for any "
				<<"other year(y/n):";
			    cin>>ch2;
			    if(ch2=='y'||ch2=='Y')
			      {
			       file3.close();
			       goto label12;
			      }
			   }
			 file3.close();
			 goto label3;
		case '3':
			 //DISPLAY PREMIUM INFORMATION AS PER MODE OF PAYMENT

			 label13:
			 file3.open("Premium.dat",ios::out|ios::in);
			 file3.seekg(ios::beg);
			 if(file3.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\tFirst run the CREATE option of "
				<<"POLICY HOLDER ";
			    getch();
			   }
			 else
			   {
			    clrscr();
			    cout<<"\n\tEnter the mode for which details have "
				<<"to be printed:";
			    cin>>mode_data;
			    flag1=1;
			    flag=0;
			    k=0;
			    gotoxy(73,25);
			    cout<<"PAGE 1";
			    gotoxy(1,5);
			    while(!file3.eof())
			      {
			       file3.read((char*)&ob,sizeof(prem_info));
			       if(strcmpi(ob.get_mode(),mode_data)==0)
				 {
				  flag1++;
				  if(flag1<5)
				    ob.print_data();
				  else
				    {
				     cout<<"\n\n\tPress any key to go to the "
					 <<"next page";
				     getch();
				     clrscr();
				     k++;
				     gotoxy(73,25);
				     cout<<"PAGE "<<k;
				     gotoxy(1,5);
				     flag1=1;
				     ob.print_data();
				    }
				  flag=1;
				 }
			      }
			    if(flag==0)
			      cout<<"\n\n\n\tThere is no policy in the mode of "
				  <<mode_data<<" payment";
			    cout<<"\n\n\tWant to display premium details for any "
				<<"other mode(y/n):";
			    cin>>ch2;
			    if(ch2=='y'||ch2=='Y')
			      {
			       file3.close();
			       goto label13;
			      }
			   }
			 file3.close();
			 goto label3;
		case '4':
			 //CHOOSING EXIT OPTION

			 choose_exit();
			 goto label;
		default:
			//EXITING ON ENTERING WRONG VALUE

			default_exit();
			goto label;
	       }
    case '4':
	     //DEFINING FORTH OPTION :- POLICIES AVAILABLE

	     label4:
	     clrscr();
	     for(i=1,j=1;i<=5;i++,j+=2)
	       {
		gotoxy(j,i);
		cout<<"*";
		gotoxy(80-j,i);
		cout<<"*";
		gotoxy(j,26-i);
		cout<<"*";
		gotoxy(80-j,26-i);
		cout<<"*";
	       }
	     gotoxy(10,5);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     for(i=6;i<21;i++)
	       {
		gotoxy(9,i);
		cout<<"*";
		gotoxy(71,i);
		cout<<"*";
	       }
	     gotoxy(10,21);
	     for(i=0;i<31;i++)
	       cout<<" *";
	     gotoxy(25,2);
	     cout<<"LIFE INSURANCE COOPERATION (L.I.C.)";
	     gotoxy(33,4);
	     cout<<"POLICIES AVAILABLE";
	     gotoxy(15,9);
	     cout<<"1.ENTER A NEW POLICY";
	     gotoxy(15,10);
	     cout<<"2.DISPLAY DETAILS OF A POLICY";
	     gotoxy(15,11);
	     cout<<"3.DELETE A POLICY";
	     gotoxy(15,12);
	     cout<<"4.MAIN MENU";
	     gotoxy(30,19);
	     cout<<"ENTER YOUR CHOICE(1-4):";
	     choice4=getch();
	     switch(choice4)
	       {
		case '1':
			 //STORING POLICY'S INFORMATION

			 label14:
			 clrscr();
			 file4.open("Policy.dat",ios::in|ios::out|ios::app);
			 file4.seekp(0,ios::end);
			 ob1.store_policy();
			 file4.write((char*)&ob1,sizeof(policy_available));
			 cout<<"\n\n\t\tWant to enter more policy details(y/n):";
			 cin>>choice43;
			 if(choice43=='y'||choice43=='Y')
			   {
			    file4.close();
			    goto label14;
			   }
			 file4.close();
			 goto label4;
		case '2':
			 //DISPLAYING POLICY'S INFORMATION

			 label15:
			 clrscr();
			 file4.open("Policy.dat",ios::out|ios::in);
			 file4.seekg(ios::beg);
			 if(file4.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\tFirst run the ENTER NEW POLICY "
				<<"option of POLICIES AVAILABLE ";
			    getch();
			   }
			 else
			   {
			    cout<<"\n\tEnter the table number of the policy"
				<<" to be viewed:";
			    cin>>t_p_no;
			    while(!file4.eof())
			      {
			       file4.read((char*)&ob1,sizeof(policy_available));
			       if(ob1.get_table_no()==t_p_no)

				       //checking the validity of table number

				 {
				  cout<<"\n\n\t\tWant to view the details of policy:";
				  puts(ob1.get_policy_name());
				  cout<<"\n\n\t\t\t\t(y/n):";
				  cin>>choice42;
				  if(choice42=='y'||choice42=='Y')
				    goto label16;
				  else
				    {
				     cout<<"\n\n\tPlease check the policy no. entered";
				     goto label17;
				    }
				 }
			      }
			    cout<<"\n\n\tPolicy with this policy no. is not available"
				<<"\n\n\tPlease check the policy no. entered";
			    goto label17;
			    label16:
			    cout<<"\n\n\tEnter the term of the policy:";
			    cin>>term_check;
			    cout<<"\n\tEnter the age of the policy holder:";
			    cin>>age_check;
			    file4.seekg(0);
			    while(!file4.eof())
			      {
			       file4.read((char*)&ob1,sizeof(policy_available));
			       if(ob1.get_table_no()==t_p_no&&
				  ob1.get_age()==age_check&&
				  ob1.get_term()==term_check)

				       //checking the validity of table number,
				       //policy holder's age and term of the policy
				       //simultaneously

				  ob1.display_policy();
			      }
			    label17:
			    cout<<"\n\n\tWant to display any other policy(y/n):";
			    cin>>choice41;
			    if(choice41=='y'||choice41=='Y')
			      {
			       file4.close();
			       goto label15;
			      }
			   }
			 file4.close();
			 goto label4;
		case '3':
			 //DELETING POLICY'S INFORMATION

			 label18:
			 clrscr();
			 file4.open("Policy.dat",ios::out|ios::in);
			 file4.seekg(ios::beg);
			 if(file4.eof())
			   {
			    cout<<"\n\n\t\t\tFile has not been created."
				<<"\n\n\tFirst run the ENTER NEW POLICY "
				<<"option of POLICIES AVAILABLE ";
			    getch();
			   }
			 else
			   {
			    cout<<"\n\tEnter the table number of the policy"
				<<" to be deleted:";
			    cin>>t_p_no;
			    while(!file4.eof())
			      {
			       file4.read((char*)&ob1,sizeof(policy_available));
			       if(ob1.get_table_no()==t_p_no)

				       //checking the validity of table number

				 {
				  cout<<"\n\n\t\tWant to delete the policy:";
				  puts(ob1.get_policy_name());
				  cout<<"\n\n\t\t\t(y/n):";
				  cin>>choice43;
				  if(choice43=='y'||choice43=='Y')
				    {
				     file4.close();
				     ob1.delete_policy(t_p_no);
				     goto label19;
				    }
				  else
				    {
				     cout<<"\n\n\tPlease Check the policy no. entered";
				     goto label19;
				    }
				 }
			      }
			    cout<<"\n\n\tPolicy with this policy no. is not available"
				<<"\n\n\tPlease check the policy no. entered";
			    label19:
			    cout<<"\n\n\tWant to delete any other policy(y/n):";
			    cin>>choice41;
			    if(choice41=='y'||choice41=='Y')
			      {
			       file4.close();
			       goto label18;
			      }
			   }
			 file4.close();
			 goto label4;
		case '4':
			 //CHOOSING EXIT OPTION

			 choose_exit();
			 goto label;
		default:
			//EXITING ON ENTERING WRONG VALUE

			default_exit();
			goto label;
	       }
    case '5':
	     //DEFINING FIFTH OPTION :- HISTORY OF L.I.C.

	     clrscr();
	     history_of_lic();
	     goto label;
    case '6':
	     //DEFINING SIXTH OPTION :- CHANGE ACCESSING PASSWORD
	     //DEFINATION OF FUNCTION TO CHANGE PASSWORD

	     change=change_password();
	     if(change==1)
	       {
		gotoxy(25,23);
		cout<<"PASSWORD CHANGED SUCCESSFULLY";
		getch();
	       }
	     else
	       {
		gotoxy(25,23);
		cout<<"PASSWORD CAN'T BE CHANGED";
		getch();
	       }
	     goto label;
    case '7':
	     //DEFINING SEVENTH OPTION :- EXIT

	     gotoxy(25,24);
	     cout<<"EXITING FROM L.I.C.";
	     for(i=0;i<10;i++)
	       {
		cout<<".";
		delay(100);
	       }
	     sound();
	     exit();
	     exit(0);
    default:
	    //EXITING ON ENTERING WRONG VALUE

	    gotoxy(20,23);
	    cout<<"WRONG CHOICE";
	    gotoxy(25,25);
	    cout<<"EXITING FROM L.I.C.";
	    for(i=0;i<10;i++)
	      {
	       cout<<".";
	       delay(100);
	      }
	    exit(0);
   }
 getch();
}
