
#include <iostream>
#include "Board.hpp"
using namespace std;
using namespace ariel;

const char defaultChar = '_';
namespace ariel {

     unsigned int Board:: updateRows(unsigned int n1, unsigned int n2, bool flag, unsigned int num){
         unsigned int max=0;
            //Optionaly for max Row
            if(n1>n2){
                if(flag){
                    if(n2-1<this->minRow){ this->minRow=n2-1;}
                }
                else{
                    if(n2-num-1< this->minRow){ this->minRow=n2-num;}
                }
                 
                if(n1>this->maxRow){this->maxRow=n1;}
                max=n1;
            }

            else{
                if(flag){
                    if(n1-1<this->minRow){this->minRow=n1-1;}
                }
                else{
                    if(n1-num-1<this->minRow){this->minRow=n1-num;}
                }
                
                if(n2>this->maxRow){this->maxRow=n2;}
                max=n2;
            }

        
        return max;      
    }

//------------------------------------------------------------------------------------------

    unsigned int Board:: updateCols(unsigned int n1, unsigned int n2, bool flag, unsigned int num){
        unsigned int max=0;

        if(n1>n2){
            if(flag){
                if(n2-num-1<this->minCol){ this->minCol=n2-num;}
            }
            else{
                if(n2-1<this->minCol){this->minCol=n2-1;}
            }
            if(n1>this->maxCol){this->maxCol=n1;}
            max=n1;
        }

        else{
            if(flag){
                if(n1-num-1<this->minCol){this->minCol=n1-num;}
            }
            else{ 
                if(n1-1<this->minCol){ this->minCol=n1-1;}
            }
            if(n2>this->maxCol){this->maxCol=n2;}
            max=n2;
        }
        return max;      
    }

 //------------------------------------------------------------------------------------------

    void Board::update(unsigned int row, unsigned int col, bool flag, unsigned num){

        //first time we update the board
        if(this->maxRow==0 && this->minRow==INT32_MAX && this->maxCol==0 && this->minCol==INT32_MAX){
             if (flag){
                this->maxRow=row+1;
                this->maxCol=col+num;
                this->minRow=row;
                this->minCol=col;
             }
             else{
                this->maxRow=row+num;
                this->maxCol=col+1;
                this->minRow=row;
                this->minCol=col;
             }
             resizeBoard(this->maxRow, this->maxCol);
        }

        else{
            flag? resizeBoard(updateRows(this->maxRow, row+1, flag, num),updateCols(this->maxCol, col+num+1, flag, num)):
                  resizeBoard(updateRows(this->maxRow, row+num+1, flag, num),updateCols(this->maxCol, col+1, flag, num));
        }
        
    }

 //------------------------------------------------------------------------------------------
    
    /*
    This function resize board size,
    and updates the number of rows and columns
    */
    void Board::resizeBoard(unsigned int row, unsigned int col){

        this-> board.resize(row);

        for(int i=0; i < row; i++){
            board.at(i).resize(col,defaultChar);
        }

    }

//------------------------------------------------------------------------------------------

    /*
    This function writes to the message board 
    and if necessary increases the size of the board.
    */
    void Board::post(unsigned int row, unsigned int col, Direction d, const string &message){
        int messageSize = message.length();
        bool flag = (d == Direction::Horizontal);

        update(row,col,flag,messageSize);

        for (char ch: message){
        board.at(row).at(col) = ch;
        flag? col++ : row++;
        }
    
    }

//------------------------------------------------------------------------------------------

    /*
    This function reads messages from the message board
    and if necessary increases the size of the board, and
    updates the default characters.
    */
    string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int num){
        string s;
        bool flag = (d == Direction::Horizontal);

        update(row,col,flag,num);

        for(int i=0; i<num; i++){
            s+=board.at(row).at(col);
            flag? col++ : row++;
        }
        
        return s;
    }

 //------------------------------------------------------------------------------------------
    void Board::show(){

        for (unsigned int i = this->minRow; i < this->maxRow; i++) {
            cout << i << ": ";
           
            for (unsigned int j = this->minCol; j < this->maxCol; j++) {
                    cout << this->board[i][j];
            }
            cout<< "\n";
        }
        cout << "\n" << endl;
    }
}

