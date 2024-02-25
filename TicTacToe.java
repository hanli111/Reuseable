public class TicTacToe
{
   //copy over your methods from the Tic Tac Toe Methods activity in the previous lesson!
   private int turn;
   private String[][] array;
    
    public TicTacToe() {
        array = new String[3][3];
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length; j++) {
                array[i][j] = "-";
            }
        }
    }

   //this method returns the current turn
   public int getTurn()
   {
       return turn;
   }
   
   /*This method prints out the board array on to the console
   */
   public void printBoard()
   {
        System.out.println("  0 1 2");
        for (int i = 0; i < array.length; i++) {
            System.out.print(i + " ");
            for (int j = 0; j < array[i].length; j++) {
                System.out.print(array[i][j] + " ");
            }
            System.out.println();
        }
   }
   
   //This method returns true if space row, col is a valid space
   public boolean pickLocation(int row, int col)
   {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[row].length; j++) {
                if (array[row][col] != "X" && array[row][col] != "O") {
                    return true;
                }
            }
        }
        return false;
   }
   
   //This method places an X or O at location row,col based on the int turn
   public void takeTurn(int row, int col)
   {
        if (turn % 2 == 0) {
            array[row][col] = "X";
        } else {
            array[row][col] = "O";
        }
        turn++;
   }
   
   public String getName() {
       String name = "";
       if (turn % 2 == 0) {
           name = "X";
       } else {
           name = "O";
       }
       return name;
   }
   
   public String getWinName() {
       String name = "";
       if (turn % 2 == 0) {
           name = "O";
       } else {
           name = "X";
       }
       return name;
   }
   
   //This method returns a boolean that returns true if a row has three X or O's in a row
   public boolean checkRow()
   {
       /*int x = 0;
       int o = 0;
       for (int i = 0; i < array.length; i++) {
           for (int j = 0; j < array[i].length; j++) {
               if (array[i][j].equals("X")) {
                   x++;
               } else if (array[i][j].equals("O")) {
                   o++;
               }
           }
       }
       
       if (x == 3 || o == 3) {
           return true;
       }
       return false;*/
       
       for (int i = 0; i < array.length; i++) {
           if (array[i][0].equals("X") || array[i][0].equals("O")) {
               if (array[i][0].equals(array[i][1]) && array[i][1].equals(array[i][2])) {
                   return true;
               }
           }
       }
       return false;
   }
   
    //This method returns a boolean that returns true if a col has three X or O's
   public boolean checkCol()
   {
       /*int x = 0;
       int o = 0;
       for (int i = 0; i < array[0].length; i++) {
           for (int j = 0; j < array.length; j++) {
               if (array[i][j].equals("X")) {
                   x++;
               } else if (array[i][j].equals("O")) {
                   o++;
               }
           }
       }
       
       if (x == 3 || o == 3) {
           return true;
       }
       return false;*/
       
       for (int i = 0; i < array[0].length; i++) {
           if (array[0][i].equals("X") || array[0][i].equals("O")) {
               if (array[0][i].equals(array[1][i]) && array[1][i].equals(array[2][i])) {
                   return true;
               }
           }
       }
       return false;
   }
   
    //This method returns a boolean that returns true if either diagonal has three X or O's
   public boolean checkDiag()
   {
        //checks right to left diagonal
        int x = 0;
        int o = 0;
        for (int i = 0, j = 2; i < array.length; i++, j--) {
            if (array[i][j].equals("X")) {
                x++;
            } else if (array[i][j].equals("O")) {
                o++;
            }
        }
        
        if (x == 3 || o == 3) {
            return true;
        }
        return false;
        
        /*if (array[0][1].equals("X") || array[0][0].equals("O")) {
            if (array[0][2].equals(array[1][1]) && array[1][1].equals(array[2][0])) {
                return true;
            }
        }
        return false;*/
   }
   
   public boolean checkDiag2() {
       //checks left to right diagonal
        int x = 0;
        int o = 0;
        for (int i = 0; i < array.length; i++) {
            if (array[i][i].equals("X")) {
                x++;
            } else if (array[i][i].equals("O")) {
                o++;
            }
        }
        if (x == 3 || o == 3) {
            return true;
        }
        return false;
   }
   
   //This method returns a boolean that checks if someone has won the game
   public boolean checkWin()
   {
       return (checkCol() || checkRow() || checkDiag() || checkDiag2());
   }

}
