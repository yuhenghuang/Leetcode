#ifndef UTILS_GENERATED_PY_HPP
#define UTILS_GENERATED_PY_HPP

template<class Solution, typename U0, typename Ret>
std::enable_if_t<!std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  Ret res = (sol.*fn)(u0);
  universal_print(res);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename Ret>
std::enable_if_t<std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  (sol.*fn)(u0);
  universal_print(U0(u0));

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename Ret>
std::enable_if_t<!std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  Ret res = (sol.*fn)(u0, u1);
  universal_print(res);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename Ret>
std::enable_if_t<std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  (sol.*fn)(u0, u1);
  universal_print(U0(u0));

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename U2, typename Ret>
std::enable_if_t<!std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1, U2), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  Ret res = (sol.*fn)(u0, u1, u2);
  universal_print(res);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename U2, typename Ret>
std::enable_if_t<std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1, U2), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  (sol.*fn)(u0, u1, u2);
  universal_print(U0(u0));

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename Ret>
std::enable_if_t<!std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1, U2, U3), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  Ret res = (sol.*fn)(u0, u1, u2, u3);
  universal_print(res);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename Ret>
std::enable_if_t<std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1, U2, U3), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  (sol.*fn)(u0, u1, u2, u3);
  universal_print(U0(u0));

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename U4, typename Ret>
std::enable_if_t<!std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1, U2, U3, U4), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);
  input_parameter<U4> u4(args[4]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  Ret res = (sol.*fn)(u0, u1, u2, u3, u4);
  universal_print(res);

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
template<class Solution, typename U0, typename U1, typename U2, typename U3, typename U4, typename Ret>
std::enable_if_t<std::is_void<Ret>::value>
run(Ret(Solution::*fn)(U0, U1, U2, U3, U4), std::string& line, double& exec_time) {
  std::vector<std::string> args = string_split(line);
  input_parameter<U0> u0(args[0]);
  input_parameter<U1> u1(args[1]);
  input_parameter<U2> u2(args[2]);
  input_parameter<U3> u3(args[3]);
  input_parameter<U4> u4(args[4]);

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  (sol.*fn)(u0, u1, u2, u3, u4);
  universal_print(U0(u0));

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}
  
#endif