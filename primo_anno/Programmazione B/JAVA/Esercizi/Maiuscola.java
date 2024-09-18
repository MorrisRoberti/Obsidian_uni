import java.util.Scanner;

public class Maiuscola {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String k = sc.nextLine();
        char capitalLetter = k.charAt(0);
        String x = Character.toUpperCase(capitalLetter) + k.substring(1);
        System.out.println(x);
        sc.close();
    }
}
