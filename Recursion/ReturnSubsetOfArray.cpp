/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

DonÃ¢ÂÂt print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
 if(n==0){
     output[0][0]=0;
     return 1;
     }
    int ans = subset(input+1,n-1,output);
    for(int i=ans;i<2*ans;i++){
        output[i][0]=1+output[i-ans][0];
        output[i][1]=input[0];
        for(int j=1;j<=output[i-ans][0];j++){
            output[i][j+1]=output[i-ans][j];
        }
    }
    return 2*ans;
    }
