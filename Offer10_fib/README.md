用O(logn)来求解的关键是把原问题转换为矩阵的问题。

$$
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}
\begin{bmatrix}
  F(n) \\
F(n-1)
\end{bmatrix}
=
\begin{bmatrix}
F(n)+F(n-1) \\
F(n)
\end{bmatrix}
\begin{bmatrix}
F(n+1) \\
F(n)
\end{bmatrix}
$$

由此就可以把原问题转换为:

$$
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}^{n-1} 
\begin{bmatrix}
F(1) \\
F(0)
\end{bmatrix}
=
\begin{bmatrix}
1 & 1 \\
1 & 0
\end{bmatrix}^{n-1}
\begin{bmatrix}
1 \\
0
\end{bmatrix}
$$

随后取左边矩阵的第一个值就是答案。