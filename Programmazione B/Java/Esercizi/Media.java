import java.util.Scanner;

public class Media {
    public static void main(String[] args) {
        int x, y, z;
        System.out.println("Inserire tre numeri: ");
        Scanner sc = new Scanner(System.in);

        x = sc.nextInt();
        y = sc.nextInt();
        z = sc.nextInt();

        float m = ((float) (x + y + z)) / 3;
        System.out.println("La media e' " + m);
        sc.close();
    }
}