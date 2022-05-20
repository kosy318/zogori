import cpp_complexity as cppcom
import py_complexity as pycom
import sys

# file_name = sys.argv[1]
file_name = "iron.cpp"
file_type = file_name.split('.')[-1]


complexity = {}
if (file_type == "cpp") or (file_type == "c"):
    complexity = cppcom.cal_complexity(file_name)
    # print(complexity)
if file_type == "py":
    complexity = pycom.cal_complexity(file_name)

print(f'''<tr><td><b>Elegance</b></td><td><b>{complexity['elegance']}</b></td></tr>
<tr><td>Functions</td><td>{len(complexity['distinct_func'])}</td></tr>
<tr><td>total nb of Functions</td><td>{complexity['number_func']}</td></tr>
<tr><td>Variables</td><td>{len(complexity['distinct_var'])}</td></tr>
<tr><td>total nb of Variables</td><td>{complexity['number_var']}</td></tr>
<tr><td>Depth</td><td>{complexity['depth']}</td></tr>
<tr><td>LOC</td><td>{complexity['LOC']}</td></tr>''')
