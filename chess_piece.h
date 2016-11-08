//
// Created by edgar on 7/11/16.
//

#ifndef TERMINALCHESS_CHESS_PIECE_H
#define TERMINALCHESS_CHESS_PIECE_H


class ChessPiece {
public:
    char color;
    char piece_type;

    ChessPiece() : color(' '), piece_type(' ') {}

    ChessPiece(std::string piece_notation) {
        color = piece_notation[0];
        piece_type = piece_notation[1];
    }

    std::string get_notation() {
        char r[] = {color, piece_type};
        return std::string(r, r+2);
    }
};


#endif //TERMINALCHESS_CHESS_PIECE_H
