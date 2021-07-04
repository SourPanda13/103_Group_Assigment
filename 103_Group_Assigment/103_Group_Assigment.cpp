// 103App_Brittany_Tim_Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//103 Group Project 
//Brittany Armstrong 270080234
//Timothy Boyd 270043384


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

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
	char last_name[30];
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

struct student
{
	char first_name[30];
	char last_name[30];
	char parent_fullname[60];
	char parent_number[20];
	char gender[2];
	int english; // All student marks will be marked 0-100
	int maths;
	int science;
	int sports;
	int arts; //includes art/music/dancing
	int social; //includes history/religous studies/languages
	int technology; //includes IT/graphics/design/
	int learning_progress; //learning progress will be stored as a number-a if else will be used to displat achieve/progressing/help
}stud;

// Front page Functions
void login();
void term_dates();
void events();
void contact();
void admin_login();
void line();

//Registration/Login functions for teacher and parents
void teacher_registration(struct teacher&); //function to input and write teacher information into teacher.dat file
void parent_registration(struct parent&); //function to input and write parent information into teacher.dat file
void teacher_login(char[], char[]); //function to match user input with teacher information from file
void parent_login(char[], char[]); //function to match user input with parent information from file
char username_t[15];	//teacher username
char password_t[15];	//teacher password
char username_p[15];	//parent username
char password_p[15];	//parent password

//Teacher Student Record Functions
void add_record(struct student&);
void view_record();
void edit_record(char[], char[]);
void delete_record(char[], char[]);
char search_f[30], search_l[30];
int position = 0;

//Parent Login Functions
void student_report(char[]);
void school_notices();
char parstu_search[15];

//Admin Funtions
void admin_viewsturec();
void admin_viewparrec();
void report_help();
void report_progressing();



bool flag = false;
fstream file, tempfile;

int main()
{
	int selection;
	bool done = false;

	do
	{
		system("CLS"); //this clears the screen, makes the output look aesthetically better. used thoughout the program
		line();
		cout << "\n\t\t\tSymonds Street Secondary School\n"; //Name of our secondary school
		line();
		cout << "\n\n\tSymonds School is New Zealand's largest specialist creative and\n\ttechnology college.We've been fuelling the creative and \n\ttechnology industries for over 30 years with talented Animators,\n\tFilmmakers, Designers, Techies, and Game Developers.";
		cout << "\n\n\tWelcome to the Home Page\n\tPlease pick an option for more details.\n\n"; //This is the main menu page with which leads to different funtions, this paragraph is just the basic information of school
		cout << "\n\t1. Registration & Login.";
		cout << "\n\t2. Contact Details.";
		cout << "\n\t3. Term Dates.";
		cout << "\n\t4. Latest & Upcoming Events.";
		cout << "\n\t5. Exit.";
		cout << "\n\n\t6. Admin Login.\n";
		line();
		cout << "\n\tPlease enter choice : ";
		cin >> selection; //take user input to select menu option


		switch (selection) //switch case used to simulate menu, this is used a lot through out the program
		{
		case 1: login();
			break;
		case 2: contact();
			break;
		case 3: term_dates();
			break;
		case 4: events();
			break;
		case 5: cout << "\n\tThank you for visiting Symonds Street Secondary School website."; //this option exits the main program, display farewell message before ending program
			cout << "\n\tHope to see you soon!\n";
			line();
			done = true;
			break;
		case 6: admin_login();
			break;
		default: cout << "\n\tI'm sorry please enter a correct option.\n";
			break;
		}
	} while (!done);//performs menu while boolean value reads false;
	return 0;
}

void term_dates()//simple cout structure that display school term dates
{
	system("CLS");
	line();
	cout << "\t\tTerm Dates Page";
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
	cout << "\n\tTerm 4 School Holidays : 11th of December - 9th of Febuary 2022.\n";
	line();
	system("pause");//this pauses program so user can read information, to resume application user inputs any key. this will return user back to main function, this is used though out the program.
	system("CLS");
}

void events()//simple cout structure that display school events and dates
{
	system("CLS");
	line();
	cout << "\t\tLatest & Upcoming Events Page";
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
	cout << "\n\t - Marathon Run for Kids : 22nd of June.\n";
	line();
	system("pause");
	system("CLS");
}

