#include <iostream>
#include <cstdlib>
using namespace std;

int numDays ();
int departTime();
int arrivalTime();
double numAirfare(),numCarRental(),povCost(),parkingCost(),taxiFees(),conferenceFees(),hotelFees(),bajetmakan;
double dailyEats(double, double, double);
double allowedMeals = bajetmakan, totalMealCost = 0;
int main()
{

  int days = 0;
    int depart, arrive = 0;
    double airfare = 0;
    double miles = 0;
    double carRental = 0;
    double taxi = 0;
    double confCost = 0;
    double hotel = 0;
    double vehicleExpense = 0;
    double totalExp,budget;
    double userFees;

    cout << "What is your budget for this trip?" <<endl;
    cin >> budget;
    cout << "What is your budget for Meals?" <<endl;
     cin >> bajetmakan;
    days = numDays();
    depart = departTime();
    arrive = arrivalTime();
    airfare = numAirfare();
    miles = povCost();
    vehicleExpense = miles * .27;
    carRental = numCarRental();
    taxi = taxiFees();
    confCost = conferenceFees();
    hotel = hotelFees();

    dailyEats(depart,arrive,days);
    totalExp = airfare + vehicleExpense + carRental + taxi + hotel + miles + confCost + vehicleExpense + totalMealCost;

     cout<<"Bajet Anda ialah RM" << budget<<endl;
    cout << "Jumlah semua pembayaran yang ditanggung: RM" << totalExp << endl;
    budget=totalExp-budget;
    
    if(totalExp>budget)
    {
	cout << "Tanggungan anda melebihi bajet anda RM "<< budget<<endl;
	}
    else if(totalExp<=budget){
	cout<<"Tanggungan anda tidak melebihi bajet anda RM" << budget <<endl;
	}
    else{}
    return 0;
}

int numDays()
{
    int days;
    cout << "How many days were you on the trip?: ";
    cin >> days;
    cout << endl;

    while (days < 1)
    {
        cout << "The number must be greater than 0, try again: ";
        cin >> days;
        cout << endl;

    }
    return days;
}

int departTime(){

    int depart;
    int hour,minute;
    char day;
    cout<<"did you leave in the morning or the afternoon?\n type in A for AM or P for PM.\n";
    cin>>day;

     while(day!='a'&&day!='A'&&day!='P'&&day!='p')
    {cout<<"Please enter either P or A\n";
        cin>>day;
    }

    switch(day){

        case 'a':case'A':
            cout<<"Enter the hour of departure\n";
            cin>>hour;


            while(hour<0||hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }

            cout<<"Enter the minute of departure\n";
            cin>>minute;

            while(minute<=0|minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }
            
            hour=100*hour;
            depart=hour+minute;
            return depart;
            break;
            default:

            cout<<"Enter the hour of departure\n";
            cin>>hour;
            
            while(hour<0|hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }
            cout<<"Enter the minute of departure\n";
            cin>>minute;

            while(minute<=0||minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }
            if(hour==12)
            {hour=hour*100;
                depart=hour+minute;
            }
            else
            {

                hour=hour*100;
                depart=hour+minute+1200;
            }

            return depart;
            break;
    }

}

	int arrivalTime()
{
    int arrive;
    int hour,minute;
    char day;
    cout<<"did you leave in the morning or the afternoon?\n type in A for AM or P for PM.\n";
    cin>>day;
    while(day!='a'&&day!='A'&&day!='P'&&day!='p')
    {cout<<"Please enter either P or A\n";
        cin>>day;
    }

    switch(day)
    {
    	case 'a':case'A':
            cout<<"Enter the hour of arrival\n";
            cin>>hour;

             while(hour<0||hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }

	         cout<<"Enter the minute of arrival\n";
            cin>>minute;
           
            while(minute<=0|minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }

            hour=100*hour;
            arrive=hour+minute;
            return arrive;
            break;

            default:

            cout<<"Enter the hour of arrival\n";
            cin>>hour;
            while(hour<0|hour>12)
            {cout<<"Please enter a correct time\n";
                cin>>hour;
            }
            cout<<"Enter the minute of arrival\n";
            cin>>minute;

            while(minute<=0||minute>60){
                cout<<"please enter the correct time\n";
                cin>>minute;
            }

            if(hour==12)
            {hour=hour*100;
                arrive=hour+minute;
            }

             else{

                hour=hour*100;
                arrive=hour+minute+1200;
            }
            return arrive;
            break;
    }

}


