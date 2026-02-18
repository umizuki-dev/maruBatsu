#include <iostream>

enum Bit {
  Empty,
  Maru,
  Batsu
};

enum Turn { Sente,
  Gote
};

struct Move {
  int i;
  int j;
};

class Board {
  public:
    Bit bitBoard[3][3];
    Turn turn;

    Board() {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          bitBoard[i][j] = Empty;
        }
      }
      turn = Sente;
    }

    void switchTurn() {
      if (turn == Sente) {
        turn = Gote;
      } else {
        turn = Sente;
      }
    }
};

void clear() {
  for (int i = 0; i < 100; i++) {
    std::cout << "\n";
  }
}

void printBoard(Board board) {
  /* TODO: pretty print Japanese */
  std::cout << "Turn: ";
  switch (board.turn) {
    case Sente:
      std::cout << "Sente";
      break;
    case Gote:
      std::cout << "Gote";
  }
  std::cout << "\n";

  /* column numbers for moves */
  std::cout << "  123\n";
  std::cout << "  ---\n";

  for (int i = 0; i < 3; i++) {
    /* row number for moves is one more than index */
    std::cout << i + 1 << "|";
    for (int j = 0; j < 3; j++) {
      switch (board.bitBoard[i][j]) {
        case Empty:
          std::cout << "*";
          break;
        case Maru:
          std::cout << "O";
          break;
        case Batsu:
          std::cout << "X";
          break;
      }
    }

    /* must stack rows */
    std::cout << "\n";
  }
}

bool canPlayMove(Board& board) {
  Move move; 
  std::cout << "Enter row: ";
  std::cin >> move.i;

  std::cout << "Enter column: ";
  std::cin >> move.j;

  move.i -= 1;
  move.j -= 1;

  if (board.bitBoard[move.i][move.j] != Empty) {
    return false;
  } else {

    switch (board.turn) {
      case Sente:
        board.bitBoard[move.i][move.j] = Maru;
        break;
      case Gote:
        board.bitBoard[move.i][move.j] = Batsu;
        break;
    }

    return true;
  }
}

bool isMate(Board board) {
  /* horizontal search */
  for (int i = 0; i < 3; i++) {
    if (board.bitBoard[i][0] == board.bitBoard[i][1] && board.bitBoard[i][1] == board.bitBoard[i][2] && board.bitBoard[i][0] != Empty) {
      return true;
    }
  }

  /* vertical search */
  for (int i = 0; i < 3; i++) {
    if (board.bitBoard[0][i] == board.bitBoard[1][i] && board.bitBoard[1][i] == board.bitBoard[2][i] && board.bitBoard[0][i] != Empty) {
      return true;
    }
  }

  /* diagonal search */
  if (board.bitBoard[0][0] == board.bitBoard[1][1] && board.bitBoard[1][1] == board.bitBoard[2][2] && board.bitBoard[0][0] != Empty) {
    return true;
  }
  if (board.bitBoard[0][2] == board.bitBoard[1][1] && board.bitBoard[1][1] == board.bitBoard[2][0] && board.bitBoard[0][2] != Empty) {
    return true;
  }

  return false;
}


int main() {
  Board gameBoard;

  while(true) {
    clear();
    printBoard(gameBoard);

    while (!canPlayMove(gameBoard)) {
      std::cout << "Illegal move. Please try again.\n";
    }

    if (isMate(gameBoard)) {

      switch (gameBoard.turn) {
        case Sente:
          std::cout << "Sente wins.\n";
          break;
        case Gote:
          std::cout << "Gote wins.\n";
          break;
      }

      return 0;
    }

    gameBoard.switchTurn();
  }

  return 0;
}
