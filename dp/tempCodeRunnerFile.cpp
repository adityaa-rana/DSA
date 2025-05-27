    if(index==n){
        if(vsum<=bag){
            return wsum;
        }
        else{
            return 0;
        }
    }

    int pick=knapsack(index+1,wsum+weight[index],vsum+value[index],weight,value,bag);
    int notpick=knapsack(index+1,wsum,vsum,weight,value,bag);
    return max(pick,notpick);
}
