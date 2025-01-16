package learn.Greedy;

import java.util.Arrays;

class Item implements Comparable<Item>{
    int wt , val;

    public Item(int wt, int val) {
        this.wt = wt;
        this.val = val;
    }

    @Override
    public int compareTo(Item i) {
        return (wt)*(i.val) - (val)*(i.wt);
    }
        
}

public class FractionalKnapScak {

    static double fracKnapSack(Item arr[] , int w){
        Arrays.sort(arr);
        double res = 0.0;
        for(int i = 0 ; i < arr.length ; i++){
            if(arr[i].wt <= w){
                res += arr[i].val;
                w -= arr[i].wt;
            }else{
                res += arr[i].val * ((double)w/arr[i].wt);
                break;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        
        Item arr[] = {new Item(10, 60), new Item(40, 40), new Item(20, 100), new Item(30, 120)};
        int w = 50;
        System.out.println(fracKnapSack(arr, w));
        
    }


    
}
