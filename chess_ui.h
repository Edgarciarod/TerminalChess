//
// Created by edgar on 5/11/16.
//

#ifndef TERMINALCHESS_CHESS_UI_H
#define TERMINALCHESS_CHESS_UI_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <cwchar>
#include "termcolor.h"



class ChessUI {
public:
    void draw(const std::unordered_map <std::string, std::string> &pieces);
};


#endif //TERMINALCHESS_CHESS_UI_H
