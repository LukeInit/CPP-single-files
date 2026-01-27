#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>

using namespace std;

 //// ints //// 
int menu;

int PlayerWeight = 0;
int VehicleWeight = 0;
int TotalCarry;

//// voids ////
void ChangeWeight();
void WeightCheck();
void menuspawn();
void OneItemProcess();
void TwoItemProcess();
void ThreeItemProcess();


// i am using this to learn voids 
int main()
{
    do
    {
    	WeightCheck(); // makes user input weight before can be deleted and hardcoded above for a quicker experiance I.E int TotalCarry = 1000; or whatever

        menuspawn(); // spawns menu

     
        switch(menu)
        {
            case 1:
                OneItemProcess();
                break;

            case 2:
                TwoItemProcess();
                break;

            case 3:
                ThreeItemProcess();
                break;

            case 4:
            	system("cls");
            	break;

            case 5:
            	ChangeWeight();
            	break;

            case 0:
			std::cout << "\n  Quitting program\n  ";
			this_thread::sleep_for(chrono::milliseconds(2000));
			break;

            default:
                cout << "Invalid option\n";
        }

    } while(menu != 0);

    return 0;
}


void WeightCheck()
{
	if (PlayerWeight == 0){
		cout << " Backpack storage\n ";
		cin >> PlayerWeight;
	}

	if (VehicleWeight == 0){
		cout << "\n Vehicle Storage\n ";
		cin >> VehicleWeight;
	}
	TotalCarry = PlayerWeight + VehicleWeight;
	system("cls");
}

void ChangeWeight() // ability to change the weight without restarting the program might be slower i dont care
{
	system("cls");

	cout << " current backpack storage: " << PlayerWeight << "\n Current vehicle storage: " << VehicleWeight << "\n\n";

	cout << " Player virtual storage\n ";
	cin >> PlayerWeight;
	cout << "\n Vehicle virtual storage\n ";
	cin >> VehicleWeight;

	TotalCarry = PlayerWeight + VehicleWeight;

}

void menuspawn() // spawns the menu 
{
cout << " you have: " << TotalCarry << "\n\n run calc pick from the options below\n 0. exit\n 1. Single item (field > process > sell)\n 2. double item process (field > field > process > sell)\n 3. triple item process (field > field > field > process > sell)\n 4. Clear Console\n 5. change weight of player and vehicle\n ";
cin >> menu;
}




void OneItemProcess() // processing of 1 item field > process > sell
{
	system("cls");
	
	int RawWeight;
	int PerProcessedItem;
	int Sellprice;

	cout << " Raw material weight\n ";
	cin >> RawWeight;
	cout << "\n How many raw materials to make 1 item\n ";
	cin >> PerProcessedItem;
	cout << "\n Sell Price\n ";
	cin >> Sellprice;

	int TotalRaw = TotalCarry / RawWeight;
	int TotalProc = TotalRaw / PerProcessedItem;
	int TotalSell = TotalProc * Sellprice;

	int sdwasd;
	cout << "\n Total Storage Provided: " << TotalCarry << "\n Total Raw materials: " << TotalRaw << "\n total processed: " << TotalProc << "\n Total Sell: " << TotalSell <<"\n\n 0-9 return to menu\n ";
	cin >> sdwasd;

}

void TwoItemProcess() // processing of 1 item field > process > sell
{

	system("cls");

	int SellPrice;
	int RawWeight1;
	int PerProcessedItem1;

	cout << " Item 1 weight\n "; 
	cin >> RawWeight1;
	cout << "\n How many to make 1 item\n ";
	cin  >> PerProcessedItem1;

	int TotalStore1 = RawWeight1 * PerProcessedItem1; // total weight used to make 1

	int RawWeight2;
	int PerProcessedItem2;

	cout << "\n Item 2 weight\n ";
	cin >> RawWeight2;
	cout << "\n How many to make 1 item\n ";
	cin  >> PerProcessedItem2;
	cout << "\n SellPrice\n ";
	cin >> SellPrice;

	int TotalStore2 = RawWeight2 * PerProcessedItem2; /// i have 0 idea how this math works

	int TotalStored = TotalStore1 + TotalStore2;

	int TotalRaw = TotalCarry / TotalStored;

	int TotalMat1 = TotalRaw * PerProcessedItem1;
	int TotalMat2 = TotalRaw * PerProcessedItem2;

	int TotalSell = SellPrice * TotalRaw;

	int sdwasd;
	cout << "\n Total Storage Provided: " << TotalCarry << " \n Item 1 amount: " << TotalMat1 << "\n Item 2 amount: " << TotalMat2 << "\n Total Processed: " << TotalRaw << "\n Total $ made: " << TotalSell <<"\n\n 0-9 return to menu\n ";
	cin >> sdwasd;


}



void ThreeItemProcess()
{

	system("cls");

	int SellPrice;

	int RawWeight1;
	int PerProcessedItem1;

	cout << " Item 1 weight\n "; 
	cin >> RawWeight1;
	cout << "\n How many to make 1 item\n ";
	cin  >> PerProcessedItem1;

	int TotalStore1 = RawWeight1 * PerProcessedItem1; // total weight used to make 1

	int RawWeight2;
	int PerProcessedItem2;

	cout << "\n Item 2 weight\n ";
	cin >> RawWeight2;
	cout << "\n How many to make 1 item\n ";
	cin  >> PerProcessedItem2;


	int TotalStore2 = RawWeight2 * PerProcessedItem2; 

	int RawWeight3;
	int PerProcessedItem3;

	cout << "\n Item 3 weight\n ";
	cin >> RawWeight3;
	cout << "\n How many to make 1 item\n ";
	cin  >> PerProcessedItem3;
	cout << "\n SellPrice\n ";
	cin >> SellPrice;

	int TotalStore3 = RawWeight3 * PerProcessedItem3; 


	int TotalStored = TotalStore1 + TotalStore2 + TotalStore3;

	int TotalRaw = TotalCarry / TotalStored;

	int TotalMat1 = TotalRaw * PerProcessedItem1;
	int TotalMat2 = TotalRaw * PerProcessedItem2;
	int TotalMat3 = TotalRaw * PerProcessedItem3;

	int TotalSell = SellPrice * TotalRaw;


	int sdwasd;
	cout << "\n Total Storage Provided: " << TotalCarry << " \n Item 1 amount: " << TotalMat1 << "\n Item 2 amount: " << TotalMat2 << " \n Item 3 amount: " << TotalMat3 << "\n Total Processed: " << TotalRaw << "\n Total $ made: " << TotalSell <<"\n\n 0-9 return to menu\n ";
	cin >> sdwasd;


}