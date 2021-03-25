#include <iostream>
#include <stdexcept>
#include <ctime>
#include <thread>
#include <chrono>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;
using ariel::Direction;



int main() {
    srand((unsigned)time(0));
    ariel::Board b;
    string message;
    uint r, c, d, l;
    bool flag=true;
    for(int i=0; flag; i++){
        
        cout << "-----------------------------\n" << flush;
        this_thread::sleep_for(chrono::milliseconds(600));

        unsigned int option;
        cout << "\nDo you want to post a message(press 1) or read a message(press 2)?\n";
        cin >> option;

        if(option == 1){
            cout << "\nEnter vertical or horizontal direction(1 or 2)\n";
            cin >> d ;
            

            if(d!=1 && d!=2){
                cout <<"\n"<<d<< " is ot an option"<<endl;
                flag=false;
            }

            else
            {
                cout << "\nEnter num of row and col, and the desired massege"<<endl;
                cin >> r >> c >> message; 
                
                if(d==1){
                b.post(/*row=*/r, /*column=*/c, Direction::Vertical, message);
                }
                
                else{
                b.post(/*row=*/r, /*column=*/c, Direction::Horizontal, message);
                }
            }
            
        }

        else if(option==2) {
            cout << "\nEnter Vertical or Horizontal direction(1 or 2)\n";
            cin >> d;

            if(d!=1 && d!=2){
                cout <<"\n"<<d<< " is ot an option"<<endl;
                flag=false;
            }
            
            else{
                
                cout << "\nEnter num of row and col, and the desired length\n";
                cin >> r >> c >> l;

                cout << "\nThe message is:\n";
                if(d==1){
                    cout << b.read(/*row=*/r, /*column=*/c, Direction::Vertical, l) << endl;
                }
                else{
                    cout << b.read(/*row=*/r, /*column=*/c, Direction::Horizontal, l) << endl;
                }
            }
            
        }
        
        else{
            cout << "\n" <<option<< " is ot an option" << endl;
            flag =false;
        }
        
        if(flag){
         cout << "Do you want to continue? Press 1 if so,  otherwise 0" << endl;
          cin >> flag;
        }
        
        if(!flag){cout << "bye bye !! " << endl;}
    }
}
