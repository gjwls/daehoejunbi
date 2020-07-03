import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static int min_last(int[][] a, int end){
        int min = 1000000000;
        int index = -1;
        for (int i = 0; i < a.length; i++) {
            if (a[i][1] < min && end < a[i][0]) min = i;
        }
        if(min == 1000000000)
            return -1;
        for (int i = 0; i < a.length; i++) {
            if(a[i][1] == min){
                index = min;
                break;
            }
        }
        if(index == -1)
            return -1;
        return index;
    }
    static int[][] sche_cal(int[][] sche){
        int end = -1;
        ArrayList<Integer> arr = new ArrayList<>();
        while(true){
            if(min_last(sche, end) == -1)
                break;
            arr.add(min_last(sche,end));
            end = sche[min_last(sche, end)][1];
        }
        int j = 0;
        int[][] new_arr = new int[sche.length - arr.size()][2];
        for (int i = 0; i < sche.length - arr.size(); i++) {
            while(arr.lastIndexOf(j) != -1) j++;
            new_arr[i][0] = sche[j][0];
            new_arr[i][1] = sche[j][1];
        }
        return new_arr;
    }
    static int ans_cal(int[][] sche){
        int end = -1;
        ArrayList<Integer> arr = new ArrayList<>();
        while(true){
            if(min_last(sche, end) == -1)
                break;
            arr.add(min_last(sche,end));
            end = sche[min_last(sche, end)][1];
        }
        return arr.size();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int rank = sc.nextInt();
        int[][] sche = new int[n][2];
        for (int i = 0; i < n; i++) {
            sche[i][0] = sc.nextInt();
            sche[i][1] = sc.nextInt();
        }
        for (int i = 0; i < rank -1; i++)
            sche = sche_cal(sche);
        System.out.println(ans_cal(sche));
    }
}
