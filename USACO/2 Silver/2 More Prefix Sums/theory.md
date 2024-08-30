we have g as a 2d array and f as a sum of all g(k, l) where k <= i && l <= j
=> f(i, j) = g(i, j) + f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1)