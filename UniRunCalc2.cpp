
#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>

using namespace std;

struct storage 
{
    int player; 
    int vehicle;
    int TotalWeight;
};

struct Process
{

	int ItemWeight;
	int NeededToMake1;
	int SellPrice;

};

struct ExtraItem
{

	int ItemWeight;
	int NeededToMake1;

};


void Menu();
void ChangeWeight(storage &s);
void WeightCheck(storage &s);
void Calculate1item(Process &p);
void Calculate2item(Process &p, ExtraItem &e);

storage store{0,0,0}; // hard code here for static calculations there in this order : player,vehicle,totalweight
Process p{0,0,0}; // processig structs set to 0 and initialised
ExtraItem e{0,0}; // extra items set to 0


int main()
{
	WeightCheck(store);
    Menu();

    return 0;


}

void WeightCheck(storage &s)
{
    if (s.player == 0)
    {
        cout << " Please input backpack weight\n ";
        cin >> s.player;
    }

    if (s.vehicle == 0)
    {
        cout << "\n Please input vehicle weight\n ";
        cin >> s.vehicle;
    }
    s.TotalWeight = s.player + s.vehicle;
    system("cls");
}


void ChangeWeight(storage &s)
{

	cout << "\n backpack storage: " << s.player << "\n Vehicle storage: " << s.vehicle << "\n Total storage: " << s.TotalWeight << "\n\n Input backpack storage\n " ;
	cin >> s.player;
	cout << "\n Input Vehicle storage: ";
	cin >> s.vehicle;
	cout << "\n";
	s.TotalWeight = s.player + s.vehicle;

	Menu();

}



void Menu()
{
	
	
	enum MenuOptions { Exit = 0, OneItemPro = 1, TwoItemPro = 2, Settings = 3 };

	
	cout << " 0. Exit\n 1. single item process\n 2. Double item process\n 3. Change weight\n ";

	int Menuint;
	cin >> Menuint;
	MenuOptions choice = static_cast<MenuOptions>(Menuint);


	switch(choice)
	{

	case Exit:
		cout << "\n Exiting\n ";
		break;

	case OneItemPro:

		Calculate1item(p);
		break;


	case TwoItemPro:
	Calculate2item(p,e);
	break;


	case Settings:
		ChangeWeight(store);
		break;

	}


}


void Calculate1item(Process &p)
{


	system("cls");

	cout << " input item weight\n ";
	cin >> p.ItemWeight;
	cout << "\n Input Amount used to make 1\n ";
	cin >> p.NeededToMake1;
	cout << "\n Sell Price\n ";
	cin >> p.SellPrice;

	int TotalRaw = store.TotalWeight / p.ItemWeight;
	int TotalProc = TotalRaw / p.NeededToMake1;
	int TotalSell = TotalProc * p.SellPrice;

	cout << "\n Total storage: " << store.TotalWeight 
	<< "\n Total Raw Items: " << TotalRaw 
	<< "\n Total Processed: " << TotalProc 
	<< "\n Total Sell Price: " << TotalSell << "\n\n";
	int Endofcalc;

	while (true)  // menu at the end
	{
    cout << "\n 1. Back to Menu (clears console)";
    cout << "\n 2. Run Again (clears console)\n ";
    cin >> Endofcalc;
    cout << "\n";

    if (Endofcalc == 1)
    {
    	system("cls");
        Menu();        // go back to main menu
        break;         // exit this loop
    }
    else if (Endofcalc == 2)
    {
    	system("cls");
        Calculate1item(p);  // run again
        break;              // exit this loop
    }
    else
    {
        cout << "\n Invalid choice, try again...\n";
    }
}
	


}


void Calculate2item(Process &p, ExtraItem &e){
	system("cls");

	cout << " input item 1 weight\n ";
	cin >> p.ItemWeight;
	cout << "\n Input amount used to make 1\n ";
	cin >> p.NeededToMake1;
	cout << "\n Input item 2 weight\n ";
	cin >> e.ItemWeight;
	cout << "\n Input amount used to make 1\n ";
	cin >> e.NeededToMake1;
	cout << "\n Sell Price\n ";
	cin >> p.SellPrice;

	int finalweight1 = p.ItemWeight * p.NeededToMake1;
	int finalweight2 = e.ItemWeight * e.NeededToMake1;
	int TotalWeight = finalweight1 + finalweight2;

	int TotalOfEach = store.TotalWeight / TotalWeight;
	int TotalSellPrice = TotalOfEach * p.SellPrice;

	int TotalMat1 = TotalOfEach * p.NeededToMake1;
	int TotalMat2 = TotalOfEach * e.NeededToMake1;


	cout << "\n Total storage: " << store.TotalWeight 
	<< "\n Total Raw Item 1: " << TotalMat1 
	<< "\n Total Raw Item 2: " << TotalMat2 
	<< "\n Total Processed: " << TotalOfEach 
	<< "\n Total Sell Price: " << TotalSellPrice << "\n\n";



	int Endofcalc;

	while (true)  // menu at the end
	{
    cout << "\n 1. Back to Menu (clears console)";
    cout << "\n 2. Run Again (clears console)\n ";
    cin >> Endofcalc;
    cout << "\n";

    if (Endofcalc == 1)
    {
    	system("cls");
        Menu();        // go back to main menu
        break;         // exit this loop
    }
    	else if (Endofcalc == 2)
    	{
    		system("cls");
        	Calculate2item(p,e);  // run again
        	break;              // exit this loop
    	}
    	else
    	{
        	cout << "\n Invalid choice, try again...\n";
    	}
	}
	
}






