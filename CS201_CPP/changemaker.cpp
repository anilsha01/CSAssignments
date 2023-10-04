// create a cpp program that takes money in a vending machine and gives back the change. The machine is initially stocked with 25 of each coin.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int change(float deposited_money, float total_price, int stock_quarters, int stock_nickels, int stock_dimes, int stock_ones, int stock_fives);
char restart();


//int nickel_stock=25, dime_stock=25, quarter_stock=25, ones_stock=0, fives_stock=0;


int main()
{   cout<< "Change Maker Initialized."<<endl;
    float price;
    //assuming stock and value of coins
    double nickel=0.05, dime=0.10, quarter=0.25, ones=1, fives=5;
    static int nickel_stock=25, dime_stock=25, quarter_stock=25, ones_stock=0, fives_stock=0;
do {
    cout<<"Contents of this change maker:\n"<<nickel_stock<<" nickels\n"<<dime_stock<<" dimes\n" <<quarter_stock<<" quarters\n"<< ones_stock
        <<" ones\n"<<fives_stock<<" fives"<<endl;

    //prompt user for price in the form xx.xx, non-negative only
    while (true)
    {
        cout<<"Enter a price in the form (xx.xx): ";
        cin>>price;
        if (price<0)
        {
            cout<<"Invalid price. Price should be non-negative."<<endl;
            cout<<"Enter a price in the form (xx.xx): ";
           // cin>>price;
        }
        else
            break;
    }
   //price verification to make sure price is a multiple of 0.05
    while (true)
    {
        int is_multiple= int(price*100)%5;
       
        if (int(price*100)%5!= 0)
        {
            cout<<"Invalid price. Price should be a multiple of 0.05."<<endl;
            cout<<"Enter a price in the form (xx.xx): ";
            cin>>price;
         }
        else
            break;
    }

    //converting price to dollars and cents
    int dollars, cents;
    dollars=int(price/1.0);
   // cents=100*(fmod(price,1));
    //cout<<100*(price-dollars);
    cents=int(100*(price-dollars));
    
    cout<< "Menu for deposits:\n'n' - deposit a nickel\n'd' - deposit a dime\n"<<"'q' - deposit a quarter\n'o' - deposit a one dollar bill\n"
        <<"'f' - deposit a five dollar bill\n'c' - cancel the purchase\n"<<"Payment due: "<<int(price/1.0)<<" dollars and "<<100*(price-dollars)<<" cents."<<endl;
    
    float money_deposited;
    int fives_change=0, ones_change=0, quarter_change=0, dime_change=0, nickel_change=0;
    
    while (price>0)
    {
        char selection;
        cout<<"Price"<<price<<"Enter selection"<<endl;
        
        cin>>selection;
        switch(selection)
        {
            case 'n': case 'N':
                price-=nickel;
                nickel_stock++;
                nickel_change++;
                money_deposited+=nickel;
                dollars=int(price/1.0);
                cents=100*(price-dollars);
                if (price<0)
                {
                    change(money_deposited, price, quarter_stock, dime_stock,nickel_stock,ones_stock,fives_stock);
                }
                else if (price==0.00)
                {
                    cout<<"Thank you for your payment."<<endl;
                }
                else
                {
                    cout<<"Payment due: "<<int(price/1.0)<<" dollars and "<<100*(price-dollars)<<" cents."<<endl;
                }
                break;
            case 'd': case 'D':
                price-=dime;
                dime_stock++;
                dime_change++;
                money_deposited+=dime;
                dollars=int(price/1.0);
                cents=100*(price-dollars);
                if (price<0)
                {
                    change(money_deposited, price, quarter_stock, dime_stock,nickel_stock,ones_stock,fives_stock);
                }
                else if (price==0.00)
                {
                    cout<<"Thank you for your payment."<<endl;
                }
                else
                {
                    cout<<"Payment due: "<<int(price/1.0)<<" dollars and "<<100*(price-dollars)<<" cents."<<endl;
                }
                break;
            case 'q': case 'Q':
                price-=quarter;
                quarter_stock++;
                quarter_change++;
                money_deposited+=quarter;
                dollars=int(price/1.0);
                cents=100*(price-dollars);
                if (price<0)
                {
                    cout<<"'inside quarter price <0'";
                    change(money_deposited, price, quarter_stock, dime_stock,nickel_stock,ones_stock,fives_stock);
                }
                else if (price==0.00)
                {
                    cout<<"Thank you for your payment."<<endl;
                }
                else
                {
                    cout<<"Payment due: "<<int(price/1.0)<<" dollars and "<<100*(price-dollars)<<" cents."<<endl;
                }
                break;
            case 'o': case 'O':
                price-=ones;
                ones_stock++;
                ones_change++;
                money_deposited+=ones;
                dollars=int(price/1.0);
                cents=100*(price-dollars);
                if (price<0)
                {
                    change(money_deposited, price, quarter_stock, dime_stock,nickel_stock,ones_stock,fives_stock);
                }
                else if (price==0.00)
                {
                    cout<<"Thank you for your payment."<<endl;
                }
                else
                {
                     cout<<"Payment due: "<<int(price/1.0)<<" dollars and "<<100*(price-dollars)<<" cents."<<endl;
                }
                break;
            case 'f': case 'F':
                price-=fives;
                fives_stock++;
                fives_change++;
                money_deposited+=fives;
                dollars=int(price/1.0);
                cents=100*(price-dollars);
                if (price<0)
                {
                    change(money_deposited, price, quarter_stock, dime_stock,nickel_stock,ones_stock,fives_stock);
                }
                else if (price==0.00)
                {
                    cout<<"Thank you for your payment."<<endl;
                }
                else
                {
                    cout<<"Payment due: "<<int(price/1.0)<<" dollars and "<<100*(price-dollars)<<" cents."<<endl;                }
                break;
            case 'c': case 'C':
                do
                {
                    cout<<"Please take the change below:\n";
                    if (fives_change>0)
                    {
                        cout<<fives_change<<" fives\n";
                        fives_stock-=fives_change;
                    }
                    if (ones_change>0)
                    {
                        cout<<ones_change<<" ones\n";
                        ones_stock-=ones_change;
                    }
                    if (quarter_change>0)
                    {
                        cout<<quarter_change<<" quarters\n";
                        quarter_stock-=quarter_change;
                    }
                    if (dime_change>0)
                    {
                        cout<<dime_change<< "dimes\n";
                        dime_stock-=dime_change;
                    }
                    if (nickel_change>0)
                    {
                        cout<<nickel_change<<" nickels"<<endl;
                        nickel_stock-=nickel_change;
                    }
                }
                while (restart()=='Y');
                //restart();
                break;
            default:
            {
                cout<<"Invalid selection.";
                break;
            }
        }
        
    }
}
while (restart()=='Y');
    //restart();
    return 0;
}
int change(float deposited_money, float total_price, int stock_quarters, int stock_dimes, int stock_nickels
, int stock_ones, int stock_fives)
{
    int quarter_change=0, dime_change=0, nickel_change=0, ones_change=0, fives_change=0;
    
    float overpayment=total_price*(-1.0);
    

    do
    {
      
        if (stock_fives>=1)
       // if (stock_fives>=1)
        {
            while (overpayment>=5.0)
            {
                overpayment-=5.0;
                fives_change++;
                stock_fives--;
            }
        
        }
        if (stock_ones>=1)
        //else if (stock_ones>=1)
        {
            while (overpayment>=1.0)
            {
                overpayment-=1.0;
                ones_change++;
                stock_ones--;
            }
       
        }
        
        if (stock_quarters>=1)
        //else if (stock_quarters>=1)
        {
            while (overpayment>=0.25)
            {
            overpayment-=0.25;
            quarter_change++;
            stock_quarters--;
            }
          
        }
        if (stock_dimes>=1)
        //else if (stock_dimes>=1)
        {
            while (overpayment>=0.10)
            {
                overpayment-=0.10;
                dime_change++;
                stock_dimes--;
            }
          
        }
        if (stock_nickels>=1)
       // else if (stock_nickels>=1)
        {
            while (overpayment>=0.05)
            {
                overpayment-=0.05;
                nickel_change++;
                stock_nickels--;
            }
         
        }
       /*else
        {
          do
            {
                cout<<"Please take the change below:\n";
                if (fives_change>0)
                {
                    cout<<fives_change<<" fives\n";
                }
                if (ones_change>0)
                {
                    cout<<ones_change<<" ones\n";
                }
                if (quarter_change>0)
                {
                    cout<<quarter_change<<" quarters\n";
                }
                if (dime_change>0)
                {
                    cout<<dime_change<< "dimes\n";
                }
                if (nickel_change>0)
                {
                    cout<<nickel_change<<" nickels"<<endl;
                }
                cout<<"Inside this while loop indu";
            }while (false);
            cout<<"Contents of this change maker:\n"<<stock_nickels<<" nickels\n"<<stock_dimes<<" dimes\n"<<stock_quarters<<" quarters\n"<<stock_ones
                <<" ones\n"<<stock_fives<<" fives"<<endl;
            break;
        }*/
    }
    while (false);
    //cout<<"Take the change"<<nickel_change<<" "<<quarter_change<<" "<<dime_change<<" "<<ones_change<<" "<<fives_change<<endl;
    do
    {
        cout<<"Please take the change below:\n";
        if (fives_change>0)
        {
            cout<<fives_change<<" fives\n";
        }
        if (ones_change>0)
        {
            cout<<ones_change<<" ones\n";
        }
        if (quarter_change>0)
        {
            cout<<quarter_change<<" quarters\n";
        }
        if (dime_change>0)
        {
            cout<<dime_change<< "dimes\n";
        }
        if (nickel_change>0)
        {
            cout<<nickel_change<<" nickels"<<endl;
        }
    }
    while (false);
    

    int dollars=int(overpayment/1.0);
    int cents=100*(overpayment-dollars);
    if (overpayment>0)
    {
        cout<<"Machine is out of change. Please see store manager for remaining refund.\n"
            <<"Amount remaining: "<<int(overpayment/1.0)<<" dollars and "<<100*(overpayment-dollars)<<" cents."<<endl;
    }
    cout<<"Contents of this change maker:\n"<<stock_nickels<<" nickels\n"<<stock_dimes<<" dimes\n"<<stock_quarters<<" quarters\n"<<stock_ones
        <<" ones\n"<<stock_fives<<" fives"<<endl;
return 0;
}

char restart()
{
    cout<<"Do you want to continue? Enter Y/N: ";
    char selection;
    cin>>selection;
    switch (selection)
    {
        case 'Y': case 'y':
           // main();
           return 'Y';
            break;
        case 'N': case 'n':
            cout<<"Have a good day!"<<endl;
            return 'N';
            break;
    }
    return 'W';
}





