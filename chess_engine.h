//
// Created by edgar on 7/11/16.
//

#ifndef TERMINALCHESS_CHESS_ENGINE_H
#define TERMINALCHESS_CHESS_ENGINE_H

#include <unordered_map>
#include <string>
#include "chess_piece.h"

class ChessEngine {
private:
    ChessPiece board_state[8][8];
    std::pair<std::pair<int,int>, std::pair<int,int>> parse_move(std::string);
    bool check_mate = false;
public:
    ChessEngine(const std::unordered_map <std::string, std::string> &pieces);
    bool try_move(std::string player_move, char player);
    std::unordered_map <std::string, std::string> get_board_state();
    bool is_check_mate();
};


#endif //TERMINALCHESS_CHESS_ENGINE_H
