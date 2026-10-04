import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] x1 = new int[n];
        int[] x2 = new int[n];
        for (int i = 0; i < n; i++) {
            x1[i] = sc.nextInt();
            x2[i] = sc.nextInt();
        }

        // Please write your code here.
        int[] array = new int[2*100+1];
        for (int i = 0; i < n; i++) {
            for (int j = x1[i]; j < x2[i]; j++) {
                array[j+100]++;
            }
        }

        int answer = 0;
        for (int i = 0; i < array.length; i++) {
            answer = Math.max(array[i], answer);
        }
        System.out.println(answer);
    }
}