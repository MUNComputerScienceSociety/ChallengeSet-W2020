/**
 * Write a description of class IliketodoeverythinginoneClass here.
 *
 * @author Hking
 * @version 6.9
 */
import java.util.Scanner;
public class IliketodoeverythinginoneClass
{
    // Constant for number of threads
    private static final int nthreads = 27;
    // The input to be put here
    private static final int[][] sudoku = getSudoku();
    // This one is invalid for sure, cuz sudoku is lame
    
    /*private static final int[][] sudoku = {
        { 5, 2, 4, 5, 3, 8, 2, 8, 7 },
        { 6, 1, 7, 6, 1, 9, 6, 4, 3 },
        { 8, 3, 9, 7, 2, 4, 1, 9, 5 },
        { 1, 8, 3, 8, 6, 5, 7, 2, 9 },
        { 7, 5, 4, 2, 4, 7, 3, 6, 1 },
        { 9, 6, 2, 3, 9, 1, 4, 5, 8 },
        { 3, 7, 5, 8, 5, 6, 8, 4, 2 },
        { 9, 4, 6, 1, 9, 2, 5, 7, 3 },
        { 2, 8, 1, 4, 7, 3, 9, 1, 6 }};
        */
    /* The working one :)
     * private static final int[][] sudoku = {
        { 6, 2, 4, 5, 3, 9, 1, 8, 7 },
        { 5, 1, 9, 7, 2, 8, 6, 3, 4 },
        { 8, 3, 7, 6, 1, 4, 2, 9, 5 },
        { 1, 4, 3, 8, 6, 5, 7, 2, 9 },
        { 9, 5, 8, 2, 4, 7, 3, 6, 1 },
        { 7, 6, 2, 3, 9, 1, 4, 5, 8 },
        { 3, 7, 1, 9, 5, 6, 8, 4, 2 },
        { 4, 9, 6, 1, 8, 2, 5, 7, 3 },
        { 2, 8, 5, 4, 7, 3, 9, 1, 6 }
        };*/
        // Array for thread updates
        public static int[][] getSudoku(){
           System.out.print("Enter 2D array size : ");
           Scanner sc=new Scanner(System.in);
           int rows=sc.nextInt();
           int columns=sc.nextInt();       
           System.out.println("Enter array elements : ");            
           int twoD[][]=new int[rows][columns];
           for(int i=0; i<rows;i++)
             {            
                for(int j=0; j<columns;j++)
                {
                    twoD[i][j]=sc.nextInt();
                }
             }
           System.out.print("\nData you entered : \n");
           for(int []x:twoD){
               for(int y:x){
               System.out.print(y+"        ");
               }
               System.out.println();
            }
           return twoD;
        }
        private static boolean[] isvalid;
        // Object for thread row and columns
        public static class RowColumnObject {
            int row;
            int col;
            RowColumnObject(int row, int column) {
                this.row = row;
                this.col = column;
            }

        }   
        // Checking for uniqueness
    public static class IsRowValid extends RowColumnObject implements Runnable {
        IsRowValid(int row, int column) {    
            super(row, column);  
        }
        @Override    
        public void run() {
            if (col != 0 || row > 8) {
                System.out.println("Invalid row/column for subsection!");
                return;
            }
            // Checking
            boolean[] validityArray = new boolean[9];  
            int i;  
            for (i = 0; i < 9; i++) {       
                // If number repeats, thread exits
                int num = sudoku[row][i];
    
                if (num < 1 || num > 9 || validityArray[num - 1]) {
                    return;
                }
                else if (!validityArray[num - 1]) {
                    validityArray[num - 1] = true;
                }
            }
            // Valid here
            isvalid[9 + row] = true;
        }
    
    }
    // Checking
    public static class IsColumnValid extends RowColumnObject implements Runnable {
        IsColumnValid(int row, int column) {
            super(row, column);
        }
        @Override
    
        public void run() {
            if (row != 0 || col > 8) {
                System.out.println("Invalid row/column for the subsection!");
                return;  
            }   
            // Checking for uniqueness
            boolean[] validityArray = new boolean[9];
            for (int i = 0; i < 9; i++) {
                // If the number repeats the thread will exit here   
                int num = sudoku[i][col];
                if (num < 1 || num > 9 || validityArray[num - 1]) {  
                    return;  
                } else if (!validityArray[num - 1]) {   
                    validityArray[num - 1] = true;   
                }  
            } 
            // Subsection is valid
            isvalid[18 + col] = true;
        }
    
    }
    // Checking class
    public static class Is3x3Valid extends RowColumnObject implements Runnable {
        Is3x3Valid(int row, int column) {
            super(row, column);
        }
    
        @Override
    
        public void run() {
            // Checking
            if (row > 6 || row % 3 != 0 || col > 6 || col % 3 != 0) {
                System.out.println("Invalid row/column for subsection!");
                return;    
            }
            // Checking for uniqueness
            boolean[] validityArray = new boolean[9];
            for (int i = row; i < row + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    int num = sudoku[i][j];
                    if (num < 1 || num > 9 || validityArray[num - 1]) {
                        return;
                    } else {   
                        validityArray[num - 1] = true;
                    }
    
                }
    
            }
            //3x3 subsection is valid if it reaches here
            isvalid[row + col / 3] = true;    
        }    
    }
    public static void main(String[] args) {    
        isvalid = new boolean[nthreads];   
        Thread[] threads = new Thread[nthreads];    
        int threadIndex = 0;
        System.out.println("My Sudoku");
        for (int i = 0; i < 9; i++) {    
            for (int j = 0; j < 9; j++) {    
                System.out.print(sudoku[i][j]+"\t");    
            }    
            System.out.println();    
        }
        // Creating 27 total threads ->
        for (int i = 0; i < 9; i++) { 
            for (int j = 0; j < 9; j++) {    
                if (i % 3 == 0 && j % 3 == 0) {    
                    threads[threadIndex++] = new Thread(new Is3x3Valid(i, j));    
                }    
                if (i == 0) {    
                    threads[threadIndex++] = new Thread(new IsColumnValid(i, j));    
                }  
                if (j == 0) {    
                    threads[threadIndex++] = new Thread(new IsRowValid(i, j));    
                }    
            }    
        }
        // Starting all threads
        for (int i = 0; i < threads.length; i++) {
            threads[i].start();
        }
        // Waiting
        for (int i = 0; i < threads.length; i++) {   
            try {   
                threads[i].join();  
            } catch (InterruptedException e) {
                e.printStackTrace();    
            }   
        }
        // If anything is 0, its invavlid
        for (int i = 0; i < isvalid.length; i++) {
            if (!isvalid[i]) {
                System.out.println("invalid!");
                return;
            }
        }
        System.out.println("valid");
    }
}

