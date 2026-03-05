 #include <stdio.h>

int main() {
    int n, sum, difference, transpose;
    printf("Enter the number of dimension;\n");
    scanf("%d", &n);
    int a[n][n], b[n][n], c[n][n];
     
    printf("Enter Matrix A:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
        scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter Matrix B:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
        scanf("%d", &b[i][j]);
        }
    }
    
    printf("Sum of A & B:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum = a[i][j] + b[i][j];
        printf(" %d\t", sum);
        }
        printf("\n");
    }
    
    printf("Difference of A & B:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            difference = a[i][j] - b[i][j];
        printf(" %d\t", difference);
        }
        printf("\n");
    }
    
    printf("Transpose of A :\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            transpose = a[j][i];
        printf(" %d\t", transpose);
        }
        printf("\n");
    }
    
    printf("Product of A & B :\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
             c[i][j] = 0;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
             c[i][j]+=a[i][k]*b[k][j];
            }
            printf(" %d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
