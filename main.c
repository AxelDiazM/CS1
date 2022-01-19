#include<stdio.h>
#include<math.h>
#include<time.h>
//the algorithm works by generating all possible (2n!)/((n!)2^k)
//pairs and analyzing them one by one to get the minimum 

//an integer array to maintain the pairs
//if a tree has not been paired then paired[i]=0
int paired[13]={0};//this case will store  the j values 
//2d array for storing the coordinates of trees
int pair_tree[13][2]={0};//coordinate the pair-tree pair 
//n
int n;
//to store the large_value initialized to large value
float large_value=1e9;


//function to evaluate the answer for a possible
//pairing
void check_distance(){

//store distance
float distance=0;
//here is how to make the length of a rope ladder built between treetops located at (xi, yi) and (xj, yj) 
for(int i=1;i<=2*n;i++){
        //printf("(%d %d)\n",i,paired[i]);
        int sq_dist=(pair_tree[i][0]-pair_tree[paired[i]][0])*(pair_tree[i][0]-pair_tree[paired[i]][0])
                   +(pair_tree[i][1]-pair_tree[paired[i]][1])*(pair_tree[i][1]-pair_tree[paired[i]][1]);
        distance+=sqrt((float)sq_dist);
        //printf("%f\n",distance);

        
        }
distance=distance/(float)2;     
//if distance is less than large_value then change the large_value
if(large_value>distance) large_value=distance;     
}

//function solve that generates all possible pairs
//calls the function evaluate
void solve(){
int i=0;
//check if any pair-tree is not paired
for(i=1;i<=2*n;i++){
        //pair-tree is not paired, exit from loop
        if(paired[i]==0) break;
        }
//all trees have been paired    
if(i>2*n){
        //check answer for the combination
        check_distance();
        //backtrack
        return;
        }       
//pair the unpaired pair-tree        
for(int j=1;j<=2*n;j++){
        if(j!=i && paired[j]==0){
                paired[i]=j;
                paired[j]=i;
                //recurse
                solve();
                //unpair
                paired[i]=0;
                paired[j]=0;
                }
        }       
}

long timediff(clock_t t1, clock_t t2) {

    long elapsed;

    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;

    return elapsed;

}



//main
int main(){
//take no of test cases

  int t1;
  int t2;

  clock_t start, end;

  int t;
  scanf("%d",&t);
  //iterate through test cases
  while(t--){
          //initialize large_value to large positive value for each case
          large_value=1e9;
          //read value of n
          scanf("%d",&n);
          //read the coordinates
          for(int i=1;i<=2*n;i++){
                  scanf("%d%d",&pair_tree[i][0],&pair_tree[i][1]);
                  }
          //call function solve() to solve the problem    
          solve();
          //print the answer
          printf("%0.3f\n",large_value);     


          

      

    //timediff unction should be defined by us and you can simply copy the function from here:


  }
  long elapsed=timediff(t1,t2); //this is not a library function. See the function definition bellow
  printf("\nfor n = %d, the process took %ld milli seconds\n", n, elapsed);
}