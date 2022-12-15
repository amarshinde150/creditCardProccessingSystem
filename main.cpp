#include<bits/stdc++.h>
using namespace std;
class ShopKeeper;
class Card{
    string cardNumber;
    int m;
    int y;
    string cvv;
    string pin;
    public:

        void setCardDetails(string cardNumber,int month,int year,string cvv,string pin){
            this->cardNumber = cardNumber;
            this->m = month;
            this->y = year;
            this->cvv = cvv;
            this->pin = pin;
        }
        void getCardDetails(string &cardNumber,int &month,int &year,string &cvv){
            //Card details
            cardNumber = this->cardNumber;
            month = this->m;
            year = this->y;
            cvv = this->cvv;

            // cardNumber = "1234567890123456";
            // month = 09;
            // year = 2024;
            // cvv = "745";

        }
        bool validateDate(int cm,int cy){
            if(cy>y){
                cout<<"Invalid Card Year";
            }
            else if(cy==y){
                if(cm>=m){
                    cout<<"Invalid Card Month";
                }
                else{
                    return true;
                }
            }
            else{
                return true;
            }
        }
        bool validateCard(int cm,int cy){
            if(this->validateDate(cm,cy)){
                cout<<"Date Validated";
                if(cardNumber.size()!=16){
                    cout<<"Wrong card number"<<endl;
                }
                if(cvv.size()!=3){
                    cout<<"Wrong cvv number"<<endl;
                }
                return true;
            }
            else{
                cout<<"Wrong date"<<endl;
                return false;
            }
        }
        string getPin(){
            return pin;
        }
};
class Bank{
    private:
        Card cardDetails;
        int currentMonth = 12;
        int currentYear = 2022;
        void setCardType(){
            //ALGORITHM TO SET CARD TYPE BY EVALUATING CARDNUMBER
        }
    public:
        void setCardNumber(string cn){
            // cardNumber = cn;
            setCardType();
        }
        void getValidDate(int &m,int &y){
            //THIS FUCTION WILL RETURN CURRENT MONTH AND YEAR
            m = currentMonth;
            y = currentMonth;
        }

};
class CardReader:public Bank{
    private:
        string cn;
        int m,y;
        string cvv;
    public:
        CardReader(){

        }
        void read(Card *myCard){
            cout<<"Enter card number:";
            cin>>cn;
            cout<<"Enter month and year:";
            cin>>m>>y;
            cout<<"Enter CVV";
            cin>>cvv;
            myCard->setCardDetails(cn,m,y,cvv,"5455");
        }
        bool validate(Card *myCard){
//            Card *tCard = new Card();
//            string testCardNumber;
//            int tm;
//            int ty;
//            string testCvv;
//            myCard->getCardDetails(testCardNumber,tm,ty,testCvv);
            int mm,yy;
            this->getValidDate(mm,yy);
            myCard->validateCard(mm,yy);
        }
        void printReceipt(){

        }

};
class Cart{
    private:
        int id;
        int amount;
    public:
        Cart(){

        }
        int getAmount(){
            return amount;
        }
        void addItemAmount(int amount){
            this->amount += amount;
        }
};
class ShopKeeper{
     private:
         string name;
     public:
         // ShopKeeper(string name){
         //     this->name = name;
         // }
         void getCard(Card *myCard){
             CardReader *cr = new CardReader();
             cr->read(myCard);
             if(cr->validate(myCard) == false){
                 cout<<"wrong details"<<endl;
             }
             else{
                 cout<<"Card details are correct"<<endl;
             }
         }
         void calculate(){

         }
         void generateBill(){

         }
 };
class Customer:public CardReader {
    private:
        int customerId;
        string name;
        string address;
        string cardNumber;
        string pin;
        Cart *cart;
        Card *myCard;
    public:
        Customer(){
            name = "Ramesh";
            cardNumber = "1234543212344323";
            pin = "5453";
            cart = new Cart();
            myCard = new Card();
        }
        void selectsItem(){
            cout<<"Enter Item Prices\nEnter -1 if over:";
            int x;
            cin>>x;
            while(x!=-1){
                cart->addItemAmount(x);
                cin>>x;
            }
            cout<<"Total amount of Cart:"<<cart->getAmount()<<endl;
        }
        bool login(){
            cout<<"Enter pin:";
            cin>>pin;
            while(pin != myCard->getPin()){
                cout<<"Incorrect pin";
                return false;
            }
            cout<<"Logged In";
            return true;
        }
        void swipeCard(){
             ShopKeeper *sk = new ShopKeeper;
             sk->getCard(myCard);
            if(this->login()){
                cout<<"Amount "<<cart->getAmount()<<" paid";
            }
            else{
                this->swipeCard();
            }
        }
        bool signUp(){

            //DATA WILL BE STORED IN DATABASE IN REALTIME
            cout<<"Enter customerId:"<<endl;
            cin>>customerId;
            cout<<"Enter name:"<<endl;
            cin>>name;
            cout<<"Enter address:"<<endl;
            cin>>address;
            cout<<"Enter card number:"<<endl;
            cin>>cardNumber;
            cout<<"Enter pin:"<<endl;
            cin>>pin;
        }
};

int main(){
    Customer *c = new Customer();
    c->selectsItem();
    c->swipeCard();
    return 0;
}
