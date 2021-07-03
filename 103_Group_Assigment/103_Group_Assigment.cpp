// 103_Group_Assigment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//103 Group Assignment 
//Brittany Armstrong 270080234
//Tim Boyd 270043384

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdio>

using namespace std;

//Front Page
void login();
void contact();
void term_dates();
void events();
void admin_login();
void line();

//Register&Login for teachers and parents
void teacher_registration(struct teacher&);									//Function to input and write teacher information into teacher.dat file
void parent_registration(struct parent&);										//Function to input and write parent information into teacher.dat file
void teacher_login(char[], char[]);											//Function to match user input with teacher information from file
void parent_login(char[], char[]);											//Function to match user input with parent information from file

//Teacher Student Record Functions
void add_record(struct student&);												//Function to add a student record
void edit_record(char[], char[]);												//Function to edit a student record
void delete_record();											//Function to delete student record
void update_record();											//Function to update student record
void view_record();												//Function to view student records
							
//Parent Login Functions
void student_report(char[]);
void school_notices();
																
//Global Variables
char username_t[15];											//Teacher username
char password_t[15];											//Teacher password
char username_p[15];											//Parent username
char password_p[15];											//Parent password
char search_f[30];												//Search first name
char search_l[30];												//Search last name
bool flag = false;
char search_f[30], search_l[30];
int position = 0;
char parstu_search[15];

struct teacher													//Teacher Structure
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

struct parent													//Parent Structure
{
	char first_name[30];
	char last_name[30];											//Using first name last name instead of just full name. Makes it easier to match parent and child
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

struct student													//Student Structure
{
	char first_name[30];
	char last_name[30];
	char gender[2];
	int english;												//All student marks will be marked 0-100
	int maths;
	int science;
	int sports;
	int arts;												    //Includes art/music/dancing
	int social;													//Includes history/religous studies/languages
	int technology;												//Includes IT/graphics/design/
	float learning_progress;
}stude;

fstream file, tempfile;

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
		case 3: teacher_login(username_t, password_t);
			break;
		case 4: parent_login(username_p, password_p);
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
	system("CLS");
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
	cout << "\n\n\tTeacher Recorded Successfully.\n";

	file.write(reinterpret_cast<char*>(&teach), sizeof(teach));	//Storing record in binary

	file.close();
}

void parent_registration(struct parent& paren)
{
	system("CLS");
	file.open("parent_files.dat", ios::out | ios::app | ios::binary);

	cout << "\n\tParent Sign Up";
	cout << "\n\tPlease Enter your information.";
	cin.ignore();

	cout << "\n\n\tFirst Name : ";
	cin.getline(paren.first_name, 30);
	cout << "\tLast Name : ";
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
	cout << "\n\n\tParent Recorded Successfully.\n";

	file.write(reinterpret_cast<char*>(&paren), sizeof(paren)); //Storing record in binary

	file.close();
}

