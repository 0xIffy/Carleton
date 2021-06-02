import java.util.Arrays;
import java.util.ArrayList;

public class ArrayPractice{
    public static void main(String[] args){
        int[] a = {3, 1, 9, 8, 2, 4, 7};
        int[] b = {11, 3, 1, 8, 9, 9, 3, 4, 5};
        int[] c = {9, 1, 3, 2, 8, 4, 3, 9, 1, 12, 15, 16};
        int[] d = {3, 1, 9, 8, 2, 4, 7};
        int[] e = {3, 1, 9, 8, 2, 4, 7, 8};
        System.out.println("Testing max method:");
        System.out.println(max(a) + " (should be 9)");
        System.out.println(max(b) + " (should be 11)");
        System.out.println(max(c) + " (should be 16)");
        System.out.println();

        System.out.println("Testing average method:");
        System.out.println(average(a) + " (should be ~4.857)");
        System.out.println(average(b) + " (should be ~5.889)");
        System.out.println(average(c) + " (should be ~6.917)");
        System.out.println();

        int[] sorted1 = {2, 4, 6, 8, 10};
        int[] sorted2 = {1, 3, 5, 7, 9};
        int[] sorted3 = {3, 8, 14, 19, 22, 23, 24, 28, 31, 33, 35};
        int[] sorted4 = {3, 4, 5, 6, 12, 18, 22, 23, 27, 28, 31, 34, 35, 36};
        //These might be easier to verify if you complete the areIdentical method and use that instead
        System.out.println("Testing merge  method:");
        System.out.println(Arrays.toString(merge(sorted1, sorted2)) + " (should be [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])");
        System.out.println(Arrays.toString(merge(sorted1, sorted3)) + " (should be [2, 3, 4, 6, 8, 8, 10, 14, 19, 22, 23, 24, 28, 31, 33, 35])");
        System.out.println(Arrays.toString(merge(sorted1, sorted4)) + " (should be [2, 3, 4, 4, 5, 6, 6, 8, 10, 12, 18, 22, 23, 27, 28, 31, 34, 35, 36])");
        System.out.println(Arrays.toString(merge(sorted2, sorted3)) + " (should be [1, 3, 3, 5, 7, 8, 9, 14, 19, 22, 23, 24, 28, 31, 33, 35])");
        System.out.println(Arrays.toString(merge(sorted2, sorted4)) + " (should be [1, 3, 3, 4, 5, 5, 6, 7, 9, 12, 18, 22, 23, 27, 28, 31, 34, 35, 36])");
        System.out.println(Arrays.toString(merge(sorted3, sorted4)) + " (should be [3, 3, 4, 5, 6, 8, 12, 14, 18, 19, 22, 22, 23, 23, 24, 27, 28, 28, 31, 31, 33, 34, 35, 35, 36])");
        System.out.println();

        System.out.println("Testing areIdentical method:");
        System.out.println(areIdentical(a, a) + " (should be true)");
        System.out.println(areIdentical(a, b) + " (should be false)");
        System.out.println(areIdentical(a, c) + " (should be false)");
        System.out.println(areIdentical(a, d) + " (should be true)");
        System.out.println(areIdentical(a, e) + " (should be false)");
        System.out.println();

        int[] inc1 = {0, 1, 2, 1, 2, 1, 3, 1, 2, 1, 3};
        int[] inc2 = {0, 1, 2, 1, 2, 3, 4, 5, 5, 4, 5, 2};
        int[] inc3 = {4, 1, 2, 3, 4, 5, 6, 6, 5, 6, 7, 8};
        int[] inc4 = {3, 1, 2, 6, 3, 5, 7, 8, 8, 9, 10, 11, 12};
        int[] inc5 = {1, 2, 3, 2, 3, 4, 3, 4, 5, 6, 4, 5, 6, 5, 6, 7};
        int[] inc6 = {9, 8, 7, 6, 5, 4, 3, 2, 1};

        System.out.println("Testing longestIncreasingSequence method:");
        System.out.println(longestIncreasingSequence(inc1) + " (should be 3)");
        System.out.println(longestIncreasingSequence(inc2) + " (should be 5)");
        System.out.println(longestIncreasingSequence(inc3) + " (should be 6)");
        System.out.println(longestIncreasingSequence(inc4) + " (should be 5)");
        System.out.println(longestIncreasingSequence(inc5) + " (should be 4)");
        System.out.println(longestIncreasingSequence(inc6) + " (should be 1)");
        System.out.println();
    }