void contact()//simple cout structure that display school details
{
	system("CLS");
	line();
	cout << "\t\tContact Us Page";
	cout << "\n\n\tHere is our contact details.";
	cout << "\n\tYou can call Symonds Street Secondary School at 0800 66 55 44 for free.";
	cout << "\n\tAuckland Campus : ";
	cout << "\n\tAuckland City Road";
	cout << "\n\tLevel 4,3 City Road, Grafton";
	cout << "\n\tAuckland 1010.";
	cout << "\n\tEmail : Symonds@symonds.com\n";
	line();
	system("pause");
	system("CLS");
}

void login()//this leads user to the login and registration page for both parents and teachers.
{
	int login_selection;
	bool login_done = false;

	do
	{
		system("CLS");
		line();
		cout << "\t\tLogin Screen";
		cout << "\n\n\t1. New Teacher Sign Up.";
		cout << "\n\t2. New Parent Sign up.";
		cout << "\n\t3. Teacher Sign In.";
		cout << "\n\t4. Parent Sign In.";
		cout << "\n\t5. Return to Home Page.\n";
		line();
		cout << "\n\n\tPlease enter choice : ";
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
		case 5: login_done = true; //sets boolean value to true, returns user to main page
			break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}
	} while (!login_done);
}

void admin_login()//this is main admin page
{
	int guess = 0;//initializing variable to 0
	int name_input, pass_input;
	int admin_name = 1; //set to a simple number just for this example, can be changed later
	int admin_pass = 1; //set to a simple number just for this example, can be changed later
	int admin_select;
	bool admin_done = false;

	while (guess < 3) //while guess is less than 3 it will repeat process
	{
		cout << "\n\n\t\tAdmin Login Screen\n";
		cout << "\n\tEnter Username : ";
		cin >> name_input;
		cout << "\n\tEnter Password : ";
		cin >> pass_input;
		if (name_input == admin_name && pass_input == admin_pass) //only access admin home screen if username password matches
		{
			do
			{
				system("CLS");
				line();
				cout << "\n\t\tAdmin Home Screen";
				cout << "\n\n\t1. Class Records.";
				cout << "\n\t2. Parent Records.";
				cout << "\n\t3. Student Report for 'Help Needed'.";
				cout << "\n\t4. Student Report for 'Progressing'.";
				cout << "\n\t5. Return to Home Page.\n";
				line();
				cout << "\n\n\tPlease enter choice : ";
				cin >> admin_select;

				switch (admin_select)
				{
				case 1: admin_viewsturec();
					break;
				case 2: admin_viewparrec();
					break;
				case 3: report_help();
					break;
				case 4: report_progressing();
					break;
				case 5: admin_done = true;
					break;
				default: "\n\tPlease enter correct option.\n";
					break;
				}
			} while (!admin_done);
			break;
		}
		else if (guess < 2) //displays message if username password dont match
		{
			cout << "\n\tSorry, try again\n";
		}
		else
		{
			cout << "\n\tYou have reached the max number password attempts\n\tPlease try again later.";//displays maximum attempts reached
			system("pause");

		}
		guess++;//used to reach max guess count
	}
}

void line() //simple line structure, used to be aesthetically pleasing
{
	cout << "\n";
	for (int i = 0; i < 80; i++) {
		cout << "*";
	}
	cout << "\n";
}

void teacher_registration(struct teacher& teach) // teacher registration function, used to follow teacher structure, pointer used to specifically access this information
{
	system("CLS");
	fstream file; //initializes file
	file.open("teacher_files.dat", ios::out | ios::app | ios::binary); //used to create teacher files

	cout << "\n\tTeacher Sign Up";
	cout << "\n\tPlease Enter your information.";
	cin.ignore();

	cout << "\n\n\tFull Name : ";
	cin.getline(teach.full_name, 60); //inputs teacher records, with char array set to 60
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
	system("pause");
	file.write(reinterpret_cast<char*>(&teach), sizeof(teach)); // storing record in binary

	file.close();
}

