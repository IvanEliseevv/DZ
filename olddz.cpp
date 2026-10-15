#include <iostream>
#include <cstddef>

int debil(int& stlb, int& strok)
{
    if (!(std::cin >> stlb >> strok))
        return 1;
    return 0;
}

int** sozdmatrix(int strok, int stlb)
{
    int** matrix = new (std::nothrow) int*[strok];
    if (matrix == nullptr)
    {
        return nullptr;
    }
    for (size_t i = 0; i < strok; ++i)
    {
        matrix[i] = new (std::nothrow) int[stlb];
        if (matrix[i] == nullptr)
        {
            for (size_t j = 0; j < i; ++j) delete[] matrix[j];
            delete[] matrix;
            return nullptr;
        }
    }
    return matrix;
}
int** debiltrans(int** matrix, int strok, int stlb)
{
    int** result = new int*[strok];
    for (size_t i = 0; i < stlb; ++i) 
    {
        result[i] = new int[strok];
    }
    for (size_t i = 0; i < strok; ++i) 
    {
        for (size_t j = 0; j < stlb; ++j) 
        {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

int main()
{
    int stlb, strok;

    int err = debil(stlb, strok);
    if (err != 0)
    {
         return err;
    }

    int** matrix = sozdmatrix(strok, stlb);
    if (matrix == nullptr)
    {
    return 2;
    }

    for (size_t i = 0; i < stlb; ++i)
    {
        for (size_t j = 0; j < strok; ++j)
        {
        std::cin >> matrix[i][j];
        }
    }

    int** transposed = debiltrans(matrix, strok, stlb);
    for (size_t j = 0; j < strok; ++j)
    {
        for (size_t i = 0; i < stlb; ++i)
        {
            std::cout << transposed[j][i] << " ";
        }
        std::cout << "\n";
    }

    for (size_t i = 0; i < stlb; ++i)
    {
        delete[] transposed[i];
    }
    delete[] transposed;

    for (size_t i = 0; i < strok; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}