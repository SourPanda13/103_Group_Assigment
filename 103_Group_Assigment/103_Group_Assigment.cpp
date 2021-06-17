// 103_Group_Assigment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//103 Group Assignment 
//Brittany Armstrong
//Tim Boyd

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void login();
void contact();
void term_dates();
void events();
void admin_login();
void line();

void teacher_registration(struct teacher&); //function to input and write teacher information into teacher.dat file
void parent_registration(struct parent&); //function to input and write parent information into teacher.dat file
void teacher_login(char[], char[]); //function to match user input with teacher information from file
void parent_login(char[], char[]); //function to match user input with parent information from file
char username_t[15];	//teacher username
char password_t[15];	//teacher password
char username_p[15];	//parent username
char password_p[15];	//parent password
bool flag = false;

struct teacher // Teacher structure
{
	char full_name[60];
	char gender[2];
	char DOB[15];
	char email[51];
	char phone_number[20];
	char classroom[15];
	char year_teach[10];
	char username[15];
	char password[15];
}teach;

struct parent //Parent Structure
{
	char first_name[30];
	char last_name[30]; //Using First Name last name instead of just full name. Makes it easier to match parent and child
	char gender[2];
	char DOB[15];
	char email[51];
	char phone_number[20];
	char child_fname[60];
	char child_class[15];
	char emer_contactname[60];
	char emer_contactnum[20];
	char username[15];
	char password[15];
}paren;


int main()
{
	int selection;
	bool done = false;

	do {
		line();
		cout << "\n\t\t\tSymonds Street Secondary School\n";
		line();
		cout << "\n\n\tSymonds School is New Zealand's largest specialist creative and\n\ttechnology college.We've been fuelling the creative and \n\ttechnology industries for over 30 years with talented Animators,\n\tFilmmakers, Designers, Techies, and Game Developers.";
		cout << "\n\n\tWelcome to the Home Page\n\tPlease pick an option for more details.\n\n";
		cout << "\n\t1. Registration & Login.";
		cout << "\n\t2. Contact Details.";
		cout << "\n\t3. Term Dates.";
		cout << "\n\t4. Latest & Upcoming Events.";
		cout << "\n\t5. Exit.";
		cout << "\n\t6. Admin Login.";
		line();
		cout << "\n\tPlease enter choice : ";
		cin >> selection;


		switch (selection)
		{
		case 1: login();
			break;
		case 2: contact();
			break;
		case 3: term_dates();
			break;
		case 4: events();
			break;
		case 5: cout << "\n\tThank you for visiting Symonds Street Secondary School website.";
			cout << "\n\tHope to see you soon!\n";
			line();
			done = true;
			break;
		case 6: admin_login();
			break;
		default: cout << "\n\tI'm sorry please enter a correct option.\n";
			break;
		}
	} while (!done);
	return 0;
}

void login() {
	int login_selection;
	bool login_done = false;

	do {

		line();
		cout << "\n\n\t\tLogin Screen";
		cout << "\n\t1. New Teacher Sign Up.";
		cout << "\n\t2. New Parent Sign up.";
		cout << "\n\t3. Teacher Sign In.";
		cout << "\n\t4. Parent Sign In.";
		cout << "\n\t5. Return to Home Page.";
		line();
		cout << "\n\tPlease enter choice : ";
		cin >> login_selection;

		switch (login_selection)
		{
		case 1: teacher_registration(teach);
			break;
		case 2: parent_registration(paren);
			break;
		case 3: teacher_login();
			break;
		case 4: parent_login();
			break;
		case 5: login_done = true;
			break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}
	} while (!login_done);
}

