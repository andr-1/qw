#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int n = 9;

void Show(int** matrix);
int ** CreateMatrix(char* filename);
bool Checker(int** matrix);
void Try(int** matrix);

int main(int argc, char* argv[]) {
    char* filename;
    char emp_filename[10]= {'e', 'x', 'm', 'p', '/', '1', '.', 't', 'x', 't'};
    
    if (argc < 2){
        filename = emp_filename;
    }else{
        filename = argv[1];
    }
    int** matrix = CreateMatrix(filename);
    Show(matrix);
    if(Checker(matrix)){
        cout<<"looool";
    }else{
        cout<<"ssss";
    }
    int y=1%3;
    cout<<y;
    cout<<8-y<<endl;
    Try(matrix);
}

int ** CreateMatrix(char* filename) {
    int ** matrix = new int * [n];
    FILE *fp;
    fp=fopen(filename, "r");
    for (int i=0;i<n;i++){
        matrix[i] = new int [n];
        for (int j=0;j<n;j++)
            fscanf (fp,"%d ",&matrix[i][j]);
    }
    fclose(fp);
    return matrix;
    
}

void Show(int** matrix){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool Checker(int** matrix){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] != 0){
                for(int row=0; row<n; row++){
                    if(matrix[i][j]==matrix[row][j] && i!=row){
                        return false;
                    }
                }
                for(int col=0; col<n; col++){
                    if(matrix[i][j]==matrix[i][col] && col!=j){
                        return false;
                    }
                }
                for(int nrow=i-i%3; nrow<i-i%3+3; nrow++){
                    for(int ncol=j-j%3; ncol<j-j%3+3; ncol++){
                        if(matrix[i][j]==matrix[nrow][ncol] && ncol!=j && nrow!=i){
                            return false;
                        }
                    }
                }
            }
        }
        
    }
    return true;
}

void Try(int** matrix){
    //for (int i=0; i<n; i++){
        //for(int j=0; j<n; j++){
            int j=6, i=8;
                for(int nrow=i-i%3; nrow<i-i%3+3; nrow++){
                    for(int ncol=j-j%3; ncol<j-j%3+3; ncol++){
                        matrix[nrow][ncol]=0;
                    }
                }
            
        //}
        
    //}
    Show(matrix);
}