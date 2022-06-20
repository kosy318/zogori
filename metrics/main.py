import cpp_complexity as cppcom
import cpp_elegance_model as cppmodel
import py_complexity as pycom
import sys

files = []
language = sys.argv[1]
# print(language)
for i in range(2, len(sys.argv)):
    files.append(sys.argv[i])
# print(type(files))
# print(files)
complexity = {}
if language == "c/c++":
    # complexity = cppcom.cal_complexity(file_name)
    print("<tr><td><b>File Name</b></td><td><b>Elegance</b></td></tr>")
    cppmodel.pred(files)
if language == "py":
    # print(files[0])
    complexity = pycom.cal_complexity(files[0])
    # print(complexity)

    print(f'''<tr><td><b>Elegance</b></td><td><b>{complexity['elegance']}</b></td></tr>
    <tr><td>Functions</td><td>{len(complexity['distinct_func'])}</td></tr>
    <tr><td>total nb of Functions</td><td>{complexity['number_func']}</td></tr>
    <tr><td>Variables</td><td>{len(complexity['distinct_var'])}</td></tr>
    <tr><td>total nb of Variables</td><td>{complexity['number_var']}</td></tr>
    <tr><td>Depth</td><td>{complexity['depth']}</td></tr>
    <tr><td>LOC</td><td>{complexity['LOC']}</td></tr>''')