void teacher_registration(struct teacher& teach)
{
	fstream file;
	file.open("teacher_files.dat", ios::out | ios::app | ios::binary);

	cout << "\n\tTeacher Sign Up";
	cout << "\n\tPlease Enter your information.";
	cin.ignore();

	cout << "\n\n\tFull Name : ";
	cin.getline(teach.full_name, 60);
	cout << "\tGender(M/F/O) : ";
	cin.getline(teach.gender, 2);
	cout << "\tDate of Birth (xx/xx/xxxx) : ";
	cin.getline(teach.DOB, 15);
	cout << "\tEmail : ";
	cin.getline(teach.email, 51);
	cout << "\tPhone Number (Max 9 digits): ";
	cin.getline(teach.phone_number, 20);
	cout << "\tClass room (Class xxx) : ";
	cin.getline(teach.classroom, 15);
	cout << "\tYear teaching (Year xx) : ";
	cin.getline(teach.year_teach, 10);
	cout << "\tUsername (Max 15 letters): ";
	cin.getline(teach.username, 15);
	cout << "\tPassword (Max 15 letters): ";
	cin.getline(teach.password, 15);
	cout << "\n\n\tTeacher record successfully.\n";

	file.write(reinterpret_cast<char*>(&teach), sizeof(teach)); // storing record in binary

	file.close();
}

void parent_registration(struct parent& paren)
{
	fstream file;
	file.open("parent_files.dat", ios::out | ios::app | ios::binary);

	cout << "\n\tParent Sign Up";
	cout << "\n\tPlease Enter your information.";
	cin.ignore();

	cout << "\n\n\tFirst Name : ";
	cin.getline(paren.first_name, 30);
	cout << "\n\n\tLast Name : ";
	cin.getline(paren.last_name, 30);
	cout << "\tGender(M/F/O) : ";
	cin.getline(paren.gender, 2);
	cout << "\tDate of Birth (xx/xx/xxxx) : ";
	cin.getline(paren.DOB, 15);
	cout << "\tEmail : ";
	cin.getline(paren.email, 51);
	cout << "\tPhone Number : ";
	cin.getline(paren.phone_number, 20);
	cout << "\tChild Full Name : ";
	cin.getline(paren.child_fname, 60);
	cout << "\tChild Class room (Class xxx) : ";
	cin.getline(paren.child_class, 15);
	cout << "\tEmergency Contact Name : ";
	cin.getline(paren.emer_contactname, 60);
	cout << "\tEmergency Contact Number (Max 9 digits) : ";
	cin.getline(paren.emer_contactnum, 20);
	cout << "\tUsername (Max 15 letters): ";
	cin.getline(paren.username, 15);
	cout << "\tPassword (Max 15 letters): ";
	cin.getline(paren.password, 15);


	file.write(reinterpret_cast<char*>(&paren), sizeof(paren)); // storing record in binary

	file.close();
}

void teacher_login(char username_t[15], char password_t[15])
{
	teacher teach;
	fstream file;

	file.open("teacher_files.dat", ios::in | ios::binary); // opening in read mode

	if (file.is_open())
	{
		cin.ignore();
		cout << "\n\n\tEnter Teacher Username : ";
		cin.getline(username_t, 15);
		cout << "\n\tEnter Teacher Password : ";
		cin.getline(password_t, 15);

		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&teach), sizeof(teach)); // reading the content from the file 
			if ((strcmp(username_t, teach.username) == 0) && (strcmp(password_t, teach.password) == 0)) // matching user input with information stored on file
			{
				// this will be where we put student read/write/edit/delete record function
				cout << "\n\n\tThat's all the information in the file for the search key provided!\n";
				flag = false;
				break;
			}
			else
			{
				flag = true;
			}
		}
	}
	else
	{
		cout << "\nNo record found in the file for the search key provided!\n";
	}

	if (flag)
	{
		cout << "\nNo record found in the file for the search key provided!\n";

	}
}

void parent_login(char username_p[15], char password_p[15])
{
	fstream file;
	parent paren;

	file.open("parent_files.dat", ios::in | ios::binary); // opening in read mode

	if (file.is_open())
	{
		cin.ignore();
		cout << "\n\n\tEnter Parent Username : ";
		cin.getline(username_t, 15);
		cout << "\n\tEnter Parent Password : ";
		cin.getline(password_t, 15);

		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&paren), sizeof(paren)); // reading the content from the file 
			if ((strcmp(username_p, paren.username) == 0) && (strcmp(password_p, paren.password) == 0)) // matching user input with information stored on file
			{
				// this will be where we put student read record function
				cout << "\n\nThat's all the information in the file for the search key provided!\n";
				flag = false;
				break;
			}
			else
			{
				flag = true;
			}
		}
	}
	else
	{
		cout << "\n\tNo record found in the file for the search key provided!\n";
	}

	if (flag)
	{
		cout << "\n\tNo record found in the file for the search key provided!\n";

	}
}