    //This method should return the largest integer value contained in the argument array
    public static int max(int[] arr){
        int high = arr[0];

        for(int i: arr) {
            if(i > high) {
                high = i;
            }
        }
        return high;
    }

    //This method should compute the average/mean of the values contained in the argument array.
    public static double average(int[] arr){
        int total = 0;

        for(int i: arr) {
            total+=i;
        }

        return (double)total/arr.length;
    }

    //This method should return true if a and b are identical arrays.
    //That is, return true if a and b have the same length and the values at each index are equal
    //Otherwise, the method should return false
    public static boolean areIdentical(int[] a, int[] b){
        if(a.length==b.length) {
            for(int i=0;i<a.length;i++) {
                if(a[i]!=b[i]) {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
    }

    //The arguments for this method will be two sorted arrays (sorted in increasing order).
    //The method must create and return a new sorted array that contains all the elements from a and b also in increasing order.
    //In other words, you are merging the two sorted lists into a new sorted list.
    //There are many ways to solve this problem, some of which are more efficient than others.
    public static int[] merge(int[] a, int[] b){
        int[] arr = new int[a.length+b.length];
        int count;

//        if(a[a.length-1]<b[0]) {
//            count = 0;
//
//            for(int i: a) {
//                arr[count] = i;
//                count++;
//            }
//
//            for(int i: b) {
//                arr[count] = i;
//                count++;
//            }
//        }
//
//        if(b[b.length-1]<a[0]) {
//            count = 0;
//
//            for(int i: b) {
//                arr[count] = i;
//                count++;
//            }
//
//            for(int i: a) {
//                arr[count] = i;
//                count++;
//            }
//        }

        //Loop through list a, compare all values to values in list b, if list a is less add that value to new arr, else add list b value, remove value that had been added
        count = 0;
        while(b.length>=1 || a.length>=1) {
            if(a.length==0) {
                //Add the rest of the array to the new array
                for(int i: b) {
                    arr[count] = i;
                    count++;
                }
                break;
            } else if(b.length==0) {
                for(int i: a) {
                    arr[count] = i;
                    count++;
                }
                break;
            }

            if(a[0]<b[0]) {
                arr[count] = a[0];
                a = remFirstEl(a);
            } else {
                arr[count] = b[0];
                b = remFirstEl(b);
            }
            count++;
        }
        return arr;
    }

    public static int[] remFirstEl(int[] arr) {
        int[] newArr = new int[arr.length-1];

        for(int i=0;i<newArr.length;i++) {
            newArr[i] = arr[i+1];
        }

        return newArr;
    }

    //This method should return the length of the longest increasing sequence in the argument array.
    //An increasing sequence consists of consecutive numbers that are each larger than the previous.
    //For example, in the array [0, 1, 2, 4, 3, 5, 7], 0-1-2-4 is an increasing sequence of length 4.
    //In the same array, 3-5-7 is an increasing sequence of length 3.
    //Note that 0-1-2-4-5-7 is not an increasing sequence as there is a 3 (which is not greater than 4) between 4 and 5.
    public static int longestIncreasingSequence(int[] a){
        //make array of inc seqs in the original array
        //-loop through list till a number not > last
        //-record index and add length of list slice to array
        //find highest number in inc seq array

        ArrayList<Integer> incSeqs = new ArrayList<>();
        int count = 1;

        //Assumed the same number twice breaks the inc seq
        for(int i=1;i<a.length;i++) {
            if(a[i-1]<a[i]) {
                count++;
            } else {
                incSeqs.add(count);
                count = 1;
            }
        }
        incSeqs.add(count);

        return highInt(incSeqs);
    }

    public static int highInt(ArrayList<Integer> arr) {
        int high = 0;

        for(int i: arr) {
            if(i>high) {
                high = i;
            }
        }
        return high;
    }
}