void parent_registration(struct parent& paren) // parent registration function, used to follow teacher structure, pointer used to specifically access this information
{
	system("CLS");
	fstream file;
	file.open("parent_files.dat", ios::out | ios::app | ios::binary); //used to create parent files

	cout << "\n\tParent Sign Up";
	cout << "\n\tPlease Enter your information.";
	cin.ignore();

	cout << "\n\n\tFirst Name : ";
	cin.getline(paren.first_name, 30); //inputs parent records, with char array set to 30
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
	cout << "\tChild Class room (xxx) : ";
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
	system("pause");
	file.write(reinterpret_cast<char*>(&paren), sizeof(paren)); //Storing record in binary

	file.close();
}

void teacher_login(char username_t[15], char password_t[15]) //teacher login function,  intiliazing username and password input to char 15 array
{
	fstream file;
	int student_selection;
	bool student_done = false;
	int count = 1; //set to 1, used to simulate password attempts
	file.open("teacher_files.dat", ios::in | ios::binary);		//Opening in read mode

	if (file.is_open())
	{
	readagain: //this repeats the password attempt
		cin.ignore();
		cout << "\n\n\tEnter Teacher Username : ";
		cin.getline(username_t, 15); //takes userinput
		cout << "\n\tEnter Teacher Password : ";
		cin.getline(password_t, 15);

		while (!file.eof()) //does program while not at the end of file
		{
			file.read(reinterpret_cast<char*>(&teach), sizeof(teach)); //Reading the content from the file 
			if ((strcmp(username_t, teach.username) == 0) && (strcmp(password_t, teach.password) == 0)) //Matching user input with information stored on file
			{
				student stud; //access student structure
				int st_selection;
				bool st_done = false;
				system("CLS");
				cout << "\n\tLogin Successful\n";
				do
				{
					system("CLS");
					line();
					cout << "\t\tStudent Record Screen";
					cout << "\n\n\t1. Add Student.";
					cout << "\n\t2. Edit/Update Student Record.";
					cout << "\n\t3. Delete Student Record.";
					cout << "\n\t4. View the Records.";
					cout << "\n\t5. Return to Login Screen.\n";
					line();
					cout << "\n\n\tPlease enter choice : ";
					cin >> st_selection;
					system("CLS");

					switch (st_selection)
					{
					case 1: add_record(stud);
						break;
					case 2: edit_record(search_f, search_l);
						break;
					case 3: delete_record(search_f, search_l);
						break;
					case 4: view_record();
						break;
					case 5: st_done = true;
						break;
					default: cout << "\n\tPlease enter correct option.\n";
						break;
					}
				} while (!st_done);
				cout << "\n\n\tThat's all the information in the file for the search key provided!\n";
				flag = false;
				break;
				cout << "\n\n\n";
			}
			else
			{
				if (count < 3) //does attempts while less than 3
				{
					count++;
					goto readagain; //starts password attempt
				}
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
		cout << "\n\tSorry you have exceeded the limit, try again later.\n"; //display message stating max limit reached
		system("pause");

	}
	file.close(); //close file
}

void parent_login(char username_p[15], char password_p[15]) //parent login function,  intiliazing username and password input to char 15 array
{
	fstream file;
	int count = 1;
	file.open("parent_files.dat", ios::in | ios::binary);	    //Opening in read mode

	if (file.is_open())
	{
	readagain:
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
				int pt_selection;
				bool pt_done = false;

				do
				{
					system("CLS");
					line();
					cout << "\t\tParent Info Screen";
					cout << "\n\n\t1.Child Report.";
					cout << "\n\t2.School Notices.";
					cout << "\n\t3.Return to Login.\n";
					line();
					cout << "\n\n\tPlease enter choice : ";
					cin >> pt_selection;
					switch (pt_selection)
					{
					case 1: student_report(parstu_search);
						break;
					case 2: school_notices();
						break;
					case 3: pt_done = true;
						break;
					default: cout << "\n\tPlease enter correct option.\n";
						break;
					}
				} while (!pt_done);
				flag = false;
				break;
			}
			else
			{
				if (count < 3)
				{
					count++;
					goto readagain;
				}
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
		cout << "\n\tSorry you have exceeded the limit, try again later.\n";
		system("pause");

	}
	file.close();
}


void add_record(struct student& stud) //add student record, accessed in teacher page, uses student structure
{
	fstream file;
	int add_select;
	bool add_done = false;

	do
	{
		cout << "\n\n\tStudent Add Record Page\n"; //menu page, we are using 3 classes with 3 seperate class files
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> add_select;

		switch (add_select)
		{
		case 1:
			file.open("class_102.dat", ios::out | ios::app | ios::binary); // Class File 102
			cout << "\n\n\tClass 102 Record.";
			cout << "\n\tPlease Enter student information.";
			cin.ignore();
			cout << "\n\tFirst Name : ";
			cin.getline(stud.first_name, 30);
			cout << "\tLast Name : ";
			cin.getline(stud.last_name, 30);
			cout << "\tParent Full Name : ";
			cin.getline(stud.parent_fullname, 60);
			cout << "\tParent Contact Number : ";
			cin.getline(stud.parent_number, 20);
			cout << "\tGender (M/F/O) : ";
			cin.getline(stud.gender, 2);
			cout << "\tEnglish Mark (0-100) : ";
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
			file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary

			file.close();
			break;
		case 2:
			file.open("class_103.dat", ios::out | ios::app | ios::binary); // Class File 103
			cout << "\n\n\tClass 103 Record.";
			cout << "\n\tPlease Enter student information.";
			cin.ignore();
			cout << "\n\tFirst Name : ";
			cin.getline(stud.first_name, 30);
			cout << "\tLast Name : ";
			cin.getline(stud.last_name, 30);
			cout << "\tParent Full Name : ";
			cin.getline(stud.parent_fullname, 60);
			cout << "\tParent Contact Number : ";
			cin.getline(stud.parent_number, 20);
			cout << "\tGender (M/F/O) : ";
			cin.getline(stud.gender, 2);
			cout << "\tEnglish Mark (0-100) : ";
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
			file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary

			file.close();
			break;
		case 3:
			file.open("class_104.dat", ios::out | ios::app | ios::binary); // Class File 104
			cout << "\n\n\tClass 104 Record.";
			cout << "\n\tPlease Enter student information.";
			cin.ignore();
			cout << "\n\tFirst Name : ";
			cin.getline(stud.first_name, 30);
			cout << "\tLast Name : ";
			cin.getline(stud.last_name, 30);
			cout << "\tParent Full Name : ";
			cin.getline(stud.parent_fullname, 60);
			cout << "\tParent Contact Number : ";
			cin.getline(stud.parent_number, 20);
			cout << "\tGender (M/F/O) : ";
			cin.getline(stud.gender, 2);
			cout << "\tEnglish Mark (0-100) : ";
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
			file.write(reinterpret_cast<char*>(&stud), sizeof(stud)); // storing record in binary

			file.close();
			break;
		case 4: add_done = true;
			break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}

	} while (!add_done);
}

void view_record() //student view record, accessed in teacher page
{
	fstream file;
	student stud;
	int view_select;
	bool view_done = false;

	do
	{
		cout << "\n\tStudent View Record Page\n"; //menu page, we are using 3 classes with 3 seperate class files
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
			file.open("class_102.dat", ios::in | ios::out | ios::binary); //opens class 102 file
			cout << "\n\tClass 102 Student Records";
			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n"; //dislpay legend of what record are being shown
			if (file.is_open()) //starts process when file is open
			{
				while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud))) //turns binary to normal text that can be read
				{
					cout << "\n\n" << stud.first_name << " " << stud.last_name; //displays student record from file
					cout << "\t" << stud.gender;
					cout << "\t" << stud.english;
					cout << "/" << stud.maths;
					cout << "/" << stud.science;
					cout << "/" << stud.sports;
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

				}
			}
			else
			{
				cout << "\n\nFile unable to access.....\n\n"; //displays if no record ion file
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 2:
			file.open("class_103.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 103 Student Records";
			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open())
			{
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

				}
			}
			else
			{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 3:
			file.open("class_104.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 104 Student Records";
			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open())
			{
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

				}
			}
			else
			{
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

void edit_record(char search_f[30], char search_l[30]) //student edit record to change record, uses input from user 
{
	student stud;
	fstream file;
	int edit_select;
	bool edit_done = false;
	do
	{
		cout << "\n\n\tStudent Edit/Update Record Page\n";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> edit_select;

		switch (edit_select)
		{
		case 1:
			file.open("class_102.dat", ios::in | ios::out | ios::binary); //open file in read write
			cout << "\n\tSearch Student in Class 102\n";
			cin.ignore();
			cout << "\n\tEnter Student First Name : ";
			cin.getline(search_f, 30); //takes user input
			cout << "\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));
					position = file.tellg(); //puts position of cursor if first name and last name matches
					// do you want me to send this part of the code you? via notepad 
					if ((strcmp(search_f, stud.first_name) == 0) && (strcmp(search_l, stud.last_name) == 0)) //if username and password matches, follows the rest of the function
					{
						cout << "\n\tRecord Found: \n\n";//this part is to display the record
						cout << "\n***************************************************************************\n\n";
						cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
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

						file.seekp(position - (sizeof(stud))); //puts position to record you want to change and overwrites it
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
					}

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
			cout << "\n\tSearch Student in Class 103\n";
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

						file.seekp(position - (sizeof(stud)));  //puts position to record you want to change and overwrites it
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
					}

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
			cout << "\n\tSearch Student in Class 104\n";
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
					}

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

void delete_record(char search_f[30], char search_l[30]) //student delete funtion
{
	student stud;
	fstream file, tempfile; //for this function we have a temp file, we use it to store the new record with the deleted record not displaying
	int edit_select1;
	bool edit_done1 = false;
	int count = 0; //intializing count
	do
	{
		cout << "\n\n\tStudent Delete Record Page\n";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> edit_select1;

		switch (edit_select1)
		{
		case 1:
			file.open("class_102.dat", ios::in | ios::out | ios::binary); //opening file in read write
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

					while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
					{
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
							cout << "/" << stud.sports;
							cout << "/" << stud.arts;
							cout << "/" << stud.social;
							cout << "/" << stud.technology;

						}
						else
						{
							count++; //stores other records
							tempfile.open("temp1.dat", ios::out | ios::app | ios::binary); // opening in a read mode
							tempfile.write(reinterpret_cast<char*>(&stud), sizeof(stud));//storing record on temp file
							tempfile.close();

						}
					}
				}
			}
			//cout << "\n\n No of records stored : " << count;
			file.close();
			cout << "\nDisplay the records after deletion";
			tempfile.open("temp1.dat", ios::in | ios::binary | ios::beg); // opening in a read mode, temp for class 102

			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";

			while (tempfile.read(reinterpret_cast<char*>(&stud), sizeof(stud))) // reading the content from the file 
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
				cout << "\n\n";
			}
			tempfile.close();
			system("pause");
			break;
		case 2:
			file.open("class_103.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 103\n";
			cin.ignore();
			cout << "\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
					{
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
							cout << "/" << stud.sports;
							cout << "/" << stud.arts;
							cout << "/" << stud.social;
							cout << "/" << stud.technology;

						}
						else
						{
							count++;
							tempfile.open("temp2.dat", ios::out | ios::app | ios::binary); // opening in a read mode
							tempfile.write(reinterpret_cast<char*>(&stud), sizeof(stud));
							tempfile.close();

						}
					}
				}
			}
			//cout << "\n\n No of records stored : " << count;
			file.close();
			cout << "\nDisplay the records after deletion";
			tempfile.open("temp2.dat", ios::in | ios::binary | ios::beg); // opening in a read mode , temp for class 103

			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";

			while (tempfile.read(reinterpret_cast<char*>(&stud), sizeof(stud))) // reading the content from the file 
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
				cout << "\n\n";
			}
			tempfile.close();
			system("pause");
			break;
		case 3:
			file.open("class_104.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tSearch Student in Class 104\n";
			cin.ignore();
			cout << "\n\tEnter Student First Name : ";
			cin.getline(search_f, 30);
			cout << "\tEnter Student Last Name : ";
			cin.getline(search_l, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
					{
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
							cout << "/" << stud.sports;
							cout << "/" << stud.arts;
							cout << "/" << stud.social;
							cout << "/" << stud.technology;

						}
						else
						{
							count++;
							tempfile.open("temp3.dat", ios::out | ios::app | ios::binary); // opening in a read mode , temp for class 102
							tempfile.write(reinterpret_cast<char*>(&stud), sizeof(stud));
							tempfile.close();

						}
					}
				}
			}
			//cout << "\n\n No of records stored : " << count;
			file.close();
			cout << "\nDisplay the records after deletion";
			tempfile.open("temp3.dat", ios::in | ios::binary | ios::beg); // opening in a read mode

			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";

			while (tempfile.read(reinterpret_cast<char*>(&stud), sizeof(stud))) // reading the content from the file 
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
				cout << "\n\n";
			}
			tempfile.close();
			system("pause");
			break;
		case 4: edit_done1 = true;
			break;
		default: "\n\tPlease enter correct option.\n";
			break;
		}

	} while (!edit_done1);
}