void teacher_login(char username_t[15], char password_t[15])
{
	int student_selection;
	bool student_done = false;

	file.open("teacher_files.dat", ios::in | ios::binary);		//Opening in read mode

	if (file.is_open())
	{
		cin.ignore();
		cout << "\n\n\tEnter Teacher Username : ";
		cin.getline(username_t, 15);
		cout << "\n\tEnter Teacher Password : ";
		cin.getline(password_t, 15);

		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&teach), sizeof(teach)); //Reading the content from the file 
			if ((strcmp(username_t, teach.username) == 0) && (strcmp(password_t, teach.password) == 0)) //Matching user input with information stored on file
			{
				cout << "\n\tLogin Successful";

				//This will be where we put student read/write/edit/delete record function

				do{
					system("CLS");
					line();
					cout << "\n\n\t\tStudent Record Screen";
					cout << "\n\t1. Add Student.";
					cout << "\n\t2. Edit Student Record.";
					cout << "\n\t3. Delete Student Record.";
					cout << "\n\t4. Update Record.";
					cout << "\n\t5. View the Records.";
					cout << "\n\t6. Return to Home Page.";
					line();
					cout << "\n\tPlease enter choice : ";
					cin >> student_selection;

					switch (student_selection)
					{
					case 1: add_record(stude);
						break;
					case 2: edit_record(search_f, search_l);
						break;
					case 3: delete_record();
						break;
					case 4: update_record();
						break;
					case 5: view_record();
						break;
					case 6: main();
						break;
					default: cout << "\n\tPlease enter correct option.\n";
						break;
					}
				} while (!student_done);
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

void add_record(struct student& stud)
{																//There will be 3 seperate class files where the teacher can store their students record, Class 102/103/104
	bool student_done_1 = false;
	int student_selection_1;

	do
	{
		cout << "\n\n\tStudent Add Record Page";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to Previous Page.";
		cout << "\n\tPlease select from menu : ";
		cin >> student_selection_1;

		switch (student_selection_1)
		{
		case 1:	file.open("class_102.dat", ios::out | ios::app | ios::binary); //Class File 102
			cout << "\n\n\tClass 102 Record.";
			cout << "\n\tPlease Enter student information.";
			cin.ignore();
			cout << "\n\tFirst Name : ";
			cin.getline(stude.first_name, 30);
			cout << "\tLast Name : ";
			cin.getline(stude.last_name, 30);
			cout << "\tGender (M/F/O) : ";
			cin.getline(stude.gender, 2);
			cout << "\tEnglish Mark (0-100) : ";
			cin >> stude.english;
			cout << "\tMaths Mark (0-100) : ";
			cin >> stude.maths;
			cout << "\tScience Mark (0-100) : ";
			cin >> stude.science;
			cout << "\tSports Mark (0-100) : ";
			cin >> stude.sports;
			cout << "\tArts Mark (0-100) : ";
			cin >> stude.arts;
			cout << "\tSocial Sciences Mark (0-100) : ";
			cin >> stude.social;
			cout << "\tTechnology Mark (0-100) : ";
			cin >> stude.technology;
			stude.learning_progress = (stude.english + stude.maths + stude.science + stude.sports + stude.arts + stude.social + stude.technology) / 7;
			cout << "\tLearning Progress : " << stude.learning_progress; //The Learning progress mark will be stored as a number, it will take all subject marks and deivide by total subjects.
			if (stude.learning_progress >= 80)					//We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
			{
				cout << "\tAchieved";
			}
			else if (stude.learning_progress <= 40)
			{
				cout << "\tHelp Needed";
			}
			else
			{
				cout << "\tProgressing";
			}
			file.write(reinterpret_cast<char*>(&stude), sizeof(stude)); //Storing record in binary

			file.close();
			break;
		case 2: file.open("class_103.dat", ios::out | ios::app | ios::binary); //Class File 103
			cout << "\n\tPlease Enter your information.";
			cin.ignore();
			cout << "\n\n\tClass 103 Record.";
			cout << "\n\tPlease Enter student information.";
			cin.ignore();
			cout << "\n\tFirst Name : ";
			cin.getline(stude.first_name, 30);
			cout << "\tLast Name : ";
			cin.getline(stude.last_name, 30);
			cout << "\tGender (M/F/O) : ";
			cin.getline(stude.gender, 2);
			cout << "\tEnglish Mark (0-100) : ";
			cin >> stude.english;
			cout << "\tMaths Mark (0-100) : ";
			cin >> stude.maths;
			cout << "\tScience Mark (0-100) : ";
			cin >> stude.science;
			cout << "\tSports Mark (0-100) : ";
			cin >> stude.sports;
			cout << "\tArts Mark (0-100) : ";
			cin >> stude.arts;
			cout << "\tSocial Sciences Mark (0-100) : ";
			cin >> stude.social;
			cout << "\tTechnology Mark (0-100) : ";
			cin >> stude.technology;
			stude.learning_progress = (stude.english + stude.maths + stude.science + stude.sports + stude.arts + stude.social + stude.technology) / 7;
			cout << "\tLearning Progress : " << stude.learning_progress; //The Learning progress mark will be stored as a number, it will take all subject marks and deivide by total subjects.
			if (stude.learning_progress >= 80)					//We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
			{
				cout << "\tAchieved";
			}
			else if (stude.learning_progress <= 40)
			{
				cout << "\tHelp Needed";
			}
			else
			{
				cout << "\tProgressing";
			}
			file.write(reinterpret_cast<char*>(&stude), sizeof(stude)); //Storing record in binary

			file.close();
			break;
		case 3: file.open("class_104.dat", ios::out | ios::app | ios::binary); //Class File 104
			cout << "\n\tPlease Enter your information.";
			cin.ignore();
			cout << "\n\n\tClass 104 Record.";
			cout << "\n\tPlease Enter student information.";
			cin.ignore();
			cout << "\n\tFirst Name : ";
			cin.getline(stude.first_name, 30);
			cout << "\tLast Name : ";
			cin.getline(stude.last_name, 30);
			cout << "\tGender (M/F/O) : ";
			cin.getline(stude.gender, 2);
			cout << "\tEnglish Mark (0-100) : ";
			cin >> stude.english;
			cout << "\tMaths Mark (0-100) : ";
			cin >> stude.maths;
			cout << "\tScience Mark (0-100) : ";
			cin >> stude.science;
			cout << "\tSports Mark (0-100) : ";
			cin >> stude.sports;
			cout << "\tArts Mark (0-100) : ";
			cin >> stude.arts;
			cout << "\tSocial Sciences Mark (0-100) : ";
			cin >> stude.social;
			cout << "\tTechnology Mark (0-100) : ";
			cin >> stude.technology;
			stude.learning_progress = (stude.english + stude.maths + stude.science + stude.sports + stude.arts + stude.social + stude.technology) / 7;
			cout << "\tLearning Progress : " << stude.learning_progress; //The Learning progress mark will be stored as a number, it will take all subject marks and deivide by total subjects.
			if (stude.learning_progress >= 80)					//We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
			{
				cout << "\tAchieved";
			}
			else if (stude.learning_progress <= 40)
			{
				cout << "\tHelp Needed";
			}
			else
			{
				cout << "\tProgressing";
			}
			file.write(reinterpret_cast<char*>(&stude), sizeof(stude)); //Storing record in binary

			file.close();
			break;
		case 4: student_done_1 = true;
			break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}

	} while (!student_done_1);
}

void edit_record(char search_f[30], char search_l[30]) {
	student stud;
	fstream file;
	int edit_select;
	bool edit_done = false;
	do
	{
		cout << "\n\n\tStudent Edit Record Page\n";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> edit_select;

		switch (edit_select)
		{
		case 1:
			file.open("class_102.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					position = file.tellg();
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(search_f, stud.first_name) == 0) && (strcmp(search_l, stud.last_name) == 0))
					{
						cout << "\n\tRecord Found: \n\n";
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
						cout << "\n\n" << stud.first_name << " " << stud.last_name;
						cout << "\t" << stud.gender;
						cout << "\t" << stud.english;
						cout << "/" << stud.maths;
						cout << "/" << stud.science;
						cout << "/" << stud.sports; //this part is to display the record
						cout << "/" << stud.arts;
						cout << "/" << stud.social;
						cout << "/" << stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\t\tAchieved";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\t\tHelp Needed";
						}
						else
						{
							cout << "\t\tProgressing";
						}

						file.seekp(position - (sizeof(stud)));
						cout << "\n\n\tEdit Student record";
						cout << "\n\tPlease Enter student information.\n";
						cout << "\n\tEnglish Mark (0-100) : ";
						cin >> stud.english;
						cout << "\tMaths Mark (0-100) : ";
						cin >> stud.maths;
						cout << "\tScience Mark (0-100) : ";
						cin >> stud.science;
						cout << "\tSports Mark (0-100) : ";
						cin >> stud.sports;
						cout << "\tArts Mark (0-100) : ";
						cin >> stud.arts;
						cout << "\tSocial Sciences Mark (0-100) : ";
						cin >> stud.social;
						cout << "\tTechnology Mark (0-100) : ";
						cin >> stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						cout << "\tLearning Progress : " << stud.learning_progress; //The Learning progress mark will be stored as a number, it will take all subject marks and deivide by total subjects.
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\tAchieved";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\tHelp Needed";
						}
						else
						{
							cout << "\tProgressing";
						}
						cout << "\n\n\tStudent Record Edit Successful\n";
						file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary
						break;
					} // i want to change to the last record

				}
			}
			else
			{
				cout << "\nFile unable to access ....";
			}
			file.close();
			break;
		case 2:
			file.open("class_103.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					position = file.tellg();
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(search_f, stud.first_name) == 0) && (strcmp(search_l, stud.last_name) == 0))
					{
						cout << "\n\tRecord Found: \n\n";
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
						cout << "\n\n" << stud.first_name << " " << stud.last_name;
						cout << "\t" << stud.gender;
						cout << "\t" << stud.english;
						cout << "/" << stud.maths;
						cout << "/" << stud.science;
						cout << "/" << stud.sports; //this part is to display the record
						cout << "/" << stud.arts;
						cout << "/" << stud.social;
						cout << "/" << stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\t\tAchieved";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\t\tHelp Needed";
						}
						else
						{
							cout << "\t\tProgressing";
						}

						file.seekp(position - (sizeof(stud)));
						cout << "\n\n\tEdit Student record";
						cout << "\n\tPlease Enter student information.\n";
						cout << "\n\tEnglish Mark (0-100) : ";
						cin >> stud.english;
						cout << "\tMaths Mark (0-100) : ";
						cin >> stud.maths;
						cout << "\tScience Mark (0-100) : ";
						cin >> stud.science;
						cout << "\tSports Mark (0-100) : ";
						cin >> stud.sports;
						cout << "\tArts Mark (0-100) : ";
						cin >> stud.arts;
						cout << "\tSocial Sciences Mark (0-100) : ";
						cin >> stud.social;
						cout << "\tTechnology Mark (0-100) : ";
						cin >> stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						cout << "\tLearning Progress : " << stud.learning_progress; //The Learning progress mark will be stored as a number, it will take all subject marks and deivide by total subjects.
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\tAchieved";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\tHelp Needed";
						}
						else
						{
							cout << "\tProgressing";
						}
						cout << "\n\n\tStudent Record Edit Successful\n";
						file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary
						break;
					} // i want to change to the last record

				}
			}
			else
			{
				cout << "\nFile unable to access ....";
			}
			file.close();
			break;
		case 3:
			file.open("class_104.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					position = file.tellg();
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(search_f, stud.first_name) == 0) && (strcmp(search_l, stud.last_name) == 0))
					{
						cout << "\n\tRecord Found: \n\n";
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
						cout << "\n\n" << stud.first_name << " " << stud.last_name;
						cout << "\t" << stud.gender;
						cout << "\t" << stud.english;
						cout << "/" << stud.maths;
						cout << "/" << stud.science;
						cout << "/" << stud.sports; //this part is to display the record
						cout << "/" << stud.arts;
						cout << "/" << stud.social;
						cout << "/" << stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\t\tAchieved";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\t\tHelp Needed";
						}
						else
						{
							cout << "\t\tProgressing";
						}

						file.seekp(position - (sizeof(stud)));
						cout << "\n\n\tEdit Student record";
						cout << "\n\tPlease Enter student information.\n";
						cout << "\n\tEnglish Mark (0-100) : ";
						cin >> stud.english;
						cout << "\tMaths Mark (0-100) : ";
						cin >> stud.maths;
						cout << "\tScience Mark (0-100) : ";
						cin >> stud.science;
						cout << "\tSports Mark (0-100) : ";
						cin >> stud.sports;
						cout << "\tArts Mark (0-100) : ";
						cin >> stud.arts;
						cout << "\tSocial Sciences Mark (0-100) : ";
						cin >> stud.social;
						cout << "\tTechnology Mark (0-100) : ";
						cin >> stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						cout << "\tLearning Progress : " << stud.learning_progress; //The Learning progress mark will be stored as a number, it will take all subject marks and deivide by total subjects.
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\tAchieved";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\tHelp Needed";
						}
						else
						{
							cout << "\tProgressing";
						}
						cout << "\n\n\tStudent Record Edit Successful\n";
						file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary
						break;
					} // i want to change to the last record

				}
			}
			else
			{
				cout << "\nFile unable to access ....";
			}
			file.close();
			break;
		case 4: edit_done = true;
			break;
		default: "\n\tPlease enter correct option.\n";
			break;
		}

	} while (!edit_done);
}

