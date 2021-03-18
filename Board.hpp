#pragma once

#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {

    class Board {

        private:
        int rows, cols;
        vector<vector<char>> board;
        void resizeBoard(int row, int col);

        public:
            Board(){
                board=vector<vector<char>>(5, vector<char>(5,'_'));
                rows=5;
                cols=5;
             };
            void post(int row, int col, Direction d, string message);
            string read(int row, int col,Direction d, int num);
            void show();
    };
}
