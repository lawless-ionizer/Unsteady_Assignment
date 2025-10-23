#!/usr/bin/env python3
from sympy import Eq, symbols, solve, diff

if __name__ == '__main__':

    k_, x, N, D1, D2, k = symbols('k_ x N D1 D2 k')

    equation = x**(1/k) - (N*(x-1)*x**(1/k))/(D1 + D2*(x-1))**0.5 - k_

    # try:
    #     solutions = solve(equation, x)
    #     print(f"Solution is x = {solutions[0]}")
    # except Exception as e:
    #     print(f"An error occurred while solving the equation: {e}")

    ans = diff(equation, x)

    print(ans)