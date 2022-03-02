import java.io.*;

public class Guess {
    private static final int max = 30;
    private static final int min = 0;
    private static final int maxChance = 5;

    public static void main(String[] args) throws IOException {
        System.out.println("Guess the Number");
        System.out.println("\nGuess the number lying b/w: "+min+"-"+max+" (exclusive)");
        System.out.println("You've got "+maxChance+" chances\n");
        int chance = 1;
        int number = (int)(Math.random()*10);
        while (chance <= maxChance) {
            int guess = Integer.parseInt(input("Chance "+chance+": "));
            if (guess == number) {
                System.out.println("You won");
                break;
            } else {
                String status = findDistance(max, number, guess);
                System.out.println("Guess was: "+status);
            }
            if (chance == maxChance) {
                System.out.println("You lost, number was: "+number);
            }
            chance++;
        }
    }

    public static String findDistance(float _max, int num, int guess) {
        int distance = guess - num;
        int factor = _max/5 < 1 ? 1 : (int) _max/5;
        String status;
        if (Math.abs(distance) < factor) {
            status = distance < 0 ? "Lower" : "Higher";
        } else {
            status = distance < 0 ? "Much Lower" : "Much Higher";
        }
        return status;
    }

    public static String input(String label) throws IOException {
        InputStreamReader read = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(read);
        System.out.print(label);
        return in.readLine().trim();
    }
}
