#include <stdio.h>
#define SIZE 50

struct mat
{
  int row;
  int col;
  int value[SIZE][SIZE];
};

void scan_mat(struct mat *);
void print_mat(const struct mat *);
void add_mat(const struct mat *, const struct mat *, struct mat *);
void mul_mat(const struct mat *, const struct mat *, struct mat *);

int main(void)
{
  struct mat m1, m2, result;
  char op;
  scan_mat(&m1);
  scanf(" %c", &op);
  scan_mat(&m2);
  switch (op)
  {
  case '+':
    add_mat(&m1, &m2, &result);
    break;
  case '*':
    mul_mat(&m1, &m2, &result);
    break;
  }
  print_mat(&result);
  return 0;
}

void scan_mat(struct mat *m_p)
{
  scanf("%d %d", &m_p->row, &m_p->col);
  for (int i = 0; i < m_p->row; ++i)
  {
    for (int j = 0; j < m_p->col; ++j)
    {
      scanf("%d", &m_p->value[i][j]);
    }
  }
}

void print_mat(const struct mat *m_p)
{
  for (int i = 0; i < m_p->row; ++i)
  {
    for (int j = 0; j < m_p->col; ++j)
    {
      printf("%d ", m_p->value[i][j]);
      if (j == m_p->col - 1)
      {
        printf("\n");
      }
    }
  }
}

void add_mat(const struct mat *m1_p, const struct mat *m2_p, struct mat *result_p)
{ // matrix addition

  for (int i = 0; i < m1_p->row; i++)
  {
    for (int j = 0; j < m1_p->col; j++)
    {
      result_p->value[i][j] = 0; // 答案初始化
      result_p->value[i][j] = m1_p->value[i][j] + m2_p->value[i][j];
    }
  }
  result_p->row = m1_p->row;
  result_p->col = m1_p->col;
}

void mul_mat(const struct mat *m1_p, const struct mat *m2_p, struct mat *result_p)
{ // matrix multiplication

  for (int i = 0; i < m1_p->row; i++)
  {
    for (int j = 0; j < m2_p->col; j++)
    {
      // 計算結果
      result_p->value[i][j] = 0; // 答案初始化
      for (int k = 0; k < m2_p->row; k++)
        result_p->value[i][j] += m1_p->value[i][k] * m2_p->value[k][j];
    }
  }
  result_p->row = m1_p->row;
  result_p->col = m2_p->col;
}