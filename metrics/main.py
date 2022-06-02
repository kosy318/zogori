import cpp_complexity as cppcom
import cpp_elegance_model as cppmodel
import py_complexity as pycom
import sys

files = []
for i in range(1,len(sys.argv)):
    files.append(sys.argv[i])
print(type(files))
print(files)
complexity = {}
# complexity = cppcom.cal_complexity(file_name)
cppmodel.pred(files)
# print(complexity)
