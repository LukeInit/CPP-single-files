using namespace std;
#include <iostream>
#include <thread>
#include <cmath>


int main()
{
    // very cool important menu stuff
    int menumain;
    int menutobacco;
    int menuswamp;
    int menushine;
    int menugold;
    int menuore;

    //default values for the calculations
    int goldproccesorcost = 50;
    float rollingpaper = 0.45;
    float tobaccogrow = 0.15;
    float cartonsellprice = 8.5;
    int oreproccesorcost = 7;
    int oreperbar = 4;
    float water = 0.5;
    int yeast = 2;

    std::cout << R"(
    ________      ___    ___      ________       ___ 
   |\   __  \    |\  \  /  /|    |\   __  \     |\  \
   \ \  \|\ /_   \ \  \/  / /    \ \  \|\  \    \ \  \
    \ \   __  \   \ \    / /      \ \   _  _\ __ \ \  \
     \ \  \|\  \   \/  /  /        \ \  \\  \|\  \\_\  \
      \ \_______\__/  / /           \ \__\\ _\ \________\
       \|_______|\___/ /             \|__|\|__\|________|
                \|___|/                                                                                
                         Version 1.2
                          Loading...
        )";
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("cls");
 
   do   
    {

     std::cout <<" \n  0. Close program - Do not use on web version\n"<<"  1. Carton cost calculator\n"<<"  2. Swamp herb cost calculator\n" <<"  3. Moonshine cost calculator\n" 
      <<"  4. Tobacco crafting calculator \n" <<"  5. Gold calculator\n" << "  6. Mining calculator\n" << "  7. Gold nugget buy calculator\n" << "  9. HELP!" << "\n\n  " ;
      std::cin >> menumain;


     switch(menumain)
       {
         case 0:
         {
         std::cout << "\n  Quitting program\n  ";
         this_thread::sleep_for(chrono::milliseconds(2000));
          }
            break;


            case 1:
            {
             std::cout << "\n  Input carton amount\n\n  ";
             int carton;
             std::cin >> carton;

             std::cout << "\n  Did you 1. grow or 2. buy : 0 to go back \n\n  ";
             std::cin >> menutobacco;


             switch(menutobacco)
             {
                case 0:
                {
                     break;
                }

                case 1:
                {
                  // i could put it above but here looks nicer and i am lazy
                  // getting values of the materials 
                  int ctobacco = carton * 6; // get carton amount times by 6 for tobacco amount
                  int cpaper = carton * 3; //get carton times times by 3 for paper amount
                  // material prices
                  float ptobacco = ctobacco * tobaccogrow; // price tob
                  float ppaper = cpaper * rollingpaper ; // price of all paper
                  // now for the epic money stuff
                  float cartonmatcost = ptobacco + ppaper; // get the material cost
                  float cartonsellamount = carton * cartonsellprice; // get the total sell amount
                  float cartontotalprof = cartonsellamount - cartonmatcost; // get the total profit made

               std::cout <<"\n  You will need \n\n  $" <<  ptobacco << " : " << ctobacco  <<  
              "   Tobacco  \n  $" << ppaper << " : " << cpaper << "   Rolling paper \n" 
               << "  Cost : $" << cartonmatcost << "\n" <<"  Sale : $"
             << cartonsellamount << "\n" << "  Prof : $" << cartontotalprof << "\n\n";
                }

                break;

                case 2:
                {
                    std::cout << "\n  How much did it cost?\n\n  ";
                    float tobaccobuy;
                    std::cin >> tobaccobuy;

                  // getting values of the materials 
                  int ctobacco = carton * 6; // get carton amount times by 6 for tobacco amount
                  int cpaper = carton * 3; //get carton times times by 3 for paper amount
                  // material prices
                  float ptobacco = ctobacco * tobaccobuy; // price tob
                  float ppaper = cpaper * rollingpaper ; // price of all paper
                  // now for the epic money stuff
                  float cartonmatcost = ptobacco + ppaper; // get the material cost
                  float cartonsellamount = carton * cartonsellprice; // get the total sell amount
                  float cartontotalprof = cartonsellamount - cartonmatcost; // get the total profit made

               std::cout <<"\n  You will need \n\n  $" <<  ptobacco << " : " << ctobacco  <<  
              "   Tobacco  \n  $" << ppaper << " : " << cpaper << "   Rolling paper \n" 
               << "  Cost : $" << cartonmatcost << "\n" <<"  Sale : $"
             << cartonsellamount << "\n" << "  Profit : $" << cartontotalprof << "\n\n";

                }  
                break;     
             }
             break; // keep these 2 here other wise it continues to swamp herb

            case 2:
            {

            std::cout << "\n  Input swamp joint amount\n\n  ";
             int swampjoint;
             std::cin >> swampjoint;

             std::cout << "\n  How much is swamp herb selling for? : average is $13 \n\n  ";
             float swampsellprice;
             std::cin >> swampsellprice;

             std::cout << "\n  Did you 1. grow or 2. buy : 0 to go back \n\n  ";
             std::cin >> menuswamp;

             switch(menuswamp)
              {
                case 0:
                {
                    break;
                }

                 case 1:
                 {
                    int saramount = swampjoint * 3; //gets the amount of paper and swamp needed
                  /* float swampcost = saramount * 1; //gets the cost of the swamp herb used */ //fuck knows why i did this use the saramount as the total cost of swamp
                    float rollingcost = saramount * rollingpaper; // gets the cost of the rolling paper

                    float totalswampmats = saramount + rollingcost; // cost of all the mats
                    float totalswampsale = swampjoint * swampsellprice; // total sale amount
                    float totalswampprof = totalswampsale - totalswampmats; // total profit made from sale

                    std::cout << "\n" << "  You will need\n\n  $" <<  saramount << " : " <<  saramount << " Swamp herb\n  $"
                    << rollingcost << " : " << saramount << " Rolling paper \n" 
                    << "  Cost : $" << totalswampmats << "\n" <<"  Sale : $"
                    << totalswampsale << "\n" << "  Profit : $" << totalswampprof << "\n\n";       

                 }
                break;
                case 2:
                {

                    std::cout << "\n  What price did u buy for? \n\n  ";
                    float swampbuyprice;
                    std::cin >> swampbuyprice;

                    int saramount = swampjoint * 3; //gets the amount of paper and swamp needed
                    float swampcost = saramount * swampbuyprice; //gets the cost of the swamp herb used 
                    float rollingcost = saramount * rollingpaper; // gets the cost of the rolling paper

                    float totalswampmats = swampcost + rollingcost; // cost of all the mats
                    float totalswampsale = swampjoint * swampsellprice; // total sale amount
                    float totalswampprof = totalswampsale - totalswampmats; // total profit made from sale

                    std::cout << "\n" << "  You will need\n\n  $" <<  swampcost << " : " 
                    <<  saramount << " Swamp herb\n  $"
                    << rollingcost << " : " << saramount << " Rolling paper \n" 
                    << "  Cost : $" << totalswampmats << "\n" <<"  Sale : $"
                    << totalswampsale << "\n" << "  Profit : $" << totalswampprof << "\n\n";       


                }
                break;
             }
             break;

             case 3:
            {
            //get moonshine amount
            std::cout <<"\n  Input moonshine amount" << "\n\n  ";
            int moonshine;
            std::cin >> moonshine;

            //moonshine sell price
            std::cout << "\n  Moonshine sell price? | average is $15 \n\n  ";
            float moonsell;
            std::cin >> moonsell; 

            // only used for the cost per shine
            std::cout << "\n  How much mash did u make per batch? \n\n  ";
            int mash;
            std::cin >> mash;

            //get sugarcane price
            std::cout << "\n  Did you 1. grow or 2. buy sugar? | 0 to go back to menu \n\n  ";
            std::cin >> menushine;
                switch(menushine)
                {
                 case 0:
                {
                    break;
                }
                    case 1:
                    {
                        float sugarprice = 0.19 * 2;

                        int finalshine = moonshine / mash; // get the amount of mashes needed
                        float onemashcost = yeast + water + sugarprice; // gets the price of a single mash
                        float allmash = onemashcost * finalshine; //gets price of all mash
                        float finalcostofshine =  allmash / moonshine; // gets the price of the individual moonshine
                        float finalshinesale =  moonsell * moonshine; //gets the total made from selling moonshine
                        float shineprof = finalshinesale - allmash ; // gets the total profit made from selling 

                    std::cout 
                    <<"\n  Amount of mashes: "<< finalshine <<"\n" 
                    << "  Material cost of the mashes: $" << allmash << "\n" 
                    << "  Individual moonshine cost: $" << finalcostofshine <<"\n"
                   << "  Total amount made: $" << finalshinesale << "\n" 
                   << "  Total profit made after sell: $" << shineprof << "\n\n" ;

                   }
                   break;

                   case 2:
                   {

                        std::cout << "\n  Price of the sugar?\n\n  ";
                        float sugarbuyprice;
                        std::cin >> sugarbuyprice;

                        float sugarprice = sugarbuyprice * 2;

                        int finalshine = moonshine / mash; // get the amount of mashes needed
                        float onemashcost = yeast + water + sugarprice; // gets the price of a single mash
                        float allmash = onemashcost * finalshine; //gets price of all mash
                        float finalcostofshine =  allmash / moonshine; // gets the price of the individual moonshine
                        float finalshinesale =  moonsell * moonshine; //gets the total made from selling moonshine
                        float shineprof = finalshinesale - allmash ; // gets the total profit made from selling 

                        std::cout 
                       <<"\n  Amount of mashes: "<< finalshine <<"\n" 
                       << "  Material cost of the mashes: $" << allmash << "\n" 
                       << "  Individual moonshine cost: $" << finalcostofshine <<"\n"
                       << "  Total amount made: $" << finalshinesale << "\n" 
                       << "  Total profit made after sell: $" << shineprof << "\n\n" ;

                   }
                   
                }
            } break;
            break;

         case 4:
            {
             std::cout << "\n  Enter tobacco amount" << "\n\n  ";
             int tobacco;
             std::cin >> tobacco;
       
             int carton = tobacco / 6;
             int paper = tobacco / 2;
             float paperc = paper * rollingpaper;
             float cartonp = carton * cartonsellprice;

             std::cout << "\n  You will need \n  "
              << paper << " Rolling paper : cost: $"
             << paperc << "\n" << "  You can make " 
             << carton << " Cartons : $"  
             << cartonp << "\n\n" ;

            }

            break;

            case 5:

            {

             std::cout << "\n  Gold nugget amount | anything under 100 wont work\n\n  ";   
             int goldamount;
             std::cin >> goldamount;

             std::cout << "\n  Gold sell price?\n\n  ";
             float goldsellprice;
             std::cin >> goldsellprice;

              std::cout << "\n  Did you 1. pan or 2. buy | 0 to go back to menu"<< "\n\n  ";
              std::cin >> menugold; 
                switch(menugold)
                {
                    case 0:
                {
                    break;

                }
                    case 1:
                    {

                        float goldbaramount = goldamount / 100; //gets amount of bars smeltable and process
                        int totalgoldmade = goldbaramount * goldsellprice; // total amount of money made from selling gold
                        int totalgoldprocessing = goldproccesorcost * goldbaramount; // gets the total processing cost
                        /*  float totalmatgoldcost =  totalgoldprocessing + 0 ; */ // dont need this smh
                        float totalgoldprofit = totalgoldmade - totalgoldprocessing; // gets the total profit made.


                        std::cout << "\n  You will need to do: " << goldbaramount << " processes\n"
                         <<"  You will get: " << goldbaramount <<" gold bars\n"  
                         << "  You will spend: " << totalgoldprocessing << " on processing \n" 
                         <<"  Your total spend is: " << totalgoldprocessing 
                         << "\n  Total money made is: " << totalgoldmade  
                         <<"\n  Your total profit is: " << totalgoldprofit << "\n\n";

                }   
                break;

                case 2:
                {
                    std::cout << "\n  How much did u buy for? \n\n";
                    float goldbuyprice;
                    std::cin >> goldbuyprice;

                        float goldnuggettotalcost = goldamount * goldbuyprice; // gets the price of all nugz
                        float goldbaramount = goldamount / 100; //gets amount of bars smeltable
                        int totalgoldmade = goldbaramount * goldsellprice; // total amount of money made from selling gold
                        int totalgoldprocessing = goldproccesorcost * goldbaramount; // gets the total processing cost
                        float totalmatgoldcost =  totalgoldprocessing + goldnuggettotalcost ; // total mat cost
                        float totalgoldprofit = totalgoldmade - totalgoldprocessing; // gets the total profit made.

                        std::cout << "\n  You will need to do: " << goldbaramount << " processes \n"
                         <<"  You will get: " << goldbaramount <<" gold bars\n"  
                         << "  You will spend: " << totalgoldprocessing << " on processing \n" 
                         <<"  Your total spend is: " << totalgoldprocessing 
                         << "\n  Total money made is: " << totalgoldmade  
                         <<"\n  Your total profit is: " << totalgoldprofit << "\n\n";
                }
                break;
              }
              break;

              case 6:
              {

                  std::cout << "\n  Amount of ore?\n\n  ";
                  int oreamount;
                  std::cin >> oreamount;
            
                  std::cout << "\n  Sell price of ore?\n\n  ";
                  int oresell;
                  std::cin >> oresell;

                  std::cout << "\n  Did you 1. mine or 2. buy\n\n  ";
                  std::cin >> menuore;
                  switch(menuore)
                  {

                    case 1:
                    {
                        int totalfullinv = oreamount / 60 ;
                        float orebaramount = oreamount / 5; //gets amount of bars 
                        int totalbarsmade = orebaramount * oresell; // total amount of money made from selling the bars
                        int totalbarprocessing = oreproccesorcost * orebaramount; // gets the total processing cost
                        float totaloreprofit = totalbarsmade - totalbarprocessing; // gets the total profit made.

                         std::cout << "\n  You will need to do: " << totalfullinv << " full inventory's\n"
                         <<"  You will get: " << orebaramount <<" bars\n"  
                         << "  You will spend: $" << totalbarprocessing << " on processing \n" 
                         <<"  Your total spend is: $" << totalbarprocessing 
                         << "\n  Total money made is: $" << totalbarsmade  
                         <<"\n  Your total profit is: $" << totaloreprofit << "\n\n";

                     }
                    break;

                    case 2:
                    {

                        std::cout << "\n  how much did you buy for?\n\n  ";
                        int orebuy;
                        std::cin >> orebuy;

                        int totalfullinv = oreamount / 60 ; // gets the amount per inv
                        float orebaramount = oreamount / 5; //gets amount of bars 
                        int totalbarsmade = orebaramount * oresell; // total amount of money made from selling the bars
                        float totalorebuy = orebuy * oreamount; // gets the total cost of all the ore
                        int totalbarprocessing = oreproccesorcost * orebaramount; // gets the total processing cost
                        float totalproductioncost = totalbarprocessing + totalorebuy; // gets the total cost of all the processes
                        float totaloreprofit = totalbarsmade - totalproductioncost; // gets the total profit made.

                         std::cout << "\n  You will need to do: " << totalfullinv << " full inventory's\n"
                         <<"  You will get: " << orebaramount <<" bars\n"  
                         << "  You will spend: $" << totalbarprocessing << " on processing \n" 
                         <<"  Your total spend is: $" << totalproductioncost 
                         << "\n  Total money made is: $" << totalbarsmade  
                         <<"\n  Your total profit is: $" << totaloreprofit << "\n\n";
                    }
                    break;
                  }

                  break;
              }


              case 7:
              {

                std::cout << "\n  How much profit per bar\n\n  ";
                int gbarprof;
                std::cin >> gbarprof;

                std::cout << "\n  Price per bar?\n\n  ";
                int gbarprice;
                std::cin >> gbarprice;

                std::cout << "\n  Amount of bars?\n\n  ";
                int gbaramount;
                std::cin >> gbaramount;

                        float totalgbarprocessing = gbaramount * goldproccesorcost; // gets the total processing cost
                        float totalgbarpreprofit = gbarprof * gbaramount; // gets the total profitmade
                        float totalgsellprice = gbarprice * gbaramount; // the actual total made
                        float totalmatcost = gbarprof + goldproccesorcost; // gets the total cost to make a bar
                        float totalgbarmakecost = totalmatcost * gbaramount; // total cost of all bars
                        float totalgbarsellprice = gbarprice - totalgbarmakecost; // the sell price after process for 1 bar
                        float importantsell = gbarprice - goldproccesorcost - gbarprof; // gets the actual costs
                        float totalpernugget = importantsell / 100 ; // gets the sell price per nuggets
                        float totalprofitmade = gbarprof * gbaramount; // profit
                    




                         std::cout <<"\n  Max gold nugget buy price: $" << totalpernugget <<"\n"   
                         <<"  Your total spend is: $" << totalgbarprocessing 
                         << "\n  Total money made is: $" << totalgsellprice  
                         <<"\n  Your total profit is: $" << totalprofitmade << "\n\n";
                    }

              break;

         case 9:
          {

            std::cout << "\n  Carton calc: will get ingrediants and costs needed to craft cartons. \n" <<
            "  Swamp calc: will get the ingrediants and costs needed to craft swamp joints.\n"<<
            "  Moonshine calc : will get the ingrediants and costs needed to make moonshine.\n"<<
           "  Tobacco calc : takes tobacco amount and finds how many cartons you can make and how much rolling paper you will need.\n" <<
           "  Gold calculator: tells you how much gold you can make and how much it costs. \n\n";

            }
            break;
            }
          }
        }
      }
    } 
     while(menumain != 0);
}
