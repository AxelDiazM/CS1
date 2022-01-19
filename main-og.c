#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 25 
#define MAXPAIRS 16
#define MAXY 10000
#define MINX 10000
#define X 0
#define Y 1
FILE * infile;
FILE*outfile;
int sumLenght();
float calculateMinSum();
void readInput(int,int);
void init();
void precompCosts(int);
float getCost(int *, int);
float perm(int [], int , int , int []);


// Will store who is in which dance routine.
float inTree[MAXPAIRS][MAXPAIRS]={0};


// cost[i][j] will store the # of quick changes between routine i
// and routine j.
float lenght[MAXPAIRS][MAXPAIRS];



int main(void) {
  clock_t start, end;
  double cpu_time_used;
  start = clock(); 

  int numTrees,numTestCases,numRopes;
  
  
  
  infile = fopen("in.txt", "r");
  outfile = fopen("out.txt", "w");
  //initialize to 0
  //init(inTree, numTrees, 0);
  fscanf(infile, "%d", &numTestCases);
  //printf("%i\n",numTestCases);
  for(int i=0;i<numTestCases;i++){
    //if(i!=1)continue; 
    fscanf(infile, "%d", &numRopes);
    //printf("gola");
    //printf("\n\n%i.%i",i+1,numRopes);
    for(int j=0;j<numRopes*2;j++){
      
      fscanf(infile, "%f %f", &inTree[j][X],&inTree[j][Y]);
      //printf("\n%f %f",inTree[j][X],inTree[j][Y]);
    }
    precompCosts(numRopes);
    int used[MAXPAIRS]={0};
    int ropes[MAXPAIRS]={0};
    float permVal;
    
    
    permVal=perm(ropes, numRopes*2, 0, used);
    printf("%.3f\n", permVal);  
    fprintf(outfile,"%.3f\n", permVal); 
    //system("pause");
  }
  fclose(infile);
  fclose(outfile);
  

  //int coordinates [MAXPAIRS+1];
  //int x,y;
  
  end = clock();
  cpu_time_used=((double)(end - start));
  //printf("%f",cpu_time_used/1000000);
  return 0;
  
}




void precompCosts(int numPairs) {
  int i,j;
  //printf("\n\n\n\n\n\n%i",numPairs);
  //printf("\n-----------------------------------------------------");
  //printf("\n\n\n\n\n%f",inTree[0][X]);
  //printf(" %f",inTree[0][Y]);
  //printf("\n%f",inTree[1][X]);
  //printf(" %f",inTree[1][Y]);
  for(i=0; i<numPairs*2; i++){
    for(j=0; j<numPairs*2; j++){
      
      //printf("\n\nCalculation\n-----------------------------------------------------");
      if(i!=j)
      lenght[i][j] =  calculateMinSum(i,j);
      //if(i==3&&j==0){
        //printf("\n%f %f  -   %f %f\n",inTree[i][X],inTree[i][Y],inTree[j][X],inTree[j][Y]);
        //printf("\n%f\n",lenght[i][j]);
    }
      
      //printf("\n%i %i\n",i,j);
  }
      //printf("\n%i)Lenght %i: %f\n\n",i,j,lenght[i][j]);
  //printf("\n");
  //for(i=0; i<numPairs*2; i++){
    //for(j=0; j<numPairs*2; j++){
      //if(i!=j)
      //printf("%i to %i)%f ",i,j,lenght[i][j]);}printf("\n");}    
}
    //printf("\n-------------------------------");
  
 //printf("\n*****************************");


float calculateMinSum(int first,int second){
  
  //printf("%i",first);
  float a,b;
  float lenght;
  //for(int i=0; i<MAXPAIRS; i++)
    //if(inTree[firstLenght][i]==1 && inTree[secondLenght][i]==1)
      //lenght++;
  //printf("\n%f\n",inTree[second][X]);    
  //a=inTree[firstLenght][a]-inTree[secondLenght][X];
  //printf("\n%f\n",x);
  a=pow(inTree[first][X]-inTree[second][X],2);
  //printf("\n-X:%f",a);
  b=pow((inTree[first][Y]-inTree[second][Y]),2);
  //printf("\n-Y:%f",b);
  lenght=sqrt(a+b);
  //printf("\n%f",lenght);
  return lenght;
}

float perm(int order[], int x, int k, int used[]) {
  //if(k==0)
  //printf("\n%i I'm the start\n",k);
   if (k==x)//{
    //printf("\nI am in %i and %i\n",k,k);
    //for(int i =0;i<x;i++){
      
      //printf("\n%i)%i %i",i,order[i],x);
    //}printf("\n88888888888888888888888888888");
     return getCost(order, x);//}

   //keeps track of minimum cost
   float minCost=80000000;

   for (int i=0; i<x; i++){
     //printf("\nI am in %i and %i\n",i,k);
     //printf("%i\n",used[i]);
     if (used[i]) continue;
     
     order[k] = i;
     //printf("I:%i  %i) %i - ",i,k,order[k]);
     //k++;
     used[i] = 1;
     float currCost = perm(order, x, k+1, used);
     if (currCost<minCost&&currCost!=0)
       minCost = currCost;
     used[i] = 0;
    
   }
   //if(minCost>23.5&&minCost<24.8){
    //printf("\n**********************%.3f\n",minCost);}
   //if(minCost>21.5&&minCost<30){
    //printf("\n----------------------%.3f\n",minCost);}
  //else printf("\n%f\n",minCost);
 return minCost;
 }


 // Returns the cost of this array ordering of dances.
float getCost(int *order, int x) {
  //printf("\nTHis is the start===================");
  float totalCost = 0;
  int i;
  // calculate the total cost of order
  for(i=0; i<x-1; i=i+2){
  
  
  //printf("\n------------- %i and %i which means %f on %f\n",order[i],order[i+1],lenght[order[i]][order[i+1]],totalCost);
  //printf("%f - %f vs %f - %f\n",inTree[order[i]][X],inTree[order[i]][Y],inTree[order[i+1]][X],inTree[order[i+1]][Y]);
    
    
    
    
    totalCost+=lenght[order[i]][order[i+1]];
  }
  //printf("\n*******FINAL:%f\n",totalCost);
  return totalCost;
}
