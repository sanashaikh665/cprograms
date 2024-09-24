#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() {
        board.resize(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void displayBoard() const {
        std::cout << "Current Board:\n";
        for (const auto& row : board) {
            std::cout << "|";
            for (const auto& cell : row) {
                std::cout << cell << "|";
            }
            std::cout << "\n-----\n";
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool checkDraw() const {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == ' ') {
                    return false; // There's still an empty cell
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }

    void resetBoard() {
        for (auto& row : board) {
            std::fill(row.begin(), row.end(), ' ');
        }
        currentPlayer = 'X';
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
};

int main() {
    TicTacToe game;
    char playAgain;

    do {
        game.resetBoard();
        bool gameWon = false;

        while (!gameWon) {
            game.displayBoard();
            int row, col;

            std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
            std::cin >> row >> col;

            if (game.makeMove(row - 1, col - 1)) {
                if (game.checkWin()) {
                    gameWon = true;
                    game.displayBoard();
                    std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                } else if (game.checkDraw()) {
                    gameWon = true;
                    game.displayBoard();
                    std::cout << "The game is a draw!\n";
                } else {
                    game.switchPlayer();
                }
            }
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
