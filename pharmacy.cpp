#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class mid {
public:
	int id;
	mid *pnext;
};
class clistMID {
public:
	mid*phead;
	mid*ptail;
	clistMID()
	{
		phead = NULL;
		ptail = NULL;
	}

	~clistMID()
	{
		mid *ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void Attach(mid *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
};
class medicine
{
public:
	int id;
	string name;
	int stock;
	int price;
	string exp_date;
	clistMID List_of_alternatives;
	medicine *pnext;
};
class clistMedicine
{
public:
	medicine *phead;
	medicine *ptail;
	clistMedicine()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clistMedicine()
	{
		medicine *ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void Attach(medicine *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void Remove(int v)
	{
		medicine *pB = NULL;
		medicine *ptrav = phead;
		while (ptrav != NULL)
		{
			if (ptrav->id == v)
			{
				break;
			}
			pB = ptrav;
			ptrav = ptrav->pnext;
		}

		if (pB != NULL)
		{
			pB->pnext = ptrav->pnext;
			if (ptrav == ptail)
			{
				ptail = pB;
			}
		}
		else {
			phead = ptrav->pnext;
		}
	}
};
class customer
{
public:
	int id;
	string name;
	customer *pnext;
};
class clistCustomer {
public:
	customer *phead;
	customer *ptail;
	clistCustomer()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clistCustomer()
	{
		customer *ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void Attach(customer *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void Remove(int v)
	{
		customer *pB = NULL;
		customer *ptrav = phead;
		while (ptrav != NULL)
		{
			if (ptrav->id == v)
			{
				break;
			}
			pB = ptrav;
			ptrav = ptrav->pnext;
		}

		if (pB != NULL)
		{
			pB->pnext = ptrav->pnext;
			if (ptrav == ptail)
			{
				ptail = pB;
			}
		}
		else {
			phead = ptrav->pnext;
		}
	}
};
class MedCust {
public:
	int Mid;
	int Cid;
	int price;
	string date;
	MedCust *pnext;
};
class clistMedCust {
public:
	MedCust *phead;
	MedCust *ptail;
	clistMedCust()
	{
		phead = NULL;
		ptail = NULL;
	}
	~clistMedCust()
	{
		MedCust *ptrav = phead;
		while (ptrav != NULL)
		{
			phead = phead->pnext;
			delete ptrav;
			ptrav = phead;
		}
	}
	void Attach(MedCust *pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void Remove(int v)
	{
		MedCust *pB = NULL;
		MedCust *ptrav = phead;
		while (ptrav != NULL)
		{
			if (ptrav->Cid == v)
			{
				break;
			}
			pB = ptrav;
			ptrav = ptrav->pnext;
		}

		if (pB != NULL)
		{
			pB->pnext = ptrav->pnext;
			if (ptrav == ptail)
			{
				ptail = pB;
			}
		}
		else {
			phead = ptrav->pnext;
		}
	}
};

void console(clistMedicine i, clistCustomer k)
{
	medicine *ptrav; customer *ptrav2; MedCust *ptrav3; mid *ptrav4;
	clistMedCust purchase_history;
	int cusID, medID, month2, year2, day2, month, year, day, input;
	string cusName, date_today;
	cout << endl;
	cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
	cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
	cout << endl << "*Execute: "; cin >> input;
	while (input != 0)
	{
		if (input == 6) //View medicine list
		{
			cout << "============MEDICINE LIST============" << endl;
			ptrav = i.phead;
			while (ptrav != NULL)
			{
				cout << "------------------" << endl;
				cout << "ID: " << ptrav->id << endl;
				cout << "Name: " << ptrav->name << endl;
				cout << "Price: " << ptrav->price << endl;
				cout << "Stock: " << ptrav->stock << endl;
				cout << "EXP: " << ptrav->exp_date << endl;
				ptrav = ptrav->pnext;
			}
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 7) //View customer list
		{
			cout << "============CUSTOMER LIST============" << endl;
			ptrav2 = k.phead;
			while (ptrav2 != NULL)
			{
				cout << "------------------" << endl;
				cout << "ID: " << ptrav2->id << endl;
				cout << "Customer: " << ptrav2->name << endl;
				ptrav2 = ptrav2->pnext;
			}
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 8) //View purchase history
		{
			ptrav3 = purchase_history.phead;
			cout << "============PURCHASE HISTORY============" << endl;
			while (ptrav3 != NULL)
			{
				cout << "------------------" << endl;
				cout << "Customer ID: " << ptrav3->Cid << endl;
				cout << "Medicine ID: " << ptrav3->Mid << endl;
				cout << "Medicine price: " << ptrav3->price << "$" << endl;
				cout << "Date of Purchase: " << ptrav3->date << endl;
				ptrav3 = ptrav3->pnext;
			}
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 1) //Make a new purchase
		{
			cout << endl << "============NEW PURCHASE============" << endl;
			cout << "Enter customer ID: "; cin >> cusID;
			cout << "Enter medicine ID: "; cin >> medID;
			cout << "Enter today's date: "; cin >> date_today;
			string temp2[3]; int it2 = 0;
			for (int i = 0; i < date_today.length(); i++)
			{
				if (date_today[i] == '/')
				{
					it2++;
				}
				else
				{
					temp2[it2] += date_today[i];
				}
			}
			day2 = stoi(temp2[0]);
			month2 = stoi(temp2[1]);
			year2 = stoi(temp2[2]);
			//Check for customer details, if not found, attach a new customer
			ptrav2 = k.phead;
			while (ptrav2 != NULL)
			{
				if (cusID == ptrav2->id)
				{
					cout << "Customer found." << endl;
					break;
				}
				else if (ptrav2->pnext == NULL)
				{
					cout << "Customer not found. Enter new customer name: "; cin >> cusName;
					cout << "New customer info has been attached." << endl;
					customer *pnn = new customer;
					pnn->id = cusID;
					pnn->name = cusName;
					pnn->pnext = NULL;
					k.Attach(pnn);
					ofstream outfile;
					outfile.open("D:\\Programming\\C++ Development\\Project DS LAB\\customer_data.txt", std::ios_base::app);
					outfile << endl << cusName << "," << cusID;
					outfile.close();
					break;
				}
				ptrav2 = ptrav2->pnext;
			}
			//Check for medicine details and make purchase
			ptrav = i.phead;
			while (ptrav != NULL)
			{
				if (medID == ptrav->id)
				{
					string temp[3]; int it = 0;
					for (int i = 0; i < ptrav->exp_date.length(); i++)
					{
						if (ptrav->exp_date[i] == '/')
						{
							it++;
						}
						else
						{
							temp[it] += ptrav->exp_date[i];
						}
					}
					day = stoi(temp[0]);
					month = stoi(temp[1]);
					year = stoi(temp[2]);
					if (year2 > year || month2 > month && year2 > year)
					{
						cout << "Medicine is expired." << endl;
						cout << "*ALTERNATIVE MEDICINE OPTIONS" << endl;
						cout << "Medicine is out of stock." << endl;
						ptrav4 = ptrav->List_of_alternatives.phead;
						cout << "Alternatives: ";
						while (ptrav4 != NULL)
						{
							cout << "[" << ptrav4->id << "] ";
							ptrav4 = ptrav4->pnext;
						}
						cout << endl << "Pick alternative medicine: "; cin >> medID;
						cout << "Purchase successful!" << endl;
						MedCust *pnn = new MedCust;
						pnn->Cid = cusID;
						pnn->Mid = medID;
						pnn->price = ptrav->price;
						pnn->date = date_today;
						pnn->pnext = NULL;
						purchase_history.Attach(pnn);
						ofstream outfile;
						outfile.open("D:\\Programming\\C++ Development\\Project DS LAB\\purchase_data.txt", std::ios_base::app);
						outfile << endl << pnn->Cid << "," << pnn->Mid << "," << pnn->price << "," << pnn->date;
						outfile.close();
						break;
					}
					else if (ptrav->stock == 0)
					{
						cout << "===========ALTERNATIVE MEDICINE OPTIONS==========" << endl;
						cout << "Medicine is out of stock." << endl;
						ptrav4 = ptrav->List_of_alternatives.phead;
						cout << "Alternative medicines: ";
						while (ptrav4 != NULL)
						{
							cout << "[" << ptrav4->id << "] ";
							ptrav4 = ptrav4->pnext;
						}
						cout << endl << "Pick alternative medicine: "; cin >> medID;
						cout << "Purchase successful!" << endl;
						MedCust *pnn = new MedCust;
						pnn->Cid = cusID;
						pnn->Mid = medID;
						pnn->price = ptrav->price;
						pnn->date = date_today;
						pnn->pnext = NULL;
						purchase_history.Attach(pnn);
						ofstream outfile;
						outfile.open("D:\\Programming\\C++ Development\\Project DS LAB\\purchase_data.txt", std::ios_base::app);
						outfile << endl << pnn->Cid << "," << pnn->Mid << "," << pnn->price << "," << pnn->date;
						outfile.close();
						break;
					}
					else {
						cout << "Purchase successful!" << endl;
						MedCust *pnn = new MedCust;
						pnn->Cid = cusID;
						pnn->Mid = medID;
						pnn->price = ptrav->price;
						pnn->date = date_today;
						pnn->pnext = NULL;
						purchase_history.Attach(pnn);
						ofstream outfile;
						outfile.open("D:\\Programming\\C++ Development\\Project DS LAB\\purchase_data.txt", std::ios_base::app);
						outfile << endl << pnn->Cid << "," << pnn->Mid << "," << pnn->price << "," << pnn->date;
						outfile.close();
						break;
					}
				}
				ptrav = ptrav->pnext;
			}
			ptrav = i.phead;
			while (ptrav != NULL)
			{
				if (ptrav->id == medID)
				{
					ptrav->stock--;
					break;
				}
				ptrav = ptrav->pnext;
			}
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 2) //Inrease medicine in stock by a value.
		{
			int stock_inc;
			ptrav = i.phead;
			int check = 0;
			while (ptrav != NULL)
			{
				if (ptrav->stock == 0)
				{
					cout << "Medicine: " << ptrav->name << " is out of stock!" << endl;
					cout << "Increase medicine stock by: "; cin >> stock_inc;
					ptrav->stock += stock_inc;
					cout << "Stock has been updated. Currently in stock: " << ptrav->stock << endl;
					check = 1;
					ofstream f;
					f.open("D:\\Programming\\C++ Development\\Project DS LAB\\medicine_data.txt");
					ptrav = i.phead;
					string input, null;
					int tid;
					while (ptrav != NULL)
					{
						input += ptrav->name;
						input += ',';

						tid = ptrav->id;
						input += to_string(tid);
						input += ',';

						tid = ptrav->stock;
						input += to_string(tid);
						input += ',';

						tid = ptrav->price;
						input += to_string(tid);
						input += ',';

						input += ptrav->exp_date;
						input += ',';

						ptrav4 = ptrav->List_of_alternatives.phead;
						while (ptrav4 != NULL)
						{
							tid = ptrav4->id;
							input += to_string(tid);
							if (ptrav4->pnext != NULL)
							{
								input += ',';
							}
							ptrav4 = ptrav4->pnext;
						}
						f << input << endl;
						input = null;
						ptrav = ptrav->pnext;
					}
					f.close();
				}
				else if (ptrav->id == 6 && check == 0) { cout << "No out of stock medicine found." << endl; }
				ptrav = ptrav->pnext;
			}
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 3) //Remove customer from customer list?
		{
			cout << "Enter customer ID: " << endl;
			cin >> cusID;
			cout << "Enter medicine ID: " << endl;
			cin >> medID;
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
			//Remove purchase from medcust.
			ptrav3 = purchase_history.phead;
			while (ptrav3 != NULL)
			{
				if (cusID == ptrav3->Cid)
				{
					purchase_history.Remove(ptrav3->Cid);
					break;
				}
				ptrav3 = ptrav3->pnext;
			}
			ptrav3 = purchase_history.phead;
			//Put medicine back in stock.
			ptrav = i.phead;
			while (ptrav != NULL)
			{
				if (medID == ptrav->id)
				{
					ptrav->stock++;
					break;
				}
				ptrav = ptrav->pnext;
			}
			//Update medicine database.
			ofstream f;
			f.open("D:\\Programming\\C++ Development\\Project DS LAB\\medicine_data.txt");
			ptrav = i.phead;
			string input, null;
			int tid;
			while (ptrav != NULL)
			{
				input += ptrav->name;
				input += ',';

				tid = ptrav->id;
				input += to_string(tid);
				input += ',';

				tid = ptrav->stock;
				input += to_string(tid);
				input += ',';

				tid = ptrav->price;
				input += to_string(tid);
				input += ',';

				input += ptrav->exp_date;
				input += ',';

				ptrav4 = ptrav->List_of_alternatives.phead;
				while (ptrav4 != NULL)
				{
					tid = ptrav4->id;
					input += to_string(tid);
					if (ptrav4->pnext != NULL)
					{
						input += ',';
					}
					ptrav4 = ptrav4->pnext;
				}
				f << input << endl;
				input = null;
				ptrav = ptrav->pnext;
			}
			f.close();
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 4) //Display income of a specific date.
		{
			string spec_date;
			int income = 0;
			cout << "Specified date: " << endl; cin >> spec_date;
			ptrav3 = purchase_history.phead;
			while (ptrav3 != NULL)
			{
				if (ptrav3->date == spec_date)
				{
					income += ptrav3->price;
				}
				ptrav3 = ptrav3->pnext;
			}
			cout << "Income: " << income << "$" << endl;
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
		if (input == 5) //Check for medicine with exp date within week.
		{
			cout << "=========EXPIRY CHECKUP=========" << endl;
			cout << "Enter today's date:" << endl;
			string today;
			cin >> today;
			string temp3[3]; int it3 = 0;
			for (int i = 0; i < today.length(); i++)
			{
				if (today[i] == '/')
				{
					it3++;
				}
				else
				{
					temp3[it3] += today[i];
				}
			}
			day = stoi(temp3[0]);
			month = stoi(temp3[1]);
			year = stoi(temp3[2]);
			ptrav = i.phead;
			while (ptrav != NULL)
			{
				string temp[3]; int it = 0;
				for (int i = 0; i < ptrav->exp_date.length(); i++)
				{
					if (ptrav->exp_date[i] == '/')
					{
						it++;
					}
					else
					{
						temp[it] += ptrav->exp_date[i];
					}
				}
				day2 = stoi(temp[0]);
				month2 = stoi(temp[1]);
				year2 = stoi(temp[2]);
				if (year == year2 && month == month2 && day2 - day <= 7 && day2 - day > 0)
				{
					cout << "Alert: " << ptrav->name << " will expire soon!" << endl;
					cout << "EXP: " << ptrav->exp_date << endl;
				}
				else if (year == year2 && month2 - month == 1 && day2 + (30 - day) <= 7 && day2 + (30 - day) > 0)
				{
					cout << "Alert: " << ptrav->name << " will expire soon!" << endl;
					cout << "EXP: " << ptrav->exp_date << endl;
				}
				else if (year2 - year == 1 && month2 == 1 && month == 12 && day2 + (30 - day) <= 7)
				{
					cout << "Alert: " << ptrav->name << " will expire soon!" << endl;
					cout << "EXP: " << ptrav->exp_date << endl;
				}
				ptrav = ptrav->pnext;
			}
			cout << endl;
			cout << "1. New purchase" << endl << "2. Update stock" << endl << "3. Return a purchase" << endl << "4. Check income for a day" << endl;
			cout << "5. Expiry checkup" << endl << "6. Medicine list" << endl << "7. Customers list" << endl << "8. Purchase history" << endl;
			cout << "*Execute: "; cin >> input;
		}
	}
}

int main()
{
	fstream f;
	f.open("D:\\Programming\\C++ Development\\Project DS LAB\\medicine_data.txt");
	clistMedicine stock;
	if (!f)
	{
		cout << "ERROR: Database file deleted or location changed. " << endl;
	}
	else {
		cout << "Database loaded: OK" << endl;
		string x;
		while (getline(f, x))
		{
			string temp[8]; int it = 0;
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] == ',')
				{
					it++;
				}
				else
				{
					temp[it] += x[i];
				}
			}
			medicine *pnn = new medicine;
			pnn->name = temp[0];
			pnn->id = stoi(temp[1]);
			pnn->stock = stoi(temp[2]);
			pnn->price = stoi(temp[3]);
			pnn->exp_date = temp[4];
			for (int i = 0; i < 3; i++)
			{
				mid *pnnAltr = new mid;
				pnnAltr->id = stoi(temp[5 + i]);
				pnnAltr->pnext = NULL;
				pnn->List_of_alternatives.Attach(pnnAltr);
			}
			pnn->pnext = NULL;
			stock.Attach(pnn);
		}
		f.close();
	}
	f.open("D:\\Programming\\C++ Development\\Project DS LAB\\customer_data.txt");
	clistCustomer customers;
	if (!f)
	{
		cout << "ERROR: Customer file deleted or location changed. " << endl;
	}
	else {
		cout << "Customers loaded: OK" << endl;
		string x;
		while (getline(f, x))
		{
			string temp[3]; int it = 0;
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] == ',')
				{
					it++;
				}
				else
				{
					temp[it] += x[i];
				}
			}
			customer *pnn = new customer;
			pnn->name = temp[0];
			pnn->id = stoi(temp[1]);
			pnn->pnext = NULL;
			customers.Attach(pnn);
		}
		f.close();
	}
	console(stock, customers);
	system("pause");
}