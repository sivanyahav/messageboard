#include <iostream>
#include "Board.hpp"
using namespace std;
using namespace ariel;

const char defaultChar = '_';
namespace ariel {
 

    void Board::update(unsigned int row, unsigned int col, bool flag, unsigned int num){

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
            this->minCol=min(this->minCol, col);
            this->minRow=min(this->minRow, row);

            if(flag){
                this->maxCol= max(this->maxCol, col+num+1);
                this->maxRow=max(this->maxRow, row+1);
            }
            else{
                this->maxCol=max(this->maxCol, col+1);
                this->maxRow=max(this->maxRow, row+num+1);
            }
           
            resizeBoard(this->maxRow, this->maxCol);
        }
        
    }

 //------------------------------------------------------------------------------------------
    
    /*
    This function resize board size,
    and updates the number of rows and columns
    */
    void Board::resizeBoard(unsigned int row, unsigned int col){

        this-> board.resize(row);

        for(unsigned int i=0; i < row; i++){
            board.at(i).resize(col,defaultChar);
        }

    }

//------------------------------------------------------------------------------------------

    /*
    This function writes to the message board 
    and if necessary increases the size of the board.
    */
    void Board::post(unsigned int row, unsigned int col, Direction d, string const &message){
        unsigned int messageSize = message.length();
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


        for(int i=0; i<num; i++){
            try
            {
                s+=board.at(row).at(col);
            }
            catch(const std::exception& e)
            {
                s+="_";
            }
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

