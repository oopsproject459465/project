 #include <iostream>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;
class Number{
public:
    int num1,num2,sum,extraCard;
};

    const string RESET = "\e[0m";   //Format Mode 0
    const string BOLD_HIGHLIGHT  = "\e[1;7m";   //Format Modes 1 and 7
    const string COMPLEX_FORMAT_1 = "\x1b[5;1;3;35;44m";  //Format Modes 5, 1, 2, 35 and 44
    const string COMPLEX_FORMAT_2 = "\x1b[4;30;42m";      //Format Modes 4, 30 and 42
    const string COMPLEX_FORMAT_3 = "\x1b[5;1m";
    
void printCard1(int num1,int num2, int num3, int sum);
void printCard2(int num1,int num2, int sum);
bool playAgain(char x,int money);
int winnerFunction(int bankerCard, int playerCard); 
int declareWinner(int winner, int decision, int bet); 


int main(){

    system ("Color 2F"); 
    srand(time(NULL)); 

    
    std::string name;
    int bet, decision, winner, prize;
    char play;
    bool logic = true;
    int money = 10000;

    cout<< "\t\t\t\t\x1b[4m\x1b|^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^| \x1b[0m\x1b[0m" << endl;
    cout<<"\t\t\t\t\t\t \x1b[4m\x1b[1mTO START,PLEASE ENTER YOUR CARD \x1b[0m\x1b[0m"<< endl;
    cout<< "\t\t\t\t\x1b[4m\x1b|^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^||^| \x1b[0m\x1b[0m" << endl;
    
    cout<< "\n\x1b[7m\tENTER YOUR NAME :\x1b[0m ";
    getline(cin, name);
    system("clear"); 
    cout<< "\n\t\t\x1b[33m HELLO! , " << name <<"\x1b[0m"<< endl;
    cout<< "\n\n\t\t\t\t<$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$>\n";
    cout<< "\n\t\t\t\t\t\t \x1b[32mWELCOME\x1b[0m \x1b[33m TO \x1b[0m \x1b[34mBACCARAT TABLE\x1b[0m\n";
    cout<< "\n\n\t\t\t\t<$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$><$>\n";
    int i=0;
    do{ 
        if (i==1)
        system("clear");
        cout<< "\n\n\t\tYOUR CURRENT BALANCE , PHP " << BOLD_HIGHLIGHT<<money << RESET<<endl;
        cout<<"\n\t\t"<<COMPLEX_FORMAT_2<<"1"<<RESET<<"-"<<COMPLEX_FORMAT_2<<"BANKER"<<RESET;
        cout<<"\n\n\t\t"<<COMPLEX_FORMAT_1<<"2"<<RESET<<"-"<<COMPLEX_FORMAT_1<<"PLAYER "<<RESET;
        cout<< "\n\n\t\tCHOOSSE YOUR BET [PLAYER or BANKER] \n";
        cout<<"\t\tPRESS 1 for BANKER"<<"\n\t\tPRESS 2 for PLAYER\n\t\t\t\t\t";

        
        while(!(cin >> decision)|| (decision < 1 || decision > 2)){
            cin.clear();
            cout<<"INVALID CHOICE!,\n\tPLEASE ENTER A VALID CHOICE....";
            //cout<< "\n\n\t\tCHOOSSE YOUR BET [PLAYER or BANKER] \n";
            //cout<<"\t\tPRESS 1 for BANKER"<<"\n\t\tPRESS 2 for PLAYER";
        }

       do{
      
        cout<< "\n\t\t Place your bet, PHP: ";
        cin >> bet;
       }while(bet > money);



        
        cout<< "\n\n\t\t\t\t<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>\n";
        cout<< "\t\t\t\t^\t\t" << "BANKER'S CARD" <<"\t\t\t^\n";
        cout<< "\t\t\t\t<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>\n\n";

        
        Number banker;
        banker.num1 = rand() % 10 + 1;
        banker.num2 = rand() % 10 + 1;
        banker.sum = banker.num1 + banker.num2;
        banker.sum = banker.sum % 10;

        //checks if card is natural win 8 or 9
        if(banker.sum != 9 && banker.sum != 8){

            banker.extraCard = rand() % 10 + 1; //Third and extra card
            banker.sum += banker.extraCard;
            banker.sum = banker.sum % 10; //gets remainder of 3 cards as final card
        
        //prints banker's card
        printCard1(banker.num1, banker.num2, banker.extraCard, banker.sum);
        }
        else{
        //Natural win 8 or 9 and prints cards
        printCard2(banker.num1, banker.num2, banker.sum);
        }


        //PLAYER CARDS
        cout<< "\n";
        cout<< "\n\n\t\t\t\t<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>\n";
        cout<< "\t\t\t\t^\t\t" << "PLAYER'S CARD" <<"\t\t\t^\n";
        cout<< "\t\t\t\t<+><+><+><+><+><+><+><+><+><+><+><+><+><+><+><+>\n\n";

        //random number generator for 2 cards
        Number player;
        player.num1 = rand() % 10 + 1;
        player.num2 = rand() % 10 + 1;
        player.sum = player.num1 + player.num2;
        player.sum = player.sum % 10;

        //checks if 2 cards are natural win 8 or 9
        if(player.sum != 9 && player.sum != 8){

            player.extraCard = rand() % 10 + 1; //Third and extra card
            player.sum += player.extraCard;
            player.sum = player.sum % 10; //gets remainder of 3 cards as final card
            
        //function to print card of players
        printCard1(player.num1,player.num2,player.extraCard,player.sum);
        }
        else{

        //natural win 8 or 9, print card of player
        printCard2(player.num1, player.num2, player.sum);
        }

    //declaration of winner
    winner = winnerFunction(banker.sum, player.sum);

    //awards prize for winner, 1:1 for winner;
    prize = declareWinner(winner, decision, bet);
    cout<< "\x1b[46m PHP " << prize <<  "\x1b[0m\n";
    money += prize;
    cout<< "\x1b[46m Current Money, PHP " << money << " \x1b[0m\n\n";

    //Asks the user if he wants to play again
    cout<< "\x1b[46m PLAY AGAIN? Y/N  \x1b[0m";
    cin >> play;
    logic = playAgain(play,money);
    i++;
    }while(logic != false);

}
int i=0;
void printCard1(int num1,int num2, int num3, int sum){
    
    if(i==0)
    {
    cout<< "\t\t\t\t\t\t\x1b[43m|<><><*><><>|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[43m|>|       |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[43m|>|   *   |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[43m|>|*  " << sum  << "  *|<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[43m|>|   *   |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[43m|>|       |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[43m|<><><*><><>|\x1b[0m\n";
    i=1;
    }
    else
    {
    cout<< "\t\t\t\t\t\t\x1b[45m|<><><*><><>|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[45m|>|       |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[45m|>|   *   |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[45m|>|*  " << sum  << "  *|<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[45m|>|   *   |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[45m|>|       |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[45m|<><><*><><>|\x1b[0m\n"; 
    i=0;
    }

    cout<< "\n\x1b[40m FIRST CARD " << num1 << "\x1b[0m\n";
    cout<< "\x1b[41m SECOND CARD " << num2 << "\x1b[0m\n";
    cout<< "\x1b[42m EXTRA CARD " << num3<<"\x1b[0m";
    //cout<< "CARD "<< sum << "\n";
}
void printCard2(int num1,int num2, int sum){

    cout<< "\t\t\t\t\t\t\x1b[46m|<><><*><><>|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[46m|>|       |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[46m|>|   *   |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[46m|>|*  " << sum  << "  *|<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[46m|>|   *   |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[46m|>|       |<|\x1b[0m\n";
    cout<< "\t\t\t\t\t\t\x1b[46m|<><><*><><>|\x1b[0m\n";
    cout<< "\n\x1b[44mTHIS IS A NATURAL WIN  8/9 \x1b[0m\n";
    cout<< "\x1b[45mFIRST CARD " << num1 << "\x1b[0m\n";
    cout<< "\x1b[46mSECOND CARD " << num2<<"\x1b[0m";
    //cout<< "CARD " << sum << "\n";
}

