#include <iostream>
#include  <cstddef>

int debil(int& stlb, int& strok)
{
    if (!(std::cin >> stlb >> strok))
        return 1;
    return 0;
}

int** sozdmatrix(int strok, int stlb)
{
    int** matrix = new (std::nothrow) int*[strok];
    if (matrix == nullptr) return nullptr;

    for (int i = 0; i < strok; ++i)
    {
        matrix[i] = new (std::nothrow) int[stlb];
        if (matrix[i] == nullptr)
        {
            for (int j = 0; j < i; ++j) delete[] matrix[j];
            delete[] matrix;
            return nullptr;
        }
    }
    return matrix;
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
    for (int i = 0; i < strok; ++i)
    {
        for (int j = 0; j < stlb; ++j)
        {
        std::cin >> matrix[i][j];
        }
    }

    for (size_t j = 0; j < stlb; ++j)
    {
        for (size_t i = 0; i < strok; ++i)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
        }
    for (size_t i = 0; i < strok; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}