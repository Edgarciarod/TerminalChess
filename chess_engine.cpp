//
// Created by edgar on 7/11/16.
//

#include <unordered_map>
#include "chess_engine.h"



ChessEngine::ChessEngine(const std::unordered_map <std::string, std::string> &pieces) {
    for(auto piece :pieces) {
        int col = piece.first[0]-'a';
        int row = 7-(piece.first[1]-'1');

        board_state[row][col] = ChessPiece(piece.second);
    }
}

std::pair<std::pair<int,int>, std::pair<int,int>> ChessEngine::parse_move(std::string move) {
    int col1 = move[0]-'a';
    int row1 = 7-(move[1]-'1');

    int col2 = move[3]-'a';
    int row2 = 7-(move[4]-'1');

    return std::make_pair(std::make_pair(row1, col1), std::make_pair(row2, col2));
};

bool ChessEngine::try_move(std::string player_move, char player) {
    auto parsed_move = parse_move(player_move);

    int row_i = parsed_move.first.first; // initial row
    int col_i = parsed_move.first.second;// initial column

    int row_d = parsed_move.second.first; // destiny row
    int col_d = parsed_move.second.second;// destiny columna

    if(board_state[row_i][col_i].color != player)
        return false;


    board_state[row_d][col_d] = board_state[row_i][col_i];
    board_state[row_i][col_i] = ChessPiece();


    return true;
}

std::unordered_map<std::string, std::string> ChessEngine::get_board_state() {
    std::unordered_map<std::string, std::string> pieces;

    for(int8_t i = 0; i < 8; ++i) {
        for (int8_t j = 0; j < 8; ++j) {
            char r = '8'-i, c = 'a'+j;
            char square_notation[] = {c, r};
            pieces[std::string(square_notation)] = ChessPiece(board_state[i][j]).get_notation();
        }
    }

    return pieces;
}

bool ChessEngine::is_check_mate() {
    return check_mate;
}