void contact() {
	line();
	cout << "\n\n\t\tContact Us Page";
	cout << "\n\tHere is our contact details.";
	cout << "\n\tYou can call Symonds Street Secondary School at 0800 66 55 44 for free.";
	cout << "\n\tAuckland Campus : ";
	cout << "\n\tAuckland City Road";
	cout << "\n\tLevel 4,3 City Road, Grafton";
	cout << "\n\tAuckland 1010.";
	cout << "\n\tEmail : Symonds@symonds.com";
	line();
	system("pause");
}

void term_dates() {

	line();
	cout << "\n\n\t\tTerm Dates Page";
	cout << "\n\n\tFor the school year of 2021 the term dates are as follow : ";
	cout << "\n\tTerm 1 : 9th of Febuary - 16th of April.";
	cout << "\n\tTerm 1 Public Holidays : 8th of Febuary, 2nd of April, 5th of April, 6th of April.";
	cout << "\n\tTerm 1 School Holidays : 17 of April - 2nd of May.";
	cout << "\n\n\tTerm 2 : 3rd of May - 9th of July.";
	cout << "\n\tTerm 2 Public Holidays : 7th of June.";
	cout << "\n\tTerm 2 School Holidays : 10 of July - 25 of July.";
	cout << "\n\n\tTerm 3 : 26th of July - 1st of October.";
	cout << "\n\tTerm 3 Public Holidays : None.";
	cout << "\n\tTerm 3 School Holidays : 2nd of October - 17th of October.";
	cout << "\n\n\tTerm 4 : 18th of October - 10th of December.";
	cout << "\n\tTerm 4 Public Holidays : None.";
	cout << "\n\tTerm 4 School Holidays : 11th of December - 9th of Febuary 2022.";
	line();
	system("pause");
}

void events() {
	line();
	cout << "\n\n\t\tLatest & Upcoming Events Page";
	cout << "\n\n\tThe Latest events for the month of March : ";
	cout << "\n\t - Athletics Day : 11th of March.";
	cout << "\n\t - Swimming Gala : 18th of Mrach.";
	cout << "\n\t - Music Night : 22nd of March.";
	cout << "\n\t - Dance Night : 29th of March.";
	cout << "\n\n\tUpcoming events in April : ";
	cout << "\n\t - Rowing Day : 1st of April.";
	cout << "\n\t - Maths Quizathon : 7th of April.";
	cout << "\n\t - Art Exhibition : 14th of April.";
	cout << "\n\n\tUpcoming Events in May : ";
	cout << "\n\t - Camp Weekend : 7th of May - 9th of May.";
	cout << "\n\t - Build a robot competition : 13th of May.";
	cout << "\n\n\tUpcoming Events in June : ";
	cout << "\n\t - Televised First XV Rugby Match : 12th of June.";
	cout << "\n\t - Charity Event : 16th of June.";
	cout << "\n\t - Marathon Run for Kids : 22nd of June.";
	line();
	system("pause");
}

void admin_login() {
	int admin_selection;
	bool admin_done = false;

	do
	{
		line();
		cout << "\n\n\t\tAdmin Login Screen";
		cout << "\n\t1. Admin Login.";
		cout << "\n\t2. Return to Home Page.";
		line();
		cout << "\n\n\tPlease Enter Choice : ";
		cin >> admin_selection;
		switch (admin_selection)
		{
		case 1:
			break;
		case 2: admin_done = true;
			break;
		default: cout << "\n\tPlease Enter Correct Option.\n";
			break;
		}
	} while (!admin_done);
}

void line() {
	cout << "\n";
	for (int i = 0; i < 80; i++) {
		cout << "*";
	}
	cout << "\n";
}