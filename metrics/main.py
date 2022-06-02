import cpp_complexity as cppcom
import cpp_elegance_model as cppmodel
import py_complexity as pycom
import sys

files = []
language = sys.argv[1]
for i in range(2,len(sys.argv)):
    files.append(sys.argv[i])
# print(type(files))
# print(files)
complexity = {}
if language=="c/c++":
    # complexity = cppcom.cal_complexity(file_name)
    cppmodel.pred(files)
if language=="python":
    complexity = pycom.cal_complexity(sys.argv[2])

    print(f'''<tr><td><b>Elegance</b></td><td><b>{complexity['elegance']}</b></td></tr>
    <tr><td>Functions</td><td>{len(complexity['distinct_func'])}</td></tr>
    <tr><td>total nb of Functions</td><td>{complexity['number_func']}</td></tr>
    <tr><td>Variables</td><td>{len(complexity['distinct_var'])}</td></tr>
    <tr><td>total nb of Variables</td><td>{complexity['number_var']}</td></tr>
    <tr><td>Depth</td><td>{complexity['depth']}</td></tr>
    <tr><td>LOC</td><td>{complexity['LOC']}</td></tr>''')
