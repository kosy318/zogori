import cpp_complexity as cppcom
import cpp_elegance_model as cppmodel
import py_complexity as pycom
import sys

file_name = sys.argv[1:]


complexity = {}
# complexity = cppcom.cal_complexity(file_name)
cppmodel.pred(file_name)
# print(complexity)
