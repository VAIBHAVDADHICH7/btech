// Exp 1: Complex Arithmetic, Matrix Multiplication, and Tower of Hanoi
public class Exp01_JavaFundamentals {
    static void towerOfHanoi(int n, char from, char aux, char to) {
        if (n == 1) { System.out.println("Move disk 1 from " + from + " to " + to); return; }
        towerOfHanoi(n - 1, from, to, aux);
        System.out.println("Move disk " + n + " from " + from + " to " + to);
        towerOfHanoi(n - 1, aux, from, to);
    }

    public static void main(String[] args) {
        int[][] A = {{1, 2}, {3, 4}}, B = {{5, 6}, {7, 8}}, C = new int[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++) C[i][j] += A[i][k] * B[k][j];

        System.out.println("Matrix Product:");
        for (int[] row : C) System.out.println(row[0] + " " + row[1]);

        System.out.println("\nTower of Hanoi (3 disks):");
        towerOfHanoi(3, 'A', 'B', 'C');
    }
}
