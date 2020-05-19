#include <iostream>
#include <fstream>
#include  <string.h>
using namespace std;

  char name [25];
  char course[25];
  char phone[25];
  char id[10]; 
  char  seat_num[10],year[10];

/////////////////////////////////////// Delete ////////////////////////////	   

void delete_student()
{

    fstream stud;
    fstream temp;

    stud.open("student.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char a[10];
    cin.ignore();
    cout<<" \n\t Enter the Id: ";
    cin.getline(a,10);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
		stud.getline(course,25,'|');
		stud.getline(phone,25,'|');
		stud.getline(id,10,'|');
        stud.getline(seat_num,10,'|');
        stud.getline(year,10);
        if(strcmp(id,a)==0)
        {
            continue;
        }
        else
        {
            temp<< name<<'|'<<course<<'|'<<phone <<'|' << id << '|' << seat_num <<'|'<<year <<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("student.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
		temp.getline(course,25,'|');
		temp.getline(phone,25,'|');
		temp.getline(id,10,'|');
        temp.getline(seat_num,10,'|');
        temp.getline(year,10);
        stud<< name<<'|'<< course <<'|'<< phone <<'|'<< id <<'|'<< seat_num <<'|'<<year << '\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}

////////////////////////////////////// Update /////////////////////////////////////
void update_student()
{
    fstream stud;
    fstream temp;

    stud.open("student.txt",ios::in);
    temp.open("temp.txt",ios::out);
    char a[10];
    cin.ignore();
    cout<<" \n enter the Id: ";
    cin.getline(a,10);
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
		stud.getline(course,25,'|');
		stud.getline(phone,25,'|');
		stud.getline(id,10,'|');
        stud.getline(seat_num,10,'|');
        stud.getline(year,10);
        if(strcmp(id,a)==0)
        {
    		cout<< " \n\t name \t course \t phone \t id \t seat_Number \t Year \n";
			cout<< "\n\t"<< name << "\t"<< course << "\t" << phone << "\t" << id << "\t" << 	  seat_num<<"\t"<<year<<endl;
            cout<<" \n\n\n\tenter new value of record  \n ";
			cout<<" \n name : ";
			cin.getline(name,25);
			cout<<" \n course name : ";
			cin.getline(course,25);
			cout<<" \n phone : ";
			cin.getline(phone,25);
			cout<<" \n id : ";
			cin.getline(id,10);
			cout<<" \n Seat Number : ";
			cin.getline(seat_num,10);
			cout<<" \n year : ";
			cin.getline(year,10);
            temp<< name<<'|'<<course<<'|'<<phone <<'|' << id << '|' << seat_num <<'|'<<year <<'\n';
        }
        else
        {
            temp<< name<<'|'<<course<<'|'<<phone <<'|' << id << '|' << seat_num <<'|'<<year <<'\n';
        }


    }
    temp.close();
    stud.close();

    stud.open("student.txt",ios::out);
    temp.open("temp.txt",ios::in);
    while(!temp.eof())
    {
        temp.getline(name,25,'|');
		temp.getline(course,25,'|');
		temp.getline(phone,25,'|');
		temp.getline(id,10,'|');
        temp.getline(seat_num,10,'|');
        temp.getline(year,10);
    stud<< name<<'|'<<course<<'|'<<phone <<'|' << id << '|' << seat_num << '|' << year <<'\n';
    }
    temp.close();
    stud.close();
    remove("temp.txt");
    cout<<"\n done !!! \n";
}

/////////////////////////////////////// Show All ////////////////////////////////////

void display_all()
{

    fstream stud;
    stud.open("student.txt",ios::in);
	if(!stud)
	{
		cout << "\n Can't Open File\n"; 
		exit(0); 
	}



    cout<< " \n\t name \t course \t phone \t id \t seat_Number \t Year \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
		stud.getline(course,25,'|');
		stud.getline(phone,25,'|');
		stud.getline(id,10,'|');
        stud.getline(seat_num,10,'|');
        stud.getline(year,10);
		cout<< "\n\t"<< name << "\t"<< course << "\t" << phone << "\t" << id << "\t" << 	  seat_num<<"\t"<<year<<endl;
    }
stud.close();
}

////////////////////////////////// Search //////////////////////////////////////

void search_student(   )
{

    fstream stud;
    stud.open("student.txt",ios::in);
    char a[10];
    cout<<" \n enter Id : ";
    cin.ignore();
    cin.getline(a,10);
    int x=0;
    cout<< " \n\t name \t course \t phone \t id \t seat_Number \t Year \n";
    while(!stud.eof())
    {
        stud.getline(name,25,'|');
		stud.getline(course,25,'|');
		stud.getline(phone,25,'|');
		stud.getline(id,10,'|');
        stud.getline(seat_num,10,'|');
        stud.getline(year,10);
        if(strcmp(id, a)==0)
        {
          cout<< "\n \t "<< name << "\t"<<course << "\t" << phone << "\t" << id << "\t" << 	  seat_num<<"\t"<<year<<endl;
            x=1;
            break;
        }

    }
    if(x==0)
    {
        cout<<" \n not found !!!!\n";
    }
    stud.close();
}

///////////////////////////////////////// ADD ////////////////////////////
void  insert_student()
{
    fstream stud;
    stud.open("student.txt", ios::app);
    cin.ignore();
    cout<<" \n name : ";
    cin.getline(name,25);
    cout<<" \n course name : ";
    cin.getline(course,25);
    cout<<" \n phone : ";
    cin.getline(phone,25);
    cout<<" \n id : ";
    cin.getline(id,10);
    cout<<" \n Seat Number : ";
    cin.getline(seat_num,10);
    cout<<" \n year : ";
    cin.getline(year,10);
    stud<< name<<'|'<<course<<'|'<<phone <<'|' << id << '|' << seat_num << '|' << year <<'\n';
    cout<< "done !";
    stud.close();
}
//////////////////////////////////////////////////////////////////
int main()
{
    bool flag=true;
    while (flag)
    {
	  cout << "\n\n####################################################################\n\n"; 
	  cout<<"\t\t (1) Add Student\n\n";
	  cout<<"\t\t (2) Show All Students\n\n";
	  cout<<"\t\t (3) Search Students\n\n";
	  cout<<"\t\t (4) edit Student Data\n\n";
	  cout<<"\t\t (5) Delate Student \n\n";
	  cout<<"\t\t (6) exit\n";
	  cout << "\n####################################################################\n"; 
	  cout<<"\n\nEnter Option: ";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :
            insert_student();
            break;
        case 2:
            display_all();
            break;
        case 3:
			search_student();
            break;
        case 4 :
            update_student();
            break;
        case 5 :
            delete_student();
            break;
		case 6: 
			exit(0);
			break; 
        default :
            cout << " \n choose A Right Number \n";
        }
        cout << "Press ' y '  To Use The Program \n ";
        char f;
        cin>>f;
        if(f!='y')
        {
            flag=false;
        }
    }
    return 0;
}

