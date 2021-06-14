                                   // LPU FINDER

#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
using namespace std;
COORD coord={0,0};
void gotoxy(int x , int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class LPU
 {
 	    
	    char s_mentor[20];
	    char s_hod[20];
	    char c_coordinator[20];
	    char p_mentor[20];
	    char s_councellor[20];
	    char e_cell[20];
	    char p_coordinator[20];
	public:
		void add();
		char section[20];
		void display();
		void remove();
		void s_name();
		void modify();
 }; 
 
 
 void LPU::add()
 {  
    
    cout<<"\n Enter details                       ";
 	cout<<"\n Enter name of Section               :- ";
 	fflush(stdin);
 	gets(section);
 	cout<<"\n Enter name of Section Mentor        :- ";
 	fflush(stdin);
 	gets(s_mentor);
 	cout<<"\n Enter name of HOD                   :- ";
 	fflush(stdin);
 	gets(s_hod);
 	cout<<"\n Enter name of Course Coordinator    :- ";
 	fflush(stdin);
 	gets(c_coordinator);
 	cout<<"\n Enter name of Placement Mentor      :- ";
 	fflush(stdin);
 	gets(p_mentor);
 	cout<<"\n Enter name of Student Councellor    :- ";
 	fflush(stdin);
 	gets(s_councellor);
 	cout<<"\n Enter name of E-cell Coordinator    :- ";
 	fflush(stdin);
 	gets(e_cell);
 	cout<<"\n Enter name of Placement Coordinator :- ";
 	fflush(stdin);
 	gets(p_coordinator);
 	cout<<"\n RECORD added Thank You ";
 	cout<<"\n\n\n\n Press any key to continue  ";
				  getch();
 
 }
 
 
 
  void LPU::display()
 {  
    cout<<"\n Details of Section "<<section<<"  :- ";
    cout<<"\n Name of Section Mentor        :- ";
    cout<<s_mentor;
    cout<<"\n Name of HOD                   :- ";
 	cout<<s_hod;
 	cout<<"\n Name of Course Coordinator    :- ";
 	cout<<c_coordinator; 
 	cout<<"\n Name of Placement Mentor      :- ";
 	cout<<p_mentor;
 	cout<<"\n Name of Student Councellor    :- ";
 	cout<<s_councellor;
 	cout<<"\n Name of E-cell Coordinator    :- ";
 	cout<<e_cell;
	cout<<"\n Name of Placement Coordinator :- ";
 	cout<<p_coordinator;     
 }
 
 
 
 
 main()

 { system("color 0a");
 	LPU l;  
	 gotoxy(10,10);                         //object of the class for loading
 	cout<<"loading";
 	Sleep(1000);
 	cout<<".";
 	Sleep(1000);
 	cout<<".";
 	Sleep(1000);
 	cout<<".";
 	system("cls");
 	
 	char sec[20];
 	int choice=1;
 	cout<<" PLEASE ENTER THE PASSWORD=";
 	int pass;
 	cin>>pass;
 	if ( pass==123)                             // password is 123
{
    while(choice!=4)
     {
      system ("cls");	
      cout<<"\n\n         MAIN MENU  ";
      cout<<"\n\n   1. Add new Section  "; 	
      cout<<"\n   2. Display Section detail  ";
      cout<<"\n   3. Delete section ";
      cout<<"\n   4. Exit  ";
      cout<<"\n\n  Enter your choice    ";
      fflush(stdin);
      cin>>choice;
       switch(choice)
        {
          case 1:{ 
		          ofstream file("section.dat",ios::app|ios::binary);
		          l.add();
		          file.write((char*)&l,sizeof(l));
 				  file.close();
                  break;
                 }
          case 2: {
          	      int flag=0;
		          ifstream file("section.dat",ios::in|ios::binary);
   	              cout<<"\n Enter your section  :- "; 
				  fflush(stdin);                                                                                              
                  gets(sec);
                  fflush(stdin);
                  
   	 			  while(file.eof()==0)
	   			  { file.read((char*)&l,sizeof(l));
	                if(stricmp(sec,l.section)==0)
	                { flag++;
		   		      l.display();
		   		      break;
	                } 
	             }
	             if(flag==0)
	             cout<<"\n Section "<<sec<<" does not exist. ";
	             file.close();
	             cout<<"\n Press any key to continue  ";
				  getch();
                  break; 
			    }
          case 3:
                  {
                  int flag=0;
		          fstream file("section.dat",ios::in|ios::binary);
		          fstream file1("temp.dat",ios::out|ios::binary);
   	              cout<<"\n\n\n Enter section to be deleted :- "; 
				  fflush(stdin);                                                                                              
                  gets(sec);
   	 			  while(!file.eof())
	   			  {  file.read((char*)&l,sizeof(l));
	                if(stricmp(sec,l.section)==0)
	                { 
					  flag++;
					  cout<<"\n"<<sec<<" has been deleted successfully . ";
	                }
	                else
	                  file1.write((char*)&l,sizeof(l));  
	              }
	              if(flag==0)
	              cout<<"\n\t Section "<<sec<<" does not exist. ";
	              file.close();
	              file1.close();
	              remove("section.dat");
	              rename("temp.dat","section.dat");
	              cout<<"\n Press any key to continue  ";
				  getch();
	              }
          case 4: {
			exit (0);
			break;
		  } 
                  
			  	  
          default:{
          	       cout<<"\n\n  Invalid Choice...!";
          	       cout<<"\n\n Press any key to continue..";
          	       getch();
	              } 	          	  	
        }
     }
}
 else
 {
 	cout<<"please error...";
 }


 }
