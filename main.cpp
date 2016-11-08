#include <iostream>
#include "chess_engine.h"
#include "chess_ui.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    std::unordered_map<std::string, std::string> initial_board = {
        {"a1","wR"}, {"b1","wN"}, {"c1","wB"}, {"d1","wQ"}, {"e1","wK"}, {"f1","wB"}, {"g1","wN"}, {"h1","wR"},
        {"a2","wP"}, {"b2","wP"}, {"c2","wP"}, {"d2","wP"}, {"e2","wP"}, {"f2","wP"}, {"g2","wP"}, {"h2","wP"},
        {"a7","bP"}, {"b7","bP"}, {"c7","bP"}, {"d7","bP"}, {"e7","bP"}, {"f7","bP"}, {"g7","bP"}, {"h7","bP"},
        {"a8","bR"}, {"b8","bN"}, {"c8","bB"}, {"d8","bQ"}, {"e8","bK"}, {"f8","bB"}, {"g8","bN"}, {"h8","bR"}
    };

    ChessUI chess_ui;
    ChessEngine chess_engine(initial_board);

    std::string active_player = "White";
    bool success = true;
    while(not chess_engine.is_check_mate()) {
        std::cout << '\n' << active_player <<"'s player turn\n\n";

        auto current_board = chess_engine.get_board_state();
        chess_ui.draw(current_board);


        std::string player_move;
        std::cout << "Your move: ";
        std::cin >> player_move;
        if(chess_engine.try_move(player_move, tolower(active_player[0])) == false) {
            std::cout << "\nInvalid move!\n";

        }
        else {
            active_player = (active_player == "White")?"Black":"White";
        }

    }

    return 0;
}