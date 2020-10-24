#ifndef UTILS_GENERATED_PY_HPP
#define UTILS_GENERATED_PY_HPP

template<class Solution, typename U0, typename Ret>
void run(Ret(Solution::*fn)(U0), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  Solution sol;
  Ret res = (sol.*fn)(u0);
  universal_print(res);
}
  
template<class Solution, typename U0, typename Ret, typename = std::enable_if_t<std::is_void<Ret>::value>>
void run(Ret(Solution::*fn)(U0), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  Solution sol;
  (sol.*fn)(u0);
  universal_print(U0(u0));
}
  
template<class Solution, typename U0, typename U1, typename Ret>
void run(Ret(Solution::*fn)(U0, U1), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  Solution sol;
  Ret res = (sol.*fn)(u0);
  universal_print(res);
}
  
template<class Solution, typename U0, typename U1, typename Ret, typename = std::enable_if_t<std::is_void<Ret>::value>>
void run(Ret(Solution::*fn)(U0, U1), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  Solution sol;
  (sol.*fn)(u0);
  universal_print(U0(u0));
}
  
template<class Solution, typename U0, typename U1, typename U2, typename Ret>
void run(Ret(Solution::*fn)(U0, U1, U2), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  Solution sol;
  Ret res = (sol.*fn)(u0);
  universal_print(res);
}
  
template<class Solution, typename U0, typename U1, typename U2, typename Ret, typename = std::enable_if_t<std::is_void<Ret>::value>>
void run(Ret(Solution::*fn)(U0, U1, U2), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  Solution sol;
  (sol.*fn)(u0);
  universal_print(U0(u0));
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename Ret>
void run(Ret(Solution::*fn)(U0, U1, U2, U3), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);
  Solution sol;
  Ret res = (sol.*fn)(u0);
  universal_print(res);
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename Ret, typename = std::enable_if_t<std::is_void<Ret>::value>>
void run(Ret(Solution::*fn)(U0, U1, U2, U3), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);
  Solution sol;
  (sol.*fn)(u0);
  universal_print(U0(u0));
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename U4, typename Ret>
void run(Ret(Solution::*fn)(U0, U1, U2, U3, U4), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);
  input_parameter<U4> u4(args[4]);
  Solution sol;
  Ret res = (sol.*fn)(u0);
  universal_print(res);
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename U4, typename Ret, typename = std::enable_if_t<std::is_void<Ret>::value>>
void run(Ret(Solution::*fn)(U0, U1, U2, U3, U4), std::string& line) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);
  input_parameter<U4> u4(args[4]);
  Solution sol;
  (sol.*fn)(u0);
  universal_print(U0(u0));
}
  
#endif