bool playAgain(char x,int money){

    if(money > 0){

        if(x == 'Y' || x == 'y'){

            return true;
        }else if(x == 'N' || x == 'n'){

            cout<< "\x1b[46mTHANK YOU FOR PLAYING!\x1b[0m";
            return false;
        }
    }else{

        cout<< "\x1b[46mINSUFFICIENT FUND!\x1b[0m";
        return false;
    }

}

int winnerFunction(int bankerCard, int playerCard){
    //function to determine nearest number to 9
    //returns 1,2,3 depending on condiiton met

    cout<< "\n\n\n>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<>^<\n\n";
    if(bankerCard > playerCard){

        cout<< "\n\x1b[46mBANKER WIN, \x1b[0m";
        return 1;
    }else if( bankerCard < playerCard){

        cout<< "\n\x1b[46mPLAYER WIN, \x1b[0m";
        return 2;

    }else if(bankerCard == playerCard){

        cout<< "\n\x1b[46mDRAW, \x1b[0m";
        return 3;
    }
}
int declareWinner(int winner, int decision, int bet){

    if(winner == decision){

        //win pays the bet
        cout<< "\x1b[46mYOU WIN!\x1b[0m\n";
        return bet;
    }if (winner == 3){

        //draw
        cout<< "\x1b[46mTIE GAME!\x1b[0m" << endl;
        return 0;
    }else{

        cout<< "\x1b[46mYOU LOSE!\x1b[0m\n";
        bet *= -1;
        return bet;
    }

}
