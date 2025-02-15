#include <iostream>

using namespace std;

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = createMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int** scalarMultiply(int** matrix, int rows, int cols, int scalar) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

bool searchElement(int** matrix, int rows, int cols, int element) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == element) {
                return true;
            }
        }
    }
    return false;
}

void editElement(int** matrix, int i, int j, int newValue, int rows, int cols) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        matrix[i][j] = newValue;
    } else {
        cout << "Index out of bounds!" << endl;
    }
}

void sumRows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i << ": " << sum << endl;
    }
}

void sumColumns(int** matrix, int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j << ": " << sum << endl;
    }
}

int sumMainDiagonal(int** matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}

int countZeroElements(int** matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

string checkMatrixType(int** matrix, int size) {
    bool upperTriangular = true;
    bool lowerTriangular = true;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i < j && matrix[i][j] != 0)
                lowerTriangular = false;
            if (i > j && matrix[i][j] != 0)
                upperTriangular = false;
        }
    }

    if (upperTriangular && lowerTriangular)
        return "Diagonal";
    else if (upperTriangular)
        return "Upper Triangular";
    else if (lowerTriangular)
        return "Lower Triangular";
    
    return "Neither";
}
int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Create matrices
    int** matrixA = createMatrix(rows, cols);
    int** matrixB = createMatrix(rows, cols);

    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrixB[i][j];
        }
    }

    // Example usage of the functions
    cout << "Matrix A:" << endl;
    printMatrix(matrixA, rows, cols);

    cout << "Matrix B:" << endl;
    printMatrix(matrixB, rows, cols);

    // Add matrices
    int** sumAB = addMatrices(matrixA, matrixB, rows, cols);
    cout << "Sum of Matrix A and B:" << endl;
    printMatrix(sumAB, rows, cols);

    // Subtract matrices
    int** diffAB = subtractMatrices(matrixA, matrixB, rows, cols);
    cout << "Difference of Matrix A and B:" << endl;
    printMatrix(diffAB, rows, cols);

    // Multiply matrices
    // Note: For multiplication, the number of columns in A must equal the number of rows in B.
    
    // Assuming we want to multiply A with itself
    if (rows == cols) { // Only square matrices can be multiplied with themselves
        int** productAA = multiplyMatrices(matrixA, matrixA, rows, cols, cols);
        cout << "Product of Matrix A with itself:" << endl;
        printMatrix(productAA, rows, cols);
        
        deleteMatrix(productAA, rows); // Free memory
    } else {
        cout << "Cannot multiply Matrix A with itself due to dimension mismatch." << endl;
    }

    // Scalar multiplication
    cout << "Enter a scalar value to multiply with Matrix A: ";
    int scalar;
    cin >> scalar;
    
    int** scalarProductA = scalarMultiply(matrixA, rows, cols, scalar);
    cout << "Scalar product of Matrix A with " << scalar << ":" << endl;
    printMatrix(scalarProductA, rows, cols);

    // Search element
    cout << "Enter an element to search in Matrix A: ";
    int elementToSearch;
    cin >> elementToSearch;

    if (searchElement(matrixA, rows, cols, elementToSearch)) {
        cout << elementToSearch << " found in Matrix A." << endl;
    } else {
        cout << elementToSearch << " not found in Matrix A." << endl;
    }

    // Edit element
    cout << "Enter row and column to edit in Matrix A: ";
    int editRow, editCol, newValue;
    cin >> editRow >> editCol;

    cout << "Enter new value: ";
    cin >> newValue;

    editElement(matrixA, editRow, editCol, newValue, rows, cols);
    
    cout << "Matrix A after editing:" << endl;
    printMatrix(matrixA, rows, cols);

    // Sum of each row
    sumRows(matrixA, rows, cols);

    // Sum of each column
    sumColumns(matrixA, rows, cols);

    // Sum of main diagonal
    if (rows == cols) { // Only square matrices have a main diagonal
        cout << "Sum of main diagonal of Matrix A: " << sumMainDiagonal(matrixA, rows) << endl;
        
        // Check type of the matrix
        cout << "Type of Matrix A: " << checkMatrixType(matrixA, rows) << endl;
        
        // Count zero elements
        cout << "Number of zero elements in Matrix A: " << countZeroElements(matrixA, rows, cols) << endl;
        
        // Clean up allocated memory
        deleteMatrix(sumAB, rows);
        deleteMatrix(diffAB, rows);
        deleteMatrix(scalarProductA, rows);
        
        deleteMatrix(matrixA, rows);
        deleteMatrix(matrixB, rows);
        
        return 0;
}