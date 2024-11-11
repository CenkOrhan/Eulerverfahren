# Differential Equations Solved with Euler's Method

This project includes C programs to solve two differential equations using Euler's method for numerical approximation. Solutions are generated for different step sizes and saved in files for easy visualization with provided plotting tools.

## Project Structure

- **Task 1**: Approximates the differential equation:
  
  \[
  y'(t) = 9y(t)^4
  \]

  on the interval \([0, 2]\) with the initial value \(y(0) = 0.2\).

- **Task 2**: Approximates the differential equation:

  \[
  y'(t) = -t \cdot y(t)
  \]

  on the interval \([-1, 1]\) with the initial value \(y(-1) = 0.8\).

## File Output

Each program generates output files in the format `y1.dat`, `y2.dat`, and `y3.dat`, which correspond to the step sizes \(h = 0.01\), \(h = 0.1\), and \(h = 0.5\), respectively. Each line in these files contains the values of \(t\) and the corresponding approximation \(y(t)\), separated by a space, as shown below:

Visualization: You can visualize the generated data using LaTeX. Place the output files (y1.dat, y2.dat, and y3.dat) in the same folder as the provided plot_exp.tex and plot_par.tex files, then run:

pdflatex plot_exp.tex
pdflatex plot_par.tex