void student_report(char parstu_search[30]) //student record display page for parent to see child record
{
	fstream file;
	student stud;
	int report_select;
	bool report_done = false;

	do
	{
		cout << "\n\n\tStudent Report Page\n"; //menu for parents to choose class
		cout << "\n\tPlease Select your childs class";
		cout << "\n\n\t1. Class 102.";
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

					if ((strcmp(parstu_search, stud.last_name) == 0)) //if user input matches student last name from file, you can see students record
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
					}

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
			cout << "\n\tSearch Student in Class 103\n";
			cin.ignore();
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(parstu_search, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));

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
					}

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
			cout << "\n\tSearch Student in Class 104\n";
			cin.ignore();
			cout << "\n\tEnter Student Last Name : ";
			cin.getline(parstu_search, 30);
			if (file.is_open())
			{
				while (!file.eof())
				{

					file.read(reinterpret_cast<char*>(&stud), sizeof(stud));

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
					}

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

void school_notices() //simple cout structure, this is for parents page, shows school notices
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

void admin_viewsturec() //admin view record page, displays all student records in all classes
{
	fstream file;
	student stud;
	int view_select1;
	bool view_done1 = false;

	do
	{
		cout << "\n\tStudent View Record Page\n";
		cout << "\n\t1. Class 102.";
		cout << "\n\t2. Class 103.";
		cout << "\n\t3. Class 104.";
		cout << "\n\t4. Return to previous page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> view_select1;

		switch (view_select1)
		{
		case 1:
			file.open("class_102.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 102 Student Records";
			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open())
			{
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

				}
			}
			else
			{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 2:
			file.open("class_103.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 103 Student Records";
			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open())
			{
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

				}
			}
			else
			{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 3:
			file.open("class_104.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tClass 104 Student Records";
			cout << "\n***************************************************************************\n\n";
			cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Learning Progress\n";
			if (file.is_open())
			{
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

				}
			}
			else
			{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			file.close();
			break;
		case 4: view_done1 = true;
			break;
		default: cout << "\n\tPlease enter correct option.\n";
			break;
		}
	} while (!view_done1);
}

void admin_viewparrec() //accessed on admin page, this displays all parents records
{
	fstream file;
	parent paren;
	int view_select2;
	int view_done2 = false;

	do
	{
		cout << "\n\n\t\tParent View Record Page";
		cout << "\n\n\t1. Parent Record.";
		cout << "\n\t2. Return to Previous Page.";
		cout << "\n\n\tPlease select from menu : ";
		cin >> view_select2;

		switch (view_select2)
		{
		case 1:
			file.open("parent_files.dat", ios::in | ios::out | ios::binary);
			cout << "\n\tParent Records";
			cout << "\n***************************************************************************";
			if (file.is_open())
			{
				while (file.read(reinterpret_cast<char*>(&paren), sizeof(paren)))
				{
					cout << "\n\nFull Name : " << paren.first_name << " " << paren.last_name; //displays all records from parent file
					cout << "\nGender(M/F/O) : " << paren.gender;
					cout << "\nDate of Birth : " << paren.DOB;
					cout << "\nEmail : " << paren.email;
					cout << "\nPhone Number : " << paren.phone_number;
					cout << "\nChild Full Name : " << paren.child_fname;
					cout << "\nChild Class room : Class " << paren.child_class;
					cout << "\nEmergency Contact Name : " << paren.emer_contactname;
					cout << "\nEmergency Contact Number : " << paren.emer_contactnum;
					cout << "\nUsername : " << paren.username;
					cout << "\nPassword : " << paren.password;
				}
				file.close();
			}
			else
			{
				cout << "\n\nFile unable to access.....\n\n";
			}
			cout << "\n\n\n";
			//file.close();
			break;
		case 2: view_done2 = true;
			break;
		default: "\n\tPlease enter correct option.\n";
			break;
		}
	} while (!view_done2);
}

void report_help() //admin function that displays all students with help needed as learning progress
{
	fstream file;
	student stud;
	teacher teach;
	file.open("class_102.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tClass 102 Student Report for 'Help Needed'";
	cout << "\n***************************************************************************\n\n";
	cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Parent Number\n";
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
		{
			if (stud.learning_progress <= 40) //access file, only displays record if learning progress is less than or equal to 40
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
				cout << "\t" << stud.parent_number;
			}
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n";
	system("pause");

	file.open("class_103.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tClass 103 Student Report for 'Help Needed'";
	cout << "\n***************************************************************************\n\n";
	cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Parent Number\n";
	if (file.is_open())
	{

		while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
		{
			if (stud.learning_progress <= 40)
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
				cout << "\t" << stud.parent_number;
			}
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n";
	system("pause");

	file.open("class_104.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tClass 104 Student Report for 'Help Needed'";
	cout << "\n***************************************************************************\n\n";
	cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Parent Number\n";
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
		{
			if (stud.learning_progress <= 40)
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
				cout << "\t" << stud.parent_number;
			}
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n";
	system("pause");

	file.open("teacher_files.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tTeacher and Class they teach";
	cout << "\n***************************************************************************\n\n";
	cout << "Teacher Full Name--Classroom Number\n";
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&teach), sizeof(teach))) // this display all teacher records form teacher file, shows name and class they teach
		{
			cout << "\n\n" << teach.full_name;
			cout << "\t" << teach.classroom;
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n\n";
	system("pause");

}

void report_progressing() //admin function that displays all students with progress as learning progress
{
	fstream file;
	student stud;
	teacher teach;
	file.open("class_102.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tClass 102 Student Report for 'Help Needed'";
	cout << "\n***************************************************************************\n\n";
	cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Parent Number\n";
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
		{
			if (stud.learning_progress >= 41 && stud.learning_progress <= 79) //access file, only displays record if learning progress is less than or equal to 79 and greaters than or equal to 41
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
				cout << "\t" << stud.parent_number;
			}
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n";
	system("pause");

	file.open("class_103.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tClass 103 Student Report for 'Help Needed'";
	cout << "\n***************************************************************************\n\n";
	cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Parent Number\n";
	if (file.is_open())
	{

		while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
		{
			if (stud.learning_progress >= 41 && stud.learning_progress <= 79)
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
				cout << "\t" << stud.parent_number;
			}
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n";
	system("pause");

	file.open("class_104.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tClass 104 Student Report for 'Help Needed'";
	cout << "\n***************************************************************************\n\n";
	cout << "Student Full Name--Gender--Eng/Mat/Sci/Spo/Art/Soc/Tec--Parent Number\n";
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&stud), sizeof(stud)))
		{
			if (stud.learning_progress >= 41 && stud.learning_progress <= 79)
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
				cout << "\t" << stud.parent_number;
			}
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n";
	system("pause");

	file.open("teacher_files.dat", ios::in | ios::out | ios::binary);
	cout << "\n\tTeacher and Class they teach";
	cout << "\n***************************************************************************\n\n";
	cout << "Teacher Full Name--Classroom Number\n";
	if (file.is_open())
	{
		while (file.read(reinterpret_cast<char*>(&teach), sizeof(teach)))
		{
			cout << "\n\n" << teach.full_name; // this display all teacher records form teacher file, shows name and class they teach
			cout << "\t" << teach.classroom;
		}
	}
	else
	{
		cout << "\n\nFile unable to access.....\n\n";
	}
	file.close();
	cout << "\n\n\n";
	system("pause");

}