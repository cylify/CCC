import java.util.ArrayList;
import java.util.Scanner;

class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int C = in.nextInt();
        in.nextLine();
        ArrayList<ArrayList<Integer>> tiles = new ArrayList<>();
        int ans = 0;
        for(int i = 0; i < 2; ++i) {
            ArrayList<Integer> temp = new ArrayList<>();
            String line = in.nextLine();
            for(String s : line.split(" ")) {
                temp.add(Integer.valueOf(s));
            }
            tiles.add(temp);
        }
        ArrayList<Integer> arrI = tiles.get(0);
        ArrayList<Integer> allNums = new ArrayList<>();
        for(int i = 0; i < arrI.size(); ++i) {
            if(arrI.get(i).equals(0))
                continue;
            else {
                allNums.add(i);
                ans += 3;
                if(i + 1 < arrI.size()) {
                    if(arrI.get(i + 1).equals(1)) {
                        allNums.add(i + 1);
                        i++;
                        ans -= 1;
                        ans += 2;
                    }
                }
            }
        }
        ArrayList<Integer> arr2 = tiles.get(1);
        for(int i = 0; i < arr2.size(); ++i) {
            if(arr2.get(i).equals(0)) {
                continue;
            } else {
                for(Integer n : allNums) {                
                    if(i == n) {
                        if(arr2.get(i).equals(1)) {
                            if(i +1 < arr2.size()) {
                                ans += 3;
                                ans -= 1;
                            }
                        }
                    }
                }
            }
        }
        in.close();
        System.out.println(ans);
    }
}