#ifndef BINOM_HPP
#define BINOM_HPP

#include <iostream> 
#include <cmath>    

class Binom {
private:
  int n;
  double p;
  
public:
  Binom(int n, double p) : n(n), p(p) {};
  int factorial(int n) const;
  double choose(int a, int b) const;
  double dbinom(int k) const;
  void print() const;  
};

// Recursive function to calculate factorial of n
inline int Binom::factorial(int n) const {
  if (n <= 1)
    return 1;
  return n * factorial(n - 1);  // Recursive call
}


inline double Binom::choose(int a, int b) const {
  return this->factorial(a) / (factorial(a - b) * factorial(b));
}


inline double Binom::dbinom(int k) const {
  return choose(n, k) * std::pow(p, k) * std::pow(1 - p, n - k);
}


inline void Binom::print() const {
  for (int i = 0; i <= n; ++i) {
    double prob = dbinom(i);
    std::printf("P(Y=%-2d; n=%d, p=%.2f) = %.4f\n", i, n, p, prob);
  }
}

#endif
