import argparse

def p1(nargs):
  s = ""
  for i in range(nargs):
    s += "typename U{}, ".format(i)
    
  s += "typename U{}".format(nargs)
  return s

def p2(flag):
  s_base = "std::enable_if_t<{}std::is_void<Ret>::value>"
  return s_base.format('') if flag else s_base.format('!')

def p3(nargs, varbase='U'):
  s = ""
  for i in range(nargs):
    s += "{}{}, ".format(varbase, i)
    
  s += "{}{}".format(varbase, nargs)
  return s

def p4(nargs):
  s = ""
  for i in range(nargs):
    s += "  input_parameter<U{0}> u{0}(args[{0}]);\n".format(i)
    
  s += "  input_parameter<U{0}> u{0}(args[{0}]);".format(nargs)
  return s

def p5(flag, nargs=0):
  s = ""

  args = p3(nargs, 'u')
  
  if flag:
    s += "(sol.*fn)({});\n  universal_print(U0(u0));".format(args)
  else:
    s += "Ret res = (sol.*fn)({});\n  universal_print(res);".format(args)

  return s

if __name__ == "__main__":
  parser = argparse.ArgumentParser(description="auto-generate ufuncs in namespace utils")
  parser.add_argument("-n", "--nargs", default=4, type=int, help="Num. of the maximum arguments in generated version, default is 4")
  parser.add_argument("-f", "--file", default="utils_generated_py.hpp", type=str, help="Name of the generated .hpp file")
  
  kwargs = parser.parse_args()
  

  macro_def = kwargs.file.upper().replace('.', '_')
  fns = []
  fns.append("#ifndef " + macro_def  + '\n')
  fns.append("#define " + macro_def + '\n')
  
  template = '''
template<class Solution, {p1}, typename Ret>
{p2}
run(Ret(Solution::*fn)({p3}), std::string& line, double& exec_time) {{
  std::vector<std::string> args = string_split(line);
{p4}

  std::chrono::time_point<std::chrono::system_clock> start( std::chrono::system_clock::now() );

  Solution sol;
  {p5}

  std::chrono::time_point<std::chrono::system_clock> end( std::chrono::system_clock::now() );
  std::chrono::duration<double, std::milli> elapsed( end - start );
  exec_time += elapsed.count();
}}
  '''  
  
  for i in range(kwargs.nargs*2):
    fns.append(template.format(
      p1 = p1(i//2),
      p2 = p2(i%2!=0),
      p3 = p3(i//2),
      p4 = p4(i//2),
      p5 = p5(i%2!=0, i//2)
    ))
    
  fns.append("\n#endif")
  
  with open(kwargs.file, "w") as f:
    f.writelines(fns)