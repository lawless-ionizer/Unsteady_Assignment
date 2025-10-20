#!/usr/bin/env python3
from sympy import Eq, symbols, solve

if __name__ == '__main__':

    r, x, g1, g4, ar = symbols('r x g1 g4 ar')

    equation = Eq(r, x*(1 - (g4-1)*ar*(x-1)/(2*g1*(2*g1 + (g1+1)*(x-1)))**0.5)**(-2*g4/(g4-1)))

    try:
        solutions = solve(equation, x)
        print(f"Solution is x = {solutions[0]}")
    except Exception as e:
        print(f"An error occurred while solving the equation: {e}")