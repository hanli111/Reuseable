import java.util.Scanner;

public class TicTacToeTester
{
    public static void main(String[] args)
    {
        System.out.println("Let's play Tic Tac Toe! You will be asked to input two numbers. The first number is asking for the row number and the second number is asking for the column number. For example, if you input 0 and 2, it would place an X or an O on the first row, third column.");
        System.out.println();
        TicTacToe game = new TicTacToe();
        game.printBoard();
        
        Scanner input = new Scanner(System.in);
        while (!game.checkWin() && game.getTurn() < 9) {
            System.out.println("It is Player " + game.getName() + "'s turn.");
            System.out.println("What row would you like to choose?");
            int userRowIndex = input.nextInt();
            System.out.println("What column would you like to choose?");
            int userColIndex = input.nextInt();
            
            if (game.pickLocation(userRowIndex, userColIndex)) {
                game.takeTurn(userRowIndex, userColIndex);
            } else {
                System.out.println("No location found! Please try again.");
            }
            game.printBoard();
        }
        
        if (!game.checkWin()) {
            System.out.println("Tie!");
        } else {
            System.out.println("Player " + game.getWinName() + " won!");
        }
    }
}
