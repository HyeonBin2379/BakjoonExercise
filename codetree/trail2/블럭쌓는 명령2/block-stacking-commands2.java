import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] array = new int[N];

        int K = sc.nextInt();
        for (int i = 0; i < K; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();

            for (int j = A-1; j < B; j++) {
                array[j]++;
            }
        }

        // Please write your code here.
        int answer = 0;
        for (int i = 0; i < N; i++) {
            answer = Math.max(array[i], answer);
        }
        System.out.println(answer);
    }
}