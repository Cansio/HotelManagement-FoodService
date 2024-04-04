#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;
void head()
{
	cout << " \n\t\t\t***********************************";
	cout << " \n\t\t\t* ROOM SERVICE MANAGEMENT PROJECT *";
	cout << " \n\t\t\t***********************************";
	cout << endl;
}
class room
{
	public:
	int rate1 = 1500, rate2 = 3000;
	int days1[50] = { 10,12,14,8,2 };
	int days2[50] = { 10,12,14 };
	int normcount = 4;
	int premcount = 2; ;
	int normstatus[50] = { 1,1,1,1,1 };
	int normfoodstatus[50] = { 0 };
	int premfoodstatus[50] = { 0 };
	int premstatus[50] = { 1,1,1 };
	int roomno1[50] = { 100,101,102,103,104 };
	int roomno2[50] = { 200,201,202 };
	string name1[50] = { "Alex Fernandes","Siraj chodankar","Pravin tupkar","Yash 
	Malgaonkar","Hasan Sheik" };
	string name2[50] = { "Sasha Naik","Ramesh Sawant","Trupthi Pednekar" };
	string address1[50] = {
	"Panjim,Goa","Talegao,Goa","Mapusa,Goa","Margao,Goa","Porvorim,Goa" };
	string address2[50] = { "Cortalim,Goa","Parra,Goa","Salcete,Goa" };
	string phoneno1[100] = {
	"9584217541","9584632741","9881314530","9028151385","9689155943"};
	string phoneno2[100] = { "9052472314","9881743625","9635874218" };
	 room()
	 {
	 int normcount = 4;
	 int premcount = 2;
	 }
	void displaycusrec()
	{
	cout << "**Normal Rooms**" << endl;
	cout << setw(30) << left << "ROOM NO";
	cout << setw(30) << left << "NAME";
	cout << setw(30) << left << "ADDRESS";
	 cout << setw(30) << left << "PHONE NUMBER";
	 cout << setw(30) << left << "NO.OF DAYS" << endl;
	for (int i = 0; i <= normcount; i++)
	 {
	 if (normstatus[i] == 1)
	 {
	 cout << setw(30) << left << roomno1[i];
	 cout << setw(30) << left << name1[i];
	 cout << setw(30) << left << address1[i];
	 cout << setw(30) << left << phoneno1[i];
	 cout << setw(30) << left << days1[i];
	 cout << endl;
	 }
	}
	cout << "**Premium Rooms**" << endl;
	cout << setw(30) << left << "ROOM NO";
	cout << setw(30) << left << "NAME";
	cout << setw(30) << left << "ADDRESS";
	 cout << setw(30) << left << "PHONE NUMBER";
	 cout << setw(30) << left << "NO.OF DAYS" << endl;
	for (int i = 0; i <= premcount; i++)
	 {
	 if (premstatus[i] == 1)
	 {
	 cout << setw(30) << left << roomno2[i];
	 cout << setw(30) << left << name2[i];
	 cout << setw(30) << left << address2[i];
	 cout << setw(30) << left << phoneno2[i];
	 cout << setw(30) << left << days2[i];
	 cout << endl;
	 }
	}
	 system("pause");
	}
};
class food :public room
{
	public:
		int ptotalcost[50] = { 0 };
		int ppersonfoodcost[50][10];
		int ppersonquant[50][10];
		int npersonfoodcost[50][10];
		int npersonquant[50][10];
		int ntotalcost[50] = { 0 };
		string ppersonorder[50][10];
		string npersonorder[50][10];
		string foodname[9]{ "softdrinks","tea","coffee","veg biryani","veg thali","paneer 
	   masala","chicken biryani","fish thali","butter chicken" };
		int foodcost[50] = { 50,20,30,200,300,300,300,350,350 };
		void operator ++()
		{
		for (int i = 0; i < 9; i++)
		{
		foodcost[i] += 10;
		}
		cout << "UPDATED MENU" << endl;
		displaymenu();
		system("pause");
		}
		void operator --()
		{
		for (int i = 0; i < 9; i++)
		{
		foodcost[i] -= 10;
		}
		cout << "UPDATED MENU" << endl;
		displaymenu();
		system("pause");
		}
		void displaymenu()
		{
		int choice;
		cout << "***********FOOD MENU***************" << endl;
		cout << setw(30) << left << "No.";
		cout << setw(30) << left << "FOOD ITEMS :";
		cout << setw(30) << left << "COST:" << endl;
		for (int i = 0; i < 9; i++)
		{

		cout << setw(30) << left << i + 1;
		cout << setw(30) << left << foodname[i];
		cout << setw(30) << left << foodcost[i] << endl;
		}
		}
		void orderfood()
		{
		displaymenu();
		int choice1,choice2,choice3;

		int roomn, roomt = 0;
		cout << "ENTER THE TYPE OF ROOM : \n1-normal\n2-premium" << endl;
		cin >> roomt;
		if (roomt == 1)
		{
		cout << "ENTER YOUR ROOM NO:" << endl;
		cin >> roomn;
		int foodcount1 = 0, foodflag = 0;
		for (int i = 0; i <= normcount; i++)
		{
		if (roomn == roomno1[i] && normstatus[i] == 1)
		{
		normfoodstatus[i] = 1;
		foodflag = 1;
		do
		{
		cout << "Enter your choice:";
		cin >> choice1;
		npersonorder[i][foodcount1] = foodname[choice1 - 1];
		cout << "Enter the quantity:";
		cin >> npersonquant[i][foodcount1];
		npersonfoodcost[i][foodcount1] = foodcost[choice1 - 1];
		foodcount1++;
		cout << endl << "do you want to continue..1-Yes/0-No";
		cin >> choice3;
		} while (choice3 != 0);

		cout << setw(30) << left << "FOOD ITEMS";
		cout << setw(30) << left << "QUANTITY";
		cout << setw(30) << left << " COST" << endl;

		for (int j = 0; j < foodcount1; j++)
		{
		cout << setw(30) << left << npersonorder[i][j];
		cout << setw(30) << left << npersonquant[i][j];
		cout << setw(30) << left << npersonfoodcost[i][j] * npersonquant[i][j] << endl;
		ntotalcost[i] = ntotalcost[i] + npersonfoodcost[i][j] * npersonquant[i][j];
		}
		cout << "Total Bill:" << ntotalcost[i] << endl;
		}
		}
		if (foodflag == 0)
		cout << "Invalid room choice" << endl;
		}
		else if (roomt == 2)
		{

		cout << "ENTER YOUR ROOM NO:" << endl;
		cin >> roomn;
		int foodcount2 = 0, foodflag = 0;
		for (int i = 0; i <= normcount; i++)
		{
		premfoodstatus[i] = 1;
		if (roomn == roomno2[i] && premstatus[i] == 1)
		{
		foodflag = 1;
		do
		{
		cout << "Enter your choice:";
		cin >> choice2;
		ppersonorder[i][foodcount2] = foodname[choice2 - 1];
		cout << "Enter the quantity:";
		cin >> ppersonquant[i][foodcount2];
		ppersonfoodcost[i][foodcount2] = foodcost[choice2 - 1];
		foodcount2++;
		cout << "do you want to continue..1.Yes/2.No" << endl;
		cin >> choice3;
		} while (choice3 != 0);
		for (int j = 0; j < foodcount2; j++)
		{
		cout << setw(30) << left << ppersonorder[i][j];
		cout << setw(30) << left << ppersonquant[i][j];
		cout << setw(30) << left << ppersonfoodcost[i][j] * ppersonquant[i][j] << endl;
		ptotalcost[i] = ptotalcost[i] + ppersonfoodcost[i][j] * ppersonquant[i][j];

		}
		cout << "Total Food Bill:" << ptotalcost[i] << endl;
		}
		}

		if (foodflag == 0)
		cout << "Invalid room choice" << endl;

		}

		system("pause");
		}

};
class hotelmanagement : public food
{
	public:
			int roomno, roomtype;
			hotelmanagement()
			{
				roomno = 0, roomtype = 0;
			}
			void normalroom()
			{
				roomno1[normcount + 1] = roomno1[normcount] + 1;
				normcount++;
				cout << "ENTER YOUR NAME:";
				getchar();
				getline(cin, name1[normcount]);
				cout << "ENTER YOUR ADDRESS:";
				getline(cin, address1[normcount]);
				cout << "ENTER YOUR PHONE NUMBER:";
				getline(cin, phoneno1[normcount]);
				cout << "ENTER THE NUMBER OF DAYS : ";
				cin >> days1[normcount];

				normstatus[normcount] = 1;
				cout << "YOUR ROOM NO IS: " << roomno1[normcount] << endl;
				cout << "ROOM BOOKED SUCCESSFULLY!!" << endl;
				system("pause");
			}
			void premiumroom()
			{
				roomno2[premcount + 1] = roomno2[premcount] + 1;
				premcount++;
				cout << "ENTER YOUR NAME:";
				getchar();
				getline(cin, name2[premcount]);
				cout << "ENTER YOUR ADDRESS:";
				getline(cin, address2[premcount]);
				cout << "ENTER YOUR PHONE NO:";
				getline(cin, phoneno2[premcount]);
				cout << "ENTER THE NUMBER OF DAYS : ";
				cin >> days2[premcount];
				premstatus[premcount] = 1;
				cout << "YOUR ROOM NO IS " << roomno2[premcount] << endl;
				cout << "ROOM BOOKED SUCCESFULLY!!" << endl;
				system("pause");
			}
			float expense(int x, int y)
			{
				float totalbill;
				totalbill = x + y;
				return totalbill;
			}
			float expense(int x)
			{
				float totalbill;
				totalbill = x;
				return totalbill;
			}
			void checkout()
			{
				int flag2 = 0;
				cout << "ENTER THE TYPE OF ROOM : \n1-normal\n2-premium";
				cin >> roomtype;
				if (roomtype == 1)
				{
					cout << "ENTER YOUR ROOM NO:" << endl;
					cin >> roomno;
					for (int i = 0; i <= normcount; i++)
					{
						if (roomno == roomno1[i])
						{
							cout << "***********CHECKOUT DETAILS***************" << endl;
							cout << setw(30) << left << "ROOM NO :" << roomno1[i] << endl;
							cout << setw(30) << left << "NAME :" << name1[i] << endl;
							cout << setw(30) << left << "ADDRESS :" << address1[i] << endl;
							cout << setw(30) << left << "PHONE NUMBER :" << phoneno1[i] << endl;
							cout << setw(30) << left << "NO.OF DAYS" << days1[i] << endl;
							int bill = rate1 * days1[i];
							if (normfoodstatus[i] == 1)
							{
								cout << setw(30) << left << "FOOD BILL :" << ntotalcost[i] << endl;
								cout << setw(30) << left << "ROOM BILL :" << bill << endl;
								cout << setw(30) << left << "BILL AMOUNT :" << expense(bill, ntotalcost[i]) << endl;
							}
							else
							{
								cout << setw(30) << left << "FOOD BILL :" << 0 << endl;
								cout << setw(30) << left << "ROOM BILL :" << bill << endl;
								cout << setw(30) << left << "BILL AMOUNT :" << expense(bill) << endl;
							}
							roomno1[i] = 0;
							name1[i] = "\0";
							address1[i] = "\0";
							phoneno1[i] = "\0";
							normstatus[i] = 0;
							flag2 = 1;
						}
					}
					if (flag2 == 0)
					{
						cout << "ROOM NOT AVAILABLE.." << endl;
					}
				}
				else if (roomtype == 2)
				{
					cout << "ENTER YOUR ROOM NO:" << endl;
					cin >> roomno;
					for (int i = 0; i <= premcount; i++)
					{
						if (roomno == roomno2[i])
						{
							cout << "***********CHECKOUT DETAILS***************" << endl;
							cout << setw(30) << left << "ROOM NO :" << roomno2[i] << endl;
							cout << setw(30) << left << "NAME :" << name2[i] << endl;
							cout << setw(30) << left << "ADDRESS :" << address2[i] << endl;
							cout << setw(30) << left << "PHONE NUMBER :" << phoneno2[i] << endl;
							cout << setw(30) << left << "NO.OF DAYS" << days2[i] << endl;
							int bill = rate2 * days2[i];
							if (premfoodstatus[i] == 1)
							{
								cout << setw(30) << left << "FOOD BILL :" << ptotalcost[i] << endl;
								cout << setw(30) << left << "ROOM BILL :" << bill << endl;
								cout << setw(30) << left << "BILL AMOUNT :" << expense(bill, ptotalcost[i]) << endl;
							}
							else
							{
								cout << setw(30) << left << "FOOD BILL :" << 0 << endl;
								cout << setw(30) << left << "ROOM BILL :" << bill << endl;
								cout << setw(30) << left << "BILL AMOUNT :" << expense(bill) << endl;
							}
							roomno2[i] = 0;
							name2[i] = "\0";
							address2[i] = "\0";
							phoneno2[i] = "\0";
							premstatus[i] = 0;
							flag2 = 1;
						}
					}
					if (flag2 == 0)
					{
						cout << "Room not available.." << endl;
					}
				}
				else
				{
					cout << "Invalid roomtype.." << endl;
				}
			}
			void editrecord()
			{
				int flag = 0;
				cout << "Enter the type of room : \n1-normal\n2-premium";
				cin >> roomtype;
				if (roomtype == 1)
				{
					cout << "Enter your room no:" << endl;
					cin >> roomno;
					for (int i = 0; i <= normcount; i++)
					{
						if (roomno == roomno1[i])
						{
							cout << "Enter your changes:" << endl;
							cout << "Enter your Name:";
							getchar();
							getline(cin, name1[i]);
							cout << "Enter your address:";
							getline(cin, address1[i]);
							cout << "Enter your phone number:";
							getline(cin, phoneno1[i]);
							cout << "Enter no. of days:";
							cin >> days1[i];
							cout << "Changes made sucessfully!!" << endl;
							flag = 1;
						}

					}
					if (flag == 0)
					{
						cout << "Room no not found!" << endl;
					}
				}
				else if (roomtype == 2)
				{
					cout << "Enter your room no:" << endl;
					cin >> roomno;
					for (int i = 0; i <= premcount; i++)
					{
						if (roomno == roomno2[i])
						{
							cout << "Enter your changes:" << endl;
							cout << "Enter your Name:";
							getchar();
							getline(cin, name2[i]);
							cout << "Enter your address:";
							getline(cin, address2[i]);
							cout << "Enter your phone number:";
							getline(cin, phoneno2[i]);
							cout << "Enter no. of days:";
							cin >> days2[i];
							cout << "Changes made sucessfully!!" << endl;
							flag = 1;
						}
					}
					if (flag == 0)
					{
						cout << "Room no not found!" << endl;
					}
				}
				else
				{
					cout << "Invalid Roomtype.." << endl;
				}
				system("pause");
			}

};
void down()
{
	for (int i = 0; i < 25; i++)
	{
		cout << "**";
	}
	cout << endl;
	cout << "Enter your choice:";
}
void main()
{
	hotelmanagement cr;
	int ch1;
	do {
			system("CLS");
			head();
			cout << "1.CHECK IN" << endl << "2.CUSTOMER RECORD" << endl << "3.ORDER FOOD" << endl
				<< "4.EDIT RECORD" << endl << "5.CHECK OUT" << endl << "6.INCREASE FOOD RATES BY Rs10" << endl
				<< "7.DECREASE FOOD RATES BY Rs10" << endl << "0.EXIT" << endl;
			down();
			cin >> ch1;
			switch (ch1)
			{
				case 0: break;
				case 1:
					int room_ch;
					do
					{
						system("CLS");
						head();
						cout << "1.NORMAL ROOM\nPer Day Rent = 1500/-\n2.PREMIUM ROOM\nPer Day Rent 
							= 3000 / -\n0.MAIN MENU\n";
							cin >> room_ch;
						switch (room_ch)
						{
						case 0:break;
						case 1:system("CLS");
							head();
							cr.normalroom();
							break;
						case 2:system("CLS");
							head();
							cr.premiumroom();
							break;
						default:cout << "invalid" << endl;
							break;
						}
					} while (room_ch != 0);
					break;
				case 2:
					cr.displaycusrec();
					break;
				case 3:

					cr.orderfood();
					break;
				case 4:
					cr.editrecord();
					break;
				case 5:
					cr.checkout();
					system("pause");
					break;
				case 6:++cr;
					break;
				case 7:
					--cr;
					break;
				default:
					cout << "invalid input" << endl;
					cout << "do you want to continue (0/1)" << endl;
					cin >> ch1;

					break;
				}
			} while (ch1 != 0);
	_getch();
}
