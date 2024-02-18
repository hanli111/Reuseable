import java.util.Scanner;
import java.util.Arrays;

public class Mastermind {
    public static void main(String[] args) {
        System.out.println("Hello, and welcome to MasterMind!");
        System.out.println("-----------------------------------------------------------------------");
        System.out.println("Your goal is to successfully guess four numbers ranging from 1-7 in the correct order. My secret numbers will be a set of four different values.");
        System.out.println("-----------------------------------------------------------------------");
        System.out.println("Each time you make a guess, I will give a color response of three options: BLACK, RED, WHITE");
        System.out.println("BLACK = A number you guessed isn't one of the secret numbers.");
        System.out.println("WHITE = A number you guessed IS one of the secret numbers, but not in the PLACE where you guessed it.");
        System.out.println("RED = A number you guessed IS one of the secret numbers, and IS where you guessed it.");
        Scanner input = new Scanner(System.in);
        int numOfGuesses = 5;
        int[] theNumber = createCompList();
        System.out.println("Let's Play!");
        System.out.println("Guesses Remaining: " + numOfGuesses);
        System.out.println("Enter 4 numbers as guesses:");
        while (numOfGuesses > 0) {
            int[] userInput = getGuess();
            checkValues(userInput, theNumber);
            numOfGuesses--;
            System.out.println();
            System.out.println("Guesses Remaining: " + numOfGuesses);
            if (Arrays.equals(userInput, theNumber)) {
                break;
            }
            
            if (numOfGuesses == 0) {
                System.out.println("Sorry! That's all the guesses you get!");
                System.out.print("The actual number was ");
                for (int i = 0; i < theNumber.length; i++) {
                    System.out.print(theNumber[i]);
                }
                System.out.println(".");
            }
        }
        System.out.println("Thanks for Playing!");
    }
    
    // Copy over methods from the previous exercises
    public static int[] createCompList() {
        int[] answer = new int[4];
        for (int i = 0; i < answer.length; i++) {
            int number = (int)(Math.random() * 7 + 1);
            answer[i] = number;
        }
        
        boolean duplicate = false;
        while (!duplicate) {
            boolean isDuplicate = false;
            
            for (int i = 0; i < answer.length; i++) {
                for (int j = i + 1; j < answer.length; j++) {
                    if (answer[i] == answer[j]) {
                        int number = (int)(Math.random() * 7 + 1);
                        while (answer[i] == number) {
                            number = (int)(Math.random() * 7 + 1);
                        }
                        answer[j] = number;
                        isDuplicate = true;
                    }
                }
                duplicate = !isDuplicate;
            }
        }
        /*for (int i = 0; i  < answer.length; i++) {
            System.out.println(answer[i]);
        }*/
        return answer;
    }
    
    public static int[] getGuess() {
        // Write your code here
        Scanner input = new Scanner(System.in);

        while (true) {
            
            //System.out.println("Enter 4 numbers as guesses: ");
            int[] userGuessList = new int[4];
            String userGuess = input.nextLine();
            
            for (int i = 0; i < 4; i++) {
                userGuessList[i] = Integer.parseInt(userGuess.substring(i, i+1));
                continue;
            }
            
            if (userGuess.length() != 4) {
                System.out.println("Your guess must consist of 4 numbers!");
                continue;
                
            }
            
            for (int i = 0; i < 4; i++) {
                if (userGuessList[i] < 1 || userGuessList[i] > 7) {
                    System.out.println("You can only use numbers 1-7 as guesses!");
                    continue;
                }
            }
            
            for (int i = 0; i < userGuessList.length; i++) {
                for (int j = i + 1; j < userGuessList.length; j++) {
                    if (userGuessList[i] == userGuessList[j]) {
                        System.out.println("You can only use each number once!");
                        continue;
                    }
                }
            }

            return userGuessList;
        }
         
    }
    
    public static int checkValues(int[] numArray, int[] guesses) {
        // Write your code here
        String[] clue = new String[4];
        for (int j = 0; j < 4; j++) {
            int index = searchArray(numArray, guesses[j]);
            if (numArray[j] == guesses[j]) {
                clue[j] = "RED";
            } else if (index == -1) {
                clue[j] = "BLACK";
            } else {
                clue[j] = "WHITE";
            }
        }
        
        for (int i = 0; i < clue.length; i++) {
            System.out.print(clue[i] + " ");
        }
        return checkWin(clue);
    }
    
    public static int searchArray(int[] nums, int value) {
        // Define and use this helper function
        for (int i = 0; i < 4; i++) {
            if (nums[i] == value) {
                return i;
            }
        }
        return -1;
    }
    
    public static String[] shuffle(String[] values) {
        for (int i = 0; i < values.length; i++) {
            int ranIndex = (int)(Math.random() * 4);
            String temp = values[ranIndex];
            values[ranIndex] = values[i];
            values[i] = temp;
        }
        return values;
    }
    
    public static int checkWin(String[] responseList) {
        // Write your code here
        int correctVal = 0;
        for (int i = 0; i < responseList.length; i++) {
            if (responseList[i].equals("RED")) {
                correctVal++;
            }
        }
        if (correctVal == 4) {
            System.out.println("You won!");
        }
        
        return correctVal;
    }
}
