#pragma once

#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {

    class Board {

        private:
        unsigned int maxRow, maxCol, minRow, minCol;
        vector<vector<char>> board;
        void resizeBoard(unsigned int row, unsigned int col);
        unsigned int updateRows(unsigned int n1, unsigned int n2, bool flag, unsigned int num);
        unsigned int updateCols(unsigned int n1, unsigned int n2, bool flag, unsigned int num);
        void update(unsigned int row, unsigned int col, bool flag, unsigned int num);

        public:
            Board(): maxRow(0), maxCol(0),minRow(INT32_MAX), minCol(INT32_MAX){
                board=vector<vector<char>>(0, vector<char>(0,'_'));
             };
            
            void post(unsigned int row, unsigned int col, Direction d, string const &message);
            string read(unsigned int row, unsigned int col,Direction d, unsigned int num);
            void show();
    };
}