void delete_record() {
	fstream tempfile;
	int student_selection_2 = false;



	cout << "\n\n\tStudent Delete Record Page";
	cout << "\n\t1. Class 102.";
	cout << "\n\t2. Class 103.";
	cout << "\n\t3. Class 104.";
	cout << "\n\t4. Return to Previous Page.";
	cout << "\n\tPlease select from menu : ";
	cin >> student_selection_2;

	switch (student_selection_2)
	{
	case 1:file.open("class_102.dat", ios::out | ios::app | ios::binary); //Class File 102

		if (file.is_open()) {
			cin.ignore();
			cout << "\n\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			while (!file.eof()) {
				while (file.read(reinterpret_cast<char*>(&stude), sizeof(stude))) {
					if ((strcmp(search_f, stude.first_name) == 0) && (strcmp(search_l, stude.last_name) == 0)) {//Matching user input with information stored on file
						cout << "\n\tRecord Found: ";
						cout << "\n\tName: " << stude.first_name << " " << stude.last_name;
					}
					else {
						tempfile.open("temp.dat", ios::out | ios::app | ios::binary);
						tempfile.write(reinterpret_cast<char*>(&stude), sizeof(stude));
						tempfile.close();
					}
				}
			}
		}
		file.close();
		remove("class_102.dat");
		rename("tempfile.dat", "class_102.dat");
		break;

	case 2:file.open("class_103.dat", ios::out | ios::app | ios::binary); //Class File 103

		if (file.is_open()) {
			cin.ignore();
			cout << "\n\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			while (!file.eof()) {
				while (file.read(reinterpret_cast<char*>(&stude), sizeof(stude))) {
					if ((strcmp(search_f, stude.first_name) == 0) && (strcmp(search_l, stude.last_name) == 0)) {//Matching user input with information stored on file
						cout << "\n\tRecord Found: ";
						cout << "\n\tName: " << stude.first_name << " " << stude.last_name;
					}
					else {
						tempfile.open("temp.dat", ios::out | ios::app | ios::binary);
						tempfile.write(reinterpret_cast<char*>(&stude), sizeof(stude));
						tempfile.close();
					}
				}
			}
		}
		file.close();
		remove("class_103.dat");
		rename("tempfile.dat", "class_103.dat");
		break;

	case 3:file.open("class_104.dat", ios::out | ios::app | ios::binary); //Class File 104
		if (file.is_open()) {
			cin.ignore();
			cout << "\n\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			while (!file.eof()) {
				while (file.read(reinterpret_cast<char*>(&stude), sizeof(stude))) {
					if ((strcmp(search_f, stude.first_name) == 0) && (strcmp(search_l, stude.last_name) == 0)) {//Matching user input with information stored on file
						cout << "\n\tRecord Found: ";
						cout << "\n\tName: " << stude.first_name << " " << stude.last_name;
					}
					else {
						tempfile.open("temp.dat", ios::out | ios::app | ios::binary);
						tempfile.write(reinterpret_cast<char*>(&stude), sizeof(stude));
						tempfile.close();
					}
				}
			}
		}
		file.close();

		remove("class_104.dat");
		rename("tempfile.dat", "class_104.dat");
		break;

	case 4:
		break;
	default:
		break;
	}
}

