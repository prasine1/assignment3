#include <iostream>
using namespace std;
#define v 11
#define MAX 4000
void printPath(int P[v][v], int x, int y);

void floydWarshall(int weight[v][v]) {
    
  int Distance[v][v];
  
  int Path[v][v];

  for (int i = 0; i < v; i++){
      
    for (int j = 0; j < v; j++){
        
      Distance[i][j] = weight[i][j];
      
      Path[i][j] = 0;
    }
  }

  for (int k = 0; k < v; k++) {
       
    for (int i = 0; i < v; i++) {            
        
      for (int j = 0; j < v; j++) {
          
        if (Distance[i][j] > Distance[i][k] + Distance[k][j]){
            
          Distance[i][j] = Distance[i][k] + Distance[k][j];
          
          Path[i][j] = k;
        }
      }
    }
  }
  
  if (Distance[0][10] < MAX){
      
    cout<<"path for New York(1) to Toronto() is 1";
    
    printPath(Path,0,10);
    
     cout<<"->11"<<endl;

      cout<<"Shortest distance is "<<Distance[0][10]<<endl;
  } 
}

void printPath(int Path[v][v], int x, int y){
    
  if (Path[x][y] !=0)
  {
    printPath(Path,x,Path[x][y]);
    
    cout <<"->"<<Path[x][y]+1;
    
    printPath(Path,Path[x][y],y);
    }
}

int main() {
  int weight[v][v] = {
  {0, 140, MAX, MAX, MAX, 180, 100, 70, MAX, MAX, MAX},
   {140, 0, 130, MAX, 100, MAX, MAX, MAX, MAX, MAX, MAX},
   {MAX, 130, 0, 160, MAX, MAX, MAX, MAX, MAX, MAX, MAX},
   {MAX, MAX, 160, 0, 65, MAX, MAX, MAX, MAX, MAX, 180},
   {MAX, 100, MAX, 65, 0, 70, MAX, MAX, 70, MAX, MAX},
   {180, MAX, MAX, MAX, 70, 0, 60, MAX, MAX, MAX, MAX},
   {100, MAX, MAX, MAX, MAX, 60, 0, 65, MAX, MAX, MAX},
   {70, MAX, MAX, MAX, MAX, MAX, 65, 0, MAX, MAX, MAX},
   {MAX, MAX, MAX, MAX, 70, MAX, MAX, MAX, 0, 60, MAX},
   {MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, 60, 0, 100},
   {MAX, MAX, MAX, 180, MAX, MAX, MAX, MAX, MAX, 100, 0},
   };
  floydWarshall(weight);
}
