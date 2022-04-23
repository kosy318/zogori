import cpp_complexity as cppcom
import py_complexity as pycom
import sys

file_name = sys.argv[1]
file_type = sys.argv[2]
distinct_func, number_func, distinct_var, number_var, maxdepth, LOC, elegance = 0,0,0,0,0,0,0
if file_type == "cpp":
    distinct_func, number_func, distinct_var, number_var, maxdepth, LOC, elegance = cppcom.cal_complexity(file_name)
if file_type == "py":
    distinct_func, number_func, distinct_var, number_var, maxdepth, LOC, elegance = pycom.cal_complexity(file_name)
    



print(f'''<tr><td>Functions</td><td>{len(distinct_func)}: {distinct_func}</td></tr>
<tr><td>total nb of Functions</td><td>{number_func}</td></tr>
<tr><td>Variables</td><td>{len(distinct_var)}: {distinct_var}</td></tr>
<tr><td>total nb of Variables</td><td>{number_var}</td></tr>
<tr><td>Depth</td><td>{maxdepth}</td></tr>
<tr><td>LOC</td><td>{LOC}</td></tr>
<tr><td>Elegancy</td><td>{elegance}</td></tr>''')