double numAirfare ()
{
	double airfare;
    cout << "What was the total cost of air fare?: RM ";
    cin >> airfare;
    cout << endl;

    while (airfare < 0)
    {
        cout << "The number must be greater than 0, try again: ";
        cin >> airfare;
        cout << endl;
    }

    return airfare;
}

double numCarRental ()
{
    double carRental;
    cout << "What was the total cost of car rentals?: RM ";
    cin >> carRental;
    cout << endl;

    while (carRental < 0)
    {
        cout << "The number must be greater than 0, try again: ";
        cin >> carRental;
        cout << endl;
    }

    return carRental;
}

double povCost()
{
    double miles;
    char answer;

    cout<<"Did you travel via privately owned vehicle? Y or N\n";
    cin>>answer;

    if(answer!= 'Y'&&answer!='y'&&answer!='n'&&answer!='N')
    {
        cout<<"Type Y for yes, or N for no.\n";
        cin>> answer;
    }

    switch(answer)
    {

        case 'y':case 'Y':
            cout<<"How many miles did you travel?\n";
            cin>>miles;
            
            if(miles<=0)
            {
                cout<<"Please enter the miles traveled.\n";
                cin>>miles;
            }

            return miles;
            break;

        default:
            miles = 0;
            return miles;
            break;
    }
}

double taxiFees()
{
    double taxiFee;
    cout << "How much was spent on taxi fees? RM";
    cin >> taxiFee;
    cout << endl;

    while (taxiFee<0)
    {
        cout << "Please enter a positive value.  ";
        cin >> taxiFee;
    }

    return taxiFee;
}

double conferenceFees()
{
    double confFee;
    cout << "How much was spent on conference/seminar fees? RM";
    cin >> confFee;
    cout << endl;

    while (confFee<0)
    {
        cout << "Please enter a positive value.  ";
        cin >> confFee;
    }

    return confFee;
}

double hotelFees()
{
    double hotelFee;
    cout << "How much was spent on hotel fees? RM";
    cin >> hotelFee;
    cout << endl;

    while (hotelFee<0)
    {
        cout << "Please enter a positive value.  ";
        cin >> hotelFee;
    }

    return hotelFee;
}

