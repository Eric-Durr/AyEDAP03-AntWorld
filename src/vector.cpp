#include "../include/vector.h"

template <class T>
CustomVector<T>::CustomVector(int low_b, int top_b) : low_boundry_(low_b),
                                                      top_boundry_(top_b)
{
  v_map_ = new T[this->size()];
  for (int i = 0; i < this->size(); i++)
  {
    v_map_[i] = 0;
  }
}

template <class T>
CustomVector<T>::~CustomVector(void)
{
  delete[] v_map_;
}

template <class T>
const T &CustomVector<T>::at(int pos) const
{
  if (pos >= low_boundry_ && pos < top_boundry_)
  {
    return low_boundry_ < 0 ? v_map_[pos - low_boundry_]
                            : v_map_[pos + low_boundry_];
  }
  else
  {
    std::cout << "position must be between "
              << low_boundry_ << "and"
              << top_boundry_ - 1 << "\n";
  }
}

template <class T>
T &CustomVector<T>::at(int pos)
{
  if (pos >= low_boundry_ && pos < top_boundry_)
  {
    return low_boundry_ < 0 ? v_map_[pos - low_boundry_]
                            : v_map_[pos + low_boundry_];
  }
  else
  {
    std::cout << "position must be between "
              << low_boundry_ << "and"
              << top_boundry_ - 1 << "\n";
  }
}

template <class T>
const T &CustomVector<T>::operator[](int pos) const
{
  return this->at(pos);
}

template <class T>
T &CustomVector<T>::operator[](int pos)
{
  return this->at(pos);
}

template <class T>
void CustomVector<T>::move_boundries(int low_b, int top_b)
{
  this->low_boundry(this->low_boundry + low_b);
  this->top_boundry(this->top_boundry + top_b);
}

template <class T>
const std::string CustomVector<T>::to_string(void) const
{
  std::string output = "[ ";
  for (int i = this->low_boundry_; i < this->top_boundry_; i++)
  {
    output += "(" + std::to_string(at(i)) + "|" + std::to_string(i) + ") ";
  }
  output += "]";

  return output;
}