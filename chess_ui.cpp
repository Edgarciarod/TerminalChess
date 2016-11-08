//
// Created by edgar on 5/11/16.
//

#include "chess_ui.h"



void ChessUI::draw(const std::unordered_map <std::string, std::string> &pieces) {
    bool is_white_skak = true;
    for(int row=8; row >= 1; --row) {
        std::cout << row << " ";

        for (char col = 'a'; col <= 'h'; ++col)  {

            std::string skak_location;
            skak_location += col;
            skak_location += std::to_string(row);

            if(is_white_skak)
                std::cout << termcolor::on_white;
            else
                std::cout << termcolor::on_grey;

            is_white_skak = not is_white_skak;

            if(pieces.find(skak_location) != pieces.end()) {
                if(pieces.find(skak_location)->second[0] == 'w')
                    std::cout << termcolor::green;
                else
                    std::cout << termcolor::red;

                std::cout << ' ' << pieces.find(skak_location)->second[1];
            }
            else
                std::cout << "  ";
        }
        is_white_skak = not is_white_skak;
        std::cout << termcolor::reset << '\n';
    }

    std::cout << "  a b c d e f g h\n";

}