void update_record() {

}

void view_record() {

	fstream file;
	student stud;
	int view_select;
	bool view_done = false;

	do{	
		cout << "\n\tStudent View Record Page\n";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> view_select;
		system("CLS");
		switch (view_select)
		{
		case 1:
			file.open("class_102.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 102 Student Records";
			line();
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open()){
				while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud))){
					cout << "\n\n" << stud.first_name << " " << stud.last_name;
					cout << "\t" << stud.gender;
					cout << "\t" << stud.english;
					cout << "/" << stud.maths;
					cout << "/" << stud.science;
					cout << "/" << stud.sports;
					cout << "/" << stud.arts;
					cout << "/" << stud.social;
					cout << "/" << stud.technology;
					stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
					if (stud.learning_progress >= 80){ //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						cout << "\t\tAchieved";
					}
					else if (stud.learning_progress <= 40){
						cout << "\t\tHelp Needed";
					}
					else{
						cout << "\t\tProgressing";
					}
				}
			}
			else{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 2:
			file.open("class_103.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 103 Student Records";
			line();
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open()){
				while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
				{
					cout << "\n\n" << stud.first_name << " " << stud.last_name;
					cout << "\t" << stud.gender;
					cout << "\t" << stud.english;
					cout << "/" << stud.maths;
					cout << "/" << stud.science;
					cout << "/" << stud.sports;
					cout << "/" << stud.arts;
					cout << "/" << stud.social;
					cout << "/" << stud.technology;
					stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
					if (stud.learning_progress >= 80){ //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						cout << "\t\tAchieved";
					}
					else if (stud.learning_progress <= 40){
						cout << "\t\tHelp Needed";
					}
					else{
						cout << "\t\tProgressing";
					}
				}
			}
			else{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 3:
			file.open("class_104.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 104 Student Records";
			line();
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open()){
				while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud))){
					cout << "\n\n" << stud.first_name << " " << stud.last_name;
					cout << "\t" << stud.gender;
					cout << "\t" << stud.english;
					cout << "/" << stud.maths;
					cout << "/" << stud.science;
					cout << "/" << stud.sports;
					cout << "/" << stud.arts;
					cout << "/" << stud.social;
					cout << "/" << stud.technology;
					stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
					if (stud.learning_progress >= 80){ //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						cout << "\t\tAchieved";
					}
					else if (stud.learning_progress <= 40){
						cout << "\t\tHelp Needed";
					}
					else{
						cout << "\t\tProgressing";
					}
				}
			}
			else{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 4: view_done = true;
				break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}
	} while (!view_done);
}

