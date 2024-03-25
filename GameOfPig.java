import java.util.*;

public class Pig
{
    public static void main(String[] args)
    {
        // Start here!
        System.out.println("Welcome to the Game of Pig! \n");
        System.out.println("The Game of Pig is a classic game played with a 6 sided die. \n");
        System.out.println("In the game you rolls a die. If you roll a 2 through 6, you add that score to your round score, but if you roll a 1, your round is over and your round score resets to zero. At any point, you can choose to bank your round score. When you do that, the points are added to your overall score and your round score resets back to zero. \n"); 
        System.out.println("Once the your overall score reaches 100, you win. While the die roll is random, there is a little strategy when deciding whether to bank or continue in the round. If you try to be a pig and get more points, you may lose everything and have to start over!");
        System.out.println();
        System.out.println("You will be playing against a computer. Let's go!");
        System.out.println();
        
        Scanner input = new Scanner(System.in);
        int turn = 1;
        //boolean play = false;
        
        // keep track of user scores
        int currentScore = 0;
        int roundScore = 0;
        
        // keep track of computer scores
        int computerCS = 0;
        int computerRS = 0;
        
        while (currentScore < 100 || computerCS < 100) {
            System.out.println("Turn " + turn);
            if (currentScore >= 100 && computerCS >= 100) {
                if (currentScore > computerCS) {
                    System.out.println("You win!");
                } else {
                    System.out.println("The Computer wins!");
                }
            }
            
            if (currentScore >= 100) {
                turn--;
                System.out.println("Congratulations! You won on " + turn + " turns!");
                break;
            }
            
            if (computerCS >= 100) {
                turn--;
                System.out.println("Good try! The Computer won on " + turn + " turns.");
                break;
            }
            
            System.out.println("Your Current Score is: " + currentScore);
            System.out.println("This round you have: " + roundScore);
            System.out.print("Would you like to roll or bank? ");
            String userInput = input.nextLine();
            System.out.println();
            
            // user turns
            int randomNumber = (int) (Math.random() * 6 + 1);
            if (userInput.equals("roll")) {
                System.out.println("You rolled a " + randomNumber);
                roundScore += randomNumber;
                if (randomNumber == 1) {
                    System.out.println("You rolled a 1! You get a zero for this round!");
                    roundScore = 0;
                    turn++;
                    System.out.println("It is the computer's turn now.");
                    System.out.println();
                    
                    // computer turns
                    while (computerRS <= 15) {
                        int computerRN = (int) (Math.random() * 6 + 1);
                        if (computerRN == 1) {
                            System.out.println("The computer rolled a 1. End of turn.");
                            computerRS = 0;
                            System.out.println("It is the user's turn now.");
                            System.out.println();
                            break;
                        }
                            
                        System.out.println("The computer rolled a " + computerRN);
                        computerRS += computerRN;
                        System.out.println("This round the computer has " + computerRS);
                        System.out.println();
                                        
                        if (computerRS > 15) {
                            System.out.println("The computer chooses to bank.");
                            computerCS += computerRS;
                            computerRS = 0;
                            System.out.println("Computer Current Score is: " + computerCS);
                            System.out.println();
                            break;
                        }
                    }
                }
            } else if (userInput.equals("bank")) {
                turn++;
                currentScore += roundScore;
                roundScore = 0;
                
                // computer turns
                while (computerRS <= 15) {
                    int computerRN = (int) (Math.random() * 6 + 1);
                    if (computerRN == 1) {
                        System.out.println("The computer rolled a 1. End of turn.");
                        computerRS = 0;
                        System.out.println("It is the user's turn now.");
                        System.out.println();
                        break;
                    }
                            
                    System.out.println("The computer rolled a " + computerRN);
                    computerRS += computerRN;
                    System.out.println("This round the computer has " + computerRS);
                    System.out.println();
                            
                    if (computerRS > 15) {
                        System.out.println("The computer chooses to bank.");
                        computerCS += computerRS;
                        computerRS = 0;
                        System.out.println("Computer Current Score is: " + computerCS);
                        System.out.println();
                        break;
                    }
                }
            }
        }
    }
}
