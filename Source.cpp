#include "stdio.h"
#include "math.h"
#include "iostream"
using namespace std;

class Transaction
{
public:
	int uid;
	int amount;


	Transaction()
	{
		uid = 0;
		amount = 0;
	}
	virtual void Report()
	{
		cout << " UID:: " << uid << " Ammount :: " << amount;
	}
};

class User
{
public:
	int id;
	int numTrans;
	Transaction* tr[100];

	User()
	{
		id = 0;
		numTrans = 0;
	}
};

class WithDraw : public Transaction
{
public:
	WithDraw()
	{

	}
	void Report()
	{
		cout << "User has withdrawn " << amount << endl;
	}
	void Do()
	{
		cout << "How much would you like to withdraw?\n";
		cin >> amount;
	}
};
class Deposit : public Transaction
{
public:
	Deposit()
	{

	}
	void Report()
	{
		cout << "User has deposited " << amount << endl;
	}
	void Do()
	{
		cout << "How much would you like to deposit?\n";
		cin >> amount;
	}
};
class Transfer : public Transaction
{
public:

	Transfer()
	{

	}
	void Report()
	{
		cout << "User has transferred " << amount << endl;
	}
	void Do()
	{
		cout << "How much would you like to transfer?\n";
		cin >> amount;
	}
};

class UI : public Transaction
{
public:
	User user[100];


	void Interface()
	{
		int counter;
		counter = 0;

		//show menu
		int u;
		printf("enter user id: ");
		scanf_s("%d", &u);
		int t;
		do
		{

			printf("What would you like to do \n1: Withdraw \n2: Deposit \n3: Transfer \n4: Recipt\n\n");
			scanf_s("%d", &t);
			for (int i = 0; i <= counter; i++)
			{

				if (t == 1) //withdraw
				{
					WithDraw* w = new WithDraw();
					w->Do();
					user[u].tr[user[u].numTrans] = w;
					user[u].numTrans++;
				}

				if (t == 2) //deposit
				{
					Deposit* d = new Deposit();
					d->Do();
					user[u].tr[user[u].numTrans] = d;
					user[u].numTrans++;

				}

				if (t == 3) //transfer
				{
					Transfer* t = new Transfer();
					t->Do();
					user[u].tr[user[u].numTrans] = t;
					user[u].numTrans++;
				}
				else if (t == 4) //report
				{
					for (int i = 0; i < user[u].numTrans; i++)
					{
						user[u].tr[i]->Report();
					}
				}
			}
		} while (t != 4);
		//process command
	}
};
int main()
{
	UI ui;
	ui.Interface();
	return 0;
}
