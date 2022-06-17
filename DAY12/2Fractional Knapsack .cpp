https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

tc o(nlogn)+o(n);
sc o(1);

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    bool static comp(Item a,Item b){
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        
        int curwt=0;
        double finalvalue=0;
        for(int i=0;i<n;i++){
            if(curwt+arr[i].weight<=W){
                curwt+=arr[i].weight;
                finalvalue+=arr[i].value;
            }
            else{
                int remain=W-curwt;
                finalvalue+=arr[i].value/double(arr[i].weight)*double(remain);
                break;
            }
        }
        
    return finalvalue;
        
        
    }
        
};