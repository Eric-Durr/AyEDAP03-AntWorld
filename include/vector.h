#include <iostream>
#include <vector>

template <class T>
class CustomVector
{
private:
  int low_boundry_;
  int top_boundry_;
  T *v_map_;

public:
  CustomVector(int low_b = 0, int top_b = 0);
  ~CustomVector(void);

  inline const int &low_boundry(void) const { return low_boundry_; }
  inline const int &top_boundry(void) const { return top_boundry_; }
  inline const int size(void) const { return top_boundry_ - low_boundry_; }

  const T &at(int pos) const;
  T &at(int pos);

  const T &operator[](int pos) const;
  T &operator[](int pos);

  void move_boundries(int low_b = 0, int top_b = 0);

  const std::string to_string(void) const;

private:
  void low_boundry(int low_b) { low_boundry_ = low_b; }
  void top_boundry(int top_b) { top_boundry_ = top_b; }
};
