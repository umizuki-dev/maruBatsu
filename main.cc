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
    /* row numbers for moves */
    std::cout << i << "|";
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

int main() {
  Board gameBoard;

  while(true) {
    clear();
    printBoard(gameBoard);
    while (!canPlayMove(gameBoard)) {
      std::cout << "Illegal move. Please try again.\n";
    }
    gameBoard.switchTurn();
  }

  return 0;
}