double dailyEats(double departureTime, double arrivalTime, double tripDays)
{
    int i, x, setX = 0, fDayMealStart = 0, onlyOnce = 0;
    double cost = 0, bExpense = 0;
    string mealType[3] = {"breakfast", "lunch", "dinner"};
    cout<<"Limit untuk makan adalah RM"<<bajetmakan<<endl;
    int mealMax[3];
    string answer = "";

     for(i = 1;i <= tripDays;i++){
     	setX = 0;
     	if(fDayMealStart == 0 && i == 1){
     		if(arrivalTime >= 0 && arrivalTime <= 699){
     			cout << "Nyatakan Breakfast Lunch and Dinner anda pada hari pertama.";
                fDayMealStart++;
                 }else if(arrivalTime >= 700 && arrivalTime < 1200){
                 	cout << "Lunch dan Dinner sahaja pada hari pertama. \n";
                 	setX = 1; fDayMealStart++;
                 	}else if(arrivalTime >= 1200 && arrivalTime < 1800){
                 		cout << "Dinner sahaja yang sempat anda makan pada hari pertama\n";
                     setX = 2; fDayMealStart++;
                     }else if(arrivalTime >= 1800 && arrivalTime <= 2400){
                cout << "Sorry xdew makan apa2 pada hari pertama.Dah lebih 6pm. \n";
                setX = 3; fDayMealStart++;
            }
        }
     if(i == tripDays){
            if(0 <= departureTime && departureTime <= 800){
                mealType[0] = "0"; mealType[1] = "0"; mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nMaaf,anda tidak sempat untuk makan apa2 sebab belum jam 8.am lagi"<<i<<". \n"; onlyOnce++;}
            }else if(800 < departureTime && departureTime <= 1300){ 
                mealType[1] = "0"; mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nBreakfast sahaja sempat selepas jam 8am-1pm pada hari terakhir. \n"; onlyOnce++;}
            }else if(1300 < departureTime && departureTime <= 1900){ 
                mealType[2] = "0";
                if(onlyOnce == 0){cout << "\nBreakfast & Lunch sahaja selepas jam 1pm-7pm pada hari terakhir. \n"; onlyOnce++;}
            }else if(1900 < departureTime && departureTime <= 2400){ 
                if(onlyOnce == 0){cout << "\nMeals sahaja selepas jam 7pm-11.59pm "<<i<<". \n"; onlyOnce++;}
        }   }

        for(x = setX;x < 3;x++){ 
            if(mealType[x] != "0"){
                cout << "\nDid you have " << mealType[x] << " on day " << i << "? [Y/N]: ";
                cin >> answer;
                if(answer == "Y" || answer == "y"){
                	cout << "\nBerapah nilai modal untuk makan?:"<< mealType[x] << " on day " << i<<endl;
                	cin >>mealMax[i];
                	
                    cout << "\nHarga cost yang anda membelanjakan??:"<<endl;
                    cin >> cost;
                    
                     while(cost < 0){
                        cout << "Really? So you were paid to eat there?\n";
                        cout << "Please CORRECTLY enter the amount spent, value more than RM0: ";
                        cin >> cost;
                    }
                    if(cost >= mealMax[x]){
                        if(cost == mealMax[x]){
                            allowedMeals = allowedMeals + mealMax[x];
                            totalMealCost = totalMealCost + cost;
                            cout <<"\nFor"<< mealType[x] << " \nBagus..same dgn bajet: RM" << mealMax[x] << endl;
                        }
						else if(cost > mealMax[x]){
                            int hutang;
                            
                            bExpense = cost - mealMax[x];
                            hutang=bExpense;
                            if(cost == 0)
							{
                              cout << mealType[x] << " Anda tak makan apa2: RM"<<bExpense<<"\n\n";
                            } else {
                              cout << mealType[x] << " Anda Telah melebihi bajet sebanyak: RM"<< bExpense<<endl;
                              cout <<".\nHutang sebanyak RM: "<<hutang<<".\n";
                            }
                        }
                    }else if(cost < mealMax[x]){
                        int balance;
                        balance=cost - bExpense;
                        bExpense=cost;
						
						
						
                        cout <<  mealType[x] << " Anda telah membelanjankan sebanyak: RM" << bExpense << endl;
						cout<<"Balance"<<balance;
                    }
                } else if(answer == "N" || answer == "n"){
                    cout << "No " << mealType[x] << ", got it. \n"; }
                else if(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
                    while(answer != "Y" || answer != "y" || answer != "N" || answer != "n"){
                        cout << "\nI didnt quite get that. ";
                        cout << "Did you have " << mealType[x] << " on day " << i << " ? [Y/N]: ";
                        cin >> answer;
                        if(answer == "Y" || answer == "y" || answer == "N" || answer == "n"){
                        if(answer == "Y" || answer == "y")
						{cout << "\nBerapah nilai modal untuk makan?:"<< mealType[x] << " on day " << i<<endl;
                       	cin >>mealMax[i];
						cout << "\nHarga cost makan berapa ?:";
						cin >> cost;
						while(cost < 0)
						{cout << "Error\n";
						cout << "Please CORRECTLY enter the amount spent, value more than RM0: ";
						cin >> cost;
						}
						if(cost >= mealMax[x]){
						if(cost == mealMax[x])
						{allowedMeals = allowedMeals + mealMax[x];
						totalMealCost = totalMealCost + cost;
                        cout <<"\nFor"<< mealType[x] << " \nBagus..same dgn bajet: RM" << mealMax[x] << endl;
						}
						else if(cost > mealMax[x])
						{
				      	int hutang;
                        bExpense = cost - mealMax[x];
                        hutang=cost - bExpense;
						if(cost == 0){
						cout << mealType[x] << " Anda tak makan apa2: RM"<<bExpense<<".\n\n";}
					    else {
						cout << mealType[x] << " Anda Telah melebihi: RM"<< bExpense;
                        cout <<".\nMelebihi RM: "<<hutang<<".\n";}
						}}
						else if(cost < mealMax[x])
						{bExpense = cost - mealMax[x];
                         int balance;
						 balance=cost - bExpense;
						
						cout <<  mealType[x] << " Anda telah membelanjankan sebanyak: RM" << bExpense << endl;
						cout<<"Balance"<<balance;}
						}
						else if(answer == "N" || answer == "n"){
						cout << "No " << mealType[x] << ", got it. \n"; }
                             break;
                        }
                    }
                }
           
            }
        }
    }

}
