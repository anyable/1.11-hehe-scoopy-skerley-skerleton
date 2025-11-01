#include <iostream>

void destroy(int ** mtx, size_t created)
{
  for(size_t i = 0; i < created; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** create(size_t rows, size_t cols)
{
  int ** mtx = new int * [rows];
  size_t created = 0;
  try
  {
    for(; created < rows; ++created)
    {
      mtx[created] = new int[cols];
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}

void construct(int ** mtx, int init, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
}

void input(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}

void output(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < cols; ++j)
    {
      std::cout << " " << mtx[i][j];
    }
    std::cout << "\n";
  }
}

int main() {
  int ** matrix = nullptr;
  size_t rows = 0;
  size_t cols = 0;
  std::cin >> rows >> cols;
  if (!std::cin)
  {
    std::cerr << "bad input\n";

    return 2;
  }
  try
  {
    matrix = create(5, 5);
  }
  catch(const std::bad_alloc & e)
  {
    std::cerr << e.what() << '\n';
  }
  
  construct(matrix, 0, rows, cols);
  input(matrix, rows, cols);
  if (!std::cin)
  {
    destroy(matrix, cols);
    std::cerr << "input error\n";
    return 1;
  }
  output(matrix, rows, cols);
  destroy(matrix, cols);
  
}