void parent_login(char username_p[15], char password_p[15])
{
	int pt_selection;
	bool pt_done=  false;

	file.open("parent_files.dat", ios::in | ios::binary);	    //Opening in read mode

	if (file.is_open())
	{
		cin.ignore();
		cout << "\n\n\tEnter Parent Username : ";
		cin.getline(username_p, 15);
		cout << "\n\tEnter Parent Password : ";
		cin.getline(password_p, 15);

		while (!file.eof())
		{
			file.read(reinterpret_cast<char*>(&paren), sizeof(paren)); //Reading the content from the file 
			if ((strcmp(username_p, paren.username) == 0) && (strcmp(password_p, paren.password) == 0)) //Matching user input with information stored on file
			{
				cout << "\n\tLogin Successful";

				do
				{
					system("CLS");
					line();
					cout << "\t\tParent Info Screen";
					cout << "\n\t1.Child Report.";
					cout << "\n\t2.School Notices.";
					cout << "\n\t3.Return to Home Page.\n";
					line();
					cout << "\n\n\tPlease enter choice : ";
					cin >> pt_selection;
					switch (pt_selection)
					{
					case 1: student_report(parstu_search);
						break;
					case 2: school_notices();
						break;
					case 3: main();
						break;
					default: cout << "\n\tPlease enter correct option.\n";
						break;
					}
				} while (!pt_done);

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

void student_report(char parstu_search[30])
{
	fstream file;
	student stud;
	int report_select;
	bool report_done = false;

	do
	{
		cout << "\n\n\tStudent Report Page\n";
		cout << "\n\tPlease Select your childs class";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> report_select;

		switch (report_select)
		{
		case 1:
			file.open("class_102.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(parstu_search, 30);
			if (file.is_open())
			{
				while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
				{

					//file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(parstu_search, stud.last_name) == 0))
					{
						cout << "\n\tRecord Found: \n\n";
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
						cout << "\n\n" << stud.first_name << " " << stud.last_name;
						cout << "\t" << stud.gender;
						cout << "\t" << stud.english;
						cout << "/" << stud.maths;
						cout << "/" << stud.science;
						cout << "/" << stud.sports; //this part is to display the record
						cout << "/" << stud.arts;
						cout << "/" << stud.social;
						cout << "/" << stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\t\tAchieved\n\n";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\t\tHelp Needed\n\n";
						}
						else
						{
							cout << "\t\tProgressing\n\n";
						}

						file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary
						break;
					} // i want to change to the last record

				}
			}
			else
			{
				cout << "\nFile unable to access ....\n\n";
			}
			file.close();
			system("pause");
			break;
		case 2:
			file.open("class_103.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(parstu_search, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(parstu_search, stud.last_name) == 0))
					{
						cout << "\n\tRecord Found: \n\n";
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
						cout << "\n\n" << stud.first_name << " " << stud.last_name;
						cout << "\t" << stud.gender;
						cout << "\t" << stud.english;
						cout << "/" << stud.maths;
						cout << "/" << stud.science;
						cout << "/" << stud.sports; //this part is to display the record
						cout << "/" << stud.arts;
						cout << "/" << stud.social;
						cout << "/" << stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\t\tAchieved\n\n";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\t\tHelp Needed\n\n";
						}
						else
						{
							cout << "\t\tProgressing\n\n";
						}

						file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary
						break;
					} // i want to change to the last record

				}
			}
			else
			{
				cout << "\nFile unable to access ....\n\n";
			}
			file.close();
			system("pause");
			break;
		case 3:
			file.open("class_104.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(parstu_search, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(parstu_search, stud.last_name) == 0))
					{
						cout << "\n\tRecord Found: \n\n";
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
						cout << "\n\n" << stud.first_name << " " << stud.last_name;
						cout << "\t" << stud.gender;
						cout << "\t" << stud.english;
						cout << "/" << stud.maths;
						cout << "/" << stud.science;
						cout << "/" << stud.sports; //this part is to display the record
						cout << "/" << stud.arts;
						cout << "/" << stud.social;
						cout << "/" << stud.technology;
						stud.learning_progress = (stud.english + stud.maths + stud.science + stud.sports + stud.arts + stud.social + stud.technology) / 7;
						if (stud.learning_progress >= 80) //We display the Achieve/Progressing/Help with if else structure instead of storing it in file as Achieve/Progressing/Help
						{
							cout << "\t\tAchieved\n\n";
						}
						else if (stud.learning_progress <= 40)
						{
							cout << "\t\tHelp Needed\n\n";
						}
						else
						{
							cout << "\t\tProgressing\n\n";
						}

						file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary
						break;
					} // i want to change to the last record

				}
			}
			else
			{
				cout << "\nFile unable to access ....\n\n";
			}
			file.close();
			system("pause");
			break;
		case 4: report_done = true;
			break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}
	} while (!report_done);
}

void school_notices()
{
	cout << "\n\n\t\tSchool Notices";
	cout << "\n\n\t -Parent and Teacher school meetings will be held on the";
	cout << "\n\tfollowing dates : 20th of April / 20th of July / 20th of ";
	cout << "\n\tOctober. In these meetings we can discuss your childs pro-";
	cout << "\n\tgress at the school, any questions you may have about the ";
	cout << "\n\tteacher or the school.";
	cout << "\n\n\t -We will be holding Summer classes at the end of the s-";
	cout << "\n\tchool year if you wish to enroll your child to do extra s-";
	cout << "\n\ttudying you can contact us on via our phone to set up enr-";
	cout << "\n\tollment.";
	cout << "\n\n\t -If you want more information about school events you ";
	cout << "\n\tsearch all the information on the front page.\n\n";
	system("pause");
}

void contact() {
	system("CLS");
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
	system("CLS");
}

void term_dates() {
	system("CLS");
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
	system("CLS");
}

void events() {
	system("CLS");
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
	system("CLS");
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