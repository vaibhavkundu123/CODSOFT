#include <iostream>
#include <array>

const int kBoardSize = 3;
std::array<std::array<char, kBoardSize>, kBoardSize> board{};

void InitializeBoard() {
    for (int i = 0; i < kBoardSize; ++i) {
        for (int j = 0; j < kBoardSize; ++j) {
            board[i][j] = ' ';
        }
    }
}

void DisplayBoard() {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < kBoardSize; ++i) {
        std::cout << i + 1 << ' ';
        for (int j = 0; j < kBoardSize; ++j) {
            std::cout << board[i][j];
            if (j != kBoardSize - 1) {
                std::cout << '|';
            }
        }
        std::cout << std::endl;
        if (i != kBoardSize - 1) {
            std::cout << "  -+-+-" << std::endl;
        }
    }
}

bool MakeMove(int row, int col, char player) {
    if (row >= 0 && row < kBoardSize && col >= 0 && col < kBoardSize && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool HasWon(char player) {
    // Check rows
    for (int i = 0; i < kBoardSize; ++i) {
        bool has_won = true;
        for (int j = 0; j < kBoardSize; ++j) {
            if (board[i][j] != player) {
                has_won = false;
                break;
            }
        }
        if (has_won) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < kBoardSize; ++j) {
        bool has_won = true;
        for (int i = 0; i < kBoardSize; ++i) {
            if (board[i][j] != player) {
                has_won = false;
                break;
            }
        }
        if (has_won) {
            return true;
        }
    }

    // Check diagonals
    bool has_won = true;
    for (int i = 0; i < kBoardSize; ++i) {
        if (board[i][i] != player) {
            has_won = false;
            break;
        }
    }
    if (has_won) {
        return true;
    }

    has_won = true;
    for (int i = 0; i < kBoardSize; ++i) {
        if (board[i][kBoardSize - i - 1] != player) {
            has_won = false;
            break;
        }
    }
    if (has_won) {
        return true;
    }

    return false;
}

bool IsDraw() {
    for (int i = 0; i < kBoardSize; ++i) {
        for (int j = 0; j < kBoardSize; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void PlayGame() {
    InitializeBoard();
    char player = 'X';
    while (true) {
        DisplayBoard();
        int row, col;
        std::cout << "Player " << player << ", enter your move (row column): ";
        std::cin >> row >> col;
        --row, --col;

        while (!MakeMove(row, col, player)) {
            std::cout << "Invalid move. Try again." << std::endl;
            std::cout << "Player " << player << ", enter your move (row column): ";
            std::cin >> row >> col;
            --row, --col;
        }

        if (HasWon(player)) {
            DisplayBoard();
            std::cout << "Player " << player << " wins!" << std::endl;
            break;
        } else if (IsDraw()) {
            DisplayBoard();
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        player = player == 'X' ? 'O' : 'X';
    }
}

int main() {
    while (true) {
        PlayGame();
        char play_again;
        std::cout << "Do you want to play again? [Y/N]: ";
        std::cin >> play_again;

        if (!(play_again == 'Y' || play_again == 'y')) {
            break;
        }
    }
    return 0;
}
