#ifndef BRUCH_HH
#define BRUCH_HH
#include <iostream>

class Bruch {
  public:
    Bruch(int zaehler = 0, int nenner = 1);
    Bruch(const Bruch& a);
    ~Bruch();
    int zaehler() const { return zaehler_;}
    int nenner() const { return nenner_;}
    Bruch operator+(const Bruch& b) const;

    friend std::istream& operator>>(std::istream& is,Bruch& b);
    friend std::istream& operator>>(std::istream& is,Bruch& b);
  private:
    int zaehler_;
    int nenner_;
    void kuerze();
    static int ggT(int a, int b);
};

#endif
