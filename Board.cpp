
#include <iostream>
#include "Board.hpp"
using namespace std;
using namespace ariel;

const char defaultChar = '_';
namespace ariel {

    void Board::resizeBoard(int row, int col){

        this-> rows =row;
        this->cols =col;
        this-> board.resize(row);

        for(int i=0; i < row; i++){
            board.at(i).resize(col,defaultChar);
        }

    }

    void Board::post(int row, int col, Direction d, string message){
        int messageSize = message.length();
        bool flag = (d == Direction::Horizontal);

        if(flag){
            resizeBoard(std :: max(this->rows, row+1), std::max(this->cols, col+messageSize+1));
        
        }
        else{
            resizeBoard(std :: max(this->rows, row+messageSize+1), std::max(this->cols, col+1));
        }

        for (int i = 0; i < messageSize; i++){
        board.at(row).at(col) = message[i];
        flag? col++ : row++;
        }
    
    }


    string Board::read(int row, int col, Direction d, int num){

        string s;
        bool flag = (d == Direction::Horizontal);

        flag? resizeBoard(std::max(this->rows,row+1),std::max(this->cols,col+num+1)):
              resizeBoard(std::max(this->rows,row+num+1),std::max(this->cols,col+1));


        for(int i=0; i<num; i++){
            s+=board.at(row).at(col);
            flag? col++ : row++;
        }
        
        return s;
    }


    void Board::show(){

        for (int i = 0; i < this->rows; i++) {
            cout << i << ": ";
            for (int j = 0; j < this->cols; j++) {
                cout << this->board[i][j];
            }
            cout<< "\n";
        }
        cout << "\n" << endl;
    }
}

