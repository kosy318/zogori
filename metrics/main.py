import cpp_complexity as cppcom
import cpp_elegance_model as cppmodel
import py_complexity as pycom
import sys
import json

# call proper metric function using file data
# maybe it can be used in command line
# make returned dictionary object json string
# return that json string to main.js

files = []
language = sys.argv[1]
for i in range(2, len(sys.argv)):
    files.append(sys.argv[i])
complexity = {}
if language == "c/c++":
    json_object = cppmodel.pred(files)
    json_string = json.dumps(json_object)
    print(json_string)

if language == "py":
    json_object = pycom.cal_complexity(files[0])
    json_string = json.dumps(json_object)
    print(json_string)

