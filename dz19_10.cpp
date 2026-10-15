#include <iostream>
#include <algorithm>

int** sozdmatrix(size_t rows, size_t cols)
{
    int** matrix = new (std::nothrow) int*[rows];
    if (matrix == nullptr) return nullptr;
    
    for (size_t i = 0; i < rows; ++i)
    {
        matrix[i] = new (std::nothrow) int[cols];
        if (matrix[i] == nullptr)
        {
            for (size_t j = 0; j < i; ++j) delete[] matrix[j];
            delete[] matrix;
            return nullptr;
        }
    }
    return matrix;
}

void deleteMatrix(int** matrix, size_t rows)
{
    if (matrix == nullptr) return;
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** concat_rows(const int* const* lhs, size_t n1, size_t m1, const int* const* rhs, size_t n2, size_t m2)
{
    size_t matrix_rows = std::max(n1, n2);
    size_t matrix_cols = m1 + m2;

    int** matrix = sozdmatrix(matrix_rows, matrix_cols);
    if (matrix == nullptr)
    {
        return nullptr; 
    }

    for (size_t i = 0; i < matrix_rows; ++i)
    {
        if (i < n1)
        {
            for (size_t j = 0; j < m1; ++j)
            {
                matrix[i][j] = lhs[i][j];
            }
        } else
        {
            for (size_t j = 0; j < m1; ++j)
            {
                matrix[i][j] = 0;
            }
        }

        if (i < n2)
        {
            for (size_t j = 0; j < m2; ++j)
            {
                matrix[i][m1 + j] = rhs[i][j];
            }
        } else
        {
            for (size_t j = 0; j < m2; ++j)
            {
                matrix[i][m1 + j] = 0;
            }
        }
    }
    return matrix;
}

int main()
{
    size_t n1, m1, n2, m2;
    if (!(std::cin >> n1 >> m1))
    {
        return 1;
    }
    int** lhs = sozdmatrix(n1, m1);
    if (lhs == nullptr) return 2;
    for (size_t i = 0; i < n1; ++i)
        for (size_t j = 0; j < m1; ++j)
            if (!(std::cin >> lhs[i][j]))
            {
                deleteMatrix(lhs, n1);
                return 1;
            }
    if (!(std::cin >> n2 >> m2))
    {
        deleteMatrix(lhs, n1);
        return 1;
    }
    int** rhs = sozdmatrix(n2, m2);
    if (rhs == nullptr) {
        deleteMatrix(lhs, n1);
        return 2;
    }
    for (size_t i = 0; i < n2; ++i)
        for (size_t j = 0; j < m2; ++j)
            if (!(std::cin >> rhs[i][j]))
            {
                deleteMatrix(lhs, n1);
                deleteMatrix(rhs, n2);
                return 1;
            }
    int** matrix = concat_rows(const_cast<const int* const*>(lhs), n1, m1, const_cast<const int* const*>(rhs), n2, m2);
    if (matrix == nullptr)
    {
        deleteMatrix(lhs, n1);
        deleteMatrix(rhs, n2);
        return 2;
    }
    size_t mat_rows = std::max(n1, n2);
    size_t mat_cols = m1 + m2;
    for (size_t i = 0; i < mat_rows; ++i)
    {
        for (size_t j = 0; j < mat_cols; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    deleteMatrix(lhs, n1);
    deleteMatrix(rhs, n2);
    deleteMatrix(matrix, mat_rows);
    return 0;
}