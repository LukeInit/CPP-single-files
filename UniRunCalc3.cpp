#include <iostream>
#include <thread>
#include <cmath>
#include <chrono>
#include <vector>

using namespace std;

struct storage 
{
    int player; 
    int vehicle;
    int TotalWeight;
};

// each item info
struct ItemInf{

int ItemWeight;
int NeededToMake1;
int Tweight;

};

// output stuff
struct ItemPrint{

    int TotalWeightUsed;
    int AmountNeeded;

};


void Calculateiems();
void WeightCheck(storage &s);

storage store{0,0,0};


void WeightCheck(storage &s){

    if (s.player == 0){
        cout << " Input Player Weight\n ";
        cin >> s.player;
    }

    if(s.vehicle == 0){

        cout << "\n Input vehicle weight\n ";
        cin >> s.vehicle;

    }

    s.TotalWeight = s.player + s.vehicle;

    system("cls");

}


void Calculateiems(){

    int materialnum;
    int TotalStoreAgeFor1Item = 0;

    cout << " How Many item?\n ";
    cin >> materialnum;

    vector<ItemInf> items(materialnum);
    vector<ItemPrint> iteminfo(materialnum);

    for(int i=0; i < materialnum; i++)// int i=0 initialises int | i < Materialnum // checks if less than material num; i++ increases the value of int i after processing the current statement
    {
        cout << "\n Item " << i + 1 << " weight: \n ";
        cin >> items[i].ItemWeight;

        cout << "\n Amount needed to make 1: \n ";
        cin >> items[i].NeededToMake1;

        items[i].Tweight = items[i].ItemWeight * items[i].NeededToMake1;
        TotalStoreAgeFor1Item = TotalStoreAgeFor1Item + items[i].Tweight;
        
    }


    int totalraw = store.TotalWeight / TotalStoreAgeFor1Item;

    int sellprice = 0;

    if (sellprice == 0){
        cout << "\n input sell price \n ";
        cin >> sellprice;
    }


    int weightused = 0;
    if(weightused != 0){
        weightused = 0;
    }

    system("cls");
    int finalsellprice=0;
    for (int i=0; i < materialnum; i++) 
    {
        iteminfo[i].AmountNeeded = totalraw * items[i].NeededToMake1;
        iteminfo[i].TotalWeightUsed = iteminfo[i].AmountNeeded * items[i].ItemWeight;
        weightused = weightused + iteminfo[i].TotalWeightUsed;
        finalsellprice = totalraw*sellprice;

    cout << " " << iteminfo[i].AmountNeeded  << " of item "<< i+1 << "\n";
    cout << " weight used: " << weightused << "\n";

    }

    cout << "\n Sell Price: " << sellprice << "\n Total Value: " << finalsellprice;

    int endmenu;

    while(true)
    {
        cout << "\n\n 1. Start again\n 2. exit\n ";
        cin >> endmenu;
        cout<< "\n";
        if(endmenu == 2)
        {
            break;
        }
        if (endmenu == 1){
        system("cls");
         return Calculateiems();
        }

    }

}


int main()
{

    WeightCheck(store);
    Calculateiems